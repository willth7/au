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

uint8_t avr_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r[0] == 'r' && r[1] == '0' && r[2] == 0) {
		return 0;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == 0) {
		return 1;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == 0) {
		return 2;
	}
	else if (r[0] == 'r' && r[1] == '3' && r[2] == 0) {
		return 3;
	}
	else if (r[0] == 'r' && r[1] == '4' && r[2] == 0) {
		return 4;
	}
	else if (r[0] == 'r' && r[1] == '5' && r[2] == 0) {
		return 5;
	}
	else if (r[0] == 'r' && r[1] == '6' && r[2] == 0) {
		return 6;
	}
	else if (r[0] == 'r' && r[1] == '7' && r[2] == 0) {
		return 7;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 0) {
		return 8;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 0) {
		return 9;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 0) {
		return 10;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 0) {
		return 11;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 0) {
		return 12;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 0) {
		return 13;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 0) {
		return 14;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 0) {
		return 15;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '6' && r[3] == 0) {
		return 16;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '7' && r[3] == 0) {
		return 17;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '8' && r[3] == 0) {
		return 18;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '9' && r[3] == 0) {
		return 19;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '0' && r[3] == 0) {
		return 20;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '1' && r[3] == 0) {
		return 21;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '2' && r[3] == 0) {
		return 22;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '3' && r[3] == 0) {
		return 23;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '4' && r[3] == 0) {
		return 24;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '5' && r[3] == 0) {
		return 25;
	}
	else if ((r[0] == 'r' && r[1] == '2' && r[2] == '6' && r[3] == 0) || r[0] == 'x') {
		return 26;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '7' && r[3] == 0) {
		return 27;
	}
	else if ((r[0] == 'r' && r[1] == '2' && r[2] == '8' && r[3] == 0) || r[0] == 'y') {
		return 28;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '9' && r[3] == 0) {
		return 29;
	}
	else if ((r[0] == 'r' && r[1] == '3' && r[2] == '0' && r[3] == 0) || r[0] == 'z') {
		return 30;
	}
	else if (r[0] == 'r' && r[1] == '3' && r[2] == '1' && r[3] == 0) {
		return 31;
	}
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_r3(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 23) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_r4(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 31) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_r5(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 31) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_r2w(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r != 24 && r != 26 && r != 28 && r != 30) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_r4w(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r % 2) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_u3(uint64_t u, int8_t* e, int8_t* path, uint64_t ln) {
	if (u > 7) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", path, ln, u);
		*e = -1;
	}
}

void avr_err_u4(uint64_t u, int8_t* e, int8_t* path, uint64_t ln) {
	if (u > 16) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", path, ln, u);
		*e = -1;
	}
}

void avr_err_u5(uint64_t u, int8_t* e, int8_t* path, uint64_t ln) {
	if (u > 31) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", path, ln, u);
		*e = -1;
	}
}

void avr_err_k6(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32 || k > 63) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void avr_err_k7(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -64 || k > 127) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void avr_err_k8(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128 || k > 255) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void avr_err_k12(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -2048 || k > 4095) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void avr_err_k16(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32768 || k > 65535) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void avr_inst_r5_r5(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] |= rs & 15;
	bin[*bn] |= rd << 4;
	bin[*bn + 1] |= rd >> 4;
	bin[*bn + 1] |= (rs >> 3) & 2;
	*bn += 2;
}

void avr_inst_r4_r4(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 1;
	rd -= 16;
	rs -= 16;
	bin[*bn] |= rs & 15;
	bin[*bn] |= rd << 4;
	*bn += 2;
}

void avr_inst_r4_k8(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	rd -= 16;
	bin[*bn] |= k & 15;
	bin[*bn] |= rd << 4;
	bin[*bn + 1] |= (k >> 4) & 15;
	*bn += 2;
}

void avr_inst_w4_w4(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	rd /= 2;
	rs /= 2;
	bin[*bn] |= rs & 15;
	bin[*bn] |= rd << 4;
	*bn += 2;
}

void avr_inst_r5_k6(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] |= k & 7;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (k >> 1) & 12;
	bin[*bn + 1] |= k & 32;
	bin[*bn + 1] |= (rd >> 4) & 1;
	*bn += 2;
}

void avr_inst_r5_k6_(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] |= k;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	bin[*bn + 1] |= (k >> 3) & 6;
	*bn += 2;
}

void avr_inst_r5_k3(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] |= k;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	*bn += 2;
}

void avr_inst_r2_k6(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	rd -= 24;
	rd /= 2;
	bin[*bn] |= k;
	bin[*bn] |= (rd << 4) & 48;
	bin[*bn] |= (k << 2) & 192;
	*bn += 2;
}

void avr_inst_k16(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn + 2] = k;
	bin[*bn + 3] = k >> 8;
	*bn += 4;
}

void avr_inst_k12(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] |= k;
	bin[*bn + 1] |= (k >> 8) & 15;
	*bn += 2;
}

void avr_inst_k5_k3(uint8_t* bin, uint64_t* bn, uint8_t k0, uint8_t k1) {
	bin[*bn] |= k1 & 7;
	bin[*bn] |= k0 << 3;
	*bn += 2;
}

void avr_inst_r5_k16(uint8_t* bin, uint64_t* bn, uint8_t rd, uint16_t k) {
	bin[*bn] |= (rd << 3) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	bin[*bn + 2] = k;
	bin[*bn + 3] = k >> 8;
	*bn += 4;
}

void avr_inst_bset(uint8_t* bin, uint64_t* bn, uint8_t b) {
	bin[*bn] = 8;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (b << 4) & 112;
	
	*bn += 2;
}

void avr_inst_bclr(uint8_t* bin, uint64_t* bn, uint8_t b) {
	bin[*bn] = 136;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (b << 4) & 112;
	
	*bn += 2;
}

void avr_inst_brbs(uint8_t* bin, uint64_t* bn, uint8_t b, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 240;
	
	k |= (k >> 1) & 64;
	
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (k << 3) & 248;
	bin[*bn + 1] |= (k >> 5) & 3;
	
	*bn += 2;
}

void avr_inst_brbc(uint8_t* bin, uint64_t* bn, uint8_t b, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 244;
	
	k |= (k >> 1) & 64;
	
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (k << 3) & 248;
	bin[*bn + 1] |= (k >> 5) & 3;
	
	*bn += 2;
}

void avr_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (*bn % 2) {
		printf("[%s, %lu] error: instruction out of alignment\n", path, ln);
		*e = -1;
	}
	
	if (op[0] == 'n' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "nop");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r4w(rv[0], e, path, ln);
			avr_err_r4w(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 1;
			avr_inst_w4_w4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "movw");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_r4(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 2;
			avr_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "muls");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 's' && op[4] == 'u' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r3(rv[0], e, path, ln);
			avr_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 3;
			avr_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mulsu");
			*e = -1;
		}
	}
	else if (op[0] == 'f' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r3(rv[0], e, path, ln);
			avr_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 8;
			bin[*bn + 1] = 3;
			avr_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "fmul");
			*e = -1;
		}
	}
	else if (op[0] == 'f' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 's' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r3(rv[0], e, path, ln);
			avr_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 128;
			bin[*bn + 1] = 3;
			avr_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "fmuls");
			*e = -1;
		}
	}
	else if (op[0] == 'f' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 's' && op[5] == 'u' && op[6] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r3(rv[0], e, path, ln);
			avr_err_r3(rv[1], e, path, ln);
			
			bin[*bn] = 136;
			bin[*bn + 1] = 3;
			avr_inst_r4_r4(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "fmulsu");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 4;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cpc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 8;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbc");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 12;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 12;
			avr_inst_r5_r5(bin, bn, rv[0], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsl");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 's' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 16;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cpse");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 20;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cp");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 24;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 28;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 28;
			avr_inst_r5_r5(bin, bn, rv[0], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rol");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 32;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 't' && op[1] == 's' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 32;
			avr_inst_r5_r5(bin, bn, rv[0], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "tst");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 36;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eor");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 36;
			avr_inst_r5_r5(bin, bn, rv[0], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "clr");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 40;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "or");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 44;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 48;
			avr_inst_r4_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 48;
			avr_inst_r4_k8(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cpi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 'i' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 64;
			avr_inst_r4_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 64;
			avr_inst_r4_k8(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbci");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'i' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 80;
			avr_inst_r4_k8(bin, bn, rv[0], rv[1]);
		}
		
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 80;
			avr_inst_r4_k8(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subi");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 96;
			avr_inst_r4_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 96;
			avr_inst_r4_k8(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ori");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 96;
			avr_inst_r4_k8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbr");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 'i' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 112;
			avr_inst_r4_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 112;
			avr_inst_r4_k8(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "andi");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'b' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 112;
			avr_inst_r4_k8(bin, bn, rv[0], ~rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cbr");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 30) && rt[2] == 2 && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_k6(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 128;
			avr_inst_r5_k6(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 28) && rt[2] == 2 && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_k6(rv[2], e, path, ln);
			
			bin[*bn] = 8;
			bin[*bn + 1] = 128;
			avr_inst_r5_k6(bin, bn, rv[0], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldd");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'd' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 30) && rt[1] == 2 && rt[2] == 1 && rt[3] == 0) {
			avr_err_k6(rv[1], e, path, ln);
			avr_err_r5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 130;
			avr_inst_r5_k6(bin, bn, rv[2], rv[1]);
		}
		else if ((rt[0] == 1 && rv[0] == 28) && rt[1] == 2 && rt[2] == 1 && rt[3] == 0) {
			avr_err_k6(rv[1], e, path, ln);
			avr_err_r5(rv[2], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 130;
			avr_inst_r5_k6(bin, bn, rv[2], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "std");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) = 1;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 144;
			avr_inst_r5_k16(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_k16(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 144;
			avr_inst_r5_k16(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lds");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 4 && rt[1] == 1 && rt[2] == 0) {
			*((uint8_t*) rv[0]) = 1;
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 146;
			avr_inst_r5_k16(bin, bn, rv[1], 0);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 1 && rt[2] == 0) {
			avr_err_k16(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 146;
			avr_inst_r5_k16(bin, bn, rv[1], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sts");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 0) {
		if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 30) && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 128;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 30) && (rt[2] == 2 && rv[2] == 1) && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 1;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 30) && (rt[2] == 3 && rv[2] == (uint64_t) -1) && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 2;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 28) && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 8;
			bin[*bn + 1] = 128;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 28) && (rt[2] == 2 && rv[2] == 1) && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 9;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 28) && (rt[2] == 3 && rv[2] == (uint64_t) -1) && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 10;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 26) && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 12;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 26) && (rt[2] == 2 && rv[2] == 1) && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 13;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 26) && (rt[2] == 3 && rv[2] == (uint64_t) -1) && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 14;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ld");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 0) {
		if ((rt[0] == 1 && rv[0] == 30) && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 130;
			avr_inst_r5_r5(bin, bn, rv[1], 0);
		}
		else if ((rt[0] == 1 && rv[0] == 30) && (rt[1] == 2 && rv[1] == 1) && rt[2] == 1 && rt[3] == 0) {
			avr_err_r5(rv[2], e, path, ln);
			
			bin[*bn] = 1;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[2], 0);
		}
		else if ((rt[0] == 1 && rv[0] == 30) && (rt[1] == 3 && rv[1] == (uint64_t) -1) && rt[2] == 1 && rt[3] == 0) {
			avr_err_r5(rv[2], e, path, ln);
			
			bin[*bn] = 2;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[2], 0);
		}
		else if ((rt[0] == 1 && rv[0] == 28) && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 8;
			bin[*bn + 1] = 130;
			avr_inst_r5_r5(bin, bn, rv[1], 0);
		}
		else if ((rt[0] == 1 && rv[0] == 28) && (rt[1] == 2 && rv[1] == 1) && rt[2] == 1 && rt[3] == 0) {
			avr_err_r5(rv[2], e, path, ln);
			
			bin[*bn] = 9;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[2], 0);
		}
		else if ((rt[0] == 1 && rv[0] == 28) && (rt[1] == 3 && rv[1] == (uint64_t) -1) && rt[2] == 1 && rt[3] == 0) {
			avr_err_r5(rv[2], e, path, ln);
			
			bin[*bn] = 10;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[2], 0);
		}
		else if ((rt[0] == 1 && rv[0] == 26) && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 12;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[1], 0);
		}
		else if ((rt[0] == 1 && rv[0] == 26) && (rt[1] == 2 && rv[1] == 1) && rt[2] == 1 && rt[3] == 0) {
			avr_err_r5(rv[2], e, path, ln);
			
			bin[*bn] = 13;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[2], 0);
		}
		else if ((rt[0] == 1 && rv[0] == 26) && (rt[1] == 3 && rv[1] == (uint64_t) -1) && rt[2] == 1 && rt[3] == 0) {
			avr_err_r5(rv[2], e, path, ln);
			
			bin[*bn] = 14;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[2], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "st");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'p' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 200;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 30) && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 4;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 30) && (rt[2] == 2 && rv[2] == 1) && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 5;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lpm");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'l' && op[2] == 'p' && op[3] == 'm' && op[4] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 216;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 30) && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 6;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 30) && (rt[2] == 2 && rv[2] == 1) && rt[3] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 7;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "elpm");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'c' && op[2] == 'h' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 30) && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 4;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xch");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 's' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 30) && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 5;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "las");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 'c' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 30) && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 6;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lac");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 't' && op[3] == 0) {
		if ((rt[0] == 1 && rv[0] == 30) && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 7;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[1], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lat");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 15;
			bin[*bn + 1] = 144;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 15;
			bin[*bn + 1] = 146;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "push");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'o' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 148;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "com");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'e' && op[2] == 'g' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 1;
			bin[*bn + 1] = 148;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "neg");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'w' && op[2] == 'a' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 2;
			bin[*bn + 1] = 148;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "swap");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 3;
			bin[*bn + 1] = 148;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "inc");
			*e = -1;
		}
	}
	
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 5;
			bin[*bn + 1] = 148;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asr");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 6;
			bin[*bn + 1] = 148;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsr");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 7;
			bin[*bn + 1] = 148;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ror");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 's' && op[2] == 'e' && op[3] == 't' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rt[2] == 0) {
			avr_err_u3(rv[0], e, path, ln);
			avr_inst_bset(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bset");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bset(bin, bn , 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sec");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'z' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bset(bin, bn , 1);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sez");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'n' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bset(bin, bn , 2);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sen");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bset(bin, bn , 3);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sev");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bset(bin, bn , 4);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ses");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'h' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bset(bin, bn , 5);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "seh");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bset(bin, bn , 6);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "set");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bset(bin, bn , 7);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sei");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'c' && op[2] == 'l' && op[3] == 'r' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rt[2] == 0) {
			avr_err_u3(rv[0], e, path, ln);
			avr_inst_bclr(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bclr");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bclr(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "clc");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'z' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bclr(bin, bn, 1);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "clz");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'n' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bclr(bin, bn, 2);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cln");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bclr(bin, bn, 3);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "clv");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bclr(bin, bn, 4);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cls");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'h' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bclr(bin, bn, 5);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "clh");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bclr(bin, bn, 6);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "clt");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_bclr(bin, bn, 7);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cli");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 8;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ret");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 't' && op[3] == 'i' && op[4] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 24;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "reti");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'l' && op[2] == 'e' && op[3] == 'e' && op[4] == 'p' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 136;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sleep");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'e' && op[3] == 'a' && op[4] == 'k' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 152;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "break");
			*e = -1;
		}
	}
	else if (op[0] == 'w' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 168;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "wdr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'p' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 232;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else if ((rt[0] == 1 && rv[0] == 30) && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 232;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else if ((rt[0] == 1 && rv[0] == 30) && (rt[1] == 2 && rv[1] == 1) && rt[2] == 0) {
			bin[*bn] = 248;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "spm");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'j' && op[2] == 'm' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 9;
			bin[*bn + 1] = 148;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ijmp");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'i' && op[2] == 'j' && op[3] == 'm' && op[4] == 'p' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 25;
			bin[*bn + 1] = 148;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eijmp");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'c' && op[2] == 'a' && op[3] == 'l' && op[4] == 'l' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 9;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "icall");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'i' && op[2] == 'c' && op[3] == 'a' && op[4] == 'l' && op[5] == 'l' && op[6] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			bin[*bn] = 25;
			bin[*bn + 1] = 149;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eicall");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			
			bin[*bn] = 10;
			bin[*bn + 1] = 148;
			avr_inst_r5_r5(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "dec");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rt[2] == 0) {
			avr_err_u4(rv[0], e, path, ln);
			
			bin[*bn] = 11;
			bin[*bn + 1] = 148;
			bin[*bn] |= rv[0] << 4;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "des");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 2;
			
			bin[*bn] = 12;
			bin[*bn + 1] = 148;
			avr_inst_k16(bin, bn, 0);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k16(rv[0], e, path, ln);
			
			bin[*bn] = 12;
			bin[*bn + 1] = 148;
			avr_inst_k16(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jmp");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'a' && op[2] == 'l' && op[3] == 'l' && op[4] == 0) {
		if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 2;
			
			bin[*bn] = 14;
			bin[*bn + 1] = 148;
			avr_inst_k16(bin, bn, 0);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k16(rv[0], e, path, ln);
			
			bin[*bn] = 14;
			bin[*bn + 1] = 148;
			avr_inst_k16(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "call");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'i' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r2w(rv[0], e, path, ln);
			avr_err_k6(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 150;
			avr_inst_r2_k6(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r2w(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) = 6;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 150;
			avr_inst_r2_k6(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adiw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r2w(rv[0], e, path, ln);
			avr_err_k6(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 151;
			avr_inst_r2_k6(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r2w(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) = 6;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 151;
			avr_inst_r2_k6(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbiw");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'b' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 2 && rt[2] == 0) {
			avr_err_u5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 152;
			avr_inst_k5_k3(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cbi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 'c' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 2 && rt[2] == 0) {
			avr_err_u5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 153;
			avr_inst_k5_k3(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbic");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 2 && rt[2] == 0) {
			avr_err_u5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 154;
			avr_inst_k5_k3(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 's') {
		if (rt[0] == 2 && rt[1] == 2 && rt[2] == 0) {
			avr_err_u5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 155;
			avr_inst_k5_k3(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbis");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 156;
			avr_inst_r5_r5(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mul");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_k6(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 176;
			avr_inst_r5_k6_(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "in");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'u' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 1 && rt[2] == 0) {
			avr_err_k6(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 184;
			avr_inst_r5_k6_(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "out");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'j' && op[2] == 'm' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 3;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 192;
			avr_inst_k12(bin, bn, 0);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k12(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 192;
			avr_inst_k12(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rjmp");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'a' && op[3] == 'l' && op[4] == 'l' && op[5] == 0) {
		if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 3;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 208;
			avr_inst_k12(bin, bn, 0);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k12(rv[0], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 208;
			avr_inst_k12(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcall");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 224;
			avr_inst_r4_k8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			
			bin[*bn] = 0;
			bin[*bn + 1] = 224;
			avr_inst_r4_k8(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			
			bin[*bn] = 15;
			bin[*bn + 1] = 239;
			bin[*bn] |= rv[0] << 4;
			*bn += 2;
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ser");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'b' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 2 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_u3(rv[0], e, path, ln);
			avr_err_k7(rv[1], e, path, ln);
			avr_inst_brbs(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 2 && rt[1] == 4 && rt[2] == 0) {
			avr_err_u3(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 2;
			avr_inst_brbs(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brbs");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'b' && op[3] == 'c' && op[4] == 0) {
		if (rt[0] == 2 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_u3(rv[0], e, path, ln);
			avr_err_k7(rv[1], e, path, ln);
			avr_inst_brbc(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 2 && rt[1] == 4 && rt[2] == 0) {
			avr_err_u3(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 4;
			avr_inst_brbc(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brbc");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbs(bin, bn, 0, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbs(bin, bn, 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brcs");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'l' && op[3] == 'o' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbs(bin, bn, 0, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbs(bin, bn, 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brlo");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'c' && op[3] == 'c' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbc(bin, bn, 0, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbc(bin, bn, 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brcc");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbc(bin, bn, 0, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbc(bin, bn, 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brsh");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'e' && op[3] == 'q' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbs(bin, bn, 1, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbs(bin, bn, 1, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "breq");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'n' && op[3] == 'e' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbc(bin, bn, 1, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbc(bin, bn, 1, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brne");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'm' && op[3] == 'i' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbs(bin, bn, 2, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbs(bin, bn, 2, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brmi");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'p' && op[3] == 'l' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbc(bin, bn, 2, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbc(bin, bn, 2, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brpl");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'v' && op[3] == 's' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbs(bin, bn, 3, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbs(bin, bn, 3, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brvs");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'v' && op[3] == 'c' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbc(bin, bn, 3, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbc(bin, bn, 3, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brvc");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'l' && op[3] == 't' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbs(bin, bn, 4, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbs(bin, bn, 4, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brlt");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'g' && op[3] == 'e' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbc(bin, bn, 4, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbc(bin, bn, 4, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brge");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'h' && op[3] == 's' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbs(bin, bn, 5, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbs(bin, bn, 5, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brhs");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'h' && op[3] == 'c' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbc(bin, bn, 5, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbc(bin, bn, 5, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brhc");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 't' && op[3] == 's' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbs(bin, bn, 6, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbs(bin, bn, 6, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brts");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 't' && op[3] == 'c' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbc(bin, bn, 6, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbc(bin, bn, 6, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brtc");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'i' && op[3] == 'e' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbs(bin, bn, 7, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbs(bin, bn, 7, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brie");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'i' && op[3] == 'd' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k7(rv[0], e, path, ln);
			avr_inst_brbc(bin, bn, 7, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			avr_inst_brbc(bin, bn, 7, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "brid");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 248;
			avr_inst_r5_k3(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bld");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 's' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 250;
			avr_inst_r5_k3(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bst");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'r' && op[3] == 'c' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 252;
			avr_inst_r5_k3(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbrc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 254;
			avr_inst_r5_k3(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbrs");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
