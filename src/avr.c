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
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		enc.x[0] = 0;
		enc.x[1] = 28;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		enc.x[0] = 0;
		enc.x[1] = 12;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'i' && op[3] == 'w' && op[4] == 0) {
		enc.x[0] = 0;
		enc.x[1] = 150;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm6(rs)) & 15;
		enc.x[0] |= (avr_imm6(rs) << 2) & 192;
		enc.x[0] |= (avr_reg2(rd) << 4) & 48;
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		enc.x[0] = 0;
		enc.x[1] = 32;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rs)) & 15;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rs) >> 3) & 2;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 'i' && op[4] == 0) {
		enc.x[0] = 0;
		enc.x[1] = 112;
		enc.n = 2;
		
		enc.x[0] |= (avr_imm8(rs)) & 15;
		enc.x[0] |= (avr_reg4(rd) << 4) & 240;
		enc.x[1] |= (avr_imm8(rs) >> 4) & 15;
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		enc[0] = 5;
		enc[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'b' && op[1] == 'c' && op[2] == 'l' && op[3] == 'r' && op[4] == 0) {
		enc.x[0] = 136;
		enc.x[1] = 148;
		enc.n = 2;
		
		enc.x[0] |= (avr_bit3(rd) << 4) & 112;
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'd' && op[3] == 0) {
		enc.x[0] = 0;
		enc.x[1] = 248;
		enc.n = 2;
		
		enc.x[0] |= (avr_bit3(rs)) & 7;
		enc.x[0] |= (avr_reg5(rd) << 4) & 240;
		enc.x[1] |= (avr_reg5(rd) >> 4) & 1;
	}
	else if (op[0] == 'b' && op[1] == 'r' && op[2] == 'b' && op[3] == 'c' && op[4] == 0) {
		enc.x[0] = 0;
		enc.x[1] = 244;
		enc.n = 2;
		
		//todo
	}
	else {
		enc.x[0] = 0;
		enc.n = 0;
	}
	return enc;
}
