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
#include <unistd.h>
#include <stdio.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "au/pseu.h"
#include "arm/32m.h"
#include "arm/32a.h"
#include "arm/64.h"
#include "x86/x86.h"
#include "x86/i386.h"
#include "x86/x64.h"

uint8_t (*au_reg) (int8_t*, int8_t*, int8_t*, uint64_t);

void (*au_enc) (uint8_t*, uint64_t*, int8_t*, uint8_t*, uint64_t*, int8_t*, int8_t*, uint64_t);

typedef struct au_sym_s {
	int64_t strl;
	int64_t strh;
	int64_t str2;
	uint64_t addr;
	uint8_t typ;
} au_sym_t;

void (*au_writ) (uint8_t*, uint64_t, au_sym_t*, uint64_t, au_sym_t*, uint64_t, int8_t*);


uint64_t au_str_int_dec(int8_t* a, int8_t* e, int8_t* path, uint64_t ln) {
	uint64_t b = 0;
	for(uint8_t i = 0; i < 20; i++) {
		if (a[i] == 0 || a[i] == ')') {
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
		else if (a[i] != '0' && a[i] != ')') {
			printf("[%s, %lu] error: illegal character '%c'\n", path, ln, a[i]);
			*e = -1;
		}
	}
}

uint64_t au_str_int_hex(int8_t* a, int8_t* e, int8_t* path, uint64_t ln) {
	uint64_t b = 0;
	for(uint8_t i = 0; i < 20; i++) {
		if (a[i] == 0 || a[i] == ')') {
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
		else if (a[i] != '0' && a[i] != ')') {
			printf("[%s, %lu] error: illegal character '%c'\n", path, ln, a[i]);
			*e = -1;
		}
	}
}

void au_clr_rg(int8_t rg[20][64]) {
	for (uint8_t i = 0; i < 20; i++) {
		*((uint64_t*) rg[i]) = 0;
		*((uint64_t*) rg[i] + 1) = 0;
		*((uint64_t*) rg[i] + 2) = 0;
	}
}

void au_lex(uint8_t* bin, uint64_t* bn, au_sym_t* sym, uint64_t* symn, au_sym_t* rel, uint64_t* reln, int8_t* path, int8_t* e) {
	int32_t fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("error: failed to open file '%s'\n", path);
		*e = -1;
        return;
    }
	
    struct stat fs;
    fstat(fd, &fs);
	
    uint8_t* fx = mmap(0, fs.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
	
	int8_t lex[64];
	uint8_t li = 0;
	uint64_t ln = 0;
	int8_t c = 0;
	
	int8_t op[64];
	*((uint64_t*) op) = 0;
	*((uint64_t*) op + 1) = 0;
	*((uint64_t*) op + 2) = 0;
	int8_t rg[20][64];
	au_clr_rg(rg);
	uint8_t ri = 0;
	uint8_t rn = 0;
	
	for (uint64_t fi = 0; fi < fs.st_size; fi++) {
		if (((fx[fi] >= 97 && fx[fi] <= 122) || (fx[fi] >= 48 && fx[fi] <= 57) || fx[fi] == '_') && !c) { //string
			lex[li] = fx[fi];
			lex[li + 1] = 0;
			li++;
		}
		else if ((fx[fi] == '*' || fx[fi] == '^' || fx[fi] == '-' || fx[fi] == '~' || fx[fi] == '(') && !li && !c) { //special init char
			lex[li] = fx[fi];
			li++;
		}
		else if (fx[fi] == ',' && op[0] && !c) { //addt operand signal
			if (rn < 20) {
				rn++;
			}
			else {
				printf("[%s, %lu] error: too many operands\n", path, ln);
				*e = -1;
			}
		}
		else if (fx[fi] == ')' && (fx[fi + 1] == ' ' || fx[fi + 1] == ',' || fx[fi + 1] == '\t' || fx[fi + 1] == '\n') && op[0] && li && !c) { //nested operand
			lex[li] = ')';
			lex[li + 1] = 0;
			li++;
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
			
			uint8_t p = 0;
			
			for (uint8_t i = 0; i < ri; i++) {
				uint8_t q = 0;
				if (rg[i][0] == '(' && !p) { //nested operands
					p = 1;
					q = 1;
				}
				else if (rg[i][0] == '(' && p) { //error
					printf("[%s, %lu] error: expected ')'\n", path, ln);
					*e = -1;
				}
				
				if (rg[i][q] >= 97 && rg[i][q] <= 122) { //arch-spec reg
					rt[i] = 1 | (p << 2);
					rv[i] = au_reg(rg[i] + q, e, path, ln);
				}
				else if (rg[i][q] >= 48 && rg[i][q] <= 57) { //imm
					rt[i] = 2 | (p << 2);
					if (rg[i][q] == '0' && rg[i][q + 1] == 'x') {
						rv[i] = au_str_int_hex(rg[i] + 2 + q, e, path, ln);
					}
					else {
						rv[i] = au_str_int_dec(rg[i] + q, e, path, ln);
					}
				}
				else if (rg[i][q] == '-' && rg[i][q + 1] >= 48 && rg[i][q + 1] <= 57) { //neg imm
					rt[i] = 2 | (p << 2);
					if (rg[i][q + 1] == '0' && rg[i][q + 2] == 'x') {
						rv[i] = -1 * au_str_int_hex(rg[i] + 3 + q, e, path, ln);
					}
					else {
						rv[i] = -1 * au_str_int_dec(rg[i] + 1 + q, e, path, ln);
					}
				}
				else if (rg[i][q] == '*' && rg[i][q + 1] >= 97 && rg[i][q + 1] <= 122) { //relocation
					rt[i] = 3 | (p << 2);
					rv[i] = (uint64_t) &(rel[*reln].typ);
					rel[*reln].addr = *bn;
					rel[*reln].typ = 0;
					if (rg[i][strlen(rg[i]) - 1] == ')' && p) {
						rg[i][strlen(rg[i]) - 1] = 0;
						p = 0;
					}
					else if (rg[i][strlen(rg[i]) - 1] == ')' && !p) { //error
						printf("[%s, %lu] error: expected '('\n", path, ln);
						*e = -1;
					}
					memcpy(&(rel[*reln].strl), rg[i] + 1 + q, 16);
					(*reln)++;
				}
				else {
					printf("[%s, %lu] error: unknown operand '%s'\n", path, ln, rg[i]);
					*e = -1;
				}

				if (rg[i][strlen(rg[i]) - 1] == ')' && p) {
					p = 0;
				}
				else if (rg[i][strlen(rg[i]) - 1] == ')' && !p) { //error
					printf("[%s, %lu] error: expected '('\n", path, ln);
					*e = -1;
				}
			}
			
			if (p) {
				printf("[%s, %lu] error: expected ')'\n", path, ln);
				*e = -1;
			}
			
			if (op[0] >= 97 && op[0] <= 122) { //arch-spec op
				au_enc(bin, bn, op, rt, rv, e, path, ln);
			}
			else if (op[0] == '*' && op[1] >= 97 && op[1] <= 122) { //symbol
				for (uint64_t i = 0; i < *symn; i++) {
					if (!memcmp(&(sym[i].strl), op + 1, 16)) {
						printf("[%s, %lu] error: redefinition of symbol '%s'\n", path, ln, op + 1);
						*e = -1;
					}
				}
				sym[*symn].addr = *bn;
				memcpy(&(sym[*symn].strl), op + 1, 16);
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
	
	munmap(fx, fs.st_size);
}

void au_writ_bin(uint8_t* bin, uint64_t bn, au_sym_t* sym, uint64_t symn, au_sym_t* rel, uint64_t reln, int8_t* path) {
	int32_t fd = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
    if (fd == -1) {
        printf("error: failed to create file '%s'\n", path);
        return;
    }
    ftruncate(fd, bn);
    uint8_t* mem = mmap(0, bn, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	memcpy(mem, bin, bn);
	munmap(mem, bn);
	close(fd);
}

void au_writ_zn(uint8_t* bin, uint64_t bn, au_sym_t* sym, uint64_t symn, au_sym_t* rel, uint64_t reln, int8_t* path) {
	uint64_t memsz = 52 + bn + (symn * 25) + (reln * 25);
	
	int32_t fd = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
    if (fd == -1) {
        printf("error: failed to create file '%s'\n", path);
        return;
    }
    ftruncate(fd, memsz);
    uint8_t* mem = mmap(0, memsz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	uint64_t binoff = 52;
	uint64_t symoff = 52 + bn;
	uint64_t reloff = 52 + bn + (symn * 25);
	
	memcpy(mem, "zinc", 4);
	memcpy(mem + 4, &binoff, 8);
	memcpy(mem + 12, &bn, 8);
	memcpy(mem + 20, &symoff, 8);
	memcpy(mem + 28, &symn, 8);
	memcpy(mem + 36, &reloff, 8);
	memcpy(mem + 44, &reln, 8);
	
	memcpy(mem + binoff, bin, bn);
	for (uint64_t i = 0; i < symn; i++) {
		memcpy(mem + symoff + (25 * i), &(sym[i].strl), 8);
		memcpy(mem + symoff + (25 * i) + 8, &(sym[i].strh), 8);
		memcpy(mem + symoff + (25 * i) + 16, &(sym[i].addr), 8);
		memcpy(mem + symoff + (25 * i) + 24, &(sym[i].typ), 1);
	}
	
	for (uint64_t i = 0; i < reln; i++) {
		memcpy(mem + reloff + (25 * i), &(rel[i].strl), 8);
		memcpy(mem + reloff + (25 * i) + 8, &(rel[i].strh), 8);
		memcpy(mem + reloff + (25 * i) + 16, &(rel[i].addr), 8);
		memcpy(mem + reloff + (25 * i) + 24, &(rel[i].typ), 1);
	}
	
	munmap(mem, memsz);
	close(fd);
}

int8_t main(int32_t argc, int8_t** argv) {
	if (argc != 4) {
		printf("usage: au [architecture] [source.s] [binary.bin or link.zn]\n");
		return -1;
	}
	
	if (!strcmp(argv[1], "arm32-m")) {
		au_reg = arm_32m_reg;
		au_enc = arm_32m_enc;
	}
	else if (!strcmp(argv[1], "arm32-a")) {
		au_reg = arm_32a_reg;
		au_enc = arm_32a_enc;
	}
	else if (!strcmp(argv[1], "arm64")) {
		au_reg = arm_64_reg;
		au_enc = arm_64_enc;
	}
	else if (!strcmp(argv[1], "x86")) {
		au_reg = x86_reg;
		au_enc = x86_enc;
	}
	else if (!strcmp(argv[1], "i386")) {
		au_reg = i386_reg;
		au_enc = i386_enc;
	}
	else if (!strcmp(argv[1], "x86-64")) {
		au_reg = x86_64_reg;
		au_enc = x86_64_enc;
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
