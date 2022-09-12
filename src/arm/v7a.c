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

uint8_t arm_v7a_cond(int8_t* c, int8_t* e, int8_t* path, uint64_t ln) {
	if (c[0] == 0) {
		return 15;
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

void arm_v7a_err_r4(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void arm_v7a_err_k5(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -16 || k > 31) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7a_err_sh(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 19) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t s, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t t, uint8_t k) {
	bin[*bn] |= r1;
	bin[*bn] |= t << 5;
	bin[*bn] |= k << 7;
	bin[*bn + 1] |= k >> 1;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= r0;
	bin[*bn + 2] |= s << 4;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_v7a_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (*bn % 4) {
		printf("[%s, %lu] error: instruction out of alignment\n", path, ln);
		*e = -1;
	}
	if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4(rv[0], e, path, ln);
			arm_v7a_err_r4(rv[1], e, path, ln);
			arm_v7a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4(rv[0], e, path, ln);
			arm_v7a_err_r4(rv[1], e, path, ln);
			arm_v7a_err_r4(rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], e, path, ln);
			arm_v7a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ands");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4(rv[0], e, path, ln);
			arm_v7a_err_r4(rv[1], e, path, ln);
			arm_v7a_err_r4(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4(rv[0], e, path, ln);
			arm_v7a_err_r4(rv[1], e, path, ln);
			arm_v7a_err_r4(rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], e, path, ln);
			arm_v7a_err_k5(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
