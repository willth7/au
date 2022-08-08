//   Copyright 2022 Will Thomas
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "avr/avr.h"

typedef struct line_s {
	int8_t* op;
	int8_t* rd;
	int8_t* rs;
	int8_t* sym;
	uint16_t ln;
} line_t;

typedef struct sym_s {
	int8_t* str;
	uint16_t off;
	uint16_t typ;
} sym_t;

int8_t main(int32_t argc, int8_t** argv) {
	line_t l[65536];
	uint16_t ln = 4;
	l[0].op = "mov";
	l[0].rd = "r3";
	l[0].rs = "r17";
	l[1].op = "call";
	l[1].rd = "func";
	l[1].rs = 0;
	l[2].op = "breq";
	l[2].rd = "gunc";
	l[2].rs = 0;
	l[3].op = "jmp";
	l[3].rd = "func";
	l[3].rs = 0;
	
	uint8_t byte[65536];
	uint16_t bi = 0;
	int8_t e = 0;
	
	sym_t sym[65536];
	uint16_t si = 0;
	
	for (uint16_t li = 0; li < ln; li++) {
		enc_t enc;
		err_t err;
		err.b = 0;
		avr_t avr = avr_enc(l[li].op, &err);
		int8_t sb = 0;
		
		uint16_t rd;
		if (avr.rd && l[li].rd) {
			rd = avr.rd(l[li].rd, &err, &sb);
		}
		else if (avr.rd && !l[li].rd) {
			err.b = 1;
		}
		else if (l[li].rd) {
			err.b = 1;
		}
		if (sb && !err.b) {
			sym[si].str = malloc(strlen(l[li].rd) + 1);
			strcpy(sym[si].str, l[li].rd);
			sym[si].off = bi;
			si++;
			sb = 0;
		}
		
		uint16_t rs;
		if (avr.rs && l[li].rs) {
			rs = avr.rs(l[li].rs, &err, &sb);
		}
		else if (avr.rs && !l[li].rs) {
			err.b = 1;
		}
		else if (l[li].rs) {
			err.b = 1;
		}
		if (sb && !err.b) {
			sym[si].str = malloc(strlen(l[li].rd) + 1);
			strcpy(sym[si].str, l[li].rd);
			sym[si].off = bi;
			si++;
			sb = 0;
		}
		
		if (avr.op) {
			enc = avr.op(rd, rs);
		}
		
		for (uint8_t ei = 0; ei < enc.n; ei++) {
			if (bi % 2 == 0) {
				printf("0x");
				
			}
			byte[bi] = enc.x[ei];
			printf("%02x", byte[bi]);
			bi++;
			if (bi % 2 == 0) {
				printf("\n");
				
			}
		}
		if (err.b) {
			e = 1;
			printf("error\n");
		}
	}
	
	for (uint16_t i = 0; i < si; i++) {
		printf("%s, %i\n", sym[i].str, sym[i].off);
		free(sym[i].str);
	}
	
	return 0;
}
