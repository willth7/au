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

uint8_t arm_v7m_cond(int8_t* c, int8_t* e, int8_t* path, uint64_t ln) {
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

void arm_v7m_err_r3(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 7) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void arm_v7m_err_r4(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void arm_v7m_err_k3(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -4 || k > 7) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7m_err_k5(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -16 || k > 31) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7m_err_k7(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -64 || k > 127) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7m_err_k8(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128 || k > 255) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7m_err_k12(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -2048 || k > 4095) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7m_err_k16(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32768 || k > 65535) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7m_err_k24(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -8388608 || k > 16777215) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v7m_err_sh(int64_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 19) {
		printf("[%s, %lu] error: illegal shift\n", path, ln);
		*e = -1;
	}
}

void arm_v7m_inst_r3_r3_r3(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	*bn += 2;
}

void arm_v7m_inst_r3_k8(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	*bn += 2;
}

void arm_v7m_inst_r4_r4_r4_sh_k5(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t sh, uint8_t k) {
	bin[*bn + 3] |= rd;
	bin[*bn] |= r0;
	bin[*bn + 2] |= r1;
	bin[*bn + 2] |= (sh - 16) << 4;
	bin[*bn + 2] |= k << 6;
	bin[*bn + 3] |= (k << 2) & 112;
	*bn += 4;
}

void arm_v7m_inst_r4_r4_k12(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint16_t k) {
	bin[*bn + 3] |= rd;
	bin[*bn] |= rs;
	bin[*bn + 2] |= k;
	bin[*bn + 3] |= (k >> 4) & 112;
	bin[*bn + 1] |= (k >> 9) & 4;
	*bn += 4;
}

void arm_v7m_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 16;
			bin[*bn + 1] = 234;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 16;
			bin[*bn + 1] = 234;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 16;
			bin[*bn + 1] = 240;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 64;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ands");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 0;
			bin[*bn + 1] = 234;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 0;
			bin[*bn + 1] = 234;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 0;
			bin[*bn + 1] = 240;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 64;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 144;
			bin[*bn + 1] = 234;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 144;
			bin[*bn + 1] = 234;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 144;
			bin[*bn + 1] = 240;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 64;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eors");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 128;
			bin[*bn + 1] = 234;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 128;
			bin[*bn + 1] = 234;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 128;
			bin[*bn + 1] = 240;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 64;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eor");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 's' && op[4] == 0) {
		if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 176;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 176;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 176;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 26;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 30;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 56;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subs");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 160;
			bin[*bn + 1] = 242;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 13) && (rt[1] == 1 && rv[1] == 13) && rt[2] == 2 && rt[3] == 0) { //sp
			arm_v7m_err_k7(rv[2], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 176;
			arm_v7m_inst_r3_k8(bin, bn, 0, rv[2]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 160;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 160;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 160;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 26;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 30;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 56;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'b' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 66;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 208;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 208;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 208;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsbs");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 66;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 192;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 192;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 192;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 's' && op[4] == 0) {
		if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 16;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 16;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 16;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 24;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 28;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 48;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adds");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 0;
			bin[*bn + 1] = 242;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "addw");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 13) && (rt[1] == 1 && rv[1] == 13) && rt[2] == 2 && rt[3] == 0) { //sp
			arm_v7m_err_k7(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 176;
			arm_v7m_inst_r3_k8(bin, bn, 0, rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 13) && rt[2] == 2 && rt[3] == 0) { //sp
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 168;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[2]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 0;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 0;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 0;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 24;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 28;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 48;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 80;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 80;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 80;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 65;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adcs");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 64;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 64;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 64;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 65;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 112;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 112;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 112;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 65;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbcs");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) { //32
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 96;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_r4(rv[2], e, path, ln);
			arm_v7m_err_sh(rv[3], e, path, ln);
			arm_v7m_err_k5(rv[4], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 96;
			bin[*bn + 1] = 235;
			arm_v7m_inst_r4_r4_r4_sh_k5(bin, bn, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else if ((rt[0] == 1 && rv[0] > 7) && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			arm_v7m_err_k12(rv[2], e, path, ln);
			
			bin[*bn + 2] = 0;
			bin[*bn + 3] = 0;
			bin[*bn] = 96;
			bin[*bn + 1] = 241;
			arm_v7m_inst_r4_r4_k12(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //16
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 65;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbc");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
