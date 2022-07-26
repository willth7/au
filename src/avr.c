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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct enc_s {
	uint8_t x[4];
	uint8_t n;
} enc_t;

uint8_t avr_reg3(uint8_t* r) {
	if (!strcmp(r, "r16")) {
		return 0;
	}
	else if (!strcmp(r, "r17")) {
		return 1;
	}
	else if (!strcmp(r, "r18")) {
		return 2;
	}
	else if (!strcmp(r, "r19")) {
		return 3;
	}
	else if (!strcmp(r, "r20")) {
		return 4;
	}
	else if (!strcmp(r, "r21")) {
		return 5;
	}
	else if (!strcmp(r, "r22")) {
		return 6;
	}
	else if (!strcmp(r, "r23")) {
		return 7;
	}
	else {
		printf("error: invalid register %s\n", r);
		return 255;
	}
}

uint8_t avr_reg4(uint8_t* r) {
	if (!strcmp(r, "r16")) {
		return 0;
	}
	else if (!strcmp(r, "r17")) {
		return 1;
	}
	else if (!strcmp(r, "r18")) {
		return 2;
	}
	else if (!strcmp(r, "r19")) {
		return 3;
	}
	else if (!strcmp(r, "r20")) {
		return 4;
	}
	else if (!strcmp(r, "r21")) {
		return 5;
	}
	else if (!strcmp(r, "r22")) {
		return 6;
	}
	else if (!strcmp(r, "r23")) {
		return 7;
	}
	else if (!strcmp(r, "r24")) {
		return 8;
	}
	else if (!strcmp(r, "r25")) {
		return 9;
	}
	else if (!strcmp(r, "r26")) {
		return 10;
	}
	else if (!strcmp(r, "r27")) {
		return 11;
	}
	else if (!strcmp(r, "r28")) {
		return 12;
	}
	else if (!strcmp(r, "r29")) {
		return 13;
	}
	else if (!strcmp(r, "r30")) {
		return 14;
	}
	else if (!strcmp(r, "r31")) {
		return 15;
	}
	else {
		printf("error: invalid register %s\n", r);
		return 255;
	}
}

uint8_t avr_reg5(uint8_t* r) {
	if (!strcmp(r, "r0")) {
		return 0;
	}
	else if (!strcmp(r, "r1")) {
		return 1;
	}
	else if (!strcmp(r, "r2")) {
		return 2;
	}
	else if (!strcmp(r, "r3")) {
		return 3;
	}
	else if (!strcmp(r, "r4")) {
		return 4;
	}
	else if (!strcmp(r, "r5")) {
		return 5;
	}
	else if (!strcmp(r, "r6")) {
		return 6;
	}
	else if (!strcmp(r, "r7")) {
		return 7;
	}
	else if (!strcmp(r, "r8")) {
		return 8;
	}
	else if (!strcmp(r, "r9")) {
		return 9;
	}
	else if (!strcmp(r, "r10")) {
		return 10;
	}
	else if (!strcmp(r, "r11")) {
		return 11;
	}
	else if (!strcmp(r, "r12")) {
		return 12;
	}
	else if (!strcmp(r, "r13")) {
		return 13;
	}
	else if (!strcmp(r, "r14")) {
		return 14;
	}
	else if (!strcmp(r, "r15")) {
		return 15;
	}
	else if (!strcmp(r, "r16")) {
		return 16;
	}
	else if (!strcmp(r, "r17")) {
		return 17;
	}
	else if (!strcmp(r, "r18")) {
		return 18;
	}
	else if (!strcmp(r, "r19")) {
		return 19;
	}
	else if (!strcmp(r, "r20")) {
		return 20;
	}
	else if (!strcmp(r, "r21")) {
		return 21;
	}
	else if (!strcmp(r, "r22")) {
		return 22;
	}
	else if (!strcmp(r, "r23")) {
		return 23;
	}
	else if (!strcmp(r, "r24")) {
		return 24;
	}
	else if (!strcmp(r, "r25")) {
		return 25;
	}
	else if (!strcmp(r, "r26")) {
		return 26;
	}
	else if (!strcmp(r, "r27")) {
		return 27;
	}
	else if (!strcmp(r, "r28")) {
		return 28;
	}
	else if (!strcmp(r, "r29")) {
		return 29;
	}
	else if (!strcmp(r, "r30")) {
		return 30;
	}
	else if (!strcmp(r, "r31")) {
		return 31;
	}
	else {
		printf("error: invalid register %s\n", r);
		return 255;
	}
}

uint8_t avr_reg4p(int8_t* r) {
	if (!strcmp(r, "r0")) {
		return 0;
	}
	else if (!strcmp(r, "r2")) {
		return 1;
	}
	else if (!strcmp(r, "r4")) {
		return 2;
	}
	else if (!strcmp(r, "r6")) {
		return 3;
	}
	else if (!strcmp(r, "r8")) {
		return 4;
	}
	else if (!strcmp(r, "r10")) {
		return 5;
	}
	else if (!strcmp(r, "r12")) {
		return 6;
	}
	else if (!strcmp(r, "r14")) {
		return 7;
	}
	else if (!strcmp(r, "r16")) {
		return 8;
	}
	else if (!strcmp(r, "r18")) {
		return 9;
	}
	else if (!strcmp(r, "r20")) {
		return 10;
	}
	else if (!strcmp(r, "r22")) {
		return 11;
	}
	else if (!strcmp(r, "r24")) {
		return 12;
	}
	else if (!strcmp(r, "r26")) {
		return 13;
	}
	else if (!strcmp(r, "r28")) {
		return 14;
	}
	else if (!strcmp(r, "r30")) {
		return 15;
	}
	else {
		printf("error: invalid register pair %s\n", r);
		return 255;
	}
}

uint8_t avr_reg4d(int8_t* r) {
	if (!strcmp(r, "z+")) {
		return 1;
	}
	else if (!strcmp(r, "z-")) {
		return 2;
	}
	else if (!strcmp(r, "y+")) {
		return 9;
	}
	else if (!strcmp(r, "y-")) {
		return 10;
	}
	else if (!strcmp(r, "x")) {
		return 12;
	}
	else if (!strcmp(r, "x+")) {
		return 13;
	}
	else if (!strcmp(r, "x-")) {
		return 14;
	}
	else {
		printf("error: invalid register %s\n", r);
		return 255;
	}
}

uint8_t avr_reg7d(int8_t* r) {
	uint8_t d = 0;
	if (r[0] == 'y') {
		d = 8;
	}
	else if (r[0] != 'z') {
		printf("error: invalid register %c\n", r[0]);
		return 255;
	}
	d |= (atoi(r) & 7) | ((atoi(r) << 1) & 112);
	return d;
}

uint8_t avr_imm4(int8_t* i) {
	return atoi(i) & 15;
}

uint8_t avr_imm6(int8_t* i) {
	return atoi(i) & 63;
}

uint8_t avr_imm8(int8_t* i) {
	return atoi(i);
}

uint16_t avr_imm16(int8_t* i) {
	return atoi(i);
}

enc_t avr_enc(int8_t* op, int8_t* rd, int8_t* rs) {
	enc_t enc;
	if (!strcmp(op, "nop")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 0;
		enc.n = 2;
	}
	else if (!strcmp(op, "movw")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 0;
		enc.n = 2;
		uint8_t r = avr_reg4p(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r;
		r = avr_reg4p(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "muls")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 2;
		enc.n = 2;
		uint8_t r = avr_reg4(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r;
		enc.x[0] = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "mulsu")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 3;
		enc.n = 2;
		uint8_t r = avr_reg3(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r;
		r = avr_reg3(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "fmul")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 8;
		enc.x[1] = 3;
		enc.n = 2;
		uint8_t r = avr_reg3(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r;
		r = avr_reg3(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "fmuls")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 128;
		enc.x[1] = 3;
		enc.n = 2;
		uint8_t r = avr_reg3(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r;
		r = avr_reg3(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "fmulsu")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 136;
		enc.x[1] = 3;
		enc.n = 2;
		uint8_t r = avr_reg3(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r;
		r = avr_reg3(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "cp")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 4;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "cpc")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 20;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "sub")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 8;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "sbc")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 24;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "add")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 12;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "adc")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 28;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "lsl")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 12;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "rol")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 28;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "cpse")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 16;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "and")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 32;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "eor")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 36;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "or")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 40;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "mov")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 44;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 3) & 2;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "cpi")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 48;
		enc.n = 2;
		uint8_t r = avr_imm8(rs);
		enc.x[0] |= r & 15;
		enc.x[1] |= r >> 4;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "subi")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 64;
		enc.n = 2;
		uint8_t r = avr_imm8(rs);
		enc.x[0] |= r & 15;
		enc.x[1] |= r >> 4;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "sbci")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 80;
		enc.n = 2;
		uint8_t r = avr_imm8(rs);
		enc.x[0] |= r & 15;
		enc.x[1] |= r >> 4;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "ori") || !strcmp(op, "sbr")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 96;
		enc.n = 2;
		uint8_t r = avr_imm8(rs);
		enc.x[0] |= r & 15;
		enc.x[1] |= r >> 4;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "andi") || !strcmp(op, "cbr")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 112;
		enc.n = 2;
		uint8_t r = avr_imm8(rs);
		enc.x[0] |= r & 15;
		enc.x[1] |= r >> 4;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
	}
	else if (!strcmp(op, "ldd")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 128;
		enc.n = 2;
		uint8_t r = avr_reg7d(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 4) & 2;
		enc.x[1] |= (r >> 1) & 32;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "std")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 130;
		enc.n = 2;
		uint8_t r = avr_reg7d(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r & 15;
		enc.x[1] |= (r >> 4) & 2;
		enc.x[1] |= (r >> 1) & 32;
		r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "lds")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 144;
		enc.n = 4;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
		uint16_t i = avr_imm16(rs);
		enc.x[2] = i;
		enc.x[3] = i >> 8;
	}
	else if (!strcmp(op, "sts")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 146;
		enc.n = 4;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
		uint16_t i = avr_imm16(rd);
		enc.x[2] = i;
		enc.x[3] = i >> 8;
	}
	else if (!strcmp(op, "ld")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 144;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
		r = avr_reg4d(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r;
	}
	else if (!strcmp(op, "st")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 146;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
		r = avr_reg4d(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r;
	}
	else if (!strcmp(op, "lpm")) {
		if (rd != 0 && rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		else if (rd == 0) {
			enc.x[0] = 200;
			enc.x[1] = 149;
			enc.n = 2;
			return enc;
		}
		enc.x[0] = 4;
		enc.x[1] = 144;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
		if (!strcmp(rs, "z+")) {
			enc.x[0] |= 1;
		}
		else if (strcmp(rs, "z")) {
			printf("error: invalid register %s\n", rs);
			enc.n = 0;
		}
	}
	else if (!strcmp(op, "elpm")) {
		if (rd != 0 && rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		else if (rd == 0) {
			enc.x[0] = 216;
			enc.x[1] = 149;
			enc.n = 2;
			return enc;
		}
		enc.x[0] = 6;
		enc.x[1] = 144;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
		if (!strcmp(rs, "z+")) {
			enc.x[0] |= 1;
		}
		else if (strcmp(rs, "z")) {
			printf("error: invalid register %s\n", rs);
			enc.n = 0;
		}
	}
	else if (!strcmp(op, "spm")) {
		if (rd != 0 && rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		else if (rd == 0) {
			enc.x[0] = 232;
			enc.x[1] = 149;
			enc.n = 2;
			return enc;
		}
		else if (!strcmp(rd, "z+")) {
			enc.x[0] = 248;
			enc.x[1] = 149;
			enc.n = 2;
			return enc;
		}
	}
	else if (!strcmp(op, "xch")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (strcmp(rd, "z")) {
			printf("error: invalid register %s\n", rd);
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 4;
		enc.x[1] = 146;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "las")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (strcmp(rd, "z")) {
			printf("error: invalid register %s\n", rd);
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 5;
		enc.x[1] = 146;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "lac")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (strcmp(rd, "z")) {
			printf("error: invalid register %s\n", rd);
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 6;
		enc.x[1] = 146;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "xch")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (strcmp(rd, "z")) {
			printf("error: invalid register %s\n", rd);
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 7;
		enc.x[1] = 146;
		enc.n = 2;
		uint8_t r = avr_reg5(rs);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "pop")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 15;
		enc.x[1] = 144;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "push")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 15;
		enc.x[1] = 146;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "com")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 0;
		enc.x[1] = 148;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "neg")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 1;
		enc.x[1] = 148;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "swap")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 2;
		enc.x[1] = 148;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "inc")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 3;
		enc.x[1] = 148;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "dec")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 10;
		enc.x[1] = 148;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "asr")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 5;
		enc.x[1] = 148;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "lsr")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 6;
		enc.x[1] = 148;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "ror")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			enc.n = 0;
			return enc;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 7;
		enc.x[1] = 148;
		enc.n = 2;
		uint8_t r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		enc.x[1] |= r >> 4;
	}
	else if (!strcmp(op, "clc")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 8;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "sec")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 136;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "clz")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 24;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "sez")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 152;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "cln")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 40;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "sen")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 168;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "clv")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 56;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "sev")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 184;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "cls")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 72;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "ses")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 200;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "clh")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 88;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "seh")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 216;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "clt")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 104;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "set")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 232;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "cli")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 120;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else if (!strcmp(op, "sei")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			enc.n = 0;
			return enc;
		}
		enc.x[0] = 248;
		enc.x[1] = 148;
		enc.n = 2;
	}
	else {
		printf("error: invalid operation\n");
		enc.n = 0;
	}
	return enc;
}
