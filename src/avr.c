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

uint16_t avr_enc(int8_t* op, int8_t* rd, int8_t* rs) {
	if (!strcmp(op, "nop")) {
		if (rd != 0 || rs != 0) {
			printf("error: too many arguements\n");
			return 65535;
		}
		return 0;
	}
	else if (!strcmp(op, "movw")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 256;
		uint8_t r = avr_reg4p(rs);
		b |= r;
		if (r == 255) {
			return 65535;
		}
		r = avr_reg4p(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "muls")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 512;
		uint8_t r = avr_reg4(rs);
		b |= r;
		if (r == 255) {
			return 65535;
		}
		r = avr_reg4(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "mulsu")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 768;
		uint8_t r = avr_reg3(rs);
		b |= r;
		if (r == 255) {
			return 65535;
		}
		r = avr_reg3(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "fmul")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 776;
		uint8_t r = avr_reg3(rs);
		b |= r;
		if (r == 255) {
			return 65535;
		}
		r = avr_reg3(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "fmuls")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 896;
		uint8_t r = avr_reg3(rs);
		b |= r;
		if (r == 255) {
			return 65535;
		}
		r = avr_reg3(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "fmulsu")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 904;
		uint8_t r = avr_reg3(rs);
		b |= r;
		if (r == 255) {
			return 65535;
		}
		r = avr_reg3(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "cp")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 1024;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "cpc")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 5120;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "sub")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 2048;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "sbc")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 6144;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "add")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 3072;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "adc")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 7168;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "lsl")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			return 65535;
		}
		uint16_t b = 3072;
		uint16_t r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "rol")) {
		if (rd == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		if (rs != 0) {
			printf("error: too many arguements\n");
			return 65535;
		}
		uint16_t b = 7168;
		uint16_t r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "cpse")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 4096;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "and")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 8192;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "eor")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 9216;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "or")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 10240;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "mov")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 11264;
		uint16_t r = avr_reg5(rs);
		if (r == 255) {
			return 65535;
		}
		uint16_t rl = r & 15;
		uint16_t rh = (r << 5) & 512;
		b |= rl;
		b |= rh;
		r = avr_reg5(rd);
		if (r == 255) {
			return 65535;
		}
		b |= r << 4;
		return b;
	}
	else if (!strcmp(op, "cpi")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 12288;
		uint16_t r = avr_imm8(rs);
		uint16_t rl = r & 15;
		uint16_t rh = (r << 4) & 3840;
		b |= rl;
		b |= rh;
		r = avr_reg4(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "subi")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 16384;
		uint16_t r = avr_imm8(rs);
		uint16_t rl = r & 15;
		uint16_t rh = (r << 4) & 3840;
		b |= rl;
		b |= rh;
		r = avr_reg4(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "sbci")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 20480;
		uint16_t r = avr_imm8(rs);
		uint16_t rl = r & 15;
		uint16_t rh = (r << 4) & 3840;
		b |= rl;
		b |= rh;
		r = avr_reg4(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "ori") || !strcmp(op, "sbr")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 24576;
		uint16_t r = avr_imm8(rs);
		uint16_t rl = r & 15;
		uint16_t rh = (r << 4) & 3840;
		b |= rl;
		b |= rh;
		r = avr_reg4(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else if (!strcmp(op, "andi") || !strcmp(op, "cbr")) {
		if (rd == 0 || rs == 0) {
			printf("error: too few arguements\n");
			return 65535;
		}
		uint16_t b = 28672;
		uint16_t r = avr_imm8(rs);
		uint16_t rl = r & 15;
		uint16_t rh = (r << 4) & 3840;
		b |= rl;
		b |= rh;
		r = avr_reg4(rd);
		b |= r << 4;
		if (r == 255) {
			return 65535;
		}
		return b;
	}
	else {
		printf("error: invalid operation\n");
		return 65535;
	}
}
