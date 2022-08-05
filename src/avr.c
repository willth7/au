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

typedef struct enc_s {
	uint8_t x[4];
	uint8_t n;
} enc_t;

typedef struct err_s {
	int8_t e[256];
	int8_t b;
} err_t;

typedef enc_t (*avr_op_t) (uint16_t, uint16_t);
typedef uint16_t (*avr_reg_t) (int8_t*);

avr_op_t avr_op[119];
avr_reg_t avr_rd[119];
avr_reg_t avr_rs[119];

int64_t au_strint(int8_t* s, uint8_t i, err_t* err) {
	int64_t v = 0;
	if (s[i] == 39 && s[i + 2] == 39) {
		v = s[i + 1];
	}
	else if (s[i] == '0' && s[i + 1] == 'x') {
		v = s[i + 1];
	}
	else {
		int8_t n = 0;
		if (s[i] == '-') {
			n = 1;
			i++;
		}
		for (; i < 20; i++) {
			if (s[i] == 0) {
				return v;
			}
			v *= 10;
			if (s[i] == '1') {
				v += 1;
			}
			else if (s[i] == '2') {
				v += 2;
			}
			else if (s[i] == '3') {
				v += 3;
			}
			else if (s[i] == '4') {
				v += 4;
			}
			else if (s[i] == '5') {
				v += 5;
			}
			else if (s[i] == '6') {
				v += 6;
			}
			else if (s[i] == '7') {
				v += 7;
			}
			else if (s[i] == '8') {
				v += 8;
			}
			else if (s[i] == '9') {
				v += 9;
			}
			else if (s[i] != '0'){
				////err->e = "invalid character";
				//err->b = 1;
				return 0;
			}
		}
	}
}

uint8_t avr_reg(int8_t* r) {
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
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '6' && r[3] == 0) {
		return 26;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '7' && r[3] == 0) {
		return 27;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '8' && r[3] == 0) {
		return 28;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '9' && r[3] == 0) {
		return 29;
	}
	else if (r[0] == 'r' && r[1] == '3' && r[2] == '0' && r[3] == 0) {
		return 30;
	}
	else if (r[0] == 'r' && r[1] == '3' && r[2] == '1' && r[3] == 0) {
		return 31;
	}
	else {
		return 255;
	}
}

uint8_t avr_r2(int8_t* r, err_t* err) {
	if (r[0] == 'r' && r[1] == '2' && r[2] == '4' && r[3] == 0) {
		return 0;
	}
	else if ((r[0] == 'r' && r[1] == '2' && r[2] == '6' && r[3] == 0) || (r[0] == 'x' && r[1] == 0)) {
		return 1;
	}
	else if ((r[0] == 'r' && r[1] == '2' && r[2] == '8' && r[3] == 0) || (r[0] == 'y' && r[1] == 0)) {
		return 2;
	}
	else if ((r[0] == 'r' && r[1] == '3' && r[2] == '0' && r[3] == 0) || (r[0] == 'z' && r[1] == 0)) {
		return 3;
	}
	else {
		////err->e = "illegal register";
		//err->b = 1;
	}
}

uint8_t avr_rex(int8_t* r, err_t* err) {
	if (r[0] == 'x' && r[1] == 0) {
		return 28;
	}
	else if (r[0] == 'x' && r[1] == '+' && r[2] == 0) {
		return 29;
	}
	else if (r[0] == 'x' && r[1] == '-' && r[2] == 0) {
		return 30;
	}
	else if (r[0] == 'y' && r[1] == 0) {
		return 8;
	}
	else if (r[0] == 'y' && r[1] == '+' && r[2] == 0) {
		return 25;
	}
	else if (r[0] == 'y' && r[1] == '-' && r[2] == 0) {
		return 26;
	}
	else if (r[0] == 'z' && r[1] == 0) {
		return 0;
	}
	else if (r[0] == 'z' && r[1] == '+' && r[2] == 0) {
		return 17;
	}
	else if (r[0] == 'z' && r[1] == '-' && r[2] == 0) {
		return 18;
	}
}

uint8_t avr_r3(int8_t* r, err_t* err) {
	uint8_t a = avr_reg(r);
	if ((a < 16 || a > 23) && a < 32) {
		//error
	}
	else if (a == 255) {
		//error
	}
	
	return a & 7;
}

uint8_t avr_r4(int8_t* r, err_t* err) {
	uint8_t a = avr_reg(r);
	if ((a < 16 || a > 32)) {
		//error
	}
	else if (a == 255) {
		//error
	}
	
	return a & 15;
}

uint8_t avr_r5(int8_t* r, err_t* err) {
	uint8_t a = avr_reg(r);
	if (a == 255) {
		//error
	}
	
	return a & 31;
}

uint8_t avr_rw(int8_t* r, err_t* err) {
	uint8_t a = avr_reg(r);
	if (a % 2 == 1) {
		//error
	}
	else if (a == 255) {
		//error
	}
	
	return (a / 2) & 15;
}

uint8_t avr_d6(int8_t* r, err_t* err) {
	uint8_t k = au_strint(r, 1, err);
	if (k > 63) {
		//error
	}
	
	if (r[0] == 'y') {
		uint8_t y = (k << 1) & 112;
		k &= 7;
		k |= y | 8;
	}
	else if (r[0] == 'z') {
		uint8_t z = (k << 1) & 112;
		k &= 7;
		k |= z;
	}
	
	return k;
}

uint8_t avr_b3(int8_t* b, err_t* err) {
	uint8_t a = au_strint(b, 0, err);
	if (a > 7) {
		//error
	}
	
	return a;
}

uint8_t avr_p5(uint8_t* p, err_t* err) {
	uint8_t a = au_strint(p, 0, err);
	if (a > 31) {
		//error
	}
	
	return a;
}

uint8_t avr_p6(uint8_t* p, err_t* err) {
	uint8_t a = au_strint(p, 0, err);
	if (a > 63) {
		//error
	}
	
	return a;
}

enc_t avr_nop() {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 0;
	enc.n = 2;
	
	return enc;
}

enc_t avr_movw(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 1;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	
	return enc;
}

enc_t avr_muls(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 2;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	
	return enc;
}

enc_t avr_mulsu(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 3;
	enc.n = 2;
		
	enc.x[0] |= (rs) & 7;
	enc.x[0] |= (rd << 4) & 112;
	
	return enc;
}

enc_t avr_fmul(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 8;
	enc.x[1] = 3;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 7;
	enc.x[0] |= (rd << 4) & 112;
	
	return enc;
}

enc_t avr_fmuls(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 128;
	enc.x[1] = 3;
	enc.n = 2;
		
	enc.x[0] |= (rs) & 7;
	enc.x[0] |= (rd << 4) & 112;
	
	return enc;
}

enc_t avr_fmulsu(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 136;
	enc.x[1] = 3;
	enc.n = 2;
		
	enc.x[0] |= (rs) & 7;
	enc.x[0] |= (rd << 4) & 112;
	
	return enc;
}

enc_t avr_cp(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 20;
	enc.n = 2;
		
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_cpc(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 4;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_sub(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 24;
	enc.n = 2;
		
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_sbc(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 8;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_add(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 12;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_adc(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 28;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_lsl(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 12;
	enc.n = 2;
		
	enc.x[0] |= (rd) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_rol(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 28;
	enc.n = 2;
	
	enc.x[0] |= (rd) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_cpse(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 16;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_and(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 32;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_tst(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 32;
	enc.n = 2;
	
	enc.x[0] |= (rd) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_eor(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 36;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_clr(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 36;
	enc.n = 2;
	
	enc.x[0] |= (rd) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_or(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 40;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_mov(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 44;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_cpi(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 48;
	enc.n = 2;
	
	enc.x[0] |= (k) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (k >> 4) & 15;
	
	return enc;
}

enc_t avr_subi(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 80;
	enc.n = 2;
		
	enc.x[0] |= (k) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (k >> 4) & 15;
	
	return enc;
}

enc_t avr_sbci(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 64;
	enc.n = 2;
		
	enc.x[0] |= (k) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (k >> 4) & 15;
	
	return enc;
}

enc_t avr_ori(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 96;
	enc.n = 2;
	
	enc.x[0] |= (k) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (k >> 4) & 15;
	
	return enc;
}

enc_t avr_sbr(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 96;
	enc.n = 2;
	
	enc.x[0] |= (k) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (k >> 4) & 15;
	
	return enc;
}

enc_t avr_andi(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 112;
	enc.n = 2;
	
	enc.x[0] |= (k) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (k >> 4) & 15;
	
	return enc;
}

enc_t avr_cbr(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 112;
	enc.n = 2;
	
	enc.x[0] |= (~k) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (~k >> 4) & 15;
	
	return enc;
}

enc_t avr_ldi(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 224;
	enc.n = 2;
	
	enc.x[0] |= (k) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (k >> 4) & 15;
	
	return enc;
}

enc_t avr_ldd(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 128;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 2) & 12;
	enc.x[1] |= (rs >> 1) & 32;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_std(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 130;
	enc.n = 2;
		
	enc.x[0] |= (rd) & 15;
	enc.x[0] |= (rs << 4) & 240;
	enc.x[1] |= (rd >> 2) & 12;
	enc.x[1] |= (rd >> 1) & 32;
	enc.x[1] |= (rs >> 4) & 1;
	
	return enc;
}

enc_t avr_lds(uint8_t rd, uint8_t k) {
	enc_t enc;
	//todo
	
	return enc;
}

enc_t avr_sts(uint8_t rd, uint8_t k) {
	enc_t enc;
	//todo
	
	return enc;
}

enc_t avr_ld(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 128;
	enc.n = 2;
		
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs) & 16;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_st(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 130;
	enc.n = 2;
	
	enc.x[0] |= (rd) & 15;
	enc.x[0] |= (rs << 4) & 240;
	enc.x[1] |= (rd) & 16;
	enc.x[1] |= (rs >> 4) & 1;
	
	return enc;
}

enc_t avr_lpm(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 144;
	enc.n = 2;
		
	//todo
	
	return enc;
}

enc_t avr_elpm(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 0;
	enc.n = 2;
		
	//todo
	
	return enc;
}

enc_t avr_xch(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 4;
	enc.x[1] = 146;
	enc.n = 2;
	
	//rd z
	enc.x[0] |= (rs << 4) & 240;
	enc.x[1] |= (rs >> 4) & 1;
	
	return enc;
}

enc_t avr_las(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 5;
	enc.x[1] = 146;
	enc.n = 2;
	
	//rd z
	enc.x[0] |= (rs << 4) & 240;
	enc.x[1] |= (rs >> 4) & 1;
	
	return enc;
}

enc_t avr_lac(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 6;
	enc.x[1] = 146;
	enc.n = 2;
	
	//rd z
	enc.x[0] |= (rs << 4) & 240;
	enc.x[1] |= (rs >> 4) & 1;
	
	return enc;
}

enc_t avr_lat(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 7;
	enc.x[1] = 146;
	enc.n = 2;
	
	//rd z
	enc.x[0] |= (rs << 4) & 240;
	enc.x[1] |= (rs >> 4) & 1;
	
	return enc;
}

enc_t avr_pop(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 15;
	enc.x[1] = 144;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_push(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 15;
	enc.x[1] = 146;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_com(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_neg(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 1;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_swap(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 2;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_inc(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 3;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_dec(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 10;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_asr(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 5;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_lsr(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 6;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_ror(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 7;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_bset(uint8_t b) {
	enc_t enc;
	enc.x[0] = 8;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (b << 4) & 112;
	
	return enc;
}

enc_t avr_sec() {
	enc_t enc;
	enc.x[0] = 8;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_sez() {
	enc_t enc;
	enc.x[0] = 24;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_sen() {
	enc_t enc;
	enc.x[0] = 40;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_sev() {
	enc_t enc;
	enc.x[0] = 56;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_ses() {
	enc_t enc;
	enc.x[0] = 72;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_seh() {
	enc_t enc;
	enc.x[0] = 88;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_set() {
	enc_t enc;
	enc.x[0] = 104;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_sei() {
	enc_t enc;
	enc.x[0] = 120;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_bclr(uint8_t b) {
	enc_t enc;
	enc.x[0] = 136;
	enc.x[1] = 148;
	enc.n = 2;
	
	enc.x[0] |= (b << 4) & 112;
	
	return enc;
}

enc_t avr_clc() {
	enc_t enc;
	enc.x[0] = 136;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_clz() {
	enc_t enc;
	enc.x[0] = 152;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_cln() {
	enc_t enc;
	enc.x[0] = 168;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_clv() {
	enc_t enc;
	enc.x[0] = 184;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_cls() {
	enc_t enc;
	enc.x[0] = 200;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_clh() {
	enc_t enc;
	enc.x[0] = 216;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_clt() {
	enc_t enc;
	enc.x[0] = 232;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_cli() {
	enc_t enc;
	enc.x[0] = 248;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}


enc_t avr_ret() {
	enc_t enc;
	enc.x[0] = 8;
	enc.x[1] = 149;
	enc.n = 2;
	
	return enc;
}

enc_t avr_reti() {
	enc_t enc;
	enc.x[0] = 24;
	enc.x[1] = 149;
	enc.n = 2;
	
	return enc;
}

enc_t avr_sleep() {
	enc_t enc;
	enc.x[0] = 136;
	enc.x[1] = 149;
	enc.n = 2;
	
	return enc;
}

enc_t avr_break() {
	enc_t enc;
	enc.x[0] = 152;
	enc.x[1] = 149;
	enc.n = 2;
	
	return enc;
}

enc_t avr_wdr() {
	enc_t enc;
	enc.x[0] = 168;
	enc.x[1] = 149;
	enc.n = 2;
	
	return enc;
}

enc_t avr_spm() {
	enc_t enc;
	enc.x[0] = 232;
	enc.x[1] = 149;
	enc.n = 2;
	//todo
	
	return enc;
}

enc_t avr_ijmp() {
	enc_t enc;
	enc.x[0] = 9;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_eijmp() {
	enc_t enc;
	enc.x[0] = 25;
	enc.x[1] = 148;
	enc.n = 2;
	
	return enc;
}

enc_t avr_icall() {
	enc_t enc;
	enc.x[0] = 9;
	enc.x[1] = 149;
	enc.n = 2;
	
	return enc;
}

enc_t avr_eicall() {
	enc_t enc;
	enc.x[0] = 25;
	enc.x[1] = 149;
	enc.n = 2;
	
	return enc;
}

enc_t avr_des(uint8_t k) {
	enc_t enc;
	enc.x[0] = 11;
	enc.x[1] = 148;
	enc.n = 2;
		
	enc.x[0] |= (k << 4) & 240;
	
	return enc;
}

enc_t avr_jmp(uint16_t k) {
	enc_t enc;
	enc.x[0] = 12;
	enc.x[1] = 148;
	enc.x[2] = k;
	enc.x[3] = k >> 8;
	enc.n = 4;
	
	return enc;
}

enc_t avr_call(uint16_t k) {
	enc_t enc;
	enc.x[0] = 14;
	enc.x[1] = 148;
	enc.x[2] = k;
	enc.x[3] = k >> 8;
	enc.n = 4;
	
	return enc;
}

enc_t avr_adiw(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 150;
	enc.n = 2;
	
	enc.x[0] |= (k) & 15;
	enc.x[0] |= (k << 2) & 192;
	enc.x[0] |= (avr_r2(rd, err) << 4) & 48;
	
	return enc;
}

enc_t avr_sbiw(uint8_t rd, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 151;
	enc.n = 2;
	
	enc.x[0] |= (k) & 15;
	enc.x[0] |= (k << 2) & 192;
	enc.x[0] |= (avr_r2(rd, err) << 4) & 48;
	
	return enc;
}

enc_t avr_cbi(uint8_t p, uint8_t b) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 152;
	enc.n = 2;
	
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (p << 3) & 248; //todo p
	
	return enc;
}

enc_t avr_sbi(uint8_t p, uint8_t b) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 154;
	enc.n = 2;
	
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (p << 3) & 248; //todo p
	
	return enc;
}

enc_t avr_sbic(uint8_t p, uint8_t b) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 153;
	enc.n = 2;
	
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (p << 3) & 248; //todo p
	
	return enc;
}

enc_t avr_sbis(uint8_t p, uint8_t b) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 155;
	enc.n = 2;
	
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (p << 3) & 248; //todo p
	
	return enc;
}

enc_t avr_mul(uint8_t rd, uint8_t rs) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 156;
	enc.n = 2;
	
	enc.x[0] |= (rs) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rs >> 3) & 2;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_in(uint8_t rd, uint8_t p) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 176;
	enc.n = 2;
	
	enc.x[0] |= (p) & 15; //todo p
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (p >> 3) & 6;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_out(uint8_t rd, uint8_t p) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 184;
	enc.n = 2;
	
	enc.x[0] |= (p) & 15;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (p >> 3) & 6; //todo p
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_rjmp(uint16_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 192;
	enc.n = 2;
	
	enc.x[0] |= (k) & 255;
	enc.x[1] |= (k >> 8) & 15;
	
	return enc;
}

enc_t avr_rcall(uint16_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 208;
	enc.n = 2;
	
	enc.x[0] |= (k) & 255;
	enc.x[1] |= (k >> 8) & 15;
	
	return enc;
}

enc_t avr_ser(uint8_t rd) {
	enc_t enc;
	enc.x[0] = 15;
	enc.x[1] = 239;
	enc.n = 2;
	
	enc.x[0] |= (rd << 4) && 240;
	
	return enc;
}

enc_t avr_brcs(uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 240;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brlo(uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 240;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brcc(uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brsh(uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_breq(uint8_t k) {
	enc_t enc;
	enc.x[0] = 1;
	enc.x[1] = 240;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brne(uint8_t k) {
	enc_t enc;
	enc.x[0] = 1;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brmi(uint8_t k) {
	enc_t enc;
	enc.x[0] = 2;
	enc.x[1] = 240;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brpl(uint8_t k) {
	enc_t enc;
	enc.x[0] = 2;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brvs(uint8_t k) {
	enc_t enc;
	enc.x[0] = 3;
	enc.x[1] = 240;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brvc(uint8_t k) {
	enc_t enc;
	enc.x[0] = 3;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brlt(uint8_t k) {
	enc_t enc;
	enc.x[0] = 4;
	enc.x[1] = 240;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brge(uint8_t k) {
	enc_t enc;
	enc.x[0] = 4;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brhs(uint8_t k) {
	enc_t enc;
	enc.x[0] = 5;
	enc.x[1] = 240;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brhc(uint8_t k) {
	enc_t enc;
	enc.x[0] = 5;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brts(uint8_t k) {
	enc_t enc;
	enc.x[0] = 6;
	enc.x[1] = 240;
	enc.n = 2;
		
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brtc(uint8_t k) {
	enc_t enc;
	enc.x[0] = 6;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brie(uint8_t k) {
	enc_t enc;
	enc.x[0] = 7;
	enc.x[1] = 240;
	enc.n = 2;
		
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brid(uint8_t k) {
	enc_t enc;
	enc.x[0] = 7;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brbs(uint8_t b, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 240;
	enc.n = 2;
	
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_brbc(uint8_t b, uint8_t k) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 244;
	enc.n = 2;
	
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (k << 3) & 248;
	enc.x[1] |= (k >> 5) & 3;
	
	return enc;
}

enc_t avr_bld(uint8_t rd, uint8_t b) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 248;
	enc.n = 2;
	
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_bst(uint8_t rd, uint8_t b) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 250;
	enc.n = 2;
	
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[1] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_sbrc(uint8_t rd, uint8_t b) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 252;
	enc.n = 2;
		
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[0] |= (rd >> 4) & 1;
	
	return enc;
}

enc_t avr_sbrs(uint8_t rd, uint8_t b) {
	enc_t enc;
	enc.x[0] = 0;
	enc.x[1] = 254;
	enc.n = 2;
	
	enc.x[0] |= (b) & 7;
	enc.x[0] |= (rd << 4) & 240;
	enc.x[0] |= (rd >> 4) & 1;
	
	return enc;
}

void avr_init() {
	avr_op[0] = (avr_op_t) avr_nop;
	avr_rd[0] = 0;
	avr_rs[0] = 0;
	
	avr_op[1] = (avr_op_t) avr_movw;
	avr_rd[1] = (avr_reg_t) avr_rw;
	avr_rs[1] = (avr_reg_t) avr_rw;
	
	avr_op[2] = (avr_op_t) avr_muls;
	avr_rd[2] = (avr_reg_t) avr_rw;
	avr_rs[2] = (avr_reg_t) avr_rw;
	
	avr_op[3] = (avr_op_t) avr_mulsu;
	avr_rd[3] = (avr_reg_t) avr_r3;
	avr_rs[3] = (avr_reg_t) avr_r3;
	
	avr_op[4] = (avr_op_t) avr_fmul;
	avr_rd[4] = (avr_reg_t) avr_r3;
	avr_rs[4] = (avr_reg_t) avr_r3;
	
	avr_op[5] = (avr_op_t) avr_fmuls;
	avr_rd[5] = (avr_reg_t) avr_r3;
	avr_rs[5] = (avr_reg_t) avr_r3;
	
	avr_op[6] = (avr_op_t) avr_fmulsu;
	avr_rd[6] = (avr_reg_t) avr_r3;
	avr_rs[6] = (avr_reg_t) avr_r3;
	
	avr_op[7] = (avr_op_t) avr_cp;
	avr_rd[7] = (avr_reg_t) avr_r5;
	avr_rs[7] = (avr_reg_t) avr_r5;
	
	avr_op[8] = (avr_op_t) avr_cpc;
	avr_rd[8] = (avr_reg_t) avr_r5;
	avr_rs[8] = (avr_reg_t) avr_r5;
	
	avr_op[9] = (avr_op_t) avr_sub;
	avr_rd[9] = (avr_reg_t) avr_r5;
	avr_rs[9] = (avr_reg_t) avr_r5;
	
	avr_op[9] = (avr_op_t) avr_sbc;
	avr_rd[9] = (avr_reg_t) avr_r5;
	avr_rs[9] = (avr_reg_t) avr_r5;
	
	avr_op[10] = (avr_op_t) avr_add;
	avr_rd[10] = (avr_reg_t) avr_r5;
	avr_rs[10] = (avr_reg_t) avr_r5;
	
	avr_op[11] = (avr_op_t) avr_adc;
	avr_rd[11] = (avr_reg_t) avr_r5;
	avr_rs[11] = (avr_reg_t) avr_r5;
	
	avr_op[12] = (avr_op_t) avr_lsl;
	avr_rd[12] = (avr_reg_t) avr_r5;
	avr_rs[12] = 0;
	
	avr_op[13] = (avr_op_t) avr_rol;
	avr_rd[13] = (avr_reg_t) avr_r5;
	avr_rs[13] = 0;
	
	avr_op[14] = (avr_op_t) avr_cpse;
	avr_rd[14] = (avr_reg_t) avr_r5;
	avr_rs[14] = (avr_reg_t) avr_r5;
	
	avr_op[15] = (avr_op_t) avr_and;
	avr_rd[15] = (avr_reg_t) avr_r5;
	avr_rs[15] = (avr_reg_t) avr_r5;
	
	avr_op[16] = (avr_op_t) avr_eor;
	avr_rd[16] = (avr_reg_t) avr_r5;
	avr_rs[16] = (avr_reg_t) avr_r5;
	
	avr_op[17] = (avr_op_t) avr_or;
	avr_rd[17] = (avr_reg_t) avr_r5;
	avr_rs[17] = (avr_reg_t) avr_r5;
	
	avr_op[18] = (avr_op_t) avr_mov;
	avr_rd[18] = (avr_reg_t) avr_r5;
	avr_rs[18] = (avr_reg_t) avr_r5;
	
	avr_op[19] = (avr_op_t) avr_cpi;
	avr_rd[19] = (avr_reg_t) avr_r4;
	avr_rs[19] = (avr_reg_t) au_strint;
	
	avr_op[20] = (avr_op_t) avr_subi;
	avr_rd[20] = (avr_reg_t) avr_r4;
	avr_rs[20] = (avr_reg_t) au_strint;
	
	avr_op[21] = (avr_op_t) avr_sbci;
	avr_rd[21] = (avr_reg_t) avr_r4;
	avr_rs[21] = (avr_reg_t) au_strint;
	
	avr_op[22] = (avr_op_t) avr_ori;
	avr_rd[22] = (avr_reg_t) avr_r4;
	avr_rs[22] = (avr_reg_t) au_strint;
	
	avr_op[23] = (avr_op_t) avr_sbr;
	avr_rd[23] = (avr_reg_t) avr_r4;
	avr_rs[23] = (avr_reg_t) au_strint;
	
	avr_op[24] = (avr_op_t) avr_andi;
	avr_rd[24] = (avr_reg_t) avr_r4;
	avr_rs[24] = (avr_reg_t) au_strint;
	
	avr_op[25] = (avr_op_t) avr_cbr;
	avr_rd[25] = (avr_reg_t) avr_r4;
	avr_rs[25] = (avr_reg_t) au_strint;
	
	avr_op[26] = (avr_op_t) avr_ldd;
	avr_rd[26] = (avr_reg_t) avr_r5;
	avr_rs[26] = (avr_reg_t) avr_d6;
	
	avr_op[27] = (avr_op_t) avr_std;
	avr_rd[27] = (avr_reg_t) avr_d6;
	avr_rs[27] = (avr_reg_t) avr_r5;
	
	avr_op[28] = (avr_op_t) avr_lds;
	
	avr_op[29] = (avr_op_t) avr_sts;
	
	avr_op[30] = (avr_op_t) avr_ld;
	avr_rd[30] = (avr_reg_t) avr_r5;
	avr_rs[30] = (avr_reg_t) avr_rex;
	
	avr_op[31] = (avr_op_t) avr_ld;
	avr_rd[31] = (avr_reg_t) avr_rex;
	avr_rs[31] = (avr_reg_t) avr_r5;
	
	avr_op[32] = (avr_op_t) avr_lpm;
	
	avr_op[33] = (avr_op_t) avr_elpm;
	
	avr_op[34] = (avr_op_t) avr_xch;
	avr_rd[34] = (avr_reg_t) avr_r5;
	avr_rs[34] = (avr_reg_t) avr_r5;
	
	avr_op[35] = (avr_op_t) avr_las;
	avr_rd[35] = (avr_reg_t) avr_r5;
	avr_rs[35] = (avr_reg_t) avr_r5;
	
	avr_op[36] = (avr_op_t) avr_lac;
	avr_rd[36] = (avr_reg_t) avr_r5;
	avr_rs[36] = (avr_reg_t) avr_r5;
	
	avr_op[37] = (avr_op_t) avr_lat;
	avr_rd[37] = (avr_reg_t) avr_r5;
	avr_rs[37] = (avr_reg_t) avr_r5;
	
	avr_op[38] = (avr_op_t) avr_pop;
	avr_rd[38] = (avr_reg_t) avr_r5;
	avr_rs[38] = 0;
	
	avr_op[39] = (avr_op_t) avr_push;
	avr_rd[39] = (avr_reg_t) avr_r5;
	avr_rs[39] = 0;
	
	avr_op[40] = (avr_op_t) avr_com;
	avr_rd[40] = (avr_reg_t) avr_r5;
	avr_rs[40] = 0;
	
	avr_op[41] = (avr_op_t) avr_neg;
	avr_rd[41] = (avr_reg_t) avr_r5;
	avr_rs[41] = 0;
	
	avr_op[42] = (avr_op_t) avr_swap;
	avr_rd[42] = (avr_reg_t) avr_r5;
	avr_rs[42] = 0;
	
	avr_op[43] = (avr_op_t) avr_inc;
	avr_rd[43] = (avr_reg_t) avr_r5;
	avr_rs[43] = 0;
	
	avr_op[44] = (avr_op_t) avr_dec;
	avr_rd[44] = (avr_reg_t) avr_r5;
	avr_rs[44] = 0;
	
	avr_op[45] = (avr_op_t) avr_asr;
	avr_rd[45] = (avr_reg_t) avr_r5;
	avr_rs[45] = 0;
	
	avr_op[46] = (avr_op_t) avr_lsr;
	avr_rd[46] = (avr_reg_t) avr_r5;
	avr_rs[46] = 0;
	
	avr_op[47] = (avr_op_t) avr_ror;
	avr_rd[47] = (avr_reg_t) avr_r5;
	avr_rs[47] = 0;
}

