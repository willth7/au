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
	uint16_t bn = 0;
	int8_t e = 0;
	
	int8_t str[65536];
	uint16_t strn = 0;;
	
	elf_st32_t sym[256];
	uint8_t symn = 0;
	
	elf_r32_t rel[256];
	uint8_t reln = 0;
	
	int8_t lex[3][256];
	uint8_t x = 0;
	uint8_t y = 0;
	int8_t com = 0;
	uint16_t ln = 0;
	
	for (uint64_t fi = 0; fi < fsz; fi++) {
		if (data[fi] == '\n') {
			ln++;
		}
		
		if (data[fi] != ' ' && data[fi] != '\t' && data[fi] != '\n' && data[fi] != ';' && data[fi] != ',' && data[fi] != ':' && !com) {
			lex[x][y] = data[fi];
			y++;
			lex[x][y] = 0;
		}
		else if ((data[fi] == ' ' || data[fi] == '\t') && x == 0 && y && !com) {
			x = 1;
			y = 0;
		}
		else if (data[fi] == ',' && x == 1 && y && !com) {
			x = 2;
			y = 0;
		}
		else if (data[fi] == ':' && x == 0 && !com) {
			uint32_t stri = elf_loct(str, strn, lex[0], strlen(lex[0]) + 1);
			if (stri == 4294967295) {
				stri = strn;
				strn = elf_copy(str, strn, lex[0], strlen(lex[0]) + 1);
				
			}
			
			uint8_t symi = 255;
			for (uint8_t i = 0; i < symn; i++) {
				if (sym[i].name == stri) {
					sym[i].value = bn;
					symi = i;
					break;
				}
			}
			if (symi >= symn) {
				sym[symn].name = stri;
				sym[symn].value = bn;
				sym[symn].size = 0;
				sym[symn].info = 0;
				sym[symn].other = 0;
				sym[symn].shndx = 0;
				
				symi = symn;
				symn++;
			}
			
			lex[0][0] = 0;
			y = 0;
		}
		else if (data[fi] == ';' && !com) {
			com = 1;
			y = 0;
		}
		else if (data[fi] == '\n' && x) {
			com = 0;
			printf("%s %s, %s\n", lex[0], lex[1], lex[2]);
			x = 0;
			y = 0;
			
			enc_t enc;
			err_t err;
			err.b = 0;
			avr_t avr = avr_enc(lex[0], &err);
			int8_t rb = 0;
			
			uint16_t rd;
			if (avr.rd && lex[1][0]) {
				rd = avr.rd(lex[1], &err, &rb);
			}
			else if (avr.rd && !lex[1][0]) {
				strcpy(err.e, "too few arguments");
				err.b = 1;
			}
			else if (lex[1][0]) {
				strcpy(err.e, "too many arguments");
				err.b = 1;
			}
			if (rb && !err.b) {
				uint32_t stri = elf_loct(str, strn, lex[1], strlen(lex[1]) + 1);
				if (stri == 4294967295) {
					stri = strn;
					strn = elf_copy(str, strn, lex[1], strlen(lex[1]) + 1);
					
				}
				
				uint8_t symi = 255;
				for (uint8_t i = 0; i < symn; i++) {
					if (sym[i].name == stri) {
						symi = i;
						break;
					}
				}
				if (symi >= symn) {
					sym[symn].name = stri;
					sym[symn].value = 0;
					sym[symn].size = 0;
					sym[symn].info = 16;
					sym[symn].other = 0;
					sym[symn].shndx = 0;
					
					symi = symn;
					symn++;
				}
				
				rel[reln].offset = bn;
				rel[reln].info = (avr.typ & 255) | (symi << 8);
				reln++;
				
				rb = 0;
			}
			
			uint16_t rs;
			if (avr.rs && lex[2][0]) {
				rs = avr.rs(lex[2], &err, &rb);
			}
			else if (avr.rs && !lex[2][0]) {
				strcpy(err.e, "too few arguments");
				err.b = 1;
			}
			else if (lex[2][0]) {
				strcpy(err.e, "too many arguments");
				err.b = 1;
			}
			if (rb && !err.b) {
				uint32_t stri = elf_loct(str, strn, lex[2], strlen(lex[2]) + 1);
				if (stri == 4294967295) {
					stri = strn;
					strn = elf_copy(str, strn, lex[2], strlen(lex[2]) + 1);
					
				}
				
				uint8_t symi = 255;
				for (uint8_t i = 0; i < symn; i++) {
					if (sym[i].name == stri) {
						symi = i;
						break;
					}
				}
				if (symi >= symn) {
					sym[symn].name = stri;
					sym[symn].value = 0;
					sym[symn].size = 0;
					sym[symn].info = 16;
					sym[symn].other = 0;
					sym[symn].shndx = 0;
					
					symi = symn;
					symn++;
				}
				
				rel[reln].offset = bn;
				rel[reln].info = (avr.typ & 255) | (symi << 8);
				reln++;
				
				rb = 0;
			}
			
			if (avr.op) {
				enc = avr.op(rd, rs);
			}
			
			for (uint8_t ei = 0; ei < enc.n; ei++) {
				if (bn % 2 == 0) {
					printf("0x");
					
				}
				bits[bn] = enc.x[ei];
				printf("%02x", bits[bn]);
				bn++;
				if (bn % 2 == 0) {
					printf("\n");
					
				}
			}
			if (err.b) {
				e = 1;
				printf("error: %s\n", err.e);
			}
			
			lex[0][0] = 0;
			lex[1][0] = 0;
			lex[2][0] = 0;
		}
	}
	free(data);
	printf("\n");
	for (uint16_t i = 0; i < symn; i++) {
		printf("symbol: %s\noffset: %i\ninfo: %i\n", str + sym[i].name, sym[i].value, sym[i].info);
	}
	printf("\n");
	for (uint16_t i = 0; i < reln; i++) {
		printf("rel: %s\noffset: %i\ntype: %i\n", str + sym[rel[i].info >> 8].name, rel[i].offset, rel[i].info & 255);
	}
	
	if (!e) {
		elf_e32_t eh;
		eh.type = 1;
		eh.machine = 83;
		eh.version = 1;
		eh.entry = 0;
		eh.phoff = 0;
		eh.shoff = 52;
		eh.flags = 133;
		eh.ehsize = 52;
		eh.phentsize = 32;
		eh.phnum = 0;
		eh.shentsize = 40;
		eh.shnum = 2;
		eh.shstrndx = 1;
		
		elf_sh32_t sh[2];
		
		sh[0].name = 10;
		sh[0].type = 1;
		sh[0].flags = 5;
		sh[0].addr = 0;
		sh[0].offset = 132;
		sh[0].size = bn;
		sh[0].link = 0;
		sh[0].info = 0;
		sh[0].addralign = 0;
		sh[0].entsize = 0;
		
		sh[1].name = 0;
		sh[1].type = 3;
		sh[1].flags = 6;
		sh[1].addr = 0;
		sh[1].offset = 132 + bn;
		sh[1].size = 15;
		sh[1].link = 0;
		sh[1].info = 0;
		sh[1].addralign = 0;
		sh[1].entsize = 0;
		
		bn = elf_copy(bits, bn, ".shstrtab\0.text\0", 15);
		
		FILE* f = fopen(argv[2], "w");
		
		uint8_t* elf = elf_write(argv[2], 1, &eh, 0, &sh, bits, bn);
		uint64_t esz = eh.ehsize + (eh.phentsize * eh.phnum) + (eh.shentsize * eh.shnum) + bn;
		
		for (uint64_t i = 0; i < esz; i++) {
			fprintf(f, "%c", elf[i]);
		}
		
		fclose(f);
		
		free(elf);
	}
	
	return 0;
}
