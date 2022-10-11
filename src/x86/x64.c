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
}

void x86_64_err_r8h(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_64_err_r8l(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r == 4 || r == 5 || r == 6 || r == 7 || (r > 15 && r != 68 && r != 69 && r != 70 && r != 71)) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_64_err_r16(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 31) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_64_err_r32(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 32 || r > 47) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_64_err_r64(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 48 || r > 63) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_64_err_rsp(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 15) == 4) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
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

uint8_t x86_64_err_scl(uint64_t a, int8_t* e, int8_t* path, uint64_t ln) {
	if (a == 1) {
		return 0;
	}
	else if (a == 2) {
		return 1;
	}
	else if (a == 4) {
		return 2;
	}
	else if (a == 8) {
		return 3;
	}
	else {
		printf("[%s, %lu] error: illegal scale '%lu'\n", path, ln, a);
		*e = -1;
	}
}

void x86_64_inst_byt(uint8_t* bin, uint64_t* bn, uint8_t a) {
	bin[*bn] = a;
	(*bn)++;
}

void x86_64_prfx_rex(uint8_t* bin, uint64_t* bn, uint8_t r0, uint8_t r1, uint8_t r2) {
	if ((r0 & 8) || (r1 & 8) || (r2 & 8)) {
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
		(*bn)++;
	}
}

void x86_64_inst_mod(uint8_t* bin, uint64_t* bn, uint8_t m, uint8_t rd, uint8_t rs) {
	bin[*bn] = (m << 6) | ((rs & 7) << 3) | (rd & 7);
	(*bn)++;
}

void x86_64_inst_k8(uint8_t* bin, uint64_t* bn, uint8_t k) {
	*(bin + *bn) = k;
	*bn += 1;
}

void x86_64_inst_k16(uint8_t* bin, uint64_t* bn, uint16_t k) {
	*((uint16_t*) bin + (*bn / 2)) = k;
	*bn += 2;
}

void x86_64_inst_k32(uint8_t* bin, uint64_t* bn, uint32_t k) {
	*((uint32_t*) bin + (*bn / 4)) = k;
	*bn += 4;
}

void x86_64_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 112) == 32 && (rv[0] & 7) != 4 && (rv[0] & 7) != 5) { //32 bit ar m0
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] == 36 || rv[0] == 44)) {
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 112) == 32) {
			x86_64_err_r32(rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			x86_64_err_r32(rv[2], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[2]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 112) == 32) {
			x86_64_err_r32(rv[1], e, path, ln);
			x86_64_err_rsp(rv[1], e, path, ln);
			uint8_t s = x86_64_err_scl(rv[2], e, path, ln);
			x86_64_err_r32(rv[3], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], rv[1], rv[3]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 101) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_r32(rv[2], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 4 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 112) == 32) {
			x86_64_err_k32(0, e, path, ln); //rel todo
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, 0, 0, rv[1]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 112) == 32 && (rv[0] & 7) != 4 && rv[1] < 256) { //32 bit ar m1
			x86_64_err_r32(rv[2], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			x86_64_inst_k8(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 36 || rv[0] == 44) && rv[1] < 256) {
			x86_64_err_r32(rv[2], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k8(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 5 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 112) == 32 && rv[1] < 256) {
			x86_64_err_r32(rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_r32(rv[3], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], rv[2], rv[3]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[2]); //sib
			x86_64_inst_k8(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 5 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && (rv[0] & 112) == 32 && rv[1] < 256) {
			x86_64_err_r32(rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			uint8_t s = x86_64_err_scl(rv[3], e, path, ln);
			x86_64_err_r32(rv[4], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], rv[2], rv[4]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			x86_64_inst_mod(bin, bn, s, rv[0], rv[2]); //sib
			x86_64_inst_k8(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 112) == 32 && (rv[0] & 7) != 4) { //32 bit ar m2
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_r32(rv[2], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] == 36 || rv[0] == 44)) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_r32(rv[2], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[2]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[1]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 5 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 112) == 32) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_r32(rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_r32(rv[3], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], rv[2], rv[3]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[0], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 5 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && (rv[0] & 112) == 32) {
			x86_64_err_k32(rv[1], e, path, ln);
			x86_64_err_r32(rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			uint8_t s = x86_64_err_scl(rv[3], e, path, ln);
			x86_64_err_r32(rv[4], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], rv[2], rv[4]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			x86_64_inst_mod(bin, bn, s, rv[0], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 112) == 32) { //32 bit rr mod3
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_prfx_rex(bin, bn, rv[0], 0, rv[1]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 112) == 32 && (rv[1] & 7) != 4 && (rv[1] & 7) != 5) { //32 bit ra m0
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] == 36 || rv[1] == 44)) {
			x86_64_err_r32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[0] & 112) == 32) {
			x86_64_err_r32(rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 112) == 32) {
			x86_64_err_r32(rv[2], e, path, ln);
			x86_64_err_rsp(rv[2], e, path, ln);
			uint8_t s = x86_64_err_scl(rv[3], e, path, ln);
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], rv[2], rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 101) {
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_r32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0 && (rv[0] & 112) == 32) {
			x86_64_err_k32(rv[2], e, path, ln); //rel todo
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, 0, 0, rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
			x86_64_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 112) == 32 && (rv[1] & 7) != 4 && rv[2] < 256) { //32 bit ra m1
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			x86_64_inst_k8(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 36 || rv[1] == 44) && rv[2] < 256) {
			x86_64_err_r32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k8(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 5 && rt[4] == 0 && (rv[0] & 112) == 32 && rv[2] < 256) {
			x86_64_err_r32(rv[3], e, path, ln);
			x86_64_err_rsp(rv[3], e, path, ln);
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], rv[3], rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[3]); //sib
			x86_64_inst_k8(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 112) == 32 && rv[2] < 256) {
			x86_64_err_r32(rv[3], e, path, ln);
			x86_64_err_rsp(rv[3], e, path, ln);
			uint8_t s = x86_64_err_scl(rv[4], e, path, ln);
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], rv[3], rv[0]);
			x86_64_inst_byt(bin, bn, 3); //op
			x86_64_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, s, rv[1], rv[3]); //sib
			x86_64_inst_k8(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 112) == 32 && (rv[1] & 7) != 4) { //32 bit ra m2
			x86_64_err_r32(rv[0], e, path, ln);
			x86_64_err_k32(rv[2], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] == 36 || rv[1] == 44)) {
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_r32(rv[0], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], 0, rv[0]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, 4, 4); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 5 && rt[4] == 0 && (rv[0] & 112) == 32) {
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_r32(rv[3], e, path, ln);
			x86_64_err_rsp(rv[3], e, path, ln);
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[1], rv[3], rv[0]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			x86_64_inst_mod(bin, bn, 0, rv[1], rv[3]); //sib
			x86_64_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 112) == 32) {
			x86_64_err_k32(rv[2], e, path, ln);
			x86_64_err_r32(rv[3], e, path, ln);
			x86_64_err_rsp(rv[3], e, path, ln);
			uint8_t s = x86_64_err_scl(rv[4], e, path, ln);
			x86_64_err_r32(rv[1], e, path, ln);
			
			x86_64_inst_byt(bin, bn, 103); //leg addr
			x86_64_prfx_rex(bin, bn, rv[0], rv[2], rv[4]);
			x86_64_inst_byt(bin, bn, 1); //op
			x86_64_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			x86_64_inst_mod(bin, bn, s, rv[0], rv[2]); //sib
			x86_64_inst_k32(bin, bn, rv[1]); //disp
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
