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

int8_t* avr_err(uint8_t e) {
	if (e == 0) {
		return "error: illegal operation";
	}
	else if (e == 1) {
		return "error: illegal operand";
	}
	else if (e == 2) {
		return "error: too few operands";
	}
	else if (e == 3) {
		return "error: too many operands";
	}
}

uint8_t avr_reg2(int8_t* r) {
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
}

uint8_t avr_reg3(int8_t* r) {
	if (r[0] == 'r' && r[1] == '1' && r[2] == '6' && r[3] == 0) {
		return 0;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '7' && r[3] == 0) {
		return 1;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '8' && r[3] == 0) {
		return 2;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '9' && r[3] == 0) {
		return 3;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '0' && r[3] == 0) {
		return 4;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '1' && r[3] == 0) {
		return 5;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '2' && r[3] == 0) {
		return 6;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '3' && r[3] == 0) {
		return 7;
	}
}

uint8_t avr_reg4(int8_t* r) {
	if (r[0] == 'r' && r[1] == '1' && r[2] == '6' && r[3] == 0) {
		return 0;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '7' && r[3] == 0) {
		return 1;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '8' && r[3] == 0) {
		return 2;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '9' && r[3] == 0) {
		return 3;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '0' && r[3] == 0) {
		return 4;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '1' && r[3] == 0) {
		return 5;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '2' && r[3] == 0) {
		return 6;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '3' && r[3] == 0) {
		return 7;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '4' && r[3] == 0) {
		return 8;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '5' && r[3] == 0) {
		return 9;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '6' && r[3] == 0) {
		return 10;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '7' && r[3] == 0) {
		return 11;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '8' && r[3] == 0) {
		return 12;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == '9' && r[3] == 0) {
		return 13;
	}
	else if (r[0] == 'r' && r[1] == '3' && r[2] == '0' && r[3] == 0) {
		return 14;
	}
	else if (r[0] == 'r' && r[1] == '3' && r[2] == '1' && r[3] == 0) {
		return 15;
	}
}

uint8_t avr_reg5(int8_t* r) {
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
}

uint8_t avr_reg5x(int8_t* r) {
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

uint8_t avr_reg7d(int8_t* r) {
	uint8_t k = 0;
	for (uint8_t i = 1; i < 4; i++) {
		if (r[i] == 0) {
			break;
		}
		k *= 10;
		if (r[i] == '1') {
			k += 1;
		}
		else if (r[i] == '2') {
			k += 2;
		}
		else if (r[i] == '3') {
			k += 3;
		}
		else if (r[i] == '4') {
			k += 4;
		}
		else if (r[i] == '5') {
			k += 5;
		}
		else if (r[i] == '6') {
			k += 6;
		}
		else if (r[i] == '7') {
			k += 7;
		}
		else if (r[i] == '8') {
			k += 8;
		}
		else if (r[i] == '9') {
			k += 9;
		}
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

uint8_t avr_bit3(int8_t* b) {
	if (b[0] == '0' && b[1] == 0) {
		return 0;
	}
	else if (b[0] == '1' && b[1] == 0) {
		return 1;
	}
	else if (b[0] == '2' && b[1] == 0) {
		return 2;
	}
	else if (b[0] == '3' && b[1] == 0) {
		return 3;
	}
	else if (b[0] == '4' && b[1] == 0) {
		return 4;
	}
	else if (b[0] == '5' && b[1] == 0) {
		return 5;
	}
	else if (b[0] == '6' && b[1] == 0) {
		return 6;
	}
	else if (b[0] == '7' && b[1] == 0) {
		return 7;
	}
}

uint8_t avr_imm6(int8_t* a) {
	uint8_t k = 0;
	for (uint8_t i = 0; i < 3; i++) {
		if (a[i] == 0) {
			return k;
		}
		k *= 10;
		if (a[i] == '1') {
			k += 1;
		}
		else if (a[i] == '2') {
			k += 2;
		}
		else if (a[i] == '3') {
			k += 3;
		}
		else if (a[i] == '4') {
			k += 4;
		}
		else if (a[i] == '5') {
			k += 5;
		}
		else if (a[i] == '6') {
			k += 6;
		}
		else if (a[i] == '7') {
			k += 7;
		}
		else if (a[i] == '8') {
			k += 8;
		}
		else if (a[i] == '9') {
			k += 9;
		}
	}
}

uint8_t avr_imm8(int8_t* a) {
	uint8_t k = 0;
	for (uint8_t i = 0; i < 4; i++) {
		if (a[i] == 0) {
			return k;
		}
		k *= 10;
		if (a[i] == '1') {
			k += 1;
		}
		else if (a[i] == '2') {
			k += 2;
		}
		else if (a[i] == '3') {
			k += 3;
		}
		else if (a[i] == '4') {
			k += 4;
		}
		else if (a[i] == '5') {
			k += 5;
		}
		else if (a[i] == '6') {
			k += 6;
		}
		else if (a[i] == '7') {
			k += 7;
		}
		else if (a[i] == '8') {
			k += 8;
		}
		else if (a[i] == '9') {
			k += 9;
		}
	}
}

enc_t avr_enc(int8_t* op, int8_t* rd, int8_t* rs) {
	enc_t enc;
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) { //adc
		enc.x[0] = 0;
		enc.x[1] = 28;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) { //add
		enc.x[0] = 0;
		enc.x[1] = 12;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'i' && op[3] == 'w' && op[4] == 0) { //adiw
		enc.x[0] = 0;
		enc.x[1] = 150;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm6(rs)) & 15;
		enc.x[0] |= (avr_imm6(rs) << 2) & 192;
		enc.x[0] |= (avr_reg2(rd) << 4) & 48;
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) { //and
		enc.x[0] = 0;
		enc.x[1] = 32;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 'i' && op[4] == 0) { //andi
		enc.x[0] = 0;
		enc.x[1] = 112;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rs)) & 15;
		enc.x[0] |= (avr_reg4(rd) << 4) & 240;
		enc.x[1] |= (avr_imm8(rs) >> 4) & 15;
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 0) { //asr
		enc.x[0] = 5;
		enc.x[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'b' && op[1] == 'c' && op[2] == 'l' && op[3] == 'r' && op[4] == 0) { //bclr
		enc.x[0] = 136;
		enc.x[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_bit3(rd) << 4) & 112;
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'd' && op[3] == 0) { //bld
		enc.x[0] = 0;
		enc.x[1] = 248;
		enc.n = 2;
		
		enc.x[0] |= (avr_bit3(rs)) & 7;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'b' && op[3] == 'c' && op[4] == 0) { //brbc
		enc.x[0] = 0;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_bit3(rd)) & 7;
		enc.x[0] |= (avr_imm8(rs) << 3) & 248;
		enc.x[1] |= (avr_imm8(rs) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'b' && op[3] == 's' && op[4] == 0) { //brbs
		enc.x[0] = 0;
		enc.x[1] = 240;
		enc.n = 2;
		
		enc.x[0] |= (avr_bit3(rd)) & 7;
		enc.x[0] |= (avr_imm8(rs) << 3) & 248;
		enc.x[1] |= (avr_imm8(rs) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'c' && op[3] == 'c' && op[4] == 0) { //brcc
		enc.x[0] = 0;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'c' && op[3] == 's' && op[4] == 0) { //brcs
		enc.x[0] = 0;
		enc.x[1] = 240;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'e' && op[3] == 'a' && op[4] == 'k' && op[5] == 0) { //break
		enc.x[0] = 152;
		enc.x[1] = 149;
		enc.n = 2;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'e' && op[3] == 'q' && op[4] == 0) { //breq
		enc.x[0] = 1;
		enc.x[1] = 240;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'g' && op[3] == 'e' && op[4] == 0) { //brge
		enc.x[0] = 4;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'h' && op[3] == 'c' && op[4] == 0) { //brhc
		enc.x[0] = 5;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'h' && op[3] == 's' && op[4] == 0) { //brhs
		enc.x[0] = 5;
		enc.x[1] = 240;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'i' && op[3] == 'd' && op[4] == 0) { //brid
		enc.x[0] = 7;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'i' && op[3] == 'e' && op[4] == 0) { //brie
		enc.x[0] = 7;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'l' && op[3] == 'o' && op[4] == 0) { //brlo
		enc.x[0] = 0;
		enc.x[1] = 240;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'l' && op[3] == 't' && op[4] == 0) { //brlt
		enc.x[0] = 4;
		enc.x[1] = 240;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'm' && op[3] == 'i' && op[4] == 0) { //brmi
		enc.x[0] = 2;
		enc.x[1] = 240;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'n' && op[3] == 'e' && op[4] == 0) { //brne
		enc.x[0] = 1;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'p' && op[3] == 'l' && op[4] == 0) { //brpl
		enc.x[0] = 2;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 's' && op[3] == 'h' && op[4] == 0) { //brsh
		enc.x[0] = 0;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 't' && op[3] == 'c' && op[4] == 0) { //brtc
		enc.x[0] = 6;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 't' && op[3] == 's' && op[4] == 0) { //brts
		enc.x[0] = 6;
		enc.x[1] = 240;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'v' && op[3] == 'c' && op[4] == 0) { //brvc
		enc.x[0] = 3;
		enc.x[1] = 244;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'v' && op[3] == 's' && op[4] == 0) { //brvs
		enc.x[0] = 3;
		enc.x[1] = 240;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rd) << 3) & 248;
		enc.x[1] |= (avr_imm8(rd) >> 5) & 3;
	}
	else if (op[0] == 'b' && op[1] == 's' && op[2] == 'e' && op[3] == 't' && op[4] == 0) { //bset
		enc.x[0] = 8;
		enc.x[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_bit3(rd) << 4) & 112;
	}
	else if (op[0] == 'b' && op[1] == 's' && op[2] == 't' && op[3] == 0) { //bst
		enc.x[0] = 0;
		enc.x[1] = 250;
		enc.n = 2;
		
		enc.x[0] |= (avr_bit3(rs)) & 7;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'c' && op[1] == 'a' && op[2] == 'l' && op[3] == 'l' && op[4] == 0) { //call
		enc.x[0] = 14;
		enc.x[1] = 148;
		enc.x[2] = 0;
		enc.x[3] = 0;
		enc.n = 4;
		
		//todo
	}
	else if (op[0] == 'c' && op[1] == 'b' && op[2] == 'i' && op[3] == 0) { //cbi
		enc.x[0] = 0;
		enc.x[1] = 152;
		enc.n = 2;
		
		enc.x[0] |= (avr_bit3(rs)) & 7;
		enc.x[0] |= (avr_imm6(rd) << 3) & 248;
	}
	else if (op[0] == 'c' && op[1] == 'b' && op[2] == 'r' && op[3] == 0) { //cbr
		enc.x[0] = 0;
		enc.x[1] = 112;
		enc.n = 2;
		
		enc.x[0] |= (~avr_imm8(rs)) & 15;
		enc.x[0] |= (avr_reg4(rd) << 4) & 240;
		enc.x[1] |= (~avr_imm8(rs) >> 4) & 15;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'c' && op[3] == 0) { //clc
		enc.x[0] = 136;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'h' && op[3] == 0) { //clh
		enc.x[0] = 216;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'i' && op[3] == 0) { //cli
		enc.x[0] = 248;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'n' && op[3] == 0) { //cln
		enc.x[0] = 168;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'r' && op[3] == 0) { //clr
		enc.x[0] = 0;
		enc.x[1] = 36;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rd)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 's' && op[3] == 0) { //cls
		enc.x[0] = 200;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 't' && op[3] == 0) { //clt
		enc.x[0] = 232;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'v' && op[3] == 0) { //clv
		enc.x[0] = 184;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'z' && op[3] == 0) { //clz
		enc.x[0] = 152;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'c' && op[1] == 'o' && op[2] == 'm' && op[3] == 0) { //com
		enc.x[0] = 0;
		enc.x[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 0) { //cp
		enc.x[0] = 0;
		enc.x[1] = 20;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 'c' && op[3] == 0) { //cpc
		enc.x[0] = 0;
		enc.x[1] = 4;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 'i' && op[3] == 0) { //cpi
		enc.x[0] = 0;
		enc.x[1] = 4;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rs)) & 15;
		enc.x[0] |= (avr_reg4(rd) << 4) & 240;
		enc.x[1] |= (avr_imm8(rs) >> 4) & 15;
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 's' && op[3] == 'e' && op[4] == 0) { //cpse
		enc.x[0] = 0;
		enc.x[1] = 16;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) { //dec
		enc.x[0] = 10;
		enc.x[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 's' && op[3] == 0) { //des
		enc.x[0] = 11;
		enc.x[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm6(rd) << 4) & 240;
	}
	else if (op[0] == 'e' && op[1] == 'i' && op[2] == 'c' && op[3] == 'a' && op[4] == 'l' && op[5] == 'l' && op[6] == 0) { //eicall
		enc.x[0] = 25;
		enc.x[1] = 149;
		enc.n = 2;
	}
	else if (op[0] == 'e' && op[1] == 'i' && op[2] == 'j' && op[3] == 'm' && op[4] == 'p' && op[5] == 0) { //eijmp
		enc.x[0] = 25;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'e' && op[1] == 'l' && op[2] == 'p' && op[3] == 'm' && op[4] == 0) { //elpm
		enc.x[0] = 0;
		enc.x[1] = 0;
		enc.n = 2;
		
		//todo
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) { //eor
		enc.x[0] = 0;
		enc.x[1] = 36;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'f' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 0) { //fmul
		enc.x[0] = 8;
		enc.x[1] = 3;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg3(rs)) & 7;
		enc.x[0] |= (avr_reg3(rd) << 4) & 112;
	}
	else if (op[0] == 'f' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 's' && op[5] == 0) { //fmuls
		enc.x[0] = 128;
		enc.x[1] = 3;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg3(rs)) & 7;
		enc.x[0] |= (avr_reg3(rd) << 4) & 112;
	}
	else if (op[0] == 'f' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 's' && op[5] == 'u' && op[6] == 0) { //fmulsu
		enc.x[0] = 136;
		enc.x[1] = 3;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg3(rs)) & 7;
		enc.x[0] |= (avr_reg3(rd) << 4) & 112;
	}
	else if (op[0] == 'i' && op[1] == 'c' && op[2] == 'a' && op[3] == 'l' && op[4] == 'l' && op[5] == 0) { //icall
		enc.x[0] = 9;
		enc.x[1] = 149;
		enc.n = 2;
	}
	else if (op[0] == 'i' && op[1] == 'j' && op[2] == 'm' && op[3] == 'p' && op[4] == 0) { //ijmp
		enc.x[0] = 9;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 0) { //in
		enc.x[0] = 0;
		enc.x[1] = 176;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm6(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_imm6(rs) >> 3) & 6;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) { //inc
		enc.x[0] = 3;
		enc.x[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'j' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) { //jmp
		enc.x[0] = 12;
		enc.x[1] = 148;
		enc.n = 4;
		
		//todo
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 'c' && op[3] == 0) { //lac
		enc.x[0] = 6;
		enc.x[1] = 146;
		enc.n = 2;
		
		//rd z
		enc.x[0] |= (avr_reg5(rs) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 4) & 1;
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 's' && op[3] == 0) { //las
		enc.x[0] = 5;
		enc.x[1] = 146;
		enc.n = 2;
		
		//rd z
		enc.x[0] |= (avr_reg5(rs) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 4) & 1;
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 't' && op[3] == 0) { //lat
		enc.x[0] = 7;
		enc.x[1] = 146;
		enc.n = 2;
		
		//rd z
		enc.x[0] |= (avr_reg5(rs) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 4) & 1;
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 0) { //ld
		enc.x[0] = 0;
		enc.x[1] = 128;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5x(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5x(rs)) & 16;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) { //ldd
		enc.x[0] = 0;
		enc.x[1] = 128;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg7d(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg7d(rs) >> 2) & 12;
		enc.x[1] |= (avr_reg7d(rs) >> 1) & 32;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'i' && op[3] == 0) { //ldi
		enc.x[0] = 0;
		enc.x[1] = 224;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rs)) & 15;
		enc.x[0] |= (avr_reg4(rd) << 4) & 240;
		enc.x[1] |= (avr_imm8(rs) >> 4) & 15;
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 's' && op[3] == 0) { //lds
		enc.x[0] = 0;
		enc.x[1] = 0;
		enc.n = 2; //4?
		
		//todo
	}
	else if (op[0] == 'l' && op[1] == 'p' && op[2] == 'm' && op[3] == 0) { //lpm
		enc.x[0] = 0;
		enc.x[1] = 144;
		enc.n = 2;
		
		//todo
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 0) { //lsl
		enc.x[0] = 0;
		enc.x[1] = 12;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rd)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 0) { //lsr
		enc.x[0] = 6;
		enc.x[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else {
		enc.x[0] = 0;
		enc.n = 0;
	}
	return enc;
}
