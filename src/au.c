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

uint8_t (*au_reg) (int8_t*, int8_t*, int8_t*, uint64_t);

void (*au_op) (uint8_t*, uint64_t*, int8_t*, uint8_t*, uint64_t*, int8_t*, int8_t*, uint64_t);

typedef struct au_sym_s {
	int64_t str;
	uint64_t addr;
	uint8_t typ;
} au_sym_t;

void (*au_writ) (uint8_t*, uint64_t, au_sym_t*, uint64_t, au_sym_t*, uint64_t, int8_t*);

uint64_t au_str_int(int8_t* a, int8_t* e, int8_t* path, uint64_t ln) {
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
	
	int8_t lex[256];
	uint8_t li = 0;
	uint64_t ln = 0;
	int8_t c = 0;
	
	int8_t op[256];
	*((uint64_t*) op) = 0;
	*((uint64_t*) op + 1) = 0;
	int8_t rg[3][256];
	*((uint64_t*) rg[0]) = 0;
	*((uint64_t*) rg[0] + 1) = 0;
	*((uint64_t*) rg[1]) = 0;
	*((uint64_t*) rg[1] + 1) = 0;
	*((uint64_t*) rg[2]) = 0;
	*((uint64_t*) rg[2] + 1) = 0;
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
			if (rn < 3) {
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
			
			uint8_t rt[3] = {0, 0, 0};
			uint64_t rv[3] = {0, 0, 0};
			
			for (uint8_t i = 0; i < ri; i++) {
				if (rg[i][0] >= 97 && rg[i][0] <= 122) { //arch-spec reg
					rt[i] = 1;
					rv[i] = au_reg(rg[i], e, path, ln);
				}
				else if (rg[i][0] >= 48 && rg[i][0] <= 57) { //imm
					rt[i] = 2;
					rv[i] = au_str_int(rg[i], e, path, ln);
				}
				else if (rg[i][0] == '-' && rg[i][1] >= 48 && rg[i][1] <= 57) { //neg imm
					rt[i] = 3;
					rv[i] = -1 * au_str_int(rg[i] + 1, e, path, ln);
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
				au_op(bin, bn, op, rt, rv, e, path, ln);
			}
			else if (op[0] == '*' && op[1] >= 97 && op[1] <= 122) { //symbol
				sym[*symn].addr = *bn;
				memcpy(&(sym[*symn].str), op + 1, 8);
				(*symn)++;
			}
			else if (op[0] == '~' && op[1] >= 97 && op[1] <= 122) { //pseudo-op
				au_pseu_op(bin, bn, op + 1, rt, rv, e, path, ln);
			}
			else {
				printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
				*e = -1;
			}
			
		}
		
		if (fx[fi] == '\n') {
			*((uint64_t*) op) = 0;
			*((uint64_t*) op + 1) = 0;
			*((uint64_t*) rg[0]) = 0;
			*((uint64_t*) rg[0] + 1) = 0;
			*((uint64_t*) rg[1]) = 0;
			*((uint64_t*) rg[1] + 1) = 0;
			*((uint64_t*) rg[2]) = 0;
			*((uint64_t*) rg[2] + 1) = 0;
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
		au_op = avr_op;
	}
	else {
		printf("error: unsupported architecture\n");
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
	
	uint8_t bin[1000000];
	uint64_t bn = 0;
	au_sym_t sym[100000];
	uint64_t symn = 0;
	au_sym_t rel[100000];
	uint64_t reln = 0;
	int8_t e = 0;
	au_lex(bin, &bn, sym, &symn, rel, &reln, argv[2], &e);
	
	if (!e) {
		for (uint16_t i = 0; i < symn; i++) {
			printf("[sym]\tname: %s\n\taddr: %lu\n\ttyp: %hhu\n", (int8_t*) &(sym[i].str), sym[i].addr, sym[i].typ);
		}
		
		for (uint16_t i = 0; i < reln; i++) {
			printf("[rel]\tname: %s\n\taddr: %lu\n\ttyp: %hhu\n", (int8_t*) &(rel[i].str), rel[i].addr, rel[i].typ);
		}
		
		au_writ(bin, bn, sym, symn, rel, reln, argv[3]);
	}
	return 0;
}
