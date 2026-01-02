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

//   agnus dei, qui tollis peccata mundi

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

uint8_t arm_64a_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r[0] == 'w' && r[1] == '0' && (r[2] == 0 || r[2] == ')')) { //32 bit general purpose
		return 0;
	}
	else if (r[0] == 'w' && r[1] == '1' && (r[2] == 0 || r[2] == ')')) {
		return 1;
	}
	else if (r[0] == 'w' && r[1] == '2' && (r[2] == 0 || r[2] == ')')) {
		return 2;
	}
	else if (r[0] == 'w' && r[1] == '3' && (r[2] == 0 || r[2] == ')')) {
		return 3;
	}
	else if (r[0] == 'w' && r[1] == '4' && (r[2] == 0 || r[2] == ')')) {
		return 4;
	}
	else if (r[0] == 'w' && r[1] == '5' && (r[2] == 0 || r[2] == ')')) {
		return 5;
	}
	else if (r[0] == 'w' && r[1] == '6' && (r[2] == 0 || r[2] == ')')) {
		return 6;
	}
	else if (r[0] == 'w' && r[1] == '7' && (r[2] == 0 || r[2] == ')')) {
		return 7;
	}
	else if (r[0] == 'w' && r[1] == '8' && (r[2] == 0 || r[2] == ')')) {
		return 8;
	}
	else if (r[0] == 'w' && r[1] == '9' && (r[2] == 0 || r[2] == ')')) {
		return 9;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 10;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 11;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 12;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) {
		return 13;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) {
		return 14;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) {
		return 15;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '6' && (r[3] == 0 || r[3] == ')')) {
		return 16;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '7' && (r[3] == 0 || r[3] == ')')) {
		return 17;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '8' && (r[3] == 0 || r[3] == ')')) {
		return 18;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '9' && (r[3] == 0 || r[3] == ')')) {
		return 19;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 20;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 21;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 22;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) {
		return 23;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) {
		return 24;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) {
		return 25;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '6' && (r[3] == 0 || r[3] == ')')) {
		return 26;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '7' && (r[3] == 0 || r[3] == ')')) {
		return 27;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '8' && (r[3] == 0 || r[3] == ')')) {
		return 28;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '9' && (r[3] == 0 || r[3] == ')')) {
		return 29;
	}
	else if (r[0] == 'w' && r[1] == '3' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 30;
	}
	else if (r[0] == 'w' && r[1] == '3' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 31;
	}
	else if (r[0] == 'l' && r[1] == 's' && r[2] == 'l' && (r[3] == 0 || r[3] == ')')) { //shifts
		return 32;
	}
	else if (r[0] == 'l' && r[1] == 's' && r[2] == 'r' && (r[3] == 0 || r[3] == ')')) {
		return 33;
	}
	else if (r[0] == 'a' && r[1] == 's' && r[2] == 'r' && (r[3] == 0 || r[3] == ')')) {
		return 34;
	}
	else if (r[0] == 'u' && r[1] == 'x' && r[2] == 't' && r[3] == 'b' && (r[4] == 0 || r[4] == ')')) { //extensions
		return 64;
	}
	else if (r[0] == 'u' && r[1] == 'x' && r[2] == 't' && r[3] == 'h' && (r[4] == 0 || r[4] == ')')) {
		return 65;
	}
	else if (r[0] == 'u' && r[1] == 'x' && r[2] == 't' && r[3] == 'w' && (r[4] == 0 || r[4] == ')')) {
		return 66;
	}
	else if (r[0] == 'u' && r[1] == 'x' && r[2] == 't' && r[3] == 'x' && (r[4] == 0 || r[4] == ')')) {
		return 67;
	}
	else if (r[0] == 's' && r[1] == 'x' && r[2] == 't' && r[3] == 'b' && (r[4] == 0 || r[4] == ')')) {
		return 68;
	}
	else if (r[0] == 's' && r[1] == 'x' && r[2] == 't' && r[3] == 'h' && (r[4] == 0 || r[4] == ')')) {
		return 69;
	}
	else if (r[0] == 's' && r[1] == 'x' && r[2] == 't' && r[3] == 'w' && (r[4] == 0 || r[4] == ')')) {
		return 70;
	}
	else if (r[0] == 's' && r[1] == 'x' && r[2] == 't' && r[3] == 'x' && (r[4] == 0 || r[4] == ')')) {
		return 71;
	}
	else if (r[0] == 'x' && r[1] == '0' && (r[2] == 0 || r[2] == ')')) { //64 bit general purpose
		return 128;
	}
	else if (r[0] == 'x' && r[1] == '1' && (r[2] == 0 || r[2] == ')')) {
		return 129;
	}
	else if (r[0] == 'x' && r[1] == '2' && (r[2] == 0 || r[2] == ')')) {
		return 130;
	}
	else if (r[0] == 'x' && r[1] == '3' && (r[2] == 0 || r[2] == ')')) {
		return 131;
	}
	else if (r[0] == 'x' && r[1] == '4' && (r[2] == 0 || r[2] == ')')) {
		return 132;
	}
	else if (r[0] == 'x' && r[1] == '5' && (r[2] == 0 || r[2] == ')')) {
		return 133;
	}
	else if (r[0] == 'x' && r[1] == '6' && (r[2] == 0 || r[2] == ')')) {
		return 134;
	}
	else if (r[0] == 'x' && r[1] == '7' && (r[2] == 0 || r[2] == ')')) {
		return 135;
	}
	else if (r[0] == 'x' && r[1] == '8' && (r[2] == 0 || r[2] == ')')) {
		return 136;
	}
	else if (r[0] == 'x' && r[1] == '9' && (r[2] == 0 || r[2] == ')')) {
		return 137;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 138;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 139;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 140;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) {
		return 141;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) {
		return 142;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) {
		return 143;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '6' && (r[3] == 0 || r[3] == ')')) {
		return 144;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '7' && (r[3] == 0 || r[3] == ')')) {
		return 145;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '8' && (r[3] == 0 || r[3] == ')')) {
		return 146;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '9' && (r[3] == 0 || r[3] == ')')) {
		return 147;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 148;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 149;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 150;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) {
		return 151;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) {
		return 152;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) {
		return 153;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '6' && (r[3] == 0 || r[3] == ')')) {
		return 154;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '7' && (r[3] == 0 || r[3] == ')')) {
		return 155;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '8' && (r[3] == 0 || r[3] == ')')) {
		return 156;
	}
	else if ((r[0] == 'x' && r[1] == '2' && r[2] == '9' && (r[3] == 0 || r[3] == ')')) || (r[0] == 's' && r[1] == 'p' && (r[2] == 0 || r[2] == ')'))) {
		return 157;
	}
	else if ((r[0] == 'x' && r[1] == '3' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) || (r[0] == 'l' && r[1] == 'r' && (r[2] == 0 || r[2] == ')'))) {
		return 158;
	}
	else if ((r[0] == 'x' && r[1] == '3' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) || (r[0] == 'p' && r[1] == 'c' && (r[2] == 0 || r[2] == ')'))) {
		return 159;
	}
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
	}
}

void arm_64a_err_reg(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r & 96) {
		printf("[%s, %lu] error: not a register\n", path, ln);
		*e = -1;
	}
}

void arm_64a_err_r36(uint8_t r0, uint8_t r1, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r0 & 128) ^ (r1 & 128)) {
		printf("[%s, %lu] error: mix-match of register widths\n", path, ln);
		*e = -1;
	}
}

void arm_64a_err_r64(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (!(r & 128)) {
		printf("[%s, %lu] error: expected 64-bit register\n", path, ln);
		*e = -1;
	}
}

void arm_64a_err_k3(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 7) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", k, path, ln);
		*e = -1;
	}
}

void arm_64a_err_k4(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 15) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", k, path, ln);
		*e = -1;
	}
}

void arm_64a_err_k6(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 63) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", k, path, ln);
		*e = -1;
	}
}

void arm_64a_err_k12(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 4095) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", k, path, ln);
		*e = -1;
	}
}

void arm_64a_err_k16(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 65535) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", k, path, ln);
		*e = -1;
	}
}

void arm_64a_err_k21(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 2097151) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", k, path, ln);
		*e = -1;
	}
}

void arm_64a_err_i12(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if ((k != 0) || (k != 12)) {
		printf("[%s, %lu] error: illegal immediate '%lu'\n", k, path, ln);
		*e = -1;
	}
}

void arm_64a_err_i16(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if ((k != 0) || (k != 16)) {
		printf("[%s, %lu] error: illegal immediate '%lu'\n", k, path, ln);
		*e = -1;
	}
}

void arm_64a_err_i64(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if ((k != 0) || (k != 16) || (k != 32) || (k != 64)) {
		printf("[%s, %lu] error: illegal immediate '%lu'\n", k, path, ln);
		*e = -1;
	}
}

void arm_64a_err_sh(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r < 32) || (r > 34)) {
		printf("[%s, %lu] error: illegal shift\n", path, ln);
		*e = -1;
	}
}

void arm_64a_err_ext(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r < 64) || (r > 71)) {
		printf("[%s, %lu] error: illegal shift\n", path, ln);
		*e = -1;
	}
}

void arm_64a_err_lsl(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r != 32) {
		printf("[%s, %lu] error: expected 'lsl'\n", path, ln);
		*e = -1;
	}
}

void arm_64a_inst_r5_r5_k12_sh(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint16_t k, uint8_t sh) {
	bin[*bn] = bin[*bn] | (rd & 31);
	bin[*bn] = bin[*bn] | (rs << 5);
	bin[*bn + 1] = bin[*bn + 1] | ((rs >> 3) & 3);
	bin[*bn + 1] = bin[*bn + 1] | (k << 2);
	bin[*bn + 2] = bin[*bn + 2] | (k >> 6);
	if (sh) {
		bin[*bn + 2] = bin[*bn + 2] | 64;
	}
	bin[*bn + 3] = bin[*bn + 3] | (rd & 128);
}

void arm_64a_inst_r5_r5_r5_k6_sh_ext(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t k, uint8_t sh, uint8_t ext) {
	bin[*bn] = bin[*bn] | (rd & 31);
	bin[*bn] = bin[*bn] | (r0 << 5);
	bin[*bn + 1] = bin[*bn + 1] | ((r0 >> 3) & 3);
	bin[*bn + 1] = bin[*bn + 1] | (k << 2);
	bin[*bn + 1] = bin[*bn + 1] | (ext << 5);
	bin[*bn + 2] = bin[*bn + 2] | r1;
	bin[*bn + 2] = bin[*bn + 2] | ((sh & 3) << 6);
	bin[*bn + 3] = bin[*bn + 3] | (rd & 128);
}

void arm_64a_inst_r5_r5_k6_k4(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k6, uint8_t k4) {
	bin[*bn] = bin[*bn] | (rd & 31);
	bin[*bn] = bin[*bn] | (rs << 5);
	bin[*bn + 1] = bin[*bn + 1] | ((rs >> 3) & 3);
	bin[*bn + 1] = bin[*bn + 1] | (k4 << 2);
	bin[*bn + 2] = bin[*bn + 2] | k6;
}

void arm_64a_inst_r5_k16_sh(uint8_t* bin, uint64_t* bn, uint8_t rd, uint16_t k, uint8_t sh) {
	bin[*bn] = bin[*bn] | (rd & 31);
	bin[*bn] = bin[*bn] | (k << 5);
	bin[*bn + 1] = bin[*bn + 1] | (k >> 3);
	bin[*bn + 2] = bin[*bn + 2] | (k >> 11);
	bin[*bn + 2] = bin[*bn + 2] | (sh << 5);
	bin[*bn + 3] = bin[*bn + 3] | (rd & 128);
}

void arm_64a_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_r64(rv[0], e, path, ln);
			arm_64a_err_k21(rv[1], e, path, ln);
			
			bin[*bn] = rv[0] & 31;
			bin[*bn] = bin[*bn] | ((rv[1] << 3) & 224);
			bin[*bn + 1] = rv[1] >> 5;
			bin[*bn + 2] = rv[1] >> 13;
			bin[*bn + 3] = 16;
			bin[*bn + 3] = bin[*bn + 3] | ((rv[1] << 5) & 96);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "adr");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'r' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_r64(rv[0], e, path, ln);
			arm_64a_err_k21(rv[1], e, path, ln);
			
			bin[*bn] = rv[0] & 31;
			bin[*bn] = bin[*bn] | ((rv[1] << 3) & 224);
			bin[*bn + 1] = rv[1] >> 5;
			bin[*bn + 2] = rv[1] >> 13;
			bin[*bn + 3] = 144;
			bin[*bn + 3] = bin[*bn + 3] | ((rv[1] << 5) & 96);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "adrp");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 11;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], 0, 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) { //shifted register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			arm_64a_err_sh(rv[3], e, path, ln);
			arm_64a_err_k6(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 11;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 10 && rt[5] == 0) { //extended register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			arm_64a_err_ext(rv[3], e, path, ln);
			arm_64a_err_k3(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 11;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], 0, rv[4], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) { //immediate
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_k12(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 17;
			arm_64a_inst_r5_r5_k12_sh(bin, bn, rv[0], rv[1], rv[2], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) { //immediate with shift
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_k12(rv[2], e, path, ln);
			arm_64a_err_lsl(rv[3], e, path, ln);
			arm_64a_err_i12(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 17;
			arm_64a_inst_r5_r5_k12_sh(bin, bn, rv[0], rv[1], rv[2], rv[4]);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 43;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], 0, 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) { //shifted register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			arm_64a_err_sh(rv[3], e, path, ln);
			arm_64a_err_k6(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 43;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 10 && rt[5] == 0) { //extended register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			arm_64a_err_ext(rv[3], e, path, ln);
			arm_64a_err_k3(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 43;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], 0, rv[4], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) { //immediate
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_k12(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 49;
			arm_64a_inst_r5_r5_k12_sh(bin, bn, rv[0], rv[1], rv[2], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) { //immediate with shift
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_k12(rv[2], e, path, ln);
			arm_64a_err_lsl(rv[3], e, path, ln);
			arm_64a_err_i12(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 49;
			arm_64a_inst_r5_r5_k12_sh(bin, bn, rv[0], rv[1], rv[2], rv[4]);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "adds");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 75;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], 0, 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) { //shifted register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			arm_64a_err_sh(rv[3], e, path, ln);
			arm_64a_err_k6(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 75;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 10 && rt[5] == 0) { //extended register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			arm_64a_err_ext(rv[3], e, path, ln);
			arm_64a_err_k3(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 75;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], 0, rv[4], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) { //immediate
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_k12(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 81;
			arm_64a_inst_r5_r5_k12_sh(bin, bn, rv[0], rv[1], rv[2], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) { //immediate with shift
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_k12(rv[2], e, path, ln);
			arm_64a_err_lsl(rv[3], e, path, ln);
			arm_64a_err_i12(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 81;
			arm_64a_inst_r5_r5_k12_sh(bin, bn, rv[0], rv[1], rv[2], rv[4]);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 107;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], 0, 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) { //shifted register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			arm_64a_err_sh(rv[3], e, path, ln);
			arm_64a_err_k6(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 107;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 10 && rt[5] == 0) { //extended register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			arm_64a_err_ext(rv[3], e, path, ln);
			arm_64a_err_k3(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 107;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], 0, rv[4], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) { //immediate
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_k12(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 113;
			arm_64a_inst_r5_r5_k12_sh(bin, bn, rv[0], rv[1], rv[2], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) { //immediate with shift
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_k12(rv[2], e, path, ln);
			arm_64a_err_lsl(rv[3], e, path, ln);
			arm_64a_err_i12(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 113;
			arm_64a_inst_r5_r5_k12_sh(bin, bn, rv[0], rv[1], rv[2], rv[4]);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "subs");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 'g' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 2 && rt[4] == 0) { //tags
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r64(rv[0], e, path, ln);
			arm_64a_err_r64(rv[1], e, path, ln);
			arm_64a_err_k6(rv[2], e, path, ln);
			arm_64a_err_k4(rv[3], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 145;
			arm_64a_inst_r5_r5_k6_k4(bin, bn, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "addg");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'g' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 2 && rt[4] == 0) { //tags
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r64(rv[0], e, path, ln);
			arm_64a_err_r64(rv[1], e, path, ln);
			arm_64a_err_k6(rv[2], e, path, ln);
			arm_64a_err_k4(rv[3], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 209;
			arm_64a_inst_r5_r5_k6_k4(bin, bn, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "subg");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 10;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], 0, 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0) { //register
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_reg(rv[2], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[2], e, path, ln);
			arm_64a_err_r36(rv[1], rv[2], e, path, ln);
			arm_64a_err_sh(rv[3], e, path, ln);
			arm_64a_err_k6(rv[4], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 10;
			arm_64a_inst_r5_r5_r5_k6_sh_ext(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) { //bitmask immediate todo
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_reg(rv[1], e, path, ln);
			arm_64a_err_r36(rv[0], rv[1], e, path, ln);
			
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 'n' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //immediate
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_k16(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 18;
			arm_64a_inst_r5_k16_sh(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) { //immediate with shift
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_k16(rv[1], e, path, ln);
			arm_64a_err_lsl(rv[2], e, path, ln);
			if (rv[0] & 128) {
				arm_64a_err_i64(rv[3], e, path, ln);
			}
			else {
				arm_64a_err_i16(rv[3], e, path, ln);
			}
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 18;
			arm_64a_inst_r5_k16_sh(bin, bn, rv[0], rv[1], rv[3]);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "movn");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 'z' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //immediate
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_k16(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 82;
			arm_64a_inst_r5_k16_sh(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) { //immediate with shift
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_k16(rv[1], e, path, ln);
			arm_64a_err_lsl(rv[2], e, path, ln);
			if (rv[0] & 128) {
				arm_64a_err_i64(rv[3], e, path, ln);
			}
			else {
				arm_64a_err_i16(rv[3], e, path, ln);
			}
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 82;
			arm_64a_inst_r5_k16_sh(bin, bn, rv[0], rv[1], rv[3]);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "movz");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 'k' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //immediate
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_k16(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 114;
			arm_64a_inst_r5_k16_sh(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) { //immediate with shift
			arm_64a_err_reg(rv[0], e, path, ln);
			arm_64a_err_k16(rv[1], e, path, ln);
			arm_64a_err_lsl(rv[2], e, path, ln);
			if (rv[0] & 128) {
				arm_64a_err_i64(rv[3], e, path, ln);
			}
			else {
				arm_64a_err_i16(rv[3], e, path, ln);
			}
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 114;
			arm_64a_inst_r5_k16_sh(bin, bn, rv[0], rv[1], rv[3]);
		}
		else {
			printf("[%s, %lu] error illegal usage of opcode '%s'\n", path, ln, "movk");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
