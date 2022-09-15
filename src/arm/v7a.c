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

void arm_v7a_err_k8(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128 || k > 256) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7a_err_k12(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -2048 || k > 4095) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7a_err_sh(uint8_t r, uint8_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 19) {
		printf("[%s, %lu] error: illegal shift\n", path, ln);
		*e = -1;
	}
	arm_v7a_err_k5(k, e, path, ln);
}

void arm_v7a_err_r4_r4_r4(uint8_t rd, uint8_t r0, uint8_t r1, int8_t* e, int8_t* path, uint64_t ln) {
	arm_v7a_err_r4(rd, e, path, ln);
	arm_v7a_err_r4(r0, e, path, ln);
	arm_v7a_err_r4(r1, e, path, ln);
}

void arm_v7a_err_r4_r4_k8(uint8_t rd, uint8_t s, uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	arm_v7a_err_r4(rd, e, path, ln);
	arm_v7a_err_r4(s, e, path, ln);
	arm_v7a_err_k8(k, e, path, ln);
}

void arm_v7a_err_r4_r4_k12(uint8_t rd, uint8_t s, uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	arm_v7a_err_r4(rd, e, path, ln);
	arm_v7a_err_r4(s, e, path, ln);
	arm_v7a_err_k12(k, e, path, ln);
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

void arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t s, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t t, uint8_t r2) {
	bin[*bn] |= r1;
	bin[*bn] |= t << 5;
	bin[*bn + 1] |= r2;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= r0;
	bin[*bn + 2] |= s << 4;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_v7a_inst_c4_s1_r4_r4_k12(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t s, uint8_t rd, uint8_t rs, uint16_t k) {
	bin[*bn] |= k;
	bin[*bn + 1] |= (k >> 4) & 15;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= rs;
	bin[*bn + 2] |= s << 4;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_v7a_inst_c4_s1_r4_r4_r4_r4(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t s, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t r2) {
	bin[*bn] |= r0;
	bin[*bn + 1] |= r1;
	bin[*bn + 1] |= r2 << 4;
	bin[*bn + 2] |= rd;
	bin[*bn + 2] |= s << 4;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_v7a_inst_c4_r4_r4_k12(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t rd, uint8_t rs, uint16_t k) {
	bin[*bn] |= k;
	bin[*bn + 1] |= (k >> 4) & 15;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= rs;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_v7a_inst_c4_r4_r4_r4_t2_k5(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t t, uint8_t k) {
	bin[*bn] |= r1;
	bin[*bn] |= t << 5;
	bin[*bn] |= k << 7;
	bin[*bn + 1] |= k >> 1;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= r0;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_v7a_inst_c4_r4_r4_k8(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] |= k & 15;
	bin[*bn + 1] |= k >> 4;
	bin[*bn + 1] |= rd << 4;
	bin[*bn + 2] |= rs;
	bin[*bn + 3] |= c << 4;
	*bn += 4;
}

void arm_v7a_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ands");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eors");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eor");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subs");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'b' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsbs");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adds");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adcs");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbcs");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbc");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'c' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rscs");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'c') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 2;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsc");
			*e = -1;
		}
	}
	else if (op[0] == 't' && op[1] == 's' && op[2] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, 0, rv[0], rv[1], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 2 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_sh(rv[2], rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7a_err_r4_r4_k12(0, rv[0], rv[1], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, 0, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "tst");
			*e = -1;
		}
	}
	else if (op[0] == 't' && op[1] == 'e' && op[2] == 'q') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, 0, rv[0], rv[1], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 2 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_sh(rv[2], rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7a_err_r4_r4_k12(0, rv[0], rv[1], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, 0, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "teq");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, 0, rv[0], rv[1], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 2 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_sh(rv[2], rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7a_err_r4_r4_k12(0, rv[0], rv[1], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, 0, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'n') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, 0, rv[0], rv[1], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 2 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_sh(rv[2], rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7a_err_r4_r4_k12(0, rv[0], rv[1], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, 0, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmn");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'r' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orrs");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orr");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], 0, rv[1], 0, 0);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], 0, rv[1], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], 0, rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "movs");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], 0, rv[1], 0, 0);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], 0, rv[1], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], 0, rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], 0, rv[1], 0, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_k5(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], 0, rv[1], 0, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsls");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], 0, rv[1], 0, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_k5(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], 0, rv[1], 0, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsl");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], 0, rv[1], 1, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_k5(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], 0, rv[1], 1, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsrs");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], 0, rv[1], 1, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_k5(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], 0, rv[1], 1, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsr");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], 0, rv[1], 2, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_k5(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], 0, rv[1], 2, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asrs");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], 0, rv[1], 2, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_k5(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], 0, rv[1], 2, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asr");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], 0, rv[1], 3, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_k5(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], 0, rv[1], 3, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rors");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], 0, rv[1], 3, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			arm_v7a_err_k5(rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], 0, rv[1], 3, rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ror");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'x' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], 0, rv[1], 3, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rrxs");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], 0, e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], 0, rv[1], 3, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rrx");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'i' && op[2] == 'c' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bics");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'i' && op[2] == 'c') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bic");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'v' && op[2] == 'n' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 1, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mvns");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'v' && op[2] == 'n') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_k5(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], 0, e, path, ln);
			arm_v7a_err_r4(rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 16;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_t2_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 3;
			arm_v7a_inst_c4_s1_r4_r4_k12(bin, bn, c, 0, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mvn");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "muls");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mul");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'l' && op[2] == 'a' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 1, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mlas");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'l' && op[2] == 'a') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mla");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'm' && op[2] == 'a' && op[3] == 'a' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "umaal");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'l' && op[2] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mls");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'l' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 1, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "umulls");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "umull");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 1, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "umlals");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "umlal");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'l' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 1, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smulls");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smull");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 1, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlals");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlal");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 'a' && op[2] == 'd' && op[3] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qadd");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 's' && op[2] == 'u' && op[3] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qsub");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 'd' && op[2] == 'a' && op[3] == 'd' && op[4] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qdadd");
			*e = -1;
		}
	}
	else if (op[0] == 'q' && op[1] == 'd' && op[2] == 's' && op[3] == 'u' && op[4] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 80;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "qdsub");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'b' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlabb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 't' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 160;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlatb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'b' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlabt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 't' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 224;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlatt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'w' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlawb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'w' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], rv[3]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlawt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'w' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 160;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smulwb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'w' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 224;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smulwt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 'b' && op[6] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlalbb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 't' && op[6] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 160;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlaltb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 'b' && op[6] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlalbt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'l' && op[3] == 'a' && op[4] == 'l' && op[5] == 't' && op[6] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_r4(rv[3], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 224;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[1], rv[2], rv[3], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smlaltt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'b' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smulbb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 't' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 160;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smultb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'b' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smulbt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 't' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 224;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[0], rv[1], rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "smultt");
			*e = -1;
		}
	}
	//sync prim
	else if (op[0] == 's' && op[1] == 'w' && op[2] == 'p' && op[3] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "swpb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'w' && op[2] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "swp");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strexd");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strexb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'h') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strexh");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strex");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrexd");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrexb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x' && op[5] == 'h') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrexh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'e' && op[4] == 'x') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 144;
			bin[*bn + 1] = 15;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_s1_r4_r4_r4_r4(bin, bn, c, 0, rv[2], rv[1], 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrex");
			*e = -1;
		}
	}
	//str
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 'p' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strbps");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 'w' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strbws");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 't' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strbts");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strbs");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strbp");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strbw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strbt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 'p' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strhps");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 'w' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strhws");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 't' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strhts");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strhs");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strhp");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strhw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strht");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strh");
			*e = -1;
		}
	}
		else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'd' && op[4] == 'p' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strdps");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'd' && op[4] == 'w' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strdws");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'd' && op[4] == 't' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strdts");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'd' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strds");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'd' && op[4] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strdp");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'd' && op[4] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strdw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'd' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strdt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 240;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strd");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'p' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strps");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'w' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strws");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 't' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strts");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strs");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strp");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strt");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "str");
			*e = -1;
		}
	}
	//ldr
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 'p' && op[6] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsbps");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 'w' && op[6] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsbws");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 't' && op[6] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsbts");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsbs");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsbp");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsbw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsbt");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 'p' && op[6] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrshps");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 'w' && op[6] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrshws");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 't' && op[6] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 7, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrshts");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrshs");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrshp");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrshw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsht");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 255;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 'p' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrbps");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 'w' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrbws");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 't' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrbts");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrbs");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrbp");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrbw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrbt");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 'p' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrhps");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 'w' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrhws");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 't' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 240;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrhts");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 208;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrhs");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrhp");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrhw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 112;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrht");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 80;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 176;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'd' && op[4] == 'p' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrdps");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'd' && op[4] == 'w' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrdws");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'd' && op[4] == 't' && op[5] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 224;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 6, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 160;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrdts");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'd' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 192;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 128;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrds");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'd' && op[4] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrdp");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'd' && op[4] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 1;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrdw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'd' && op[4] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 96;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 32;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrdt");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'd') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k8(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 64;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_k8(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 208;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrd");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'p' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrps");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'w' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrws");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 't' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrts");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrs");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrp");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrt");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldr");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
