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

#include "avr/enc.h"
#include "elf/elf.h"

uint16_t au_sym_loct(elf_st32_t* sym, uint16_t* symn, uint16_t strn) {
	uint16_t symi = -1;
	for (uint16_t i = 0; i < *symn; i++) {
		if (sym[i].name == strn) {
			symi = i;
			i = *symn;
		}
	}
	
	if (symi == (uint16_t) -1) { //create symbol if doesn't exist
		symi = *symn;
		sym[symi].name = strn;
		sym[*symn].value = 0;
		sym[*symn].size = 0;
		sym[*symn].info = 0;
		sym[*symn].other = 0;
		sym[*symn].shndx = 0;
		(*symn)++;
	}
	return symi;
}

uint64_t au_enc_avr(int8_t* op, int8_t* r0, int8_t* r1, int8_t* r2, uint8_t* bits, uint64_t bn, uint8_t* str, uint16_t* strn, elf_st32_t* sym, uint16_t* symn, elf_r32_t* rel, uint16_t* reln) {
	if (r0 && r0[strlen(r0) - 1] == ',') {
		r0[strlen(r0) - 1] = 0;
	}
	if (r1 && r1[strlen(r1) - 1] == ',') {
		r1[strlen(r1) - 1] = 0;
	}
	
	int8_t eb = 0;
	int8_t rb = 0;
	
	avr_t avr = avr_enc(op, &eb);
	
	uint16_t rd;
	if (avr.rd) {
		rd = avr.rd(r0, &eb, &rb);
	}
	else if (r0) {
		eb = 1;
	}
	if (rb && !eb) {
		uint32_t stri = elf_loct(str, *strn, r0, strlen(r0) + 1);
		if (stri == -1) {
			stri = *strn;
			memcpy(str + *strn, r0, strlen(r0) + 1);
			*strn += strlen(r0) + 1;
		}
		
		uint16_t symi = au_sym_loct(sym, symn, stri);
		
		rel[*reln].offset = bn;
		rel[*reln].info = (avr.rel & 255) | (symi << 8);
		(*reln)++;
		
		rb = 0;
	}
	
	uint16_t rs;
	if (avr.rs) {
		rs = avr.rs(r1, &eb, &rb);
	}
	else if (r1) {
		eb = 1;
	}
	if (rb && !eb) {
		uint32_t stri = elf_loct(str, *strn, r1, strlen(r1) + 1);
		if (stri == -1) {
			stri = *strn;
			memcpy(str + *strn, r1, strlen(r1) + 1);
			*strn += strlen(r1) + 1;
		}
		
		uint16_t symi = au_sym_loct(sym, symn, stri);
		
		rel[*reln].offset = bn;
		rel[*reln].info = (avr.rel & 255) | (symi << 8);
		(*reln)++;
		
		rb = 0;
	}
	
	if (avr.op) {
		uint64_t bi = bn;
		bn = avr.op(bits, bn, rd, rs);
		
		printf("0x");
		for (uint8_t i = bi; i < bn; i++) {
			printf("%02x", bits[i]);
		}
		printf("\n");
	}
	
	if (eb) {
		printf("error\n");
	}
	
	return bn;
}

int8_t main(int32_t argc, int8_t** argv) {
	if (argc < 3) {
		printf("error: too few arguments\n");
		return -1;
	}
	
	uint8_t bits[65536];
	uint16_t bn = 0;
	int8_t e = 0;
	
	int8_t str[65536];
	uint16_t strn = 0;
	
	elf_st32_t sym[65536];
	uint16_t symn = 0;
	
	elf_r32_t rel[65536];
	uint16_t reln = 0;
	
	int8_t lex[256];
	lex[0] = 0;
	uint8_t lexn = 0;
	int8_t com = 0;
	uint16_t ln = 0;
	
	int8_t* op = 0;
	int8_t* r0 = 0;
	int8_t* r1 = 0;
	int8_t* r2 = 0;
	
	for (uint8_t ai = 1; ai < argc - 1; ai ++) {
		FILE* f = fopen(argv[ai], "r");
		if (f == 0) {
			printf("error: file %s doesn't exist'\n", argv[1]);
			return -1;
		}
		fseek(f, 0, SEEK_END);
		uint64_t fn = ftell(f);
		uint8_t* data = malloc(fn);
		fseek(f, 0, SEEK_SET);
		fread(data, fn, 1, f);
		fclose(f);
		
		for (uint64_t fi = 0; fi < fn; fi++) {
			if (data[fi] == '\n') {
				ln++;
				com = 0;
			}
			
			if (data[fi] != ' ' && data[fi] != '\t' && data[fi] != '\n' && data[fi] != ';' && !com) {
				lex[lexn] = data[fi];
				lexn++;
				lex[lexn] = 0;
			}
			else if ((data[fi] == ' ' || data[fi] == '\t' || data[fi] == '\n' || data[fi] == ';') && lexn && !com) {
				if (lex[lexn - 1] == ':') { //symbol
					lex[lexn - 1] = 0;
					
					uint32_t stri = elf_loct(str, strn, lex, lexn); //look for string
					if (stri == -1) { //create string if doesn't exist
						stri = strn;
						memcpy(str + strn, lex, lexn);
						strn += lexn;
					}
					
					uint16_t symi = au_sym_loct(sym, &symn, stri);
					sym[symi].value = bn;
					sym[symi].shndx = 1;
					
					lex[0] = 0;
					lexn = 0;
				}
				else if (!op && lexn) {
					op = malloc(lexn + 1);
					strcpy(op, lex);
				}
				else if (!r0 && lexn) {
					r0 = malloc(lexn + 1);
					strcpy(r0, lex);
				}
				else if (!r1 && lexn) {
					r1 = malloc(lexn + 1);
					strcpy(r1, lex);
				}
				else if (!r2 && lexn) {
					r2 = malloc(lexn + 1);
					strcpy(r2, lex);
				}
				
				lexn = 0;
			}
			
			if (data[fi] == ';' && !com) {
				com = 1;
				lexn = 0;
			}
			
			if (data[fi] == '\n' && op) {
				lexn = 0;
				
				if (op[0] == '.') { //directive
					 if (op[1] == 'v' && op[2] == 'a' && op[3] == 'r' && op[4] == 0) {
						int32_t stri = elf_loct(str, strn, r0, strlen(r0) + 1);
						if (stri == -1) {
							stri = strn;
							memcpy(str + strn, r0, strlen(r0) + 1);
							strn += strlen(r0) + 1;
						}
						
						uint16_t symi = au_sym_loct(sym, &symn, stri);
						sym[symi].info &= 240;
						sym[symi].info |= 1;
					}
					else if (op[1] == 'f' && op[2] == 'u' && op[3] == 'n' && op[4] == 'c' && op[5] == 0) {
						int32_t stri = elf_loct(str, strn, r0, strlen(r0) + 1);
						if (stri == -1) {
							stri = strn;
							memcpy(str + strn, r0, strlen(r0) + 1);
							strn += strlen(r0) + 1;
						}
						
						uint16_t symi = au_sym_loct(sym, &symn, stri);
						sym[symi].info &= 240;
						sym[symi].info |= 2;
						
					}
					else if (op[1] == 'l' && op[2] == 'o' && op[3] == 'c' && op[4] == 'a' && op[5] == 'l' && op[6] == 0) {
						int32_t stri = elf_loct(str, strn, r0, strlen(r0) + 1);
						if (stri == -1) {
							stri = strn;
							memcpy(str + strn, r0, strlen(r0) + 1);
							strn += strlen(r0) + 1;
						}
						
						uint16_t symi = au_sym_loct(sym, &symn, stri);
						sym[symi].info &= 15;
					}
					else if (op[1] == 'g' && op[2] == 'l' && op[3] == 'o' && op[4] == 'b' && op[5] == 'l' && op[6] == 0) {
						int32_t stri = elf_loct(str, strn, r0, strlen(r0) + 1);
						if (stri == -1) {
							stri = strn;
							memcpy(str + strn, r0, strlen(r0) + 1);
							strn += strlen(r0) + 1;
						}
						
						uint16_t symi = au_sym_loct(sym, &symn, stri);
						sym[symi].info &= 15;
						sym[symi].info |= 16;
					}
					else {
						//error
					}
				}
				else {
					printf("%s", op);
					if (r0) {
						printf(" %s", r0);
					}
					if (r1) {
						printf(" %s", r1);
					}
					printf("\n");
					
					bn = au_enc_avr(op, r0, r1, 0, bits, bn, str, &strn, sym, &symn, rel, &reln);
				}
				lex[0] = 0;
				if (op) {
					op = 0;
					free(op);
				}
				if (r0) {
					r0 = 0;
					free(r0);
				}
				if (r1) {
					r1 = 0;
					free(r1);
				}
			}
		}
		
		free(data);
	}
	
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
		
		eh.flags = 133;
		eh.ehsize = 52;
		eh.phentsize = 32;
		eh.phnum = 0;
		eh.shentsize = 40;
		
		elf_sh32_t sh[5];
		uint8_t shn = 0;
		int8_t shstr[65536];
		uint16_t shstrn = 0;
		
		sh[shn].name = 0;
		sh[shn].type = 0;
		sh[shn].flags = 0;
		sh[shn].addr = 0;
		sh[shn].offset = 0;
		sh[shn].size = 0;
		sh[shn].link = 0;
		sh[shn].info = 0;
		sh[shn].addralign = 0;
		sh[shn].entsize = 0;
		memcpy(shstr + shstrn, "\0", 1);
		shstrn += 1;
		shn++;
		
		sh[shn].name = shstrn;
		sh[shn].type = 1;
		sh[shn].flags = 7;
		sh[shn].addr = 0;
		sh[shn].offset = eh.ehsize;
		sh[shn].size = bn;
		sh[shn].link = 0;
		sh[shn].info = 0;
		sh[shn].addralign = 0;
		sh[shn].entsize = 0;
		memcpy(shstr + shstrn, "code", 5);
		shstrn += 5;
		shn++;
		
		if (symn > 0) {
			sh[shn].name = shstrn;
			sh[shn].type = 3;
			sh[shn].flags = 0;
			sh[shn].addr = 0;
			sh[shn].offset = eh.ehsize + bn;
			sh[shn].size = strn;
			sh[shn].link = 0;
			sh[shn].info = 0;
			sh[shn].addralign = 0;
			sh[shn].entsize = 0;
			memcpy(shstr + shstrn, "str", 4);
			shstrn += 4;
			memcpy(bits + bn, str, strn);
			bn += strn;
			shn++;
			
			sh[shn].name = shstrn;
			sh[shn].type = 2;
			sh[shn].flags = 0;
			sh[shn].addr = 0;
			sh[shn].offset = eh.ehsize + bn;
			sh[shn].size = symn * 16;
			sh[shn].link = shn - 1;
			sh[shn].info = symn;
			sh[shn].addralign = 0;
			sh[shn].entsize = 16;
			memcpy(shstr + shstrn, "sym", 4);
			shstrn += 4;
			memcpy(bits + bn, sym, symn * 16);
			bn += symn * 16;
			shn++;
		}
		
		if (reln > 0) {
			sh[shn].name = shstrn;
			sh[shn].type = 9;
			sh[shn].flags = 64;
			sh[shn].addr = 0;
			sh[shn].offset = eh.ehsize + bn;
			sh[shn].size = reln * 8;
			sh[shn].link = shn - 1;
			sh[shn].info = 1;
			sh[shn].addralign = 0;
			sh[shn].entsize = 8;
			memcpy(shstr + shstrn, "rel", 4);
			shstrn += 4;
			memcpy(bits + bn, rel, reln * 8);
			bn += reln * 8;
			shn++;
		}
		
		sh[shn].name = shstrn;
		sh[shn].type = 3;
		sh[shn].flags = 0;
		sh[shn].addr = 0;
		sh[shn].offset = eh.ehsize + bn;
		sh[shn].size = shstrn + 10;
		sh[shn].link = 0;
		sh[shn].info = 0;
		sh[shn].addralign = 0;
		sh[shn].entsize = 0;
		memcpy(shstr + shstrn, "shstr", 6);
		shstrn += 6;
		memcpy(bits + bn, shstr, shstrn);
		bn += shstrn;
		eh.shstrndx = shn;
		shn++;
		
		eh.shoff = eh.ehsize + bn;
		eh.shnum = shn;
		
		FILE* f = fopen(argv[argc - 1], "w");
		
		uint8_t* elf = elf_write_32(&eh, 0, sh, bits, bn);
		uint64_t esz = eh.ehsize + (eh.phentsize * eh.phnum) + (eh.shentsize * eh.shnum) + bn;
		
		for (uint64_t i = 0; i < esz; i++) {
			fprintf(f, "%c", elf[i]);
		}
		
		fclose(f);
		
		free(elf);
	}
	
	return 0;
}
