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

uint8_t avr_imm4(int8_t* i) {
	return atoi(i) & 15;
}

uint8_t avr_imm6(int8_t* i) {
	return atoi(i) & 63;
}

uint8_t avr_imm8(int8_t* i) {
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
		return enc;
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
		return enc;
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
		return enc;
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
		return enc;
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
		return enc;
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
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = (r >> 3) & 2;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		rl = r << 4;
		rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		return enc;
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
		uint8_t rl = r & 15;
		uint8_t rh = r >> 4;
		enc.x[0] |= rl;
		enc.x[1] |= rh;
		r = avr_reg4(rd);
		if (r == 255) {
			enc.n = 0;
			return enc;
		}
		enc.x[0] |= r << 4;
		return enc;
	}
	else {
		printf("error: invalid operation\n");
		enc.n = 0;
			return enc;
	}
}
