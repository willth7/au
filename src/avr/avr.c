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
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_r4(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 32) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_r5(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 23) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_r4w(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r % 2) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_rp(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r != 26 && r != 28 && r != 30) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_ry(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r != 28 && r != 30) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_rz(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r != 30) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_err_k0(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k != 1) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void avr_err_k1(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k != 0 && k != 1) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void avr_err_k2(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -1 || k > 1) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
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

void avr_inst_nop(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 0;
	bin[*bn + 1] = 0;
	
	*bn += 2;
}

void avr_inst_movw(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 1;
	
	rd /= 2;
	rs /= 2;
	
	bin[*bn] |= rs;
	bin[*bn] |= rd << 4;
	
	*bn += 2;
}

void avr_inst_muls(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 2;
	
	rd &= 15;
	rs &= 15;
	
	bin[*bn] |= rs;
	bin[*bn] |= rd << 4;
	
	*bn += 2;
}

void avr_inst_mulsu(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 3;
	
	rd &= 7;
	rs &= 7;
	
	bin[*bn] |= rs;
	bin[*bn] |= rd << 4;
	
	*bn += 2;
}

void avr_inst_fmul(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 8;
	bin[*bn + 1] = 3;
	
	rd &= 7;
	rs &= 7;
	
	bin[*bn] |= rs;
	bin[*bn] |= rd << 4;
	
	*bn += 2;
}

void avr_inst_fmuls(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 128;
	bin[*bn + 1] = 3;
	
	rd &= 7;
	rs &= 7;
	
	bin[*bn] |= rs;
	bin[*bn] |= rd << 4;
	
	*bn += 2;
}

void avr_inst_fmulsu(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 136;
	bin[*bn + 1] = 3;
	
	rd &= 7;
	rs &= 7;
	
	bin[*bn] |= rs;
	bin[*bn] |= rd << 4;
	
	*bn += 2;
}

void avr_inst_cp(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 20;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_cpc(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 4;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_sub(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 24;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_sbc(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 8;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_add(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 12;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_adc(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 28;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_cpse(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 16;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_and(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 32;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_eor(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 36;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_or(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 40;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_mov(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 44;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_mul(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 156;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rs >> 3) & 2;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_cpi(uint8_t* bin, uint64_t* bn, uint8_t rd, int8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 48;
	
	rd &= 15;
	
	bin[*bn] |= (k) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (k >> 4) & 15;
	
	*bn += 2;
}

void avr_inst_subi(uint8_t* bin, uint64_t* bn, uint8_t rd, int8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 80;
	
	rd &= 15;
	
	bin[*bn] |= (k) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (k >> 4) & 15;
	
	*bn += 2;
}

void avr_inst_sbci(uint8_t* bin, uint64_t* bn, uint8_t rd, int8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 64;
	
	rd &= 15;
	
	bin[*bn] |= (k) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (k >> 4) & 15;
	
	*bn += 2;
}

void avr_inst_ori(uint8_t* bin, uint64_t* bn, uint8_t rd, int8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 96;
	
	rd &= 15;
	
	bin[*bn] |= (k) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (k >> 4) & 15;
	
	*bn += 2;
}

void avr_inst_andi(uint8_t* bin, uint64_t* bn, uint8_t rd, int8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 112;
	
	rd &= 15;
	
	bin[*bn] |= (k) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (k >> 4) & 15;
	
	*bn += 2;
}

void avr_inst_cbr(uint8_t* bin, uint64_t* bn, uint8_t rd, int8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 112;
	
	rd &= 15;
	
	bin[*bn] |= (~k) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (~k >> 4) & 15;
	
	*bn += 2;
}

void avr_inst_ldi(uint8_t* bin, uint64_t* bn, uint8_t rd, int8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 224;
	
	rd &= 15;
	
	bin[*bn] |= (k) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (k >> 4) & 15;
	
	*bn += 2;
}

void avr_inst_ldd(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rp, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 128;
	
	rp &= 2;
	
	bin[*bn] |= (!rp) << 3;
	bin[*bn] |= k & 7;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (k >> 1) & 12;
	bin[*bn + 1] |= (k) & 32;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_std(uint8_t* bin, uint64_t* bn, uint8_t rp, uint8_t k, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 130;
	
	rp &= 2;
	
	bin[*bn] |= (!rp) << 3;
	bin[*bn] |= k & 7;
	bin[*bn] |= (rs << 4) & 240;
	bin[*bn + 1] |= (k >> 1) & 12;
	bin[*bn + 1] |= (k) & 32;
	bin[*bn + 1] |= (rs >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_lds(uint8_t* bin, uint64_t* bn, uint8_t rd, uint16_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 144;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	bin[*bn + 2] = k;
	bin[*bn + 3] = k >> 8;
	
	*bn += 4;
}

void avr_inst_sts(uint8_t* bin, uint64_t* bn, uint16_t k, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 146;
	
	bin[*bn] |= (rs << 4) & 240;
	bin[*bn + 1] |= (rs >> 4) & 1;
	bin[*bn + 2] = k;
	bin[*bn + 3] = k >> 8;
	
	*bn += 4;
}

void avr_inst_ld(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rp, int8_t k) { //todo
	bin[*bn] = 0;
	bin[*bn + 1] = 144;
	
	if (rp == 26) {
		rp = 12;
	}
	else if (rp == 28) {
		rp = 8;
	}
	else if (rp == 30) {
		rp = 0;
	}
	
	if (rp != 12 && k == 0) {
		bin[*bn + 1] = 128;
	}
	
	if (k == -1) {
		k = 2;
	}
	
	bin[*bn] |= k;
	bin[*bn] |= (rp) & 12;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_st(uint8_t* bin, uint64_t* bn, uint8_t rp, int8_t k, uint8_t rs) { //todo
	bin[*bn] = 0;
	bin[*bn + 1] = 146;
	
	if (rp == 26) {
		rp = 12;
	}
	else if (rp == 28) {
		rp = 8;
	}
	else if (rp == 30) {
		rp = 0;
	}
	
	if (rp != 12 && k == 0) {
		bin[*bn + 1] = 130;
	}
	
	if (k == -1) {
		k = 2;
	}
	
	bin[*bn] |= k;
	bin[*bn] |= (rp) & 12;
	bin[*bn] |= (rs << 4) & 240;
	bin[*bn + 1] |= (rs >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_lpm(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 200;
	bin[*bn + 1] = 149;
	
	*bn += 2;
}

void avr_inst_lpm_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 4;
	bin[*bn + 1] = 144;
	
	bin[*bn] |= k;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_elpm(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 216;
	bin[*bn + 1] = 149;
	
	*bn += 2;
}

void avr_inst_elpm_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 6;
	bin[*bn + 1] = 144;
	
	bin[*bn] |= k;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_xch(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 4;
	bin[*bn + 1] = 146;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_las(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 5;
	bin[*bn + 1] = 146;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_lac(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 6;
	bin[*bn + 1] = 146;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_lat(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 7;
	bin[*bn + 1] = 146;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_pop(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 15;
	bin[*bn + 1] = 144;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_push(uint8_t* bin, uint64_t* bn, uint8_t rs) {
	bin[*bn] = 15;
	bin[*bn + 1] = 146;
	
	bin[*bn] |= (rs << 4) & 240;
	bin[*bn + 1] |= (rs >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_com(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 0;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_neg(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 1;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_swap(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 2;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_inc(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 3;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_dec(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 10;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_asr(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 5;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_lsr(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 6;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_ror(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 7;
	bin[*bn + 1] = 148;
	
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
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


void avr_inst_ret(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 8;
	bin[*bn + 1] = 149;
	
	*bn += 2;
}

void avr_inst_reti(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 24;
	bin[*bn + 1] = 149;
	
	*bn += 2;
}

void avr_inst_sleep(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 136;
	bin[*bn + 1] = 149;
	
	*bn += 2;
}

void avr_inst_break(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 152;
	bin[*bn + 1] = 149;
	
	*bn += 2;
}

void avr_inst_wdr(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 168;
	bin[*bn + 1] = 149;
	
	*bn += 2;
}

void avr_inst_spm(uint8_t* bin, uint64_t* bn, uint8_t k) {
	bin[*bn] = 232;
	bin[*bn + 1] = 149;
	
	bin[*bn] |= k << 4;
	
	*bn += 2;
}

void avr_inst_ijmp(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 9;
	bin[*bn + 1] = 148;
	
	*bn += 2;
}

void avr_inst_eijmp(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 25;
	bin[*bn + 1] = 148;
	
	*bn += 2;
}

void avr_inst_icall(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 9;
	bin[*bn + 1] = 149;
	
	*bn += 2;
}

void avr_inst_eicall(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 25;
	bin[*bn + 1] = 149;
	
	*bn += 2;
}

void avr_inst_des(uint8_t* bin, uint64_t* bn, uint8_t k) {
	bin[*bn] = 11;
	bin[*bn + 1] = 148;
		
	bin[*bn] |= (k << 4) & 240;
	
	*bn += 2;
}

void avr_inst_jmp(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = 12;
	bin[*bn + 1] = 148;
	bin[*bn + 2] = k;
	bin[*bn + 3] = k >> 8;
	
	*bn += 4;
}

void avr_inst_call(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = 14;
	bin[*bn + 1] = 148;
	bin[*bn + 2] = k;
	bin[*bn + 3] = k >> 8;
	
	*bn += 4;
}

void avr_inst_adiw(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 150;
	
	rd /= 2;
	
	bin[*bn] |= (k) & 15;
	bin[*bn] |= (k << 2) & 192;
	bin[*bn] |= (rd << 4) & 48;
	
	*bn += 2;
}

void avr_inst_sbiw(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 151;
	
	rd /= 2;
	
	bin[*bn] |= (k) & 15;
	bin[*bn] |= (k << 2) & 192;
	bin[*bn] |= (rd << 4) & 48;
	
	*bn += 2;
}

void avr_inst_cbi(uint8_t* bin, uint64_t* bn, uint8_t p, uint8_t b) {
	bin[*bn] = 0;
	bin[*bn + 1] = 152;
	
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (p << 3) & 248;
	
	*bn += 2;
}

void avr_inst_sbi(uint8_t* bin, uint64_t* bn, uint8_t p, uint8_t b) {
	bin[*bn] = 0;
	bin[*bn + 1] = 154;
	
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (p << 3) & 248;
	
	*bn += 2;
}

void avr_inst_sbic(uint8_t* bin, uint64_t* bn, uint8_t p, uint8_t b) {
	bin[*bn] = 0;
	bin[*bn + 1] = 153;
	
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (p << 3) & 248;
	
	*bn += 2;
}

void avr_inst_sbis(uint8_t* bin, uint64_t* bn, uint8_t p, uint8_t b) {
	bin[*bn] = 0;
	bin[*bn + 1] = 155;
	
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (p << 3) & 248;
	
	*bn += 2;
}

void avr_inst_in(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t p) {
	bin[*bn] = 0;
	bin[*bn + 1] = 176;
	
	bin[*bn] |= (p) & 15;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (p >> 3) & 6;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_out(uint8_t* bin, uint64_t* bn, uint8_t p, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 184;
	
	bin[*bn] |= (p) & 15;
	bin[*bn] |= (rs << 4) & 240;
	bin[*bn + 1] |= (p >> 3) & 6;
	bin[*bn + 1] |= (rs >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_rjmp(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 192;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= (k >> 8) & 15;
	
	*bn += 2;
}

void avr_inst_rcall(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 208;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= (k >> 8) & 15;
	
	*bn += 2;
}

void avr_inst_ser(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 15;
	bin[*bn + 1] = 239;
	
	rd &= 15;
	
	bin[*bn] |= (rd << 4) && 240;
	
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

void avr_inst_bld(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t b) {
	bin[*bn] = 0;
	bin[*bn + 1] = 248;
	
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_bst(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t b) {
	bin[*bn] = 0;
	bin[*bn + 1] = 250;
	
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn + 1] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_sbrc(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t b) {
	bin[*bn] = 0;
	bin[*bn + 1] = 252;
		
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_inst_sbrs(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t b) {
	bin[*bn] = 0;
	bin[*bn + 1] = 254;
		
	bin[*bn] |= (b) & 7;
	bin[*bn] |= (rd << 4) & 240;
	bin[*bn] |= (rd >> 4) & 1;
	
	*bn += 2;
}

void avr_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (*bn % 2) {
		printf("[%s, %lu] error: instruction out of alignment\n", path, ln);
		*e = -1;
	}
	
	if (op[0] == 'n' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_nop(bin, bn);
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
			avr_inst_movw(bin, bn, rv[0], rv[1]);
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
			avr_inst_muls(bin, bn, rv[0], rv[1]);
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
			avr_inst_mulsu(bin, bn, rv[0], rv[1]);
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
			avr_inst_fmul(bin, bn, rv[0], rv[1]);
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
			avr_inst_fmuls(bin, bn, rv[0], rv[1]);
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
			avr_inst_fmulsu(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "fmulsu");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_cp(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cp");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_cpc(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cpc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_sub(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_sbc(bin, bn, rv[0], rv[1]);
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
			avr_inst_add(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_adc(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_add(bin, bn, rv[0], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsl");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_adc(bin, bn, rv[0], rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rol");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 's' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_cpse(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cpse");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_and(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 't' && op[1] == 's' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_and(bin, bn, rv[0], rv[0]);
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
			avr_inst_eor(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eor");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_eor(bin, bn, rv[0], rv[0]);
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
			avr_inst_or(bin, bn, rv[0], rv[1]);
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
			avr_inst_mov(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_mul(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mul");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			avr_inst_cpi(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			avr_inst_cpi(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cpi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'i' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			avr_inst_subi(bin, bn, rv[0], rv[1]);
		}
		
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			avr_inst_subi(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 'i' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			avr_inst_sbci(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			avr_inst_sbci(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbci");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			avr_inst_ori(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			avr_inst_ori(bin, bn, rv[0], 0);
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
			avr_inst_ori(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			avr_inst_ori(bin, bn, rv[0], 0);
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
			avr_inst_andi(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			avr_inst_andi(bin, bn, rv[0], 0);
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
			avr_inst_cbr(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			avr_inst_cbr(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cbr");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_err_k8(rv[1], e, path, ln);
			avr_inst_ldi(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 5;
			avr_inst_ldi(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldi");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_ry(rv[1], e, path, ln);
			avr_err_k6(rv[2], e, path, ln);
			avr_inst_ldd(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldd");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 1) {
			avr_err_ry(rv[0], e, path, ln);
			avr_err_k6(rv[1], e, path, ln);
			avr_err_r5(rv[2], e, path, ln);
			avr_inst_std(bin, bn, rv[0], rv[1], rv[2]);
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
			avr_inst_lds(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_k16(rv[1], e, path, ln);
			avr_inst_lds(bin, bn, rv[0], rv[1]);
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
			avr_inst_sts(bin, bn, 0, rv[1]);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 1 && rt[2] == 0) {
			avr_err_k16(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_sts(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sts");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_rp(rv[1], e, path, ln);
			avr_inst_ld(bin, bn, rv[0], rv[1], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_rp(rv[1], e, path, ln);
			avr_err_k2(rv[2], e, path, ln);
			avr_inst_ld(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ld");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_rp(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_st(bin, bn, rv[0], 0, rv[1]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 1) {
			avr_err_rp(rv[0], e, path, ln);
			avr_err_k2(rv[1], e, path, ln);
			avr_err_r5(rv[2], e, path, ln);
			avr_inst_st(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "st");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'p' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_lpm(bin, bn);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_rz(rv[1], e, path, ln);
			avr_inst_lpm_reg(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_rz(rv[1], e, path, ln);
			avr_err_k1(rv[2], e, path, ln);
			avr_inst_lpm_reg(bin, bn, rv[0], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lpm");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'l' && op[2] == 'p' && op[3] == 'm' && op[4] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_elpm(bin, bn);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_rz(rv[1], e, path, ln);
			avr_inst_elpm_reg(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_rz(rv[1], e, path, ln);
			avr_err_k1(rv[2], e, path, ln);
			avr_inst_elpm_reg(bin, bn, rv[0], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "elpm");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'c' && op[2] == 'h' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_rz(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_xch(bin, bn, rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xch");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_rz(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_las(bin, bn, rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "las");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_rz(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_lac(bin, bn, rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lac");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_err_rz(rv[0], e, path, ln);
			avr_err_r5(rv[1], e, path, ln);
			avr_inst_lat(bin, bn, rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lat");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_pop(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_push(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "push");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'o' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_com(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "com");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'e' && op[2] == 'g' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_neg(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "neg");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'w' && op[2] == 'a' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_swap(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "swap");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_inc(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "inc");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_dec(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "dec");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_asr(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asr");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_lsr(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsr");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_inst_ror(bin, bn, rv[0]);
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
			avr_inst_ret(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ret");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 't' && op[3] == 'i' && op[4] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_reti(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "reti");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'l' && op[2] == 'e' && op[3] == 'e' && op[4] == 'p' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_sleep(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sleep");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'e' && op[3] == 'a' && op[4] == 'k' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_break(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "break");
			*e = -1;
		}
	}
	else if (op[0] == 'w' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_wdr(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "wdr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'p' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_spm(bin, bn, 0);
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			avr_err_rz(rv[0], e, path, ln);
			avr_err_k0(rv[1], e, path, ln);
			avr_inst_spm(bin, bn, 1);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "spm");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'j' && op[2] == 'm' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_ijmp(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ijmp");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'i' && op[2] == 'j' && op[3] == 'm' && op[4] == 'p' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_eijmp(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eijmp");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'c' && op[2] == 'a' && op[3] == 'l' && op[4] == 'l' && op[5] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_icall(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "icall");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'i' && op[2] == 'c' && op[3] == 'a' && op[4] == 'l' && op[5] == 'l' && op[6] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_inst_eicall(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eicall");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rt[2] == 0) {
			avr_err_u4(rv[0], e, path, ln);
			avr_inst_des(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "des");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 2;
			avr_inst_jmp(bin, bn, 0);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k16(rv[0], e, path, ln);
			avr_inst_jmp(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jmp");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'a' && op[2] == 'l' && op[3] == 'l' && op[4] == 0) {
		if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 2;
			avr_inst_call(bin, bn, 0);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k16(rv[0], e, path, ln);
			avr_inst_call(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "call");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'i' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4w(rv[0], e, path, ln);
			avr_err_k6(rv[1], e, path, ln);
			avr_inst_adiw(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4w(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) = 6;
			avr_inst_adiw(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adiw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			avr_err_r4w(rv[0], e, path, ln);
			avr_err_k6(rv[1], e, path, ln);
			avr_inst_sbiw(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			avr_err_r4w(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) = 6;
			avr_inst_sbiw(bin, bn, rv[0], 0);
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
			avr_inst_cbi(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cbi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 2 && rt[2] == 0) {
			avr_err_u5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			avr_inst_sbi(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 'c' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 2 && rt[2] == 0) {
			avr_err_u5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			avr_inst_sbic(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbic");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 's') {
		if (rt[0] == 2 && rt[1] == 2 && rt[2] == 0) {
			avr_err_u5(rv[0], e, path, ln);
			avr_err_u3(rv[1], e, path, ln);
			avr_inst_sbis(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbis");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			avr_err_r5(rv[0], e, path, ln);
			avr_err_k6(rv[1], e, path, ln);
			avr_inst_in(bin, bn, rv[0], rv[1]);
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
			avr_inst_out(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "out");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'j' && op[2] == 'm' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 3;
			avr_inst_rjmp(bin, bn, 0);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k12(rv[0], e, path, ln);
			avr_inst_rjmp(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rjmp");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'a' && op[3] == 'l' && op[4] == 'l' && op[5] == 0) {
		if (rt[0] == 4 && rt[1] == 0 && rt[2] == 0) {
			*((uint8_t*) rv[0]) |= 3;
			avr_inst_rcall(bin, bn, 0);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0 && rt[2] == 0) {
			avr_err_k12(rv[0], e, path, ln);
			avr_inst_rcall(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcall");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			avr_err_r4(rv[0], e, path, ln);
			avr_inst_ser(bin, bn, rv[0]);
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
			avr_inst_bld(bin, bn, rv[0], rv[1]);
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
			avr_inst_bst(bin, bn, rv[0], rv[1]);
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
			avr_inst_sbrc(bin, bn, rv[0], rv[1]);
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
			avr_inst_sbrs(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbrs");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, "sbrs");
			*e = -1;
	}
}
