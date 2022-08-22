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

typedef uint64_t (*au_op) (uint8_t*, uint64_t, uint64_t, uint64_t);

typedef uint8_t (*au_reg) (uint8_t*);

typedef struct au_sym_s {
	int8_t* str;
	uint8_t typ;
	uint64_t addr;
} au_sym_t;

uint64_t au_str_int(int8_t* a) {
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
			//error
		}
	}
}

int8_t au_lex(int8_t* path, uint8_t* bin, uint64_t* bn) {
	FILE* f = fopen(path, "r");
	if (!f) {
		printf("error: file %s doesn't exists\n", path);
		return -1;
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
	op[0] = 0;
	int8_t rg[3][256];
	rg[0][0] = 0;
	rg[1][0] = 0;
	rg[2][0] = 0;
	uint8_t ri = 0;
	uint8_t rn = 0;
	
	au_sym_t sym[65536];
	uint16_t symn = 0;
	au_sym_t rel[65536];
	uint16_t reln = 0;
	
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
				printf("[line %lu] error: too many operands\n", ln);
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
				printf("[line %lu] error: expected ','\n", ln);
			}
			lex[0] = 0;
			li = 0;
		}
		else if (fx[fi] == ';') { //comment
			c = 1;
		}
		else if (fx[fi] != ' ' && fx[fi] != '\t' && !c) {
			printf("[line %lu] error: junk character '%c'\n", ln, fx[fi]);
		}
		
		if (fx[fi] == '\n' && op[0]) { //encode line
			if (ri != rn && rn > 1) {
				printf("[line %lu] error: expected operand\n" , ln);
			}
			
			uint8_t rt[3] = {0, 0, 0};
			uint64_t rv[3] = {0, 0, 0};
			uint8_t* relp = 0;
			
			for (uint8_t i = 0; i < ri; i++) {
				if (rg[i][0] >= 97 && rg[i][0] <= 122) { //arch-spec reg
					rt[i] = 1;
				}
				else if (rg[i][0] >= 48 && rg[i][0] <= 57) { //imm
					rt[i] = 2;
					rv[i] = au_str_int(rg[i]);
				}
				else if (rg[i][0] == '-' && rg[i][1] >= 48 && rg[i][1] <= 57) { //neg imm
					rt[i] = 2;
					rv[i] = -1 * au_str_int(rg[i] + 1);
				}
				else if (rg[i][0] == '*' && rg[i][1] >= 97 && rg[i][1] <= 122) { //symbol
					rt[i] = 2;
					rv[i] = 0;
					rel[reln].str = malloc(strlen(rg[i] + 1));
					rel[reln].addr = *bn;
					relp = &(rel[reln].typ);
					strcpy(rel[reln].str, rg[i]);
					reln++;
				}
				else {
					printf("[line %lu] error: invalid operand '%s'\n", ln, rg[i]);
				}
			}
			
			if (op[0] >= 97 && op[0] <= 122) { //arch-spec op
				
			}
			else if (op[0] == '*' && op[1] >= 97 && op[1] <= 122) { //symbol
				sym[symn].str = malloc(strlen(op + 1));
				sym[symn].addr = *bn;
				strcpy(sym[symn].str, op);
				symn++;
			}
			else if (op[0] == '~' && op[1] >= 97 && op[1] <= 122) { //pseudo-op
				
			}
			else {
				printf("[line %lu] error: invalid opcode '%s'\n", ln, op);
			}
		}
		
		if (fx[fi] == '\n') {
			op[0] = 0;
			rg[0][0] = 0;
			rg[1][0] = 0;
			rg[2][0] = 0;
			ri = 0;
			rn = 0;
			lex[0] = 0;
			li = 0;
			c = 0;
			ln++;
		}
	}
	
	for (uint16_t i = 0; i < symn; i++) {
		printf("[sym]\tname: %s\n\taddr:%lu\n", sym[i].str, sym[i].addr);
		free(sym[i].str);
	}
	
	for (uint16_t i = 0; i < reln; i++) {
		printf("[rel]\tname: %s\n\taddr:%lu\n", rel[i].str, rel[i].addr);
		free(rel[i].str);
	}
	
	free(fx);
	return 0;
}

int8_t main(int32_t argc, int8_t** argv) {
	if (argc != 3) {
		printf("usage: au [source.au] [binary.bin]\n");
		return -1;
	}
	
	if (strcmp(argv[1] + strlen(argv[1]) - 3, ".au")) {
		printf("error: expected .au file\n");
		return -1;
	}
	if (strcmp(argv[2] + strlen(argv[2]) - 4, ".bin")) {
		printf("error: expected .bin file\n");
		return -1;
	}
	
	uint8_t* bin;
	uint64_t bn = 0;
	if(au_lex(argv[1], bin, &bn)) {
		printf("failed to assemble binary\n");
		return -1;
	}
	
	FILE* f = fopen(argv[2], "w");
	fwrite(bin, bn, 1, f);
	fclose(f);
	
	return 0;
}
