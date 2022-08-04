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
	uint8_t rn;
} line_t;

int8_t main(int32_t argc, int8_t** argv) {
	line_t l[65536];
	uint16_t ln = 3;
	l[0].op = "adiw";
	l[0].rd = "r30";
	l[0].rs = "3";
	l[0].rn = 2;
	l[1].op = "adc";
	l[1].rd = "r17";
	l[1].rs = "r19";
	l[1].rn = 2;
	l[2].op = "nop";
	l[2].rn = 0;
	
	uint8_t byte[65536];
	uint16_t bi = 0;
	
	for (uint16_t li = 0; li < ln; li++) {
		enc_t enc;
		err_t err;
		err.b = 0;
		if (l[li].rn == 0) {
			enc = avr_enc(l[li].op, 0, 0, l[li].rn, &err);
		}
		else if (l[li].rn == 1) {
			enc = avr_enc(l[li].op, l[li].rd, 0, l[li].rn, &err);
		}
		else if (l[li].rn == 2) {
			enc = avr_enc(l[li].op, l[li].rd, l[li].rs, l[li].rn, &err);
		}
		if (err.b) {
			printf("error: %s\n", err.e);
			return -1;
		}
		printf("0x%02x%02x\n", enc.x[0], enc.x[1]);
		for (uint8_t ei = 0; ei < enc.n; ei++) {
			byte[bi] = enc.x[ei];
			bi++;
		}
	}
	
	return 0;
}
