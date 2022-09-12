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
	if (c[0] == 'e' && c[1] == 'q' && c[2] == 0) {
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

void arm_v7m_err_rl(uint64_t* r, uint8_t rn, uint8_t ex, int8_t* e, int8_t* path, uint64_t ln) {
	for (uint8_t i = 0; i < rn; i++) {
		if (r[i] != ex) {
			arm_v7m_err_r3(r[i], e, path, ln);
		}
		for (uint8_t j = 0; j < rn; j++) {
			if (r[i] == r[j] && i != j) {
				printf("[%s, %lu] error: duplicate register 'r%u'\n", path, ln, (uint32_t) r[i]);
				*e = -1;
			}
		}
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

void arm_v7m_err_k11(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -1024 || k > 2047) {
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

void arm_v7m_inst_r3_r3_k5(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	*bn += 2;
}

void arm_v7m_inst_r3_r3_r3(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	*bn += 2;
}

void arm_v7m_inst_r4_r4(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] |= rd & 7;
	bin[*bn] |= rs << 3;
	bin[*bn] |= (rd << 4) & 128;
	*bn += 2;
}

void arm_v7m_inst_r3_k8(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	*bn += 2;
}

void arm_v7m_inst_rl9(uint8_t* bin, uint64_t* bn, uint64_t* rl, uint8_t rn, uint8_t r) {
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn] |= 128;
		}
		else if (rl[i] == r) {
			bin[*bn + 1] |= 1;
		}
	}
	*bn += 2;
}

void arm_v7m_inst_r3_rl(uint8_t* bin, uint64_t* bn, uint8_t rd, uint64_t* rl, uint8_t rn) {
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn] |= 128;
		}
	}
	bin[*bn + 1] |= rd;
	*bn += 2;
}

void arm_v7m_inst_b_cond(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 208;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= c;
	
	*bn += 2;
}

void arm_v7m_inst_b(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 224;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= k >> 8;
	
	*bn += 2;
}

void arm_v7m_inst_cbz(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) { //todo
	bin[*bn] = 0;
	bin[*bn + 1] = 177;
	
	bin[*bn] |= rd;
	bin[*bn] |= k;
	
	*bn += 2;
}

void arm_v7m_inst_cbnz(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) { //todo
	bin[*bn] = 0;
	bin[*bn + 1] = 185;
	
	bin[*bn] |= rd;
	bin[*bn] |= k;
	
	*bn += 2;
}

void arm_v7m_inst_it(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t x) {
	bin[*bn] = 0;
	bin[*bn + 1] = 191;
	
	bin[*bn] |= c << 4;
	bin[*bn] |= x;
	
	*bn += 2;
}

void arm_v7m_inst_stm_32(uint8_t* bin, uint64_t* bn, uint8_t rd, uint64_t* rl, uint8_t rn) { //todo
	bin[*bn] = 128;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn] |= rd;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn + 2] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn + 2] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn + 2] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn + 2] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn + 2] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn + 2] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn + 2] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn + 2] |= 128;
		}
		else if (rl[i] == 8) {
			bin[*bn + 3] |= 1;
		}
		else if (rl[i] == 9) {
			bin[*bn + 3] |= 2;
		}
		else if (rl[i] == 10) {
			bin[*bn + 3] |= 4;
		}
		else if (rl[i] == 11) {
			bin[*bn + 3] |= 8;
		}
		else if (rl[i] == 12) {
			bin[*bn + 3] |= 16;
		}
		else if (rl[i] == 14) {
			bin[*bn + 3] |= 64;
		}
	}
	
	*bn += 4;
}

void arm_v7m_inst_ldm_32(uint8_t* bin, uint64_t* bn, uint8_t rd, uint64_t* rl, uint8_t rn) { //todo
	bin[*bn] = 144;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn] |= rd;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn + 2] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn + 2] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn + 2] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn + 2] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn + 2] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn + 2] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn + 2] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn + 2] |= 128;
		}
		else if (rl[i] == 8) {
			bin[*bn + 3] |= 1;
		}
		else if (rl[i] == 9) {
			bin[*bn + 3] |= 2;
		}
		else if (rl[i] == 10) {
			bin[*bn + 3] |= 4;
		}
		else if (rl[i] == 11) {
			bin[*bn + 3] |= 8;
		}
		else if (rl[i] == 12) {
			bin[*bn + 3] |= 16;
		}
		else if (rl[i] == 14) {
			bin[*bn + 3] |= 64;
		}
	}
	
	*bn += 4;
}

void arm_v7m_inst_pop_32(uint8_t* bin, uint64_t* bn, uint64_t* rl, uint8_t rn) { //todo
	bin[*bn] = 189;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn + 2] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn + 2] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn + 2] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn + 2] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn + 2] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn + 2] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn + 2] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn + 2] |= 128;
		}
		else if (rl[i] == 8) {
			bin[*bn + 3] |= 1;
		}
		else if (rl[i] == 9) {
			bin[*bn + 3] |= 2;
		}
		else if (rl[i] == 10) {
			bin[*bn + 3] |= 4;
		}
		else if (rl[i] == 11) {
			bin[*bn + 3] |= 8;
		}
		else if (rl[i] == 12) {
			bin[*bn + 3] |= 16;
		}
		else if (rl[i] == 14) {
			bin[*bn + 3] |= 64;
		}
		else if (rl[i] == 15) {
			bin[*bn + 3] |= 128;
		}
	}
	
	*bn += 4;
}

void arm_v7m_inst_stmdb(uint8_t* bin, uint64_t* bn, uint8_t rd, uint64_t* rl, uint8_t rn) { //todo, stmfd
	bin[*bn] = 0;
	bin[*bn + 1] = 233;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn] |= rd;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn + 2] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn + 2] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn + 2] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn + 2] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn + 2] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn + 2] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn + 2] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn + 2] |= 128;
		}
		else if (rl[i] == 8) {
			bin[*bn + 3] |= 1;
		}
		else if (rl[i] == 9) {
			bin[*bn + 3] |= 2;
		}
		else if (rl[i] == 10) {
			bin[*bn + 3] |= 4;
		}
		else if (rl[i] == 11) {
			bin[*bn + 3] |= 8;
		}
		else if (rl[i] == 12) {
			bin[*bn + 3] |= 16;
		}
		else if (rl[i] == 14) {
			bin[*bn + 3] |= 64;
		}
	}
	
	*bn += 4;
}

void arm_v7m_inst_push_32(uint8_t* bin, uint64_t* bn, uint64_t* rl, uint8_t rn) { //todo
	bin[*bn] = 77;
	bin[*bn + 1] = 233;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn + 2] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn + 2] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn + 2] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn + 2] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn + 2] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn + 2] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn + 2] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn + 2] |= 128;
		}
		else if (rl[i] == 8) {
			bin[*bn + 3] |= 1;
		}
		else if (rl[i] == 9) {
			bin[*bn + 3] |= 2;
		}
		else if (rl[i] == 10) {
			bin[*bn + 3] |= 4;
		}
		else if (rl[i] == 11) {
			bin[*bn + 3] |= 8;
		}
		else if (rl[i] == 12) {
			bin[*bn + 3] |= 16;
		}
		else if (rl[i] == 14) {
			bin[*bn + 3] |= 64;
		}
	}
	
	*bn += 4;
}

void arm_v7m_inst_ldmdb(uint8_t* bin, uint64_t* bn, uint8_t rd, uint64_t* rl, uint8_t rn) { //todo, ldmea
	bin[*bn] = 16;
	bin[*bn + 1] = 233;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn] |= rd;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn + 2] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn + 2] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn + 2] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn + 2] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn + 2] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn + 2] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn + 2] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn + 2] |= 128;
		}
		else if (rl[i] == 8) {
			bin[*bn + 3] |= 1;
		}
		else if (rl[i] == 9) {
			bin[*bn + 3] |= 2;
		}
		else if (rl[i] == 10) {
			bin[*bn + 3] |= 4;
		}
		else if (rl[i] == 11) {
			bin[*bn + 3] |= 8;
		}
		else if (rl[i] == 12) {
			bin[*bn + 3] |= 16;
		}
		else if (rl[i] == 14) {
			bin[*bn + 3] |= 64;
		}
		else if (rl[i] == 15) {
			bin[*bn + 3] |= 128;
		}
	}
	
	*bn += 4;
}

void arm_v7m_inst_strex(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t k) {
	bin[*bn] = 64;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn + 3] |= rd;
	bin[*bn + 3] |= r0 << 4;
	bin[*bn] |= r1;
	bin[*bn + 2] |= k;
	
	*bn += 4;
}

void arm_v7m_inst_ldrex(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 80;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 15;
	
	bin[*bn + 3] |= rd << 4;
	bin[*bn] |= rs;
	bin[*bn + 2] |= k;
	
	*bn += 4;
}

void arm_v7m_inst_strd(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t k) { //todo
	bin[*bn] = 64;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn + 3] |= rd;
	bin[*bn + 3] |= r0 << 4;
	bin[*bn] |= r1;
	bin[*bn + 2] |= k;
	
	*bn += 4;
}

void arm_v7m_inst_strexb(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 192;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 64;
	bin[*bn + 3] = 15;
	
	bin[*bn + 2] |= rd;
	bin[*bn + 3] |= r0 << 4;
	bin[*bn] |= r1;
	
	*bn += 4;
}

void arm_v7m_inst_strexh(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 192;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 80;
	bin[*bn + 3] = 15;
	
	bin[*bn + 2] |= rd;
	bin[*bn + 3] |= r0 << 4;
	bin[*bn] |= r1;
	
	*bn += 4;
}

void arm_v7m_inst_tbb(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 208;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 240;
	
	bin[*bn + 2] |= rs;
	bin[*bn] |= rd;
	
	*bn += 4;
}

void arm_v7m_inst_tbh(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 208;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 16;
	bin[*bn + 3] = 240;
	
	bin[*bn + 2] |= rs;
	bin[*bn] |= rd;
	
	*bn += 4;
}

void arm_v7m_inst_ldrexb(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 208;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 79;
	bin[*bn + 3] = 15;
	
	bin[*bn + 3] |= rd << 4;
	bin[*bn] |= rs;
	
	*bn += 4;
}

void arm_v7m_inst_ldrexh(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 208;
	bin[*bn + 1] = 232;
	bin[*bn + 2] = 95;
	bin[*bn + 3] = 15;
	
	bin[*bn + 3] |= rd << 4;
	bin[*bn] |= rs;
	
	*bn += 4;
}

void arm_v7m_inst_and_reg32(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t t, uint8_t k) { //todo
	bin[*bn] = 0;
	bin[*bn + 1] = 234;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn + 3] |= rd;
	bin[*bn] |= r0;
	bin[*bn + 2] |= r1;
	bin[*bn + 2] |= t << 4;
	bin[*bn + 2] |= k << 6;
	bin[*bn + 3] |= (k << 2) & 112;
	
	*bn += 4;
}

void arm_v7m_inst_ands_reg32(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t t, uint8_t k) { //todo
	bin[*bn] = 16;
	bin[*bn + 1] = 234;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn + 3] |= rd;
	bin[*bn] |= r0;
	bin[*bn + 2] |= r1;
	bin[*bn + 2] |= t << 4;
	bin[*bn + 2] |= k << 6;
	bin[*bn + 3] |= (k << 2) & 112;
	
	*bn += 4;
}

void arm_v7m_inst_bic_reg32(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t t, uint8_t k) { //todo
	bin[*bn] = 32;
	bin[*bn + 1] = 234;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn + 3] |= rd;
	bin[*bn] |= r0;
	bin[*bn + 2] |= r1;
	bin[*bn + 2] |= t << 4;
	bin[*bn + 2] |= k << 6;
	bin[*bn + 3] |= (k << 2) & 112;
	
	*bn += 4;
}

void arm_v7m_inst_bics_reg32(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1, uint8_t t, uint8_t k) { //todo
	bin[*bn] = 48;
	bin[*bn + 1] = 234;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 0;
	
	bin[*bn + 3] |= rd;
	bin[*bn] |= r0;
	bin[*bn + 2] |= r1;
	bin[*bn + 2] |= t << 4;
	bin[*bn + 2] |= k << 6;
	bin[*bn + 3] |= (k << 2) & 112;
	
	*bn += 4;
}

void arm_v7m_inst_bl(uint8_t* bin, uint64_t* bn, int32_t k) { //todo
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

void arm_v7m_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (*bn % 2) {
		printf("[%s, %lu] error: instruction out of alignment\n", path, ln);
		*e = -1;
	}
	
	if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 64;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsl");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 64;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsls");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 8;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 64;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsr");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 8;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 64;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsrs");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 16;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 65;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asr");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 16;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 65;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asrs");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 168;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[2]);
		}
		else if ((rt[0] == 1 && rv[0] == 13) && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_k7(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 176;
			arm_v7m_inst_r3_k8(bin, bn, 0, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 24;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 28;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 48;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 68;
			arm_v7m_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 24;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 28;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
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
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 13) && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_k7(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 176;
			arm_v7m_inst_r3_k8(bin, bn, 0, 128 + rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 26;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 30;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
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
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 26;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 30;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
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
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 32;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 70;
			arm_v7m_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 32;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "movs");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 'y' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 70;
			arm_v7m_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cpy");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 40;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && ((rv[0] > 7) ^ (rv[1] > 7))) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			arm_v7m_err_r4(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 69;
			arm_v7m_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 66;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
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
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
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
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
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
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
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
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
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
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
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
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
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
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
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
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 65;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ror");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 65;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rors");
			*e = -1;
		}
	}
	else if (op[0] == 't' && op[1] == 's' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 66;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "tst");
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsb");
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsbs");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'e' && op[2] == 'g' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 66;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "neg");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'n' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 66;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmn");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 67;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orr");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 67;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orrs");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 67;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mul");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 67;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "muls");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'i' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 67;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bic");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'i' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 67;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bics");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'v' && op[2] == 'n' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 67;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mvn");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'v' && op[2] == 'n' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 67;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mvns");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'x' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 71;
			arm_v7m_inst_r4_r4(bin, bn, 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bx");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'x' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_v7m_err_r4(rv[0], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 71;
			arm_v7m_inst_r4_r4(bin, bn, 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "blx");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 15) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 72;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 2;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 72;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 88;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 152;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 104;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 80;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 144;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 96;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "str");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 82;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 128;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strh");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 84;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 112;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 86;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 90;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 136;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 92;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_k5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 120;
			arm_v7m_inst_r3_r3_k5(bin, bn, rv[0], rv[1], rv[2]); 
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			arm_v7m_err_r3(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 94;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsh");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 15) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_k8(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 160;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 2;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 160;
			arm_v7m_inst_r3_k8(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'x' && op[2] == 't' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 178;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sxth");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'x' && op[2] == 't' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 178;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sxtb");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'x' && op[2] == 't' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 178;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uxth");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'x' && op[2] == 't' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 178;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uxtb");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		bin[*bn] = 0;
		bin[*bn + 1] = 180;
		if (rt[0] == 1 && rt[1] == 0) {
			arm_v7m_err_rl(rv, 1, 14, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 1, 14);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_rl(rv, 2, 14, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 2, 14);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_rl(rv, 3, 14, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 3, 14);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7m_err_rl(rv, 4, 14, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 4, 14);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7m_err_rl(rv, 5, 14, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 5, 14);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v7m_err_rl(rv, 6, 14, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 6, 14);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v7m_err_rl(rv, 7, 14, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 7, 14);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v7m_err_rl(rv, 8, 14, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 8, 14);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v7m_err_rl(rv, 9, 14, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 9, 14);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "push");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 's' && op[3] == 'i' && op[4] == 'e' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 98;
			bin[*bn + 1] = 182;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cpsie");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 's' && op[3] == 'i' && op[4] == 'd' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 114;
			bin[*bn + 1] = 182;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cpsid");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 186;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rev");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'v' && op[3] == '1' && op[4] == '6' && op[5] == '0') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 64;
			bin[*bn + 1] = 186;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rev16");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'v' && op[3] == 's' && op[4] == 'h' && op[5] == '0') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 192;
			bin[*bn + 1] = 186;
			arm_v7m_inst_r3_r3_r3(bin, bn, rv[0], rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "revsh");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		bin[*bn] = 0;
		bin[*bn + 1] = 188;
		if (rt[0] == 1 && rt[1] == 0) {
			arm_v7m_err_rl(rv, 1, 15, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 1, 15);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_rl(rv, 2, 15, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 2, 15);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_rl(rv, 3, 15, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 3, 15);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7m_err_rl(rv, 4, 15, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 4, 15);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7m_err_rl(rv, 5, 15, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 5, 15);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v7m_err_rl(rv, 6, 15, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 6, 15);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v7m_err_rl(rv, 7, 15, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 7, 15);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v7m_err_rl(rv, 8, 15, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 8, 15);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v7m_err_rl(rv, 9, 15, e, path, ln);
			arm_v7m_inst_rl9(bin, bn, rv, 9, 15);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'k' && op[2] == 'p' && op[3] == 't' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v7m_err_k8(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 190;
			arm_v7m_inst_r3_k8(bin, bn, 0, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bkpt");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 0) {
			bin[*bn] = 0;
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
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 0) {
		bin[*bn] = 0;
		bin[*bn + 1] = 192;
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stm");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 0) {
		bin[*bn] = 0;
		bin[*bn + 1] = 192;
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmia");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'e' && op[4] == 'a' && op[5] == 0) {
		bin[*bn] = 0;
		bin[*bn + 1] = 192;
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmea");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 0) {
		bin[*bn] = 0;
		bin[*bn + 1] = 200;
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldm");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 0) {
		bin[*bn] = 0;
		bin[*bn + 1] = 200;
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmia");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'f' && op[4] == 'd' && op[5] == 0) {
		bin[*bn] = 0;
		bin[*bn + 1] = 200;
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v7m_err_r3(rv[0], e, path, ln);
			arm_v7m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v7m_inst_r3_rl(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmfd");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] != 0 && op[2] != 0 && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v7m_err_k8(rv[0], e, path, ln);
			arm_v7m_inst_b_cond(bin, bn, arm_v7m_cond(op + 1, e, path, ln), rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v7m_inst_b_cond(bin, bn, arm_v7m_cond(op + 1, e, path, ln), 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, op);
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'd' && op[2] == 'f' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v7m_err_k8(rv[0], e, path, ln);
			arm_v7m_inst_b_cond(bin, bn, 14, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "udf");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'v' && op[2] == 'c' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v7m_err_k8(rv[0], e, path, ln);
			arm_v7m_inst_b_cond(bin, bn, 15, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "svc");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v7m_err_k11(rv[0], e, path, ln);
			arm_v7m_inst_b(bin, bn, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3;
			arm_v7m_inst_b(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "b");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v7m_err_k24(rv[0], e, path, ln);
			arm_v7m_inst_bl(bin, bn, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			arm_v7m_inst_bl(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bl");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
