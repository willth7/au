//   Copyright 2022 Will Thomas
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0;
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

//   gloria in excelsis deo

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "au/pseu.h"
#include "avr/avr.h"
#include "arm/32.h"
#include "arm/32m.h"
#include "arm/32a.h"

uint8_t (*au_reg) (int8_t*, int8_t*, int8_t*, uint64_t);

void (*au_enc) (uint8_t*, uint64_t*, int8_t*, uint8_t*, uint64_t*, int8_t*, int8_t*, uint64_t);

typedef struct au_sym_s {
	int64_t str;
	uint64_t addr;
	uint8_t typ;
} au_sym_t;

void (*au_writ) (uint8_t*, uint64_t, au_sym_t*, uint64_t, au_sym_t*, uint64_t, int8_t*);

uint64_t au_str_int_dec(int8_t* a, int8_t* e, int8_t* path, uint64_t ln) {
	uint64_t b = 0;
	for(uint8_t i = 0; i < 20; i++) {
		if (a[i] == 0) {
			return b;
		}
		b *= 10;
		if (a[i] == '1') {
			b += 1;
		}
		else if (a[i] == '2') {
			b += 2;
		}
		else if (a[i] == '3') {
			b += 3;
		}
		else if (a[i] == '4') {
			b += 4;
		}
		else if (a[i] == '5') {
			b += 5;
		}
		else if (a[i] == '6') {
			b += 6;
		}
		else if (a[i] == '7') {
			b += 7;
		}
		else if (a[i] == '8') {
			b += 8;
		}
		else if (a[i] == '9') {
			b += 9;
		}
		else if (a[i] != '0') {
			printf("[%s, %lu] error: illegal character '%c'\n", path, ln, a[i]);
			*e = -1;
		}
	}
}

uint64_t au_str_int_hex(int8_t* a, int8_t* e, int8_t* path, uint64_t ln) {
	uint64_t b = 0;
	for(uint8_t i = 0; i < 20; i++) {
		if (a[i] == 0) {
			return b;
		}
		b *= 16;
		if (a[i] == '1') {
			b += 1;
		}
		else if (a[i] == '2') {
			b += 2;
		}
		else if (a[i] == '3') {
			b += 3;
		}
		else if (a[i] == '4') {
			b += 4;
		}
		else if (a[i] == '5') {
			b += 5;
		}
		else if (a[i] == '6') {
			b += 6;
		}
		else if (a[i] == '7') {
			b += 7;
		}
		else if (a[i] == '8') {
			b += 8;
		}
		else if (a[i] == '9') {
			b += 9;
		}
		else if (a[i] == 'a') {
			b += 10;
		}
		else if (a[i] == 'b') {
			b += 11;
		}
		else if (a[i] == 'c') {
			b += 12;
		}
		else if (a[i] == 'd') {
			b += 13;
		}
		else if (a[i] == 'e') {
			b += 14;
		}
		else if (a[i] == 'f') {
			b += 15;
		}
		else if (a[i] != '0') {
			printf("[%s, %lu] error: illegal character '%c'\n", path, ln, a[i]);
			*e = -1;
		}
	}
}

void au_clr_rg(int8_t rg[20][64]) {
	for (uint8_t i = 0; i < 20; i++) {
		*((uint64_t*) rg[i]) = 0;
		*((uint64_t*) rg[i] + 1) = 0;
	}
}

void au_lex(uint8_t* bin, uint64_t* bn, au_sym_t* sym, uint64_t* symn, au_sym_t* rel, uint64_t* reln, int8_t* path, int8_t* e) {
	FILE* f = fopen(path, "r");
	if (!f) {
		printf("[%s] error: file doesn't exist\n", path);
		*e = -1;
		return;
	}
	fseek(f, 0, SEEK_END);
	uint64_t fn = ftell(f);
	int8_t* fx = malloc(fn);
	fseek(f, 0, SEEK_SET);
	fread(fx, fn, 1, f);
	fclose(f);
	
	int8_t lex[64];
	uint8_t li = 0;
	uint64_t ln = 0;
	int8_t c = 0;
	
	int8_t op[64];
	*((uint64_t*) op) = 0;
	*((uint64_t*) op + 1) = 0;
	int8_t rg[20][64];
	au_clr_rg(rg);
	uint8_t ri = 0;
	uint8_t rn = 0;
	
	for (uint64_t fi = 0; fi < fn; fi++) {
		if (((fx[fi] >= 97 && fx[fi] <= 122) || (fx[fi] >= 48 && fx[fi] <= 57) || fx[fi] == '_') && !c) { //string
			lex[li] = fx[fi];
			lex[li + 1] = 0;
			li++;
		}
		else if ((fx[fi] == '*' || fx[fi] == '^' || fx[fi] == '-' || fx[fi] == '~') && !li && !c) { //special init char
			lex[li] = fx[fi];
			li++;
		}
		else if (fx[fi] == ',' && !c) { //addt operand signal
			if (rn < 20) {
				rn++;
			}
			else {
				printf("[%s, %lu] error: too many operands\n", path, ln);
				*e = -1;
			}
		}
		else if ((fx[fi] == ' ' || fx[fi] == '\t' || fx[fi] == '\n') && li && !c) { //next string
			if (!(op[0])) {
				strcpy(op, lex);
				rn = 1;
			}
			else if (ri < rn) {
				strcpy(rg[ri], lex);
				ri++;
				
			}
			else {
				printf("[%s, %lu] error: expected ','\n", path, ln);
				*e = -1;
			}
			lex[0] = 0;
			li = 0;
		}
		else if (fx[fi] == ';') { //comment
			c = 1;
		}
		else if (fx[fi] != ' ' && fx[fi] != '\t' && fx[fi] != '\n' && !c) {
			printf("[%s, %lu] error: junk character '%c'\n", path, ln, fx[fi]);
			*e = -1;
		}
		
		if (fx[fi] == '\n' && op[0]) { //encode line
			if (ri != rn && rn > 1) {
				printf("[%s, %lu] error: expected operand\n", path, ln);
				*e = -1;
			}
			
			uint8_t rt[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint64_t rv[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			
			for (uint8_t i = 0; i < ri; i++) {
				if (rg[i][0] >= 97 && rg[i][0] <= 122) { //arch-spec reg
					rt[i] = 1;
					rv[i] = au_reg(rg[i], e, path, ln);
				}
				else if (rg[i][0] >= 48 && rg[i][0] <= 57) { //imm
					rt[i] = 2;
					if (rg[i][0] == '0' && rg[i][1] == 'x') {
						rv[i] = au_str_int_hex(rg[i] + 2, e, path, ln);
					}
					else {
						rv[i] = au_str_int_dec(rg[i], e, path, ln);
					}
				}
				else if (rg[i][0] == '-' && rg[i][1] >= 48 && rg[i][1] <= 57) { //neg imm
					rt[i] = 2;
					if (rg[i][0] == '0' && rg[i][1] == 'x') {
						rv[i] = -1 * au_str_int_hex(rg[i] + 3, e, path, ln);
					}
					else {
						rv[i] = -1 * au_str_int_dec(rg[i] + 1, e, path, ln);
					}
				}
				else if (rg[i][0] == '*' && rg[i][1] >= 97 && rg[i][1] <= 122) { //relocation
					rt[i] = 4;
					rv[i] = (uint64_t) &(rel[*reln].typ);
					rel[*reln].addr = *bn;
					rel[*reln].typ = 0;
					memcpy(&(rel[*reln].str), rg[i] + 1, 8);
					(*reln)++;
				}
				else if (rg[i][0] == '^' && rg[i][1] >= 97 && rg[i][1] <= 122) { //relocation
					rt[i] = 4;
					rv[i] = (uint64_t) &(rel[*reln].typ);
					rel[*reln].addr = *bn;
					rel[*reln].typ = 128;
					memcpy(&(rel[*reln].str), rg[i] + 1, 8);
					(*reln)++;
				}
				else {
					printf("[%s, %lu] error: unknown operand '%s'\n", path, ln, rg[i]);
					*e = -1;
				}
			}
			
			
			if (op[0] >= 97 && op[0] <= 122) { //arch-spec op
				au_enc(bin, bn, op, rt, rv, e, path, ln);
			}
			else if (op[0] == '*' && op[1] >= 97 && op[1] <= 122) { //symbol
				for (uint64_t i = 0; i < *symn; i++) {
					if (!memcmp(&(sym[i].str), op + 1, 8)) {
						printf("[%s, %lu] error: redefinition of symbol '%s'\n", path, ln, op + 1);
						*e = -1;
					}
				}
				sym[*symn].addr = *bn;
				memcpy(&(sym[*symn].str), op + 1, 8);
				(*symn)++;
			}
			else if (op[0] == '~' && op[1] >= 97 && op[1] <= 122) { //pseudo-op
				au_pseu_enc(bin, bn, op + 1, rt, rv, e, path, ln);
			}
			else {
				printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
				*e = -1;
			}
			
		}
		
		if (fx[fi] == '\n') {
			*((uint64_t*) op) = 0;
			*((uint64_t*) op + 1) = 0;
			au_clr_rg(rg);
			ri = 0;
			rn = 0;
			lex[0] = 0;
			li = 0;
			c = 0;
			ln++;
		}
	}
	
	free(fx);
}

void au_writ_bin(uint8_t* bin, uint64_t bn, au_sym_t* sym, uint64_t symn, au_sym_t* rel, uint64_t reln, int8_t* path) {
	FILE* f = fopen(path, "w");
	fwrite(bin, bn, 1, f);
	fclose(f);
}

void au_writ_zn(uint8_t* bin, uint64_t bn, au_sym_t* sym, uint64_t symn, au_sym_t* rel, uint64_t reln, int8_t* path) {
	uint8_t* buf = malloc(52 + bn + (symn * 17) + (reln * 17));
	
	uint64_t binoff = 52;
	uint64_t symoff = 52 + bn;
	uint64_t reloff = 52 + bn + (symn * 17);
	
	memcpy(buf, "zinc", 4);
	memcpy(buf + 4, &binoff, 8);
	memcpy(buf + 12, &bn, 8);
	memcpy(buf + 20, &symoff, 8);
	memcpy(buf + 28, &symn, 8);
	memcpy(buf + 36, &reloff, 8);
	memcpy(buf + 44, &reln, 8);
	
	memcpy(buf + binoff, bin, bn);
	for (uint64_t i = 0; i < symn; i++) {
		memcpy(buf + symoff + (17 * i), &(sym[i].str), 8);
		memcpy(buf + symoff + (17 * i) + 8, &(sym[i].addr), 8);
		memcpy(buf + symoff + (17 * i) + 16, &(sym[i].typ), 1);
	}
	
	for (uint64_t i = 0; i < reln; i++) {
		memcpy(buf + reloff + (17 * i), &(rel[i].str), 8);
		memcpy(buf + reloff + (17 * i) + 8, &(rel[i].addr), 8);
		memcpy(buf + reloff + (17 * i) + 16, &(rel[i].typ), 1);
	}
	
	FILE* f = fopen(path, "w");
	fwrite(buf, 52 + bn + (symn * 17) + (reln * 17), 1, f);
	fclose(f);
	
	free(buf);
}

int8_t main(int32_t argc, int8_t** argv) {
	if (argc != 4) {
		printf("usage: au [architecture] [source.s] [binary.bin or link.zn]\n");
		return -1;
	}
	
	if (!strcmp(argv[1], "avr")) {
		au_reg = avr_reg;
		au_enc = avr_enc;
	}
	else if (!strcmp(argv[1], "arm-32m")) {
		au_reg = arm_32_reg;
		au_enc = arm_32m_enc;
	}
	else if (!strcmp(argv[1], "arm-32a")) {
		au_reg = arm_32_reg;
		au_enc = arm_32a_enc;
	}
	else {
		printf("error: unsupported architecture\n");
		return -1;
	}
	
	if (strcmp(argv[2] + strlen(argv[2]) - 2, ".s")) {
		printf("error: expected .s file\n");
		return -1;
	}
	
	if (!strcmp(argv[3] + strlen(argv[3]) - 4, ".bin")) {
		au_writ = au_writ_bin;
	}
	else if (!strcmp(argv[3] + strlen(argv[3]) - 3, ".zn")) {
		au_writ = au_writ_zn;
	}
	else {
		printf("error: invalid writput format\n");
		return -1;
	}
	
	uint8_t* bin = calloc(1000000, 1);
	uint64_t bn = 0;
	au_sym_t* sym = calloc(1000000, 1);
	uint64_t symn = 0;
	au_sym_t* rel = calloc(1000000, 1);
	uint64_t reln = 0;
	int8_t e = 0;
	au_lex(bin, &bn, sym, &symn, rel, &reln, argv[2], &e);
	
	if (!e) {
		au_writ(bin, bn, sym, symn, rel, reln, argv[3]);
	}
	
	free(bin);
	free(sym);
	free(rel);
	return 0;
}
