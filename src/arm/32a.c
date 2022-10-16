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

uint8_t arm_32a_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r[0] == 'r' && r[1] == '0' && (r[2] == 0 || r[2] == ')')) { //general purpose
		return 0;
	}
	else if (r[0] == 'r' && r[1] == '1' && (r[2] == 0 || r[2] == ')')) {
		return 1;
	}
	else if (r[0] == 'r' && r[1] == '2' && (r[2] == 0 || r[2] == ')')) {
		return 2;
	}
	else if (r[0] == 'r' && r[1] == '3' && (r[2] == 0 || r[2] == ')')) {
		return 3;
	}
	else if (r[0] == 'r' && r[1] == '4' && (r[2] == 0 || r[2] == ')')) {
		return 4;
	}
	else if (r[0] == 'r' && r[1] == '5' && (r[2] == 0 || r[2] == ')')) {
		return 5;
	}
	else if (r[0] == 'r' && r[1] == '6' && (r[2] == 0 || r[2] == ')')) {
		return 6;
	}
	else if (r[0] == 'r' && r[1] == '7' && (r[2] == 0 || r[2] == ')')) {
		return 7;
	}
	else if (r[0] == 'r' && r[1] == '8' && (r[2] == 0 || r[2] == ')')) {
		return 8;
	}
	else if (r[0] == 'r' && r[1] == '9' && (r[2] == 0 || r[2] == ')')) {
		return 9;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 10;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 11;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 12;
	}
	else if ((r[0] == 'r' && r[1] == '1' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) || (r[0] == 's' && r[1] == 'p' && (r[2] == 0 || r[2] == ')'))) {
		return 13;
	}
	else if ((r[0] == 'r' && r[1] == '1' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) || (r[0] == 'l' && r[1] == 'r' && (r[2] == 0 || r[2] == ')'))) {
		return 14;
	}
	else if ((r[0] == 'r' && r[1] == '1' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) || (r[0] == 'p' && r[1] == 'c' && (r[2] == 0 || r[2] == ')'))) {
		return 15;
	}
	else if (r[0] == 'l' && r[1] == 's' && r[2] == 'l' && r[3] == 0) { //shifts
		return 16;
	}
	else if (r[0] == 'l' && r[1] == 's' && r[2] == 'r' && r[3] == 0) {
		return 17;
	}
	else if (r[0] == 'a' && r[1] == 's' && r[2] == 'r' && r[3] == 0) {
		return 18;
	}
	else if (r[0] == 'r' && r[1] == 'o' && r[2] == 'r' && r[3] == 0) {
		return 19;
	}
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
	}
}

uint8_t arm_32a_cond(int8_t* c, int8_t* e, int8_t* path, uint64_t ln) {
	if (c[0] == 0) {
		return 14;
	}
	else if (c[0] == 'e' && c[1] == 'q' && c[2] == 0) {
		return 0;
	}
	else if (c[0] == 'n' && c[1] == 'e' && c[2] == 0) {
		return 1;
	}
	else if (c[0] == 'c' && c[1] == 's' && c[2] == 0) {
		return 2;
	}
	else if (c[0] == 'h' && c[1] == 's' && c[2] == 0) {
		return 2;
	}
	else if (c[0] == 'c' && c[1] == 'c' && c[2] == 0) {
		return 3;
	}
	else if (c[0] == 'l' && c[1] == 'o' && c[2] == 0) {
		return 3;
	}
	else if (c[0] == 'm' && c[1] == 'i' && c[2] == 0) {
		return 4;
	}
	else if (c[0] == 'p' && c[1] == 'l' && c[2] == 0) {
		return 5;
	}
	else if (c[0] == 'v' && c[1] == 's' && c[2] == 0) {
		return 6;
	}
	else if (c[0] == 'v' && c[1] == 'c' && c[2] == 0) {
		return 7;
	}
	else if (c[0] == 'h' && c[1] == 'i' && c[2] == 0) {
		return 8;
	}
	else if (c[0] == 'l' && c[1] == 's' && c[2] == 0) {
		return 9;
	}
	else if (c[0] == 'g' && c[1] == 'e' && c[2] == 0) {
		return 10;
	}
	else if (c[0] == 'l' && c[1] == 't' && c[2] == 0) {
		return 11;
	}
	else if (c[0] == 'g' && c[1] == 't' && c[2] == 0) {
		return 12;
	}
	else if (c[0] == 'l' && c[1] == 'e' && c[2] == 0) {
		return 13;
	}
	else {
		printf("[%s, %lu] error: illegal condition '%s'\n", path, ln, c);
		*e = -1;
	}
}

uint8_t arm_32a_str(int8_t* s) {
	if (*s == 's') {
		return 1;
	}
	return 0;
}

uint8_t arm_32a_uk(int64_t k) {
	if (k >= 0) {
		return 1;
	}
	return 0;
}

uint8_t arm_32a_sk(int64_t k) {
	if (k < 0) {
		return 1;
	}
	return 0;
}

uint64_t arm_32a_abs(int64_t k) {
	if (k >= 0) {
		return k;
	}
	else {
		return k * -1;
	}
}

void arm_32a_err_r4(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void arm_32a_err_p4(uint8_t p, int8_t* e, int8_t* path, uint64_t ln) {
	if (p < 16 || p > 31) {
		printf("[%s, %lu] error: illegal processor 'p%u'\n", path, ln, p - 16);
		*e = -1;
	}
}

void arm_32a_err_k5(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -16 || k > 31) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32a_err_k8(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128 || k > 255) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32a_err_k12(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -2048 || k > 4095) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32a_err_k16(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32768 || k > 65535) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32a_err_k24(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -8388608 || k > 16777215) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32a_err_sh(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 19) {
		printf("[%s, %lu] error: illegal shift\n", path, ln);
		*e = -1;
	}
}

uint8_t arm_32a_err_rl(uint64_t* v, uint8_t* t, int8_t* e, int8_t* path, uint64_t ln) {
	uint8_t n;
	
	for (uint8_t i = 0; i < 16; i++) {
		if (t[i] == 0) {
			n = i;
			break;
		}
		else if (t[i] != 1) {
			printf("[%s, %lu] error: expected register\n", path, ln);
			*e = -1;
		}
	}
	
	for (uint8_t i = 0; i < n; i++) {
		arm_32a_err_r4(v[i], e, path, ln);
		for (uint8_t j = 0; j < n; j++) {
			if (v[i] == v[j] && i != j) {
				printf("[%s, %lu] error: duplicate register 'r%u'\n", path, ln, (uint32_t) v[i]);
				*e = -1;
			}
		}
	}
	return n;
}

void arm_32a_inst_c4_r4_r4_r4_sh_k5(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t sh, uint8_t k) {
	bin[*bn] |= r1;
	bin[*bn] |= (sh - 16) << 5;
	bin[*bn] |= k << 7;
	bin[*bn + 1] |= k >> 1;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= r0;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_32a_inst_c4_r4_r4_r4_sh_r4(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t sh, uint8_t r2) {
	bin[*bn] |= r1;
	bin[*bn] |= (sh - 16) << 5;
	bin[*bn + 1] |= r2;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= r0;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_32a_inst_c4_r4_r4_r4_r4(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t r2) {
	bin[*bn] |= r0;
	bin[*bn + 1] |= r1;
	bin[*bn + 1] |= r2 << 4;
	bin[*bn + 2] |= rd;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_32a_inst_c4_r4_r4_k12(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t rd, uint8_t rs, uint16_t k) {
	bin[*bn] |= k;
	bin[*bn + 1] |= (k >> 8) & 15;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= rs;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_32a_inst_c4_r4_r4_k8(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] |= k & 15;
	bin[*bn + 1] |= k >> 4;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= rs;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_32a_inst_c4_p4_r4_r4_k8(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t p, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] |= k;
	bin[*bn + 1] |= p - 16;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= rs;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_32a_inst_k16(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] |= k & 15;
	bin[*bn + 1] |= k >> 4;
	bin[*bn + 2] |= k >> 12;
	*bn += 4;
}

void arm_32a_inst_c4_r4_rl(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t rd, uint64_t* rl, uint8_t rn) {
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] < 8) {
			bin[*bn] |= 1 << rl[i];
		}
		else {
			bin[*bn + 1] |= 1 << (rl[i] - 8);
		}
	}
	bin[*bn + 2] |= rd;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_32a_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 5 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0 | (s << 4);
			bin[*bn + 3] = 2;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 5 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32 | (s << 4);
			bin[*bn + 3] = 2;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eor");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 5 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 4);
			bin[*bn + 3] = 2;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 5 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96 | (s << 4);
			bin[*bn + 3] = 2;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 5 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128 | (s << 4);
			bin[*bn + 3] = 2;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 2;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192 | (s << 4);
			bin[*bn + 3] = 2;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbc");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'c') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 2;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsc");
			*e = -1;
		}
	}
	else if (op[0] == 't' && op[1] == 's' && op[2] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, 0, rv[0], rv[1], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_sh(rv[2], e, path, ln);
			arm_32a_err_k5(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 5 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_k12(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 3;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "tst");
			*e = -1;
		}
	}
	else if (op[0] == 't' && op[1] == 'e' && op[2] == 'q') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, 0, rv[0], rv[1], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_sh(rv[2], e, path, ln);
			arm_32a_err_k5(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 5 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_k12(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 3;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "teq");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, 0, rv[0], rv[1], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_sh(rv[2], e, path, ln);
			arm_32a_err_k5(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 5 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_k12(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 3;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'n') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, 0, rv[0], rv[1], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_sh(rv[2], e, path, ln);
			arm_32a_err_k5(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 5 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_k12(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 3;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmn");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 5 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128 | (s << 4);
			bin[*bn + 3] = 3;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orr");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], 0, rv[1], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_k12(rv[1], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 3;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 0, rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], 0, rv[1], 0, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k5(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], 0, rv[1], 0, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsl");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], 0, rv[1], 1, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k5(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], 0, rv[1], 1, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsr");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], 0, rv[1], 2, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k5(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], 0, rv[1], 2, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asr");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], 0, rv[1], 3, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k5(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], 0, rv[1], 3, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ror");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], 0, rv[1], 3, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rrx");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'i' && op[2] == 'c') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192 | (s << 4);
			bin[*bn + 3] = 3;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bic");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'v' && op[2] == 'n') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_r4(rv[4], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224 | (s << 4);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224 | (s << 4);
			bin[*bn + 3] = 3;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mvn");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mul");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'l' && op[2] == 'a') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t s = arm_32a_str(op + 3);
			uint8_t c = arm_32a_cond(op + 3 + s, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mla");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'm' && op[2] == 'a' && op[3] == 'a' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "umaal");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'l' && op[2] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mls");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t s = arm_32a_str(op + 5);
			uint8_t c = arm_32a_cond(op + 5 + s, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "umull");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t s = arm_32a_str(op + 5);
			uint8_t c = arm_32a_cond(op + 5 + s, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "umlal");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t s = arm_32a_str(op + 5);
			uint8_t c = arm_32a_cond(op + 5 + s, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smull");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t s = arm_32a_str(op + 5);
			uint8_t c = arm_32a_cond(op + 5 + s, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224 | (s << 4);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlal");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 'a' && op[2] == 'd' && op[3] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qadd");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 's' && op[2] == 'u' && op[3] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qsub");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 'd' && op[2] == 'a' && op[3] == 'd' && op[4] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qdadd");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 'd' && op[2] == 's' && op[3] == 'u' && op[4] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qdsub");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'b' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlabb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 't' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 160;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlatb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'b' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlabt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 't' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 224;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlatt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'w' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlawb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'w' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlawt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'w' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 160;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smulwb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'w' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 224;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smulwt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 'b' && op[6] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlalbb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 't' && op[6] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 160;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlaltb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 'b' && op[6] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlalbt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 't' && op[6] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 224;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlaltt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'b' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smulbb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 't' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 160;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smultb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'b' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smulbt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 't' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 224;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smultt");
			*e = -1;
		}
	}
	//sync prim
	else if (op[0] == 's' && op[1] == 'w' && op[2] == 'p' && op[3] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "swpb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'w' && op[2] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "swp");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strexd");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strexb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'h') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strexh");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strex");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'd') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], 0, 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrexd");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], 0, 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrexb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'h') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], 0, 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrexh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], 0, 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrex");
			*e = -1;
		}
	}
	//hints
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 'p') {
		if (rt[0] == 0) {
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 240;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = (c << 4) + 3;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "nop");
			*e = -1;
		}
	}
	else if (op[0] == 'y' && op[1] == 'i' && op[2] == 'e' && op[3] == 'l' && op[4] == 'd') {
		if (rt[0] == 0) {
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 1;
			bin[*bn + 1] = 240;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = (c << 4) + 3;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "yield");
			*e = -1;
		}
	}
	else if (op[0] == 'w' && op[1] == 'f' && op[2] == 'e') {
		if (rt[0] == 0) {
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 2;
			bin[*bn + 1] = 240;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = (c << 4) + 3;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "wfe");
			*e = -1;
		}
	}
	else if (op[0] == 'w' && op[1] == 'f' && op[2] == 'i') {
		if (rt[0] == 0) {
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 3;
			bin[*bn + 1] = 240;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = (c << 4) + 3;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "wfi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'v') {
		if (rt[0] == 0) {
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 4;
			bin[*bn + 1] = 240;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = (c << 4) + 3;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sev");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 's' && op[2] == 'd' && op[3] == 'b') {
		if (rt[0] == 0) {
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 20;
			bin[*bn + 1] = 240;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = (c << 4) + 3;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "csdb");
			*e = -1;
		}
	}
	//misc
	else if (op[0] == 'b' && op[1] == 'x' && op[2] == 'j') {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = rv[0] + 32;
			bin[*bn + 1] = 255;
			bin[*bn + 2] = 47;
			bin[*bn + 3] = (c << 4) + 1;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bxj");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'x') {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 2, e, path, ln);
			
			bin[*bn] = rv[0] + 16;
			bin[*bn + 1] = 255;
			bin[*bn + 2] = 47;
			bin[*bn + 3] = (c << 4) + 1;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bx");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'z') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = rv[1] + 16;
			bin[*bn + 1] = (rv[0] << 4) + 15;
			bin[*bn + 2] = 111;
			bin[*bn + 3] = (c << 4) + 1;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "clz");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'r' && op[2] == 'e' && op[3] == 't') {
		if (rt[0] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 110;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = (c << 4) + 1;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eret");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'k' && op[2] == 'p' && op[3] == 't' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_32a_err_k16(rv[0], e, path, ln);
			
			bin[*bn] = 112;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 225;
			arm_32a_inst_k16(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bkpt");
			*e = -1;
		}
	}
	else if (op[0] == 'h' && op[1] == 'v' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_32a_err_k16(rv[0], e, path, ln);
			
			bin[*bn] = 112;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 225;
			arm_32a_inst_k16(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "hvc");
			*e = -1;
		}
	}
	//str
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 7);
			bin[*bn + 3] = 4;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strbt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 7);
			bin[*bn + 3] = 4;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 7);
			bin[*bn + 3] = 5;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 6;
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 5;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 7;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 7;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strht");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 7);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 7;
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strh");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'd') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 7);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 7;
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strd");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 't') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0 | (s << 7);
			bin[*bn + 3] = 4;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0 | (s << 7);
			bin[*bn + 3] = 4;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0 | (s << 7);
			bin[*bn + 3] = 5;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 6;
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 5;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 7;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 7;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "str");
			*e = -1;
		}
	}
	//ldr
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsbt");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80 | (s << 7);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 7;
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsht");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80 | (s << 7);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 7;
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80 | (s << 7);
			bin[*bn + 3] = 4;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrbt");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80 | (s << 7);
			bin[*bn + 3] = 4;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80 | (s << 7);
			bin[*bn + 3] = 5;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 6;
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 5;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 7;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 7;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrht");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80 | (s << 7);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 7;
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'd') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 7);
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k8(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64 | (s << 7);
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 7;
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrd");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 't') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16 | (s << 7);
			bin[*bn + 3] = 4;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrt");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16 | (s << 7);
			bin[*bn + 3] = 4;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_k12(rv[2], e, path, ln);
			uint8_t s = arm_32a_uk(rv[2]);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16 | (s << 7);
			bin[*bn + 3] = 5;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], arm_32a_abs(rv[2]));
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32a_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 6;
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 5;
			arm_32a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 7;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			arm_32a_err_sh(rv[3], e, path, ln);
			arm_32a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 7;
			arm_32a_inst_c4_r4_r4_r4_sh_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldr");
			*e = -1;
		}
	}
	//media
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'd' && op[3] == 'd' && op[4] == '1' && op[5] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sadd16");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 's' && op[3] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 48;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sasx");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 's' && op[2] == 'a' && op[3] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ssax");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 's' && op[2] == 'u' && op[3] == 'b' && op[4] == '1' && op[5] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 112;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ssub16");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'd' && op[3] == 'd' && op[4] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sadd8");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 's' && op[2] == 'u' && op[3] == 'b' && op[4] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ssub8");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 'a' && op[2] == 'd' && op[3] == 'd' && op[4] == '1' && op[5] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qadd16");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 'a' && op[2] == 's' && op[3] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 48;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qasx");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 's' && op[2] == 'a' && op[3] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qsax");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 's' && op[2] == 'u' && op[3] == 'b' && op[4] == '1' && op[5] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 112;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qsub16");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 'a' && op[2] == 'd' && op[3] == 'd' && op[4] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qadd8");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 's' && op[2] == 'u' && op[3] == 'b' && op[4] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qsub8");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'a' && op[3] == 'd' && op[4] == 'd' && op[5] == '1' && op[6] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shadd16");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'a' && op[3] == 's' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 48;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shasx");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 's' && op[3] == 'a' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shsax");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 's' && op[3] == 'u' && op[4] == 'b' && op[5] == '1' && op[6] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 112;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shsub16");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'a' && op[3] == 'd' && op[4] == 'd' && op[5] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shadd8");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 's' && op[3] == 'u' && op[4] == 'b' && op[5] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shsub8");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'a' && op[2] == 'd' && op[3] == 'd' && op[4] == '1' && op[5] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uadd16");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'a' && op[2] == 's' && op[3] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 48;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uasx");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 's' && op[2] == 'a' && op[3] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "usax");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 's' && op[2] == 'u' && op[3] == 'b' && op[4] == '1' && op[5] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 112;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "usub16");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'a' && op[2] == 'd' && op[3] == 'd' && op[4] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uadd8");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 's' && op[2] == 'u' && op[3] == 'b' && op[4] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "usub8");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'q' && op[2] == 'a' && op[3] == 'd' && op[4] == 'd' && op[5] == '1' && op[6] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uqadd16");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'q' && op[2] == 'a' && op[3] == 's' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 48;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uqasx");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'q' && op[2] == 's' && op[3] == 'a' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uqsax");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'q' && op[2] == 's' && op[3] == 'u' && op[4] == 'b' && op[5] == '1' && op[6] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 112;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uqsub16");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'q' && op[2] == 'a' && op[3] == 'd' && op[4] == 'd' && op[5] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uqadd8");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'q' && op[2] == 's' && op[3] == 'u' && op[4] == 'b' && op[5] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uqsub8");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'h' && op[2] == 'a' && op[3] == 'd' && op[4] == 'd' && op[5] == '1' && op[6] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uhadd16");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'h' && op[2] == 'a' && op[3] == 's' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 48;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uhasx");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'h' && op[2] == 's' && op[3] == 'a' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uhsax");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'h' && op[2] == 's' && op[3] == 'u' && op[4] == 'b' && op[5] == '1' && op[6] == '6') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 112;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uhsub16");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'h' && op[2] == 'a' && op[3] == 'd' && op[4] == 'd' && op[5] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uhadd8");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'h' && op[2] == 's' && op[3] == 'u' && op[4] == 'b' && op[5] == '8') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			arm_32a_err_r4(rv[1], e, path, ln);
			arm_32a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 6;
			arm_32a_inst_c4_r4_r4_r4_r4(bin, bn, c, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uhsub8");
			*e = -1;
		}
	}
	//branch & block
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'd' && op[4] == 'a' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmdaw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'e' && op[4] == 'd' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmedw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'd' && op[4] == 'a') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmda");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'e' && op[4] == 'd') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmed");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'd' && op[4] == 'a' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmdaw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'f' && op[4] == 'a' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmfaw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'd' && op[4] == 'a') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmda");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'f' && op[4] == 'a') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmfa");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmiaw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'e' && op[4] == 'a' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmeaw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmia");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'e' && op[4] == 'a') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmea");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stm");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmiaw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'f' && op[4] == 'd' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmfdw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmia");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'f' && op[4] == 'd') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmfd");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldm");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p') {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 4;
			bin[*bn + 1] = rv[0] << 4;
			bin[*bn + 2] = 157;
			bin[*bn + 3] = (c << 4) + 4;
			*bn += 4;
		}
		else if (rt[16] == 0) {
			uint8_t n = arm_32a_err_rl(rv, rt, e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 8;
			arm_32a_inst_c4_r4_rl(bin, bn, c, 13, rv, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'd' && op[4] == 'b' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmdbw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'f' && op[4] == 'd' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmfdw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'd' && op[4] == 'b') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmdb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'f' && op[4] == 'd') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmfd");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h') {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 4;
			bin[*bn + 1] = rv[0] << 4;
			bin[*bn + 2] = 45;
			bin[*bn + 3] = (c << 4) + 5;
			*bn += 4;
		}
		else if (rt[16] == 0) {
			uint8_t n = arm_32a_err_rl(rv, rt, e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 45;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, 13, rv, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "push");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'd' && op[4] == 'b' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmdbw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'e' && op[4] == 'a' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmeaw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'd' && op[4] == 'b') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmdb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'e' && op[4] == 'a') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmea");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'i' && op[4] == 'b' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmibw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'f' && op[4] == 'a' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmfaw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'i' && op[4] == 'b') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmib");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'f' && op[4] == 'a') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmfa");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'i' && op[4] == 'b' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmibw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'e' && op[4] == 'd' && op[5] == 'w') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmedw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'i' && op[4] == 'b') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmib");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'e' && op[4] == 'd') {
		if (rt[0] == 1 && rt[17] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t n = arm_32a_err_rl(rv + 1, rt + 1, e, path, ln);
			uint8_t c = arm_32a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 9;
			arm_32a_inst_c4_r4_rl(bin, bn, c, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmed");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'x' && op[3] == 0) { //todo
		if (rt[0] == 1 && rt[1] == 0) {
			arm_32a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = rv[0] + 48;
			bin[*bn + 1] = 255;
			bin[*bn + 2] = 47;
			bin[*bn + 3] = (c << 4) + 1;
			*bn += 4;
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			arm_32a_err_k24(rv[0], e, path, ln);
			
			bin[*bn] = rv[0];
			bin[*bn + 1] = rv[0] >> 8;
			bin[*bn + 2] = rv[0] >> 16;
			bin[*bn + 3] = 250;
			*bn += 4;
		}
		else if (rt[0] == 3 && rt[1] == 0) { //rel
			*((uint8_t*) rv[0]) |= 5;
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 250;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "blx");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l') {
		if (rt[0] == 2 && rt[1] == 0) {
			arm_32a_err_k24(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 2, e, path, ln);
			
			bin[*bn] = rv[0];
			bin[*bn + 1] = rv[0] >> 8;
			bin[*bn + 2] = rv[0] >> 16;
			bin[*bn + 3] = (c << 4) + 11;
			*bn += 4;
		}
		else if (rt[0] == 3 && rt[1] == 0) { //rel
			*((uint8_t*) rv[0]) |= 5;
			uint8_t c = arm_32a_cond(op + 2, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = (c << 4) + 11;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bl");
			*e = -1;
		}
	}
	else if (op[0] == 'b') {
		if (rt[0] == 2 && rt[1] == 0) {
			arm_32a_err_k24(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 1, e, path, ln);
			
			bin[*bn] = rv[0];
			bin[*bn + 1] = rv[0] >> 8;
			bin[*bn + 2] = rv[0] >> 16;
			bin[*bn + 3] = (c << 4) + 10;
			*bn += 4;
		}
		else if (rt[0] == 3 && rt[1] == 0) { //rel
			*((uint8_t*) rv[0]) |= 5;
			uint8_t c = arm_32a_cond(op + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = (c << 4) + 10;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "b");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'v' && op[2] == 'c') {
		if (rt[0] == 2 && rt[1] == 0) {
			arm_32a_err_k24(rv[0], e, path, ln);
			uint8_t c = arm_32a_cond(op + 3, e, path, ln);
			
			bin[*bn] = rv[0];
			bin[*bn + 1] = rv[0] >> 8;
			bin[*bn + 2] = rv[0] >> 16;
			bin[*bn + 3] = (c << 4) + 15;
			*bn += 4;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "svc");
			*e = -1;
		}
	}
}
