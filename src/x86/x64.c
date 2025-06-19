//   Copyright 2025 Will Thomas
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

//   agnus dei, qui tollis peccata mundi

#include <stdint.h>
#include <stdio.h>

uint8_t x86_64_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r[0] == 'a' && r[1] == 'l' && (r[2] == 0 || r[2] == ')')) { //8 bit
		return 0;
	}
	else if (r[0] == 'c' && r[1] == 'l' && (r[2] == 0 || r[2] == ')')) {
		return 1;
	}
	else if (r[0] == 'd' && r[1] == 'l' && (r[2] == 0 || r[2] == ')')) {
		return 2;
	}
	else if (r[0] == 'b' && r[1] == 'l' && (r[2] == 0 || r[2] == ')')) {
		return 3;
	}
	else if (r[0] == 'a' && r[1] == 'h' && (r[2] == 0 || r[2] == ')')) {
		return 4;
	}
	else if (r[0] == 'c' && r[1] == 'h' && (r[2] == 0 || r[2] == ')')) {
		return 5;
	}
	else if (r[0] == 'd' && r[1] == 'h' && (r[2] == 0 || r[2] == ')')) {
		return 6;
	}
	else if (r[0] == 'b' && r[1] == 'h' && (r[2] == 0 || r[2] == ')')) {
		return 7;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 'b' && (r[3] == 0 || r[3] == ')')) {
		return 8;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 'b' && (r[3] == 0 || r[3] == ')')) {
		return 9;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 'b' && (r[4] == 0 || r[4] == ')')) {
		return 10;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 'b' && (r[4] == 0 || r[4] == ')')) {
		return 11;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 'b' && (r[4] == 0 || r[4] == ')')) {
		return 12;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 'b' && (r[4] == 0 || r[4] == ')')) {
		return 13;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 'b' && (r[4] == 0 || r[4] == ')')) {
		return 14;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 'b' && (r[4] == 0 || r[4] == ')')) {
		return 15;
	}	
	else if (r[0] == 'a' && r[1] == 'x' && (r[2] == 0 || r[2] == ')')) { //16 bit
		return 16;
	}
	else if (r[0] == 'c' && r[1] == 'x' && (r[2] == 0 || r[2] == ')')) {
		return 17;
	}
	else if (r[0] == 'd' && r[1] == 'x' && (r[2] == 0 || r[2] == ')')) {
		return 18;
	}
	else if (r[0] == 'b' && r[1] == 'x' && (r[2] == 0 || r[2] == ')')) {
		return 19;
	}
	else if (r[0] == 's' && r[1] == 'p' && (r[2] == 0 || r[2] == ')')) {
		return 20;
	}
	else if (r[0] == 'b' && r[1] == 'p' && (r[2] == 0 || r[2] == ')')) {
		return 21;
	}
	else if (r[0] == 's' && r[1] == 'i' && (r[2] == 0 || r[2] == ')')) {
		return 22;
	}
	else if (r[0] == 'd' && r[1] == 'i' && (r[2] == 0 || r[2] == ')')) {
		return 23;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 'w' && (r[3] == 0 || r[3] == ')')) {
		return 24;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 'w' && (r[3] == 0 || r[3] == ')')) {
		return 25;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 'w' && (r[4] == 0 || r[4] == ')')) {
		return 26;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 'w' && (r[4] == 0 || r[4] == ')')) {
		return 27;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 'w' && (r[4] == 0 || r[4] == ')')) {
		return 28;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 'w' && (r[4] == 0 || r[4] == ')')) {
		return 29;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 'w' && (r[4] == 0 || r[4] == ')')) {
		return 30;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 'w' && (r[4] == 0 || r[4] == ')')) {
		return 31;
	}
	else if (r[0] == 'e' && r[1] == 'a' && r[2] == 'x' && (r[3] == 0 || r[3] == ')')) { //32 bit
		return 32;
	}
	else if (r[0] == 'e' && r[1] == 'c' && r[2] == 'x' && (r[3] == 0 || r[3] == ')')) {
		return 33;
	}
	else if (r[0] == 'e' && r[1] == 'd' && r[2] == 'x' && (r[3] == 0 || r[3] == ')')) {
		return 34;
	}
	else if (r[0] == 'e' && r[1] == 'b' && r[2] == 'x' && (r[3] == 0 || r[3] == ')')) {
		return 35;
	}
	else if (r[0] == 'e' && r[1] == 's' && r[2] == 'p' && (r[3] == 0 || r[3] == ')')) {
		return 36;
	}
	else if (r[0] == 'e' && r[1] == 'b' && r[2] == 'p' && (r[3] == 0 || r[3] == ')')) {
		return 37;
	}
	else if (r[0] == 'e' && r[1] == 's' && r[2] == 'i' && (r[3] == 0 || r[3] == ')')) {
		return 38;
	}
	else if (r[0] == 'e' && r[1] == 'd' && r[2] == 'i' && (r[3] == 0 || r[3] == ')')) {
		return 39;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 'd' && (r[3] == 0 || r[3] == ')')) {
		return 40;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 'd' && (r[3] == 0 || r[3] == ')')) {
		return 41;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 'd' && (r[4] == 0 || r[4] == ')')) {
		return 42;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 'd' && (r[4] == 0 || r[4] == ')')) {
		return 43;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 'd' && (r[4] == 0 || r[4] == ')')) {
		return 44;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 'd' && (r[4] == 0 || r[4] == ')')) {
		return 45;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 'd' && (r[4] == 0 || r[4] == ')')) {
		return 46;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 'd' && (r[4] == 0 || r[4] == ')')) {
		return 47;
	}
	else if (r[0] == 'r' && r[1] == 'a' && r[2] == 'x' && (r[3] == 0 || r[3] == ')')) { //64 bit
		return 48;
	}
	else if (r[0] == 'r' && r[1] == 'c' && r[2] == 'x' && (r[3] == 0 || r[3] == ')')) {
		return 49;
	}
	else if (r[0] == 'r' && r[1] == 'd' && r[2] == 'x' && (r[3] == 0 || r[3] == ')')) {
		return 50;
	}
	else if (r[0] == 'r' && r[1] == 'b' && r[2] == 'x' && (r[3] == 0 || r[3] == ')')) {
		return 51;
	}
	else if (r[0] == 'r' && r[1] == 's' && r[2] == 'p' && (r[3] == 0 || r[3] == ')')) {
		return 52;
	}
	else if (r[0] == 'r' && r[1] == 'b' && r[2] == 'p' && (r[3] == 0 || r[3] == ')')) {
		return 53;
	}
	else if (r[0] == 'r' && r[1] == 's' && r[2] == 'i' && (r[3] == 0 || r[3] == ')')) {
		return 54;
	}
	else if (r[0] == 'r' && r[1] == 'd' && r[2] == 'i' && (r[3] == 0 || r[3] == ')')) {
		return 55;
	}
	else if (r[0] == 'r' && r[1] == '8' && (r[2] == 0 || r[2] == ')')) {
		return 56;
	}
	else if (r[0] == 'r' && r[1] == '9' && (r[2] == 0 || r[2] == ')')) {
		return 57;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 58;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 59;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 60;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) {
		return 61;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) {
		return 62;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) {
		return 63;
	}
	else if (r[0] == 's' && r[1] == 'p' && r[2] == 'l' && (r[3] == 0 || r[3] == ')')) { //8 bit rex
		return 68;
	}
	else if (r[0] == 'b' && r[1] == 'p' && r[2] == 'l' && (r[3] == 0 || r[3] == ')')) {
		return 69;
	}
	else if (r[0] == 's' && r[1] == 'i' && r[2] == 'l' && (r[3] == 0 || r[3] == ')')) {
		return 70;
	}
	else if (r[0] == 'd' && r[1] == 'i' && r[2] == 'l' && (r[3] == 0 || r[3] == ')')) {
		return 71;
	}
	else if (r[0] == 'e' && r[1] == 'i' && r[2] == 'p' && (r[3] == 0 || r[3] == ')')) { //32 bit ip
		return 101;
	}
	else if (r[0] == 'r' && r[1] == 'i' && r[2] == 'p' && (r[3] == 0 || r[3] == ')')) { //64 bit ip
		return 117;
	}
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
		return 0;
	}
}

int8_t* x86_64_dec_reg(uint8_t r) {
	if (r == 0) {
		return "al";
	}
	else if (r == 1) {
		return "cl";
	}
	else if (r == 2) {
		return "dl";
	}
	else if (r == 3) {
		return "bl";
	}
	else if (r == 4) {
		return "ah";
	}
	else if (r == 5) {
		return "ch";
	}
	else if (r == 6) {
		return "dh";
	}
	else if (r == 7) {
		return "bh";
	}
	else if (r == 8) {
		return "r8b";
	}
	else if (r == 9) {
		return "r9b";
	}
	else if (r == 10) {
		return "r10b";
	}
	else if (r == 11) {
		return "r11b";
	}
	else if (r == 12) {
		return "r12b";
	}
	else if (r == 13) {
		return "r13b";
	}
	else if (r == 14) {
		return "r14b";
	}
	else if (r == 15) {
		return "r15b";
	}
	else if (r == 16) {
		return "ax";
	}
	else if (r == 17) {
		return "cx";
	}
	else if (r == 18) {
		return "dx";
	}
	else if (r == 19) {
		return "bx";
	}
	else if (r == 20) {
		return "sp";
	}
	else if (r == 21) {
		return "bp";
	}
	else if (r == 22) {
		return "si";
	}
	else if (r == 23) {
		return "di";
	}
	else if (r == 24) {
		return "r8w";
	}
	else if (r == 25) {
		return "r9w";
	}
	else if (r == 26) {
		return "r10w";
	}
	else if (r == 27) {
		return "r11w";
	}
	else if (r == 28) {
		return "r12w";
	}
	else if (r == 29) {
		return "r13w";
	}
	else if (r == 30) {
		return "r14w";
	}
	else if (r == 31) {
		return "r15w";
	}
	else if (r == 32) {
		return "eax";
	}
	else if (r == 33) {
		return "ecx";
	}
	else if (r == 34) {
		return "edx";
	}
	else if (r == 35) {
		return "ebx";
	}
	else if (r == 36) {
		return "esp";
	}
	else if (r == 37) {
		return "ebp";
	}
	else if (r == 38) {
		return "esi";
	}
	else if (r == 39) {
		return "edi";
	}
	else if (r == 40) {
		return "r8d";
	}
	else if (r == 41) {
		return "r9d";
	}
	else if (r == 42) {
		return "r10d";
	}
	else if (r == 43) {
		return "r11d";
	}
	else if (r == 44) {
		return "r12d";
	}
	else if (r == 45) {
		return "r13d";
	}
	else if (r == 46) {
		return "r14d";
	}
	else if (r == 47) {
		return "r15d";
	}
	else if (r == 48) {
		return "rax";
	}
	else if (r == 49) {
		return "rcx";
	}
	else if (r == 50) {
		return "rdx";
	}
	else if (r == 51) {
		return "rbx";
	}
	else if (r == 52) {
		return "rsp";
	}
	else if (r == 53) {
		return "rbp";
	}
	else if (r == 54) {
		return "rsi";
	}
	else if (r == 55) {
		return "rdi";
	}
	else if (r == 56) {
		return "r8";
	}
	else if (r == 57) {
		return "r9";
	}
	else if (r == 58) {
		return "r10";
	}
	else if (r == 59) {
		return "r11";
	}
	else if (r == 60) {
		return "r12";
	}
	else if (r == 61) {
		return "r13";
	}
	else if (r == 62) {
		return "r14";
	}
	else if (r == 63) {
		return "r15";
	}
	else if (r == 68) {
		return "spl";
	}
	else if (r == 69) {
		return "bpl";
	}
	else if (r == 70) {
		return "sil";
	}
	else if (r == 71) {
		return "dil";
	}
	else if (r == 101) {
		return "eip";
	}
	else if (r == 117) {
		return "rip";
	}
}

void x86_64_err_r8(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15 && r != 68 && r != 69 && r != 70 && r != 71) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(r));
		*e = -1;
	}
}

void x86_64_err_r16(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 31) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(r));
		*e = -1;
	}
}

void x86_64_err_r32(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 32 || r > 47) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(r));
		*e = -1;
	}
}

void x86_64_err_r64(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 48 || r > 63) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(r));
		*e = -1;
	}
}

void x86_64_err_rsp(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 15) == 4) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(r));
		*e = -1;
	}
}

void x86_64_err_rbp(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 15) == 5) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(r));
		*e = -1;
	}
}

void x86_64_err_164(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 16) == 0) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(r));
		*e = -1;
	}
}

void x86_64_err_264(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 48) == 0) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(r));
		*e = -1;
	}
}

void x86_64_err_364(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 96) != 32) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(r));
		*e = -1;
	}
}

void x86_64_err_k8(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128 || k > 255) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void x86_64_err_k16(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32768 || k > 65535) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void x86_64_err_k32(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -2147483648 || k > 4294967295) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void x86_64_err_reg(uint8_t rd, uint8_t rs, int8_t* e, int8_t* path, uint64_t ln) {
	if ((rd & 48) != (rs & 48)) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(rs));
		*e = -1;
	}
	if ((rd & 48) == 0) {
		if ((rd == 4 || rd == 5 || rd == 6 || rd == 7) && rs > 7) {
			printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(rd));
			*e = -1;
		}
		else if ((rs == 4 || rs == 5 || rs == 6 || rs == 7) && rd > 7) {
			printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_64_dec_reg(rs));
			*e = -1;
		}
	}
}

void x86_64_inst_byt(uint8_t* bin, uint64_t* bn, uint8_t a) {
	bin[*bn] = a;
	(*bn)++;
}

void x86_64_prfx_leg(uint8_t* bin, uint64_t* bn, uint8_t b, uint8_t r) {
	if ((r & 48) == 16) {
		bin[*bn] = 102;
		(*bn)++;
	}
	if ((b & 48) == 32) {
		bin[*bn] = 103;
		(*bn)++;
	}
}

void x86_64_prfx_rex(uint8_t* bin, uint64_t* bn, uint8_t r0, uint8_t r1, uint8_t r2) {
	if ((r0 & 8) || (r1 & 8) || (r2 & 8) || (r2 & 48) == 48 || (r0 & 64) || (r2 & 64)) {
		bin[*bn] = 64;
		if (r0 & 8) {
			bin[*bn] |= 1;
		}
		if (r1 & 8) {
			bin[*bn] |= 2;
		}
		if (r2 & 8) {
			bin[*bn] |= 4;
		}
		if ((r2 & 48) == 48) {
			bin[*bn] |= 8;
		}
		(*bn)++;
	}
}

void x86_64_inst_mod(uint8_t* bin, uint64_t* bn, uint8_t m, uint8_t rd, uint8_t rs) {
	bin[*bn] = (m << 6) | ((rs & 7) << 3) | (rd & 7);
	(*bn)++;
}

void x86_64_inst_k16(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = k;
	bin[*bn + 1] = k >> 8;
	*bn += 2;
}

void x86_64_inst_k32(uint8_t* bin, uint64_t* bn, uint32_t k) {
	bin[*bn] = k;
	bin[*bn + 1] = k >> 8;
	bin[*bn + 2] = k >> 16;
	bin[*bn + 3] = k >> 24;
	*bn += 4;
}

void x86_64_inst_k64(uint8_t* bin, uint64_t* bn, uint64_t k) {
	bin[*bn] = k;
	bin[*bn + 1] = k >> 8;
	bin[*bn + 2] = k >> 16;
	bin[*bn + 3] = k >> 24;
	bin[*bn + 4] = k >> 32;
	bin[*bn + 5] = k >> 40;
	bin[*bn + 6] = k >> 48;
	bin[*bn + 7] = k >> 56;
	*bn += 8;
}

void x86_64_inst_lcp(uint8_t* bin, uint64_t* bn, uint8_t r, uint32_t k) {
	if ((r & 48) == 0) {
		x86_64_inst_byt(bin, bn, k);
	}
	else if ((r & 48) == 16) {
		x86_64_inst_k16(bin, bn, k);
	}
	else {
		x86_64_inst_k32(bin, bn, k);
	}
}

void x86_64_inst_mvp(uint8_t* bin, uint64_t* bn, uint8_t r, uint64_t k) {
	if ((r & 48) == 0) {
		x86_64_inst_byt(bin, bn, k);
	}
	else if ((r & 48) == 16) {
		x86_64_inst_k16(bin, bn, k);
	}
	else if ((r & 48) == 32) {
		x86_64_inst_k32(bin, bn, k);
	}
	else {
		x86_64_inst_k64(bin, bn, k);
	}
}

void x86_64_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, int64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 0 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 4 + !!(rv[0] & 48)); //op
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] < 256 && rv[1] > -128) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]);
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_k32(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);

			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 128 + !!(rv[0] & 48));
			x86_64_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 8 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 12 + !!(rv[0] & 48)); //op
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] < 256 && rv[1] > -128) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]);
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_k32(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);

			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 128 + !!(rv[0] & 48));
			x86_64_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "or");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 16 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 20 + !!(rv[0] & 48)); //op
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] < 256 && rv[1] > -128) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]);
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_k32(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);

			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 128 + !!(rv[0] & 48));
			x86_64_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 24 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 28 + !!(rv[0] & 48)); //op
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] < 256 && rv[1] > -128) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]);
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_k32(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);

			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 128 + !!(rv[0] & 48));
			x86_64_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 32 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 36 + !!(rv[0] & 48)); //op
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] < 256 && rv[1] > -128) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]);
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_k32(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);

			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 128 + !!(rv[0] & 48));
			x86_64_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 40 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 44 + !!(rv[0] & 48)); //op
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] < 256 && rv[1] > -128) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_64_inst_byt(bin, bn, rv[1]);
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_k32(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);

			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 128 + !!(rv[0] & 48));
			x86_64_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 48 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 52 + !!(rv[0] & 48)); //op
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] < 256 && rv[1] > -128) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]);
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_k32(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);

			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 128 + !!(rv[0] & 48));
			x86_64_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xor");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 56 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 60 + !!(rv[0] & 48)); //op
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] < 256 && rv[1] > -128) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_64_inst_byt(bin, bn, rv[1]);
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_k32(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);

			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 128 + !!(rv[0] & 48));
			x86_64_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_64_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			x86_64_err_164(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 80 | (rv[0] & 7)); //op
		}
		else if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256) {
			x86_64_inst_byt(bin, bn, 106); //op
			x86_64_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 104); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "push");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			x86_64_err_164(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 88 | (rv[0] & 7)); //op
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'o' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 112); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 128); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 128); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jo");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'o' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 113); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 129); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jno");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'b' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 114); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 130); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 130); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jb");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'a' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 114); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 130); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 130); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnae");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'c' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 114); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 130); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 130); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jc");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 115); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnb");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'a' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 115); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jae");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 115); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 131); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnc");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'z' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 116); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 132); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 132); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jz");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'e' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 116); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 132); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 132); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "je");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'z' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 117); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 133); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 133); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnz");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 117); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 133); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 133); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jne");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'b' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 118); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 134); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 134); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jbe");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'a' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 118); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 134); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 134); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jna");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'b' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 119); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 135); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 135); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnbe");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'a' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 119); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 135); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 135); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ja");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 's' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 120); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 136); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 136); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "js");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 121); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 137); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 137); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jns");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'p' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 122); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 138); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 138); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jp");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'p' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 122); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 138); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 138); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jpe");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 123); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 139); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 139); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnp");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'p' && op[2] == 'o' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 123); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 139); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 139); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jpo");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'l' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 124); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 140); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 140); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jl");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'g' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 124); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 140); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 140); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnge");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 125); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnl");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'g' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 125); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jge");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'l' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 126); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 142); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 142); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jle");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'g' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 126); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 142); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 142); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jng");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'l' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 127); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnle");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'g' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_64_inst_byt(bin, bn, 127); //op
			x86_64_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 143); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jg");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'c' && op[2] == 'h' && op[3] == 'g' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 15) == 0) { //ax
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 144 + (rv[0] & 7)); //op
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xchg");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[2]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[2]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], rv[3]);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[3] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[1]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 136 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, (176 + (!!(rv[0] & 48) * 8)) | (rv[0] & 7)); //op
			x86_64_inst_mvp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] < 256 && rv[1] > -128) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] < 256 && rv[2] > -128) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 198); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_k32(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);

			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 199); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_k32(bin, bn, rv[3]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'e' && op[2] == 'a' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_rbp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_264(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[1] == 101 || rv[1] == 117)) {
			x86_64_err_264(rv[0], e, path, ln);
			*((uint8_t*) rv[2]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			x86_64_err_264(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_364(rv[2], e, path, ln);
			x86_64_err_reg(rv[1], rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_k32(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[1], rv[0]);
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 141); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[3]); //disp
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lea");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rol");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ror");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcl");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shl");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 5); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 5); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 6); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 6); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sal");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 209); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 2 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[0]) |= 4; //rel
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
			x86_64_inst_byt(bin, bn, rv[1]); //img
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_k8(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
			x86_64_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_k8(rv[3], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 193); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
			x86_64_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_64_err_k8(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] == 1) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[1] == 1) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 101 || rv[0] == 117) && rv[2] == 1) {
			*((uint8_t*) rv[0]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 5, 7); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 0, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 1, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] == 1) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 211); //op
			x86_64_inst_mod(bin, bn, 2, 4, 7); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sar");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k16(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 194); //op
			x86_64_inst_k16(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 0) {
			x86_64_inst_byt(bin, bn, 195); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ret");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] == 3) {
			x86_64_inst_byt(bin, bn, 204); //op
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k8(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 205); //op
			x86_64_inst_byt(bin, bn, rv[0]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "int");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 't' && op[3] == 'o' && op[4] == 0) {
		if (rt[0] == 0) {
			x86_64_inst_byt(bin, bn, 206); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "into");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'r' && op[2] == 'e' && op[3] == 't' && op[4] == 0) {
		if (rt[0] == 0) {
			x86_64_inst_byt(bin, bn, 207); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "iret");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'a' && op[2] == 'l' && op[3] == 'l' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 232); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 232); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_64_err_164(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "call");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 233); //op
			x86_64_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			x86_64_inst_byt(bin, bn, 233); //op
			x86_64_inst_k32(bin, bn, 0); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 4); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 4); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_64_err_164(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jmp");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 0); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 0); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 254 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "inc");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 5, 1); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 0, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 1, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 255); //op
			x86_64_inst_mod(bin, bn, 2, 4, 1); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 254 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "dec");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 5, 2); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 1, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 2, 4, 2); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 246 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "not");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'e' && op[2] == 'g' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 7) == 4) { //mod 0
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 0 && (rv[0] == 101 || rv[0] == 117)) {
			*((uint8_t*) rv[1]) |= 4; //rel
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 5, 3); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_rbp(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_64_err_k32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 0, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 5, 4); //sib
			x86_64_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			x86_64_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
		
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 1, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 2
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_k32(rv[1], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], 0, 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			x86_64_err_364(rv[0], e, path, ln);
			x86_64_err_364(rv[1], e, path, ln);
			x86_64_err_reg(rv[0], rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_prfx_leg(bin, bn, rv[0], 0);
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], 0);
			x86_64_inst_byt(bin, bn, 247); //op
			x86_64_inst_mod(bin, bn, 2, 4, 3); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_64_prfx_leg(bin, bn, 0, rv[0]);
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[0] & 48);
			x86_64_inst_byt(bin, bn, 246 + !!(rv[0] & 48)); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "neg");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'y' && op[2] == 's' && op[3] == 'c' && op[4] == 'a' && op[5] == 'l' && op[6] == 'l' && op[7] == 0) {
		if (rt[0] == 0) {
			x86_64_inst_byt(bin, bn, 15); //op
			x86_64_inst_byt(bin, bn, 5); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "syscall");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
