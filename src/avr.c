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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
}

void avr_enc_r3(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 23) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_enc_r4(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 32) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_enc_r5(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 23) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_enc_r4w(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r % 2) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_enc_rp(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r != 26 && r != 28 && r != 30) {
		printf("[%s, %lu] error: illegal register '%u'\n", path, ln, r);
		*e = -1;
	}
}

void avr_enc_nop(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 0;
	bin[*bn + 1] = 0;
	
	*bn += 2;
}

void avr_movw(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 1;
	
	rd /= 2;
	rs /= 2;
	
	bin[*bn] |= (rs) & 15;
	bin[*bn] |= (rd << 4) & 240;
	
	*bn += 2;
}

uint64_t avr_muls(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 2;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	
	return bn + 2;
}

uint64_t avr_mulsu(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 3;
		
	bin[bn] |= (rs) & 7;
	bin[bn] |= (rd << 4) & 112;
	
	return bn + 2;
}

uint64_t avr_fmul(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 8;
	bin[bn + 1] = 3;
	
	bin[bn] |= (rs) & 7;
	bin[bn] |= (rd << 4) & 112;
	
	return bn + 2;
}

uint64_t avr_fmuls(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 128;
	bin[bn + 1] = 3;
		
	bin[bn] |= (rs) & 7;
	bin[bn] |= (rd << 4) & 112;
	
	return bn + 2;
}

uint64_t avr_fmulsu(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 136;
	bin[bn + 1] = 3;
		
	bin[bn] |= (rs) & 7;
	bin[bn] |= (rd << 4) & 112;
	
	return bn + 2;
}

uint64_t avr_cp(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 20;
		
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_cpc(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 4;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_sub(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 24;
		
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_sbc(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 8;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_add(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 12;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_adc(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 28;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_lsl(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 0;
	bin[bn + 1] = 12;
		
	bin[bn] |= (rd) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_rol(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 0;
	bin[bn + 1] = 28;
	
	bin[bn] |= (rd) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_cpse(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 16;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_and(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 32;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_tst(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 0;
	bin[bn + 1] = 32;
	
	bin[bn] |= (rd) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_eor(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 36;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_clr(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 0;
	bin[bn + 1] = 36;
	
	bin[bn] |= (rd) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_or(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 40;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_mov(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 44;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_cpi(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 48;
	
	bin[bn] |= (k) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (k >> 4) & 15;
	
	return bn + 2;
}

uint64_t avr_subi(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 80;
		
	bin[bn] |= (k) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (k >> 4) & 15;
	
	return bn + 2;
}

uint64_t avr_sbci(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 64;
		
	bin[bn] |= (k) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (k >> 4) & 15;
	
	return bn + 2;
}

uint64_t avr_ori(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 96;
	
	bin[bn] |= (k) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (k >> 4) & 15;
	
	return bn + 2;
}

uint64_t avr_sbr(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 96;
	
	bin[bn] |= (k) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (k >> 4) & 15;
	
	return bn + 2;
}

uint64_t avr_andi(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 112;
	
	bin[bn] |= (k) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (k >> 4) & 15;
	
	return bn + 2;
}

uint64_t avr_cbr(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 112;
	
	bin[bn] |= (~k) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (~k >> 4) & 15;
	
	return bn + 2;
}

uint64_t avr_ldi(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 224;
	
	bin[bn] |= (k) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (k >> 4) & 15;
	
	return bn + 2;
}

uint64_t avr_ldd(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 128;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 2) & 12;
	bin[bn + 1] |= (rs >> 1) & 32;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_std(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 130;
		
	bin[bn] |= (rd) & 15;
	bin[bn] |= (rs << 4) & 240;
	bin[bn + 1] |= (rd >> 2) & 12;
	bin[bn + 1] |= (rd >> 1) & 32;
	bin[bn + 1] |= (rs >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_lds(uint8_t* bin, uint64_t bn, uint8_t rd, uint16_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 144;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	bin[bn + 2] = k;
	bin[bn + 3] = k >> 8;
	
	return bn + 4;
}

uint64_t avr_sts(uint8_t* bin, uint64_t bn, uint8_t k, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 146;
	
	bin[bn] |= (rs << 4) & 240;
	bin[bn + 1] |= (rs >> 4) & 1;
	bin[bn + 2] = k;
	bin[bn + 3] = k >> 8;
	
	return bn + 4;
}

uint64_t avr_ld(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 128;
		
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs) & 16;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_st(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 130;
	
	bin[bn] |= (rd) & 15;
	bin[bn] |= (rs << 4) & 240;
	bin[bn + 1] |= (rd) & 16;
	bin[bn + 1] |= (rs >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_lpm(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 4;
	bin[bn + 1] = 144;
	//todo
	bin[bn] |= (rs) & 1;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_elpm(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 6;
	bin[bn + 1] = 144;
	//todo
	bin[bn] |= (rs) & 1;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_xch(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 4;
	bin[bn + 1] = 146;
	
	bin[bn] |= (rs << 4) & 240;
	bin[bn + 1] |= (rs >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_las(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 5;
	bin[bn + 1] = 146;
	
	bin[bn] |= (rs << 4) & 240;
	bin[bn + 1] |= (rs >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_lac(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 6;
	bin[bn + 1] = 146;
	
	bin[bn] |= (rs << 4) & 240;
	bin[bn + 1] |= (rs >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_lat(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 7;
	bin[bn + 1] = 146;
	
	bin[bn] |= (rs << 4) & 240;
	bin[bn + 1] |= (rs >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_pop(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 15;
	bin[bn + 1] = 144;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_push(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 15;
	bin[bn + 1] = 146;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_com(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 0;
	bin[bn + 1] = 148;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_neg(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 1;
	bin[bn + 1] = 148;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_swap(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 2;
	bin[bn + 1] = 148;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_inc(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 3;
	bin[bn + 1] = 148;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_dec(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 10;
	bin[bn + 1] = 148;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_asr(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 5;
	bin[bn + 1] = 148;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_lsr(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 6;
	bin[bn + 1] = 148;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_ror(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 7;
	bin[bn + 1] = 148;
	
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_bset(uint8_t* bin, uint64_t bn, uint8_t b) {
	bin[bn] = 8;
	bin[bn + 1] = 148;
	
	bin[bn] |= (b << 4) & 112;
	
	return bn + 2;
}

uint64_t avr_sec(uint8_t* bin, uint64_t bn) {
	bin[bn] = 8;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_sez(uint8_t* bin, uint64_t bn) {
	bin[bn] = 24;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_sen(uint8_t* bin, uint64_t bn) {
	bin[bn] = 40;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_sev(uint8_t* bin, uint64_t bn) {
	bin[bn] = 56;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_ses(uint8_t* bin, uint64_t bn) {
	bin[bn] = 72;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_seh(uint8_t* bin, uint64_t bn) {
	bin[bn] = 88;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_set(uint8_t* bin, uint64_t bn) {
	bin[bn] = 104;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_sei(uint8_t* bin, uint64_t bn) {
	bin[bn] = 120;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_bclr(uint8_t* bin, uint64_t bn, uint8_t b) {
	bin[bn] = 136;
	bin[bn + 1] = 148;
	
	bin[bn] |= (b << 4) & 112;
	
	return bn + 2;
}

uint64_t avr_clc(uint8_t* bin, uint64_t bn) {
	bin[bn] = 136;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_clz(uint8_t* bin, uint64_t bn) {
	bin[bn] = 152;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_cln(uint8_t* bin, uint64_t bn) {
	bin[bn] = 168;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_clv(uint8_t* bin, uint64_t bn) {
	bin[bn] = 184;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_cls(uint8_t* bin, uint64_t bn) {
	bin[bn] = 200;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_clh(uint8_t* bin, uint64_t bn) {
	bin[bn] = 216;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_clt(uint8_t* bin, uint64_t bn) {
	bin[bn] = 232;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_cli(uint8_t* bin, uint64_t bn) {
	bin[bn] = 248;
	bin[bn + 1] = 148;
	
	return bn + 2;
}


uint64_t avr_ret(uint8_t* bin, uint64_t bn) {
	bin[bn] = 8;
	bin[bn + 1] = 149;
	
	return bn + 2;
}

uint64_t avr_reti(uint8_t* bin, uint64_t bn) {
	bin[bn] = 24;
	bin[bn + 1] = 149;
	
	return bn + 2;
}

uint64_t avr_sleep(uint8_t* bin, uint64_t bn) {
	bin[bn] = 136;
	bin[bn + 1] = 149;
	
	return bn + 2;
}

uint64_t avr_break(uint8_t* bin, uint64_t bn) {
	bin[bn] = 152;
	bin[bn + 1] = 149;
	
	return bn + 2;
}

uint64_t avr_wdr(uint8_t* bin, uint64_t bn) {
	bin[bn] = 168;
	bin[bn + 1] = 149;
	
	return bn + 2;
}

uint64_t avr_spm(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 232;
	bin[bn + 1] = 149;
	
	bin[bn] |= (rd << 4) & 16;
	
	return bn + 2;
}

uint64_t avr_ijmp(uint8_t* bin, uint64_t bn) {
	bin[bn] = 9;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_eijmp(uint8_t* bin, uint64_t bn) {
	bin[bn] = 25;
	bin[bn + 1] = 148;
	
	return bn + 2;
}

uint64_t avr_icall(uint8_t* bin, uint64_t bn) {
	bin[bn] = 9;
	bin[bn + 1] = 149;
	
	return bn + 2;
}

uint64_t avr_eicall(uint8_t* bin, uint64_t bn) {
	bin[bn] = 25;
	bin[bn + 1] = 149;
	
	return bn + 2;
}

uint64_t avr_des(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 11;
	bin[bn + 1] = 148;
		
	bin[bn] |= (k << 4) & 240;
	
	return bn + 2;
}

uint64_t avr_jmp(uint8_t* bin, uint64_t bn, uint16_t k) {
	bin[bn] = 12;
	bin[bn + 1] = 148;
	bin[bn + 2] = k;
	bin[bn + 3] = k >> 8;
	
	return bn + 4;
}

uint64_t avr_call(uint8_t* bin, uint64_t bn, uint16_t k) {
	bin[bn] = 14;
	bin[bn + 1] = 148;
	bin[bn + 2] = k;
	bin[bn + 3] = k >> 8;
	
	return bn + 4;
}

uint64_t avr_adiw(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 150;
	
	bin[bn] |= (k) & 15;
	bin[bn] |= (k << 2) & 192;
	bin[bn] |= (rd << 4) & 48;
	
	return bn + 2;
}

uint64_t avr_sbiw(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 151;
	
	bin[bn] |= (k) & 15;
	bin[bn] |= (k << 2) & 192;
	bin[bn] |= (rd << 4) & 48;
	
	return bn + 2;
}

uint64_t avr_cbi(uint8_t* bin, uint64_t bn, uint8_t p, uint8_t b) {
	bin[bn] = 0;
	bin[bn + 1] = 152;
	
	bin[bn] |= (b) & 7;
	bin[bn] |= (p << 3) & 248;
	
	return bn + 2;
}

uint64_t avr_sbi(uint8_t* bin, uint64_t bn, uint8_t p, uint8_t b) {
	bin[bn] = 0;
	bin[bn + 1] = 154;
	
	bin[bn] |= (b) & 7;
	bin[bn] |= (p << 3) & 248;
	
	return bn + 2;
}

uint64_t avr_sbic(uint8_t* bin, uint64_t bn, uint8_t p, uint8_t b) {
	bin[bn] = 0;
	bin[bn + 1] = 153;
	
	bin[bn] |= (b) & 7;
	bin[bn] |= (p << 3) & 248;
	
	return bn + 2;
}

uint64_t avr_sbis(uint8_t* bin, uint64_t bn, uint8_t p, uint8_t b) {
	bin[bn] = 0;
	bin[bn + 1] = 155;
	
	bin[bn] |= (b) & 7;
	bin[bn] |= (p << 3) & 248;
	
	return bn + 2;
}

uint64_t avr_mul(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 156;
	
	bin[bn] |= (rs) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rs >> 3) & 2;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_in(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t p) {
	bin[bn] = 0;
	bin[bn + 1] = 176;
	
	bin[bn] |= (p) & 15;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (p >> 3) & 6;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_out(uint8_t* bin, uint64_t bn, uint8_t p, uint8_t rs) {
	bin[bn] = 0;
	bin[bn + 1] = 184;
	
	bin[bn] |= (p) & 15;
	bin[bn] |= (rs << 4) & 240;
	bin[bn + 1] |= (p >> 3) & 6;
	bin[bn + 1] |= (rs >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_rjmp(uint8_t* bin, uint64_t bn, uint16_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 192;
	
	bin[bn] |= (k) & 255;
	bin[bn + 1] |= (k >> 8) & 15;
	
	return bn + 2;
}

uint64_t avr_rcall(uint8_t* bin, uint64_t bn, uint16_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 208;
	
	bin[bn] |= (k) & 255;
	bin[bn + 1] |= (k >> 8) & 15;
	
	return bn + 2;
}

uint64_t avr_ser(uint8_t* bin, uint64_t bn, uint8_t rd) {
	bin[bn] = 15;
	bin[bn + 1] = 239;
	
	bin[bn] |= (rd << 4) && 240;
	
	return bn + 2;
}

uint64_t avr_brcs(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 240;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brlo(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 240;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brcc(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 244;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brsh(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 244;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_breq(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 1;
	bin[bn + 1] = 240;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brne(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 1;
	bin[bn + 1] = 244;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brmi(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 2;
	bin[bn + 1] = 240;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brpl(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 2;
	bin[bn + 1] = 244;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brvs(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 3;
	bin[bn + 1] = 240;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brvc(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 3;
	bin[bn + 1] = 244;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brlt(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 4;
	bin[bn + 1] = 240;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brge(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 4;
	bin[bn + 1] = 244;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brhs(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 5;
	bin[bn + 1] = 240;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brhc(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 5;
	bin[bn + 1] = 244;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brts(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 6;
	bin[bn + 1] = 240;
		
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brtc(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 6;
	bin[bn + 1] = 244;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brie(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 7;
	bin[bn + 1] = 240;
		
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brid(uint8_t* bin, uint64_t bn, uint8_t k) {
	bin[bn] = 7;
	bin[bn + 1] = 244;
	
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brbs(uint8_t* bin, uint64_t bn, uint8_t b, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 240;
	
	bin[bn] |= (b) & 7;
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_brbc(uint8_t* bin, uint64_t bn, uint8_t b, uint8_t k) {
	bin[bn] = 0;
	bin[bn + 1] = 244;
	
	bin[bn] |= (b) & 7;
	bin[bn] |= (k << 3) & 248;
	bin[bn + 1] |= (k >> 5) & 3;
	
	return bn + 2;
}

uint64_t avr_bld(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t b) {
	bin[bn] = 0;
	bin[bn + 1] = 248;
	
	bin[bn] |= (b) & 7;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_bst(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t b) {
	bin[bn] = 0;
	bin[bn + 1] = 250;
	
	bin[bn] |= (b) & 7;
	bin[bn] |= (rd << 4) & 240;
	bin[bn + 1] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_sbrc(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t b) {
	bin[bn] = 0;
	bin[bn + 1] = 252;
		
	bin[bn] |= (b) & 7;
	bin[bn] |= (rd << 4) & 240;
	bin[bn] |= (rd >> 4) & 1;
	
	return bn + 2;
}

uint64_t avr_sbrs(uint8_t* bin, uint64_t bn, uint8_t rd, uint8_t b) {
	bin[bn] = 0;
	bin[bn + 1] = 254;
	
	bin[bn] |= (b) & 7;
	bin[bn] |= (rd << 4) & 240;
	bin[bn] |= (rd >> 4) & 1;
	
	return bn + 2;
}

void avr_op(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'n' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			avr_enc_nop(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "nop");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			avr_enc_r4w(rv[0], e, path, ln);
			avr_enc_r4w(rv[1], e, path, ln);
			avr_movw(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "nop");
			*e = -1;
		}
	}
	/*else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 's' && op[4] == 0) {
		avr.op = (avr_op_f) avr_muls;
		avr.rd = (avr_reg_f) avr_rw;
		avr.rs = (avr_reg_f) avr_rw;
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 's' && op[4] == 'u' && op[5] == 0) {
		avr.op = (avr_op_f) avr_mulsu;
		avr.rd = (avr_reg_f) avr_r3;
		avr.rs = (avr_reg_f) avr_r3;
	}
	else if (op[0] == 'f' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 0) {
		avr.op = (avr_op_f) avr_fmul;
		avr.rd = (avr_reg_f) avr_r3;
		avr.rs = (avr_reg_f) avr_r3;
	}
	else if (op[0] == 'f' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 's' && op[5] == 0) {
		avr.op = (avr_op_f) avr_fmuls;
		avr.rd = (avr_reg_f) avr_r3;
		avr.rs = (avr_reg_f) avr_r3;
	}
	else if (op[0] == 'f' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 's' && op[5] == 'u' && op[6] == 0) {
		avr.op = (avr_op_f) avr_fmulsu;
		avr.rd = (avr_reg_f) avr_r3;
		avr.rs = (avr_reg_f) avr_r3;
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 0) {
		avr.op = (avr_op_f) avr_cp;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 'c' && op[3] == 0) {
		avr.op = (avr_op_f) avr_cpc;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sub;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sbc;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		avr.op = (avr_op_f) avr_add;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		avr.op = (avr_op_f) avr_adc;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 0) {
		avr.op = (avr_op_f) avr_lsl;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'l' && op[3] == 0) {
		avr.op = (avr_op_f) avr_rol;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 's' && op[3] == 'e' && op[4] == 0) {
		avr.op = (avr_op_f) avr_cpse;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		avr.op = (avr_op_f) avr_and;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 't' && op[1] == 's' && op[2] == 't' && op[3] == 0) {
		avr.op = (avr_op_f) avr_tst;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		avr.op = (avr_op_f) avr_eor;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'r' && op[3] == 0) {
		avr.op = (avr_op_f) avr_clr;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 0) {
		avr.op = (avr_op_f) avr_or;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		avr.op = (avr_op_f) avr_mov;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 'i' && op[3] == 0) {
		avr.op = (avr_op_f) avr_cpi;
		avr.rd = (avr_reg_f) avr_r4;
		avr.rs = (avr_reg_f) avr_i8;
		avr.rel = 19;
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'i' && op[4] == 0) {
		avr.op = (avr_op_f) avr_subi;
		avr.rd = (avr_reg_f) avr_r4;
		avr.rs = (avr_reg_f) avr_i8;
		avr.rel = 19;
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 'i' && op[4] == 0) {
		avr.op = (avr_op_f) avr_sbci;
		avr.rd = (avr_reg_f) avr_r4;
		avr.rs = (avr_reg_f) avr_i8;
		avr.rel = 19;
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'i' && op[3] == 0) {
		avr.op = (avr_op_f) avr_ori;
		avr.rd = (avr_reg_f) avr_r4;
		avr.rs = (avr_reg_f) avr_i8;
		avr.rel = 19;
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'r' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sbr;
		avr.rd = (avr_reg_f) avr_r4;
		avr.rs = (avr_reg_f) avr_i8;
		avr.rel = 19;
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 'i' && op[4] == 0) {
		avr.op = (avr_op_f) avr_andi;
		avr.rd = (avr_reg_f) avr_r4;
		avr.rs = (avr_reg_f) avr_i8;
		avr.rel = 19;
	}
	else if (op[0] == 'c' && op[1] == 'b' && op[2] == 'r' && op[3] == 0) {
		avr.op = (avr_op_f) avr_cbr;
		avr.rd = (avr_reg_f) avr_r4;
		avr.rs = (avr_reg_f) avr_i8;
		avr.rel = 19;
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'i' && op[3] == 0) {
		avr.op = (avr_op_f) avr_ldi;
		avr.rd = (avr_reg_f) avr_r4;
		avr.rs = (avr_reg_f) avr_i8;
		avr.rel = 19;
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		avr.op = (avr_op_f) avr_ldd;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_d6;
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'd' && op[3] == 0) {
		avr.op = (avr_op_f) avr_std;
		avr.rd = (avr_reg_f) avr_d6;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 's' && op[3] == 0) {
		avr.op = (avr_op_f) avr_lds;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_i16;
		avr.rel = 4;
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 's' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sts;
		avr.rd = (avr_reg_f) avr_i16;
		avr.rs = (avr_reg_f) avr_r5;
		avr.rel = 4;
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 0) {
		avr.op = (avr_op_f) avr_ld;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_rex;
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 0) {
		avr.op = (avr_op_f) avr_st;
		avr.rd = (avr_reg_f) avr_rex;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'l' && op[1] == 'p' && op[2] == 'm' && op[3] == 0) {
		avr.op = (avr_op_f) avr_lpm;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_z1;
	}
	else if (op[0] == 'e' && op[1] == 'l' && op[2] == 'p' && op[3] == 'm' && op[4] == 0) {
		avr.op = (avr_op_f) avr_elpm;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_z1;
	}
	else if (op[0] == 'x' && op[1] == 'c' && op[2] == 'h' && op[3] == 0) {
		avr.op = (avr_op_f) avr_xch;
		avr.rd = (avr_reg_f) avr_z0;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 's' && op[3] == 0) {
		avr.op = (avr_op_f) avr_las;
		avr.rd = (avr_reg_f) avr_z0;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 'c' && op[3] == 0) {
		avr.op = (avr_op_f) avr_lac;
		avr.rd = (avr_reg_f) avr_z0;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 't' && op[3] == 0) {
		avr.op = (avr_op_f) avr_lat;
		avr.rd = (avr_reg_f) avr_z0;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		avr.op = (avr_op_f) avr_pop;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		avr.op = (avr_op_f) avr_push;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'c' && op[1] == 'o' && op[2] == 'm' && op[3] == 0) {
		avr.op = (avr_op_f) avr_com;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'n' && op[1] == 'e' && op[2] == 'g' && op[3] == 0) {
		avr.op = (avr_op_f) avr_neg;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'w' && op[2] == 'a' && op[3] == 'p' && op[4] == 0) {
		avr.op = (avr_op_f) avr_swap;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		avr.op = (avr_op_f) avr_inc;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) {
		avr.op = (avr_op_f) avr_dec;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		avr.op = (avr_op_f) avr_asr;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		avr.op = (avr_op_f) avr_lsr;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		avr.op = (avr_op_f) avr_ror;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = 0;
	}
	else if (op[0] == 'b' && op[1] == 's' && op[2] == 'e' && op[3] == 't' && op[4] == 0) {
		avr.op = (avr_op_f) avr_bset;
		avr.rd = (avr_reg_f) avr_b3;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sec;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'z' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sez;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'n' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sen;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'v' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sev;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 's' && op[3] == 0) {
		avr.op = (avr_op_f) avr_ses;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'h' && op[3] == 0) {
		avr.op = (avr_op_f) avr_seh;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 't' && op[3] == 0) {
		avr.op = (avr_op_f) avr_set;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'i' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sei;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'b' && op[1] == 'c' && op[2] == 'l' && op[3] == 'r' && op[4] == 0) {
		avr.op = (avr_op_f) avr_bclr;
		avr.rd = (avr_reg_f) avr_b3;
		avr.rs = 0;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'c' && op[3] == 0) {
		avr.op = (avr_op_f) avr_clc;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'z' && op[3] == 0) {
		avr.op = (avr_op_f) avr_clz;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'n' && op[3] == 0) {
		avr.op = (avr_op_f) avr_cln;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		avr.op = (avr_op_f) avr_clv;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 's' && op[3] == 0) {
		avr.op = (avr_op_f) avr_cls;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 'h' && op[3] == 0) {
		avr.op = (avr_op_f) avr_clh;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 't' && op[3] == 0) {
		avr.op = (avr_op_f) avr_clt;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 'i' && op[3] == 0) {
		avr.op = (avr_op_f) avr_cli;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 't' && op[3] == 0) {
		avr.op = (avr_op_f) avr_ret;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 't' && op[3] == 'i' && op[4] == 0) {
		avr.op = (avr_op_f) avr_reti;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'l' && op[2] == 'e' && op[3] == 'e' && op[4] == 'p' && op[5] == 0) {
		avr.op = (avr_op_f) avr_sleep;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'e' && op[3] == 'a' && op[4] == 'k' && op[5] == 0) {
		avr.op = (avr_op_f) avr_break;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'w' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		avr.op = (avr_op_f) avr_wdr;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 's' && op[1] == 'p' && op[2] == 'm' && op[3] == 0) {
		avr.op = (avr_op_f) avr_spm;
		avr.rd = (avr_reg_f) avr_z0;
		avr.rs = 0;
	}
	else if (op[0] == 'i' && op[1] == 'j' && op[2] == 'm' && op[3] == 'p' && op[4] == 0) {
		avr.op = (avr_op_f) avr_ijmp;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'e' && op[1] == 'i' && op[2] == 'j' && op[3] == 'm' && op[4] == 'p' && op[5] == 0) {
		avr.op = (avr_op_f) avr_eijmp;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'i' && op[1] == 'c' && op[2] == 'a' && op[3] == 'l' && op[4] == 'l' && op[5] == 0) {
		avr.op = (avr_op_f) avr_icall;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'e' && op[1] == 'i' && op[2] == 'c' && op[3] == 'a' && op[4] == 'l' && op[5] == 'l' && op[6] == 0) {
		avr.op = (avr_op_f) avr_eicall;
		avr.rd = 0;
		avr.rs = 0;
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 's' && op[3] == 0) {
		avr.op = (avr_op_f) avr_des;
		avr.rd = (avr_reg_f) avr_i4;
		avr.rs = 0;
	}
	else if (op[0] == 'j' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		avr.op = (avr_op_f) avr_jmp;
		avr.rd = (avr_reg_f) avr_i16;
		avr.rs = 0;
		avr.rel = 18;
	}
	else if (op[0] == 'c' && op[1] == 'a' && op[2] == 'l' && op[3] == 'l' && op[4] == 0) {
		avr.op = (avr_op_f) avr_call;
		avr.rd = (avr_reg_f) avr_i16;
		avr.rs = 0;
		avr.rel = 18;
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'i' && op[3] == 'w' && op[4] == 0) {
		avr.op = (avr_op_f) avr_adiw;
		avr.rd = (avr_reg_f) avr_r2;
		avr.rs = (avr_reg_f) avr_i6;
		avr.rel = 21;
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 'w' && op[4] == 0) {
		avr.op = (avr_op_f) avr_sbiw;
		avr.rd = (avr_reg_f) avr_r2;
		avr.rs = (avr_reg_f) avr_i6;
		avr.rel = 21;
	}
	else if (op[0] == 'c' && op[1] == 'b' && op[2] == 'i' && op[3] == 0) {
		avr.op = (avr_op_f) avr_cbi;
		avr.rd = (avr_reg_f) avr_p5;
		avr.rs = (avr_reg_f) avr_b3;
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 0) {
		avr.op = (avr_op_f) avr_sbi;
		avr.rd = (avr_reg_f) avr_p5;
		avr.rs = (avr_reg_f) avr_b3;
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 'c' && op[4] == 0) {
		avr.op = (avr_op_f) avr_sbic;
		avr.rd = (avr_reg_f) avr_p5;
		avr.rs = (avr_reg_f) avr_b3;
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'i' && op[3] == 's') {
		avr.op = (avr_op_f) avr_sbis;
		avr.rd = (avr_reg_f) avr_p5;
		avr.rs = (avr_reg_f) avr_b3;
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 0) {
		avr.op = (avr_op_f) avr_mul;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 0) {
		avr.op = (avr_op_f) avr_in;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_p6;
	}
	else if (op[0] == 'o' && op[1] == 'u' && op[2] == 't' && op[3] == 0) {
		avr.op = (avr_op_f) avr_out;
		avr.rd = (avr_reg_f) avr_p6;
		avr.rs = (avr_reg_f) avr_r5;
	}
	else if (op[0] == 'r' && op[1] == 'j' && op[2] == 'm' && op[3] == 'p' && op[4] == 0) {
		avr.op = (avr_op_f) avr_rjmp;
		avr.rd = (avr_reg_f) avr_i16;
		avr.rs = 0;
		avr.rel = 3;
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'a' && op[3] == 'l' && op[4] == 'l' && op[5] == 0) {
		avr.op = (avr_op_f) avr_rcall;
		avr.rd = (avr_reg_f) avr_i16;
		avr.rs = 0;
		avr.rel = 3;
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'r' && op[3] == 0) {
		avr.op = (avr_op_f) avr_ser;
		avr.rd = (avr_reg_f) avr_r4;
		avr.rs = 0;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'c' && op[3] == 's' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brcs;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'l' && op[3] == 'o' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brlo;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'c' && op[3] == 'c' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brcc;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brsh;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'e' && op[3] == 'q' && op[4] == 0) {
		avr.op = (avr_op_f) avr_breq;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'n' && op[3] == 'e' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brne;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'm' && op[3] == 'i' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brmi;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'p' && op[3] == 'l' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brpl;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'v' && op[3] == 's' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brvs;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'v' && op[3] == 'c' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brvc;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'l' && op[3] == 't' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brlt;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'g' && op[3] == 'e' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brge;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'h' && op[3] == 's' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brhs;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'h' && op[3] == 'c' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brhc;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 't' && op[3] == 's' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brts;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 't' && op[3] == 'c' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brtc;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'i' && op[3] == 'e' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brie;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'i' && op[3] == 'd' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brid;
		avr.rd = (avr_reg_f) avr_i7;
		avr.rs = 0;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'b' && op[3] == 's' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brbs;
		avr.rd = (avr_reg_f) avr_b3;
		avr.rs = (avr_reg_f) avr_i7;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'b' && op[3] == 'c' && op[4] == 0) {
		avr.op = (avr_op_f) avr_brbc;
		avr.rd = (avr_reg_f) avr_b3;
		avr.rs = (avr_reg_f) avr_i7;
		avr.rel = 2;
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'd' && op[3] == 0) {
		avr.op = (avr_op_f) avr_bld;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_b3;
	}
	else if (op[0] == 'b' && op[1] == 's' && op[2] == 't' && op[3] == 0) {
		avr.op = (avr_op_f) avr_bst;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_b3;
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'r' && op[3] == 'c' && op[4] == 0) {
		avr.op = (avr_op_f) avr_sbrc;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_b3;
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'r' && op[3] == 's' && op[4] == 0) {
		avr.op = (avr_op_f) avr_sbrs;
		avr.rd = (avr_reg_f) avr_r5;
		avr.rs = (avr_reg_f) avr_b3;
	}*/
}
