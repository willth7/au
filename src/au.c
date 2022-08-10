//   Copyright 2022 Will Thomas
//
//   Licensed under the Apache License, Verrion 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BAriS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permisrions and
//   limitations under the License.

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "avr/avr.h"
#include "elf/elf.h"

typedef struct sym_s {
	int8_t* sym;
	uint16_t off;
	uint16_t typ;
} sym_t;

int8_t main(int32_t argc, int8_t** argv) {
	if (argc != 3) {
		printf("error: too few arguments\n");
		return -1;
	}
	
	FILE* f = fopen(argv[1], "r");
	if (f == 0) {
		printf("error: file %s doesn't exist'\n", argv[1]);
		return -1;
	}
	fseek(f, 0, SEEK_END);
	uint64_t fsz = ftell(f);
	uint8_t* data = malloc(fsz);
	fseek(f, 0, SEEK_SET);
	fread(data, fsz, 1, f);
	fclose(f);
	
	uint8_t bits[65536];
	uint16_t bi = 0;
	int8_t e = 0;
	
	sym_t sym[65536];
	uint16_t si = 0;
	
	sym_t rel[65536];
	uint16_t ri = 0;
	
	int8_t str[3][256];
	uint8_t sx = 0;
	uint8_t sy = 0;
	int8_t com = 0;
	uint16_t ln = 0;
	
	for (uint64_t fi = 0; fi < fsz; fi++) {
		if (data[fi] == '\n') {
			ln++;
		}
		
		if (data[fi] != ' ' && data[fi] != '\t' && data[fi] != '\n' && data[fi] != ';' && data[fi] != ',' && data[fi] != ':' && !com) {
			str[sx][sy] = data[fi];
			sy++;
			str[sx][sy] = 0;
		}
		else if ((data[fi] == ' ' || data[fi] == '\t') && sx == 0 && sy && !com) {
			sx = 1;
			sy = 0;
		}
		else if (data[fi] == ',' && sx == 1 && sy && !com) {
			sx = 2;
			sy = 0;
		}
		else if (data[fi] == ':' && sx == 0 && !com) {
			sym[si].sym = malloc(strlen(str[0]) + 1);
			strcpy(sym[si].sym, str[0]);
			sym[si].off = bi;
			sym[si].typ = 1;
			si++;
			str[0][0] = 0;
			sy = 0;
		}
		else if (data[fi] == ';' && !com) {
			com = 1;
			sy = 0;
		}
		else if (data[fi] == '\n' && sx) {
			com = 0;
			printf("%s %s, %s\n", str[0], str[1], str[2]);
			sx = 0;
			sy = 0;
			
			enc_t enc;
			err_t err;
			err.b = 0;
			avr_t avr = avr_enc(str[0], &err);
			int8_t rb = 0;
			
			uint16_t rd;
			if (avr.rd && str[1][0]) {
				rd = avr.rd(str[1], &err, &rb);
			}
			else if (avr.rd && !str[1][0]) {
				strcpy(err.e, "too few arguments");
				err.b = 1;
			}
			else if (str[1][0]) {
				strcpy(err.e, "too many arguments");
				err.b = 1;
			}
			if (rb && !err.b) {
				rel[ri].sym = malloc(strlen(str[1]) + 1);
				strcpy(rel[ri].sym, str[1]);
				rel[ri].off = bi;
				rel[ri].typ = avr.typ;
				ri++;
				rb = 0;
			}
			
			uint16_t rs;
			if (avr.rs && str[2][0]) {
				rs = avr.rs(str[2], &err, &rb);
			}
			else if (avr.rs && !str[2][0]) {
				strcpy(err.e, "too few arguments");
				err.b = 1;
			}
			else if (str[2][0]) {
				strcpy(err.e, "too many arguments");
				err.b = 1;
			}
			if (rb && !err.b) {
				rel[ri].sym = malloc(strlen(str[1]) + 1);
				strcpy(rel[ri].sym, str[1]);
				rel[ri].off = bi;
				ri++;
				rb = 0;
			}
			
			if (avr.op) {
				enc = avr.op(rd, rs);
			}
			
			for (uint8_t ei = 0; ei < enc.n; ei++) {
				if (bi % 2 == 0) {
					printf("0x");
					
				}
				bits[bi] = enc.x[ei];
				printf("%02x", bits[bi]);
				bi++;
				if (bi % 2 == 0) {
					printf("\n");
					
				}
			}
			if (err.b) {
				e = 1;
				printf("error: %s\n", err.e);
			}
			
			str[0][0] = 0;
			str[1][0] = 0;
			str[2][0] = 0;
		}
	}
	free(data);
	for (uint16_t i = 0; i < si; i++) {
		printf("symbol: %s\noffset: %i\ntype: %i\n", sym[i].sym, sym[i].off, sym[i].typ);
		free(sym[i].sym);
	}
	for (uint16_t i = 0; i < ri; i++) {
		printf("rel symbol: %s\noffset: %i\ntype: %i\n", rel[i].sym, rel[i].off, rel[i].typ);
		free(rel[i].sym);
	}
	
	if (!e) {
		elf_e64_t eh;
		eh.type = 1;
		eh.machine = 83;
		eh.version = 1;
		eh.entry = 0;
		eh.phoff = 0;
		eh.shoff = 0;
		eh.ehsize = 52;
		eh.phentsize = 32;
		eh.phnum = 0;
		eh.shentsize = 40;
		eh.shnum = 0;
		eh.shstrndx = 0;
		
		elf_write(argv[2], 1, &eh, 0, 0, bits, bi);
	}
	
	return 0;
}
