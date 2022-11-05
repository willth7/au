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
//   WITHOUT WARRANTIES OR c4ITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

//   gloria in excelsis deo

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

uint8_t arm_32m_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
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
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
	}
}

uint8_t arm_32m_c4(int8_t* c, int8_t* e, int8_t* path, uint64_t ln) {
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
		printf("[%s, %lu] error: illegal c4ition '%s'\n", path, ln, c);
		*e = -1;
	}
}

uint8_t arm_32m_m4(uint8_t m, uint8_t c) {
	if (m == 0) {
		return 8;
	}
	else if (m == 1) {
		return ((c << 3) & 8) + 4;
	}
	else if (m == 2) {
		return ((~c << 3) & 8) + 4;
	}
	else if (m == 3) {
		return ((c << 3) & 8) + ((c << 2) & 4) + 2;
	}
	else if (m == 4) {
		return ((~c << 3) & 8) + ((c << 2) & 4) + 2;
	}
	else if (m == 5) {
		return ((c << 3) & 8) + ((~c << 2) & 4) + 2;
	}
	else if (m == 6) {
		return ((~c << 3) & 8) + ((~c << 2) & 4) + 2;
	}
	else if (m == 7) {
		return ((c << 3) & 8) + ((c << 2) & 4) + ((c << 1) & 2) + 1;
	}
	else if (m == 8) {
		return ((~c << 3) & 8) + ((c << 2) & 4) + ((c << 1) & 2) + 1;
	}
	else if (m == 9) {
		return ((c << 3) & 8) + ((~c << 2) & 4) + ((c << 1) & 2) + 1;
	}
	else if (m == 10) {
		return ((~c << 3) & 8) + ((~c << 2) & 4) + ((c << 1) & 2) + 1;
	}
	else if (m == 11) {
		return ((c << 3) & 8) + ((c << 2) & 4) + ((~c << 1) & 2) + 1;
	}
	else if (m == 12) {
		return ((~c << 3) & 8) + ((c << 2) & 4) + ((~c << 1) & 2) + 1;
	}
	else if (m == 13) {
		return ((c << 3) & 8) + ((~c << 2) & 4) + ((~c << 1) & 2) + 1;
	}
	else if (m == 14) {
		return ((~c << 3) & 8) + ((~c << 2) & 4) + ((~c << 1) & 2) + 1;
	}
}

uint8_t arm_32m_uk(int64_t k) {
	if (k >= 0) {
		return 1;
	}
	return 0;
}

uint8_t arm_32m_sk(int64_t k) {
	if (k < 0) {
		return 1;
	}
	return 0;
}

uint64_t arm_32m_abs(int64_t k) {
	if (k >= 0) {
		return k;
	}
	else {
		return k * -1;
	}
}

void arm_32m_err_r3(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 7) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void arm_32m_err_r4(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void arm_32m_err_k2(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -2 || k > 3) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32m_err_k3(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -4 || k > 7) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32m_err_k5(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -16 || k > 31) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32m_err_k6(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32 || k > 63) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32m_err_k7(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -64 || k > 127) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32m_err_k8(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128 || k > 255) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32m_err_k12(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -2048 || k > 4095) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_32m_err_k24(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -8388608 || k > 16777215) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

uint8_t arm_32m_err_rl3(uint64_t* v, uint8_t* t, int8_t* e, int8_t* path, uint64_t ln) {
	uint8_t n;
	
	for (uint8_t i = 0; i < 8; i++) {
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
		arm_32m_err_r3(v[i], e, path, ln);
		for (uint8_t j = 0; j < n; j++) {
			if (v[i] == v[j] && i != j) {
				printf("[%s, %lu] error: duplicate register 'r%u'\n", path, ln, (uint32_t) v[i]);
				*e = -1;
			}
		}
	}
	return n;
}

uint8_t arm_32m_err_rlx(uint64_t* v, uint8_t* t, uint8_t x, int8_t* e, int8_t* path, uint64_t ln) {
	uint8_t n;
	
	for (uint8_t i = 0; i < 9; i++) {
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
		if (v[i] != x) {
			arm_32m_err_r3(v[i], e, path, ln);
		}
		for (uint8_t j = 0; j < n; j++) {
			if (v[i] == v[j] && i != j) {
				printf("[%s, %lu] error: duplicate register 'r%u'\n", path, ln, (uint32_t) v[i]);
				*e = -1;
			}
		}
	}
	return n;
}

uint8_t arm_32m_err_rl4(uint64_t* v, uint8_t* t, int8_t* e, int8_t* path, uint64_t ln) {
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
		arm_32m_err_r4(v[i], e, path, ln);
		for (uint8_t j = 0; j < n; j++) {
			if (v[i] == v[j] && i != j) {
				printf("[%s, %lu] error: duplicate register 'r%u'\n", path, ln, (uint32_t) v[i]);
				*e = -1;
			}
		}
	}
	return n;
}

void arm_32m_inst_r3_r3_r3(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	*bn += 2;
}

void arm_32m_inst_r3_k6(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] |= rd;
	bin[*bn] |= k << 3;
	bin[*bn + 1] |= (k >> 4) & 2;
	*bn += 2;
}

void arm_32m_inst_r3_k8(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	*bn += 2;
}

void arm_32m_inst_r3_rl(uint8_t* bin, uint64_t* bn, uint8_t rd, uint64_t* rl, uint8_t rn) {
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] < 8) {
			bin[*bn] |= 1 << rl[i];
		}
		else {
			bin[*bn + 1] |= 1;
		}
	}
	bin[*bn + 1] |= rd;
	*bn += 2;
}

void arm_32m_inst_r4_r4(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= (rd << 4) & 128;
	*bn += 2;
}

void arm_32m_inst_bl(uint8_t* bin, uint64_t* bn, int32_t k) { //todo
	bin[*bn] = 0;
	bin[*bn + 1] = 240;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 248;
	
	k |= (k >> 8) & 8388608;
	
	bin[*bn + 2] |= k;
	bin[*bn + 3] |= (k >> 8) & 7;
	bin[*bn] |= k >> 11;
	bin[*bn + 1] |= k >> 19;
	
	*bn += 4;
}

void arm_32m_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 64;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ands");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 64;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 64;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eors");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 64;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eor");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 26;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 30;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 56;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subs");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 13) && (rt[1] == 1 && rv[1] == 13) && rt[2] == 2 && rt[3] == 0) { //sp
			arm_32m_err_k7(rv[2], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 176;
			arm_32m_inst_r3_k8(bin, bn, 0, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 26;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 30;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 56;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'b' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 66;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsbs");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 66;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 24;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 28;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 48;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32m_err_r4(rv[0], e, path, ln);
			arm_32m_err_r4(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 68;
			arm_32m_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adds");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 13) && (rt[1] == 1 && rv[1] == 13) && rt[2] == 2 && rt[3] == 0) { //sp
			arm_32m_err_k7(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 176;
			arm_32m_inst_r3_k8(bin, bn, 0, rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 13) && rt[2] == 2 && rt[3] == 0) { //sp
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 168;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 24;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 28;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 48;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32m_err_r4(rv[0], e, path, ln);
			arm_32m_err_r4(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 68;
			arm_32m_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 65;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adcs");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 65;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 65;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbcs");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 65;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbc");
			*e = -1;
		}
	}
	else if (op[0] == 't' && op[1] == 's' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 66;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "tst");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] > 7 || rv[1] > 7)) { //16
			arm_32m_err_r4(rv[0], e, path, ln);
			arm_32m_err_r4(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 69;
			arm_32m_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 66;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 40;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'n' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 66;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmn");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 67;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orrs");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 67;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orr");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 32;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "movs");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] > 7 || rv[1] > 7)) { //16
			arm_32m_err_r4(rv[0], e, path, ln);
			arm_32m_err_r4(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 70;
			arm_32m_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 32;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 64;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsls");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 64;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsl");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 64;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 8;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsrs");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 64;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 8;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsr");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 65;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 16;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asrs");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 65;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 16;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asr");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 65;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rors");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 65;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ror");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'i' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 67;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bics");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'i' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 67;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bic");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'v' && op[2] == 'n' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 67;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mvns");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'v' && op[2] == 'n' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 67;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mvn");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 67;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "muls");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 67;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mul");
			*e = -1;
		}
	}
	//str
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 84;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 112;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 82;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 128;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strh");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 80;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 13)) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 144;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 96;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "str");
			*e = -1;
		}
	}
	//ldr
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 86;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 94;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 92;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 120;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 90;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 136;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 88;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 13)) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 152;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_r3(rv[1], e, path, ln);
			arm_32m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 104;
			arm_32m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32m_err_r3(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 2;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 72;
			arm_32m_inst_r3_k8(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldr");
			*e = -1;
		}
	}
	//block
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 192;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stm");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 192;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmia");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'e' && op[4] == 'a' && op[5] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 192;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmea");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 192;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 'w' && op[6] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 192;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmiaw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'e' && op[4] == 'a' && op[5] == 'w' && op[6] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 192;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmeaw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 200;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldm");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 200;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmia");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'f' && op[4] == 'd' && op[5] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 200;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmfd");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 200;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 'w' && op[6] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 200;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmiaw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'f' && op[4] == 'd' && op[5] == 'w' && op[6] == 0) {
		if (rt[0] == 5 && rt[9] == 0) { //16
			arm_32m_err_r3(rv[0], e, path, ln);
			uint8_t n = arm_32m_err_rl3(rv + 1, rt + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 200;
			arm_32m_inst_r3_rl(bin, bn, rv[0], rv + 1, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmfdw");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		if (rt[8] == 0) { //16
			uint8_t n = arm_32m_err_rlx(rv, rt, 14, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 180;
			arm_32m_inst_r3_rl(bin, bn, 0, rv, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "push");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[8] == 0) { //16
			uint8_t n = arm_32m_err_rlx(rv, rt, 15, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 188;
			arm_32m_inst_r3_rl(bin, bn, 0, rv, n);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	
	//branch
	else if (op[0] == 'b' && op[1] == 'k' && op[2] == 'p' && op[3] == 't' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			arm_32m_err_k8(rv[0], e, path, ln);
			
			bin[*bn] = rv[0];
			bin[*bn + 1] = 190;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bkpt");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 'e' && op[3] == 'e' && op[4] == 'e' && op[6] != 0) {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 5, e, path, ln);
			uint8_t m = arm_32m_m4(14, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "iteee");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 't' && op[3] == 'e' && op[4] == 'e' && op[6] != 0) {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 5, e, path, ln);
			uint8_t m = arm_32m_m4(13, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ittee");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 'e' && op[3] == 't' && op[4] == 'e' && op[6] != 0) {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 5, e, path, ln);
			uint8_t m = arm_32m_m4(12, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "itete");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 't' && op[3] == 't' && op[4] == 'e' && op[6] != 0) {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 5, e, path, ln);
			uint8_t m = arm_32m_m4(11, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ittte");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 'e' && op[3] == 'e' && op[4] == 't') {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 5, e, path, ln);
			uint8_t m = arm_32m_m4(10, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "iteet");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 't' && op[3] == 'e' && op[4] == 't') {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 5, e, path, ln);
			uint8_t m = arm_32m_m4(9, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ittet");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 'e' && op[3] == 't' && op[4] == 't') {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 5, e, path, ln);
			uint8_t m = arm_32m_m4(8, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "itett");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 't' && op[3] == 't' && op[4] == 't') {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 5, e, path, ln);
			uint8_t m = arm_32m_m4(7, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "itttt");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 'e' && op[3] == 'e' && op[5] != 0) {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 4, e, path, ln);
			uint8_t m = arm_32m_m4(6, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "itee");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 't' && op[3] == 'e' && op[5] != 0) {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 4, e, path, ln);
			uint8_t m = arm_32m_m4(5, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "itte");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 'e' && op[3] == 't') {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 4, e, path, ln);
			uint8_t m = arm_32m_m4(4, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "itet");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 't' && op[3] == 't') {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 4, e, path, ln);
			uint8_t m = arm_32m_m4(3, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ittt");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 'e' && op[4] != 0) {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 3, e, path, ln);
			uint8_t m = arm_32m_m4(2, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ite");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't' && op[2] == 't') {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 3, e, path, ln);
			uint8_t m = arm_32m_m4(1, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "itt");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 't') {
		if (rt[0] == 0) {
			uint8_t c = arm_32m_c4(op + 4, e, path, ln);
			uint8_t m = arm_32m_m4(0, c);
			
			bin[*bn] = (c << 4) + m;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "it");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 0) {
			bin[*bn] = 32;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "nop");
			*e = -1;
		}
	}
	else if (op[0] == 'y' && op[1] == 'i' && op[2] == 'e' && op[3] == 'l' && op[4] == 'd' && op[5] == 0) {
		if (rt[0] == 0) {
			bin[*bn] = 16;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "yield");
			*e = -1;
		}
	}
	else if (op[0] == 'w' && op[1] == 'f' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 0) {
			bin[*bn] = 32;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "wfe");
			*e = -1;
		}
	}
	else if (op[0] == 'w' && op[1] == 'f' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 0) {
			bin[*bn] = 48;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "wfi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 0) {
			bin[*bn] = 64;
			bin[*bn + 1] = 191;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sev");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'b' && op[2] == 'z' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k6(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 177;
			arm_32m_inst_r3_k6(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k6(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 177;
			arm_32m_inst_r3_k6(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cbz");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'b' && op[2] == 'n' && op[3] == 'z' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k6(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 185;
			arm_32m_inst_r3_k6(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k6(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 185;
			arm_32m_inst_r3_k6(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cbnz");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'x' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_32m_err_r4(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 71;
			arm_32m_inst_r4_r4(bin, bn, 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bx");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'x' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_32m_err_r4(rv[0], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 71;
			arm_32m_inst_r4_r4(bin, bn, 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "blx");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 15) && rt[2] == 2 && rt[3] == 0) {
			arm_32m_err_r3(rv[0], e, path, ln);
			arm_32m_err_k8(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 160;
			arm_32m_inst_r3_k8(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 3 && rt[2] == 0) { //rel
			arm_32m_err_r3(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 2;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 160;
			arm_32m_inst_r3_k8(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adr");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			arm_32m_err_k24(rv[0], e, path, ln);
			arm_32m_inst_bl(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) { //rel
			*((uint8_t*) rv[0]) |= 4;
			arm_32m_inst_bl(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bl");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			arm_32m_err_k12(rv[0], e, path, ln);
	
			bin[*bn] = rv[0];
			bin[*bn + 1] = (rv[0] >> 4) + 224;
			*bn += 2;
		}
		else if (rt[0] == 3 && rt[1] == 0) { //rel
			*((uint8_t*) rv[0]) |= 3;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 224;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "b");
			*e = -1;
		}
	}
	else if (op[0] == 'b') {
		if (rt[0] == 2 && rt[1] == 0) {
			arm_32m_err_k8(rv[0], e, path, ln);
			uint8_t c = arm_32m_c4(op + 1, e, path, ln);
			
			bin[*bn] = rv[0];
			bin[*bn + 1] = c + 208;
			*bn += 2;
		}
		else if (rt[0] == 3 && rt[1] == 0) { //rel
			*((uint8_t*) rv[0]) |= 1;
			uint8_t c = arm_32m_c4(op + 1, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = c + 208;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, op);
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'd' && op[2] == 'f' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			arm_32m_err_k8(rv[0], e, path, ln);
			
			bin[*bn] = rv[0];
			bin[*bn + 1] = 222;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "udf");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'v' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			arm_32m_err_k8(rv[0], e, path, ln);
			
			bin[*bn] = rv[0];
			bin[*bn + 1] = 223;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "svc");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
