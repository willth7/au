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

uint8_t i386_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
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
	else if (r[0] == 'e' && r[1] == 'i' && r[2] == 'p' && (r[3] == 0 || r[3] == ')')) { //32 bit ip
		return 101;
	}
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
		return 0;
	}
}

int8_t* i386_dec_reg(uint8_t r) {
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
	else if (r == 101) {
		return "eip";
	}
}

void i386_err_r8(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_r16(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 31) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_r32(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 32 || r > 47) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_rsp(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 15) == 4) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_k8(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128 || k > 255) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void i386_err_k16(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32768 || k > 65535) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void i386_err_k32(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -2147483648 || k > 4294967295) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

uint8_t i386_err_scl(uint64_t a, int8_t* e, int8_t* path, uint64_t ln) {
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

uint8_t i386_err_a16(uint8_t rb, uint8_t ri, int8_t* e, int8_t* path, uint64_t ln) {
	rb &= 7;
	ri &= 7;
	if (rb == 3 && ri == 6) {
		return 0;
	}
	else if (rb == 3 && ri == 7) {
		return 1;
	}
	else if (rb == 5 && ri == 6) {
		return 2;
	}
	else if (rb == 5 && ri == 7) {
		return 3;
	}
	else if (rb == 6 && ri == 8) {
		return 4;
	}
	else if (rb == 7 && ri == 8) {
		return 5;
	}
	else if (rb == 5 && ri == 8) {
		return 6;
	}
	else if (rb == 3 && ri == 8) {
		return 7;
	}
	else {
		printf("[%s, %lu] error: illegal base/index register pair '%u, %u'\n", path, ln, rb, ri);
		*e = -1;
	}
}

void i386_inst_byt(uint8_t* bin, uint64_t* bn, uint8_t a) {
	bin[*bn] = a;
	(*bn)++;
}

void i386_inst_mod(uint8_t* bin, uint64_t* bn, uint8_t m, uint8_t rd, uint8_t rs) {
	bin[*bn] = (m << 6) | ((rs & 7) << 3) | (rd & 7);
	(*bn)++;
}

void i386_inst_k8(uint8_t* bin, uint64_t* bn, uint8_t k) {
	bin[*bn] = k;
	*bn += 1;
}

void i386_inst_k16(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = k;
	bin[*bn + 1] = k >> 8;
	*bn += 2;
}

void i386_inst_k32(uint8_t* bin, uint64_t* bn, uint32_t k) {
	bin[*bn] = k;
	bin[*bn + 1] = k >> 8;
	bin[*bn + 2] = k >> 16;
	bin[*bn + 3] = k >> 24;
	*bn += 4;
}

uint8_t i386_enc_8r(uint8_t* bin, uint64_t* bn, uint8_t op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 48) == 0) {
		i386_err_k32(rv[0], e, path, ln);
		
		i386_inst_byt(bin, bn, op); //op
		i386_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
		i386_inst_k32(bin, bn, rv[0]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 0) {
		i386_err_r8(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op); //op
		i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 0) {
		i386_err_k32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 2); //op
		i386_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
		i386_inst_k32(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 0) {
		i386_err_k8(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 4); //op
		i386_inst_k8(bin, bn, rv[1]); //imm
		return 0;
	}
	return 1;
}

uint8_t i386_enc_16r(uint8_t* bin, uint64_t* bn, uint8_t op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
		uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
		i386_err_r16(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
		i386_err_r16(rv[1], e, path, ln);
		uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
		i386_err_r16(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
		uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
		i386_err_r16(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
		i386_inst_k8(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
		i386_err_r16(rv[1], e, path, ln);
		uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
		i386_err_r16(rv[3], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
		i386_inst_k8(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
		uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
		i386_err_k16(rv[1], e, path, ln);
		i386_err_r16(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
		i386_inst_k16(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
		i386_err_r16(rv[1], e, path, ln);
		uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
		i386_err_k16(rv[2], e, path, ln);
		i386_err_r16(rv[3], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
		i386_inst_k16(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 48) == 16) {
		i386_err_k32(rv[0], e, path, ln);
		
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 2, 5, rv[1]); //modrm
		i386_inst_k32(bin, bn, rv[0]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
		i386_err_r16(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 48) == 16) {
		uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
		i386_err_r16(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[0] & 48) == 16) {
		i386_err_r16(rv[1], e, path, ln);
		uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
		i386_err_r16(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
		uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
		i386_err_r16(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
		i386_inst_k8(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
		i386_err_r16(rv[1], e, path, ln);
		uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
		i386_err_r16(rv[3], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
		i386_inst_k8(bin, bn, rv[3]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
		uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
		i386_err_k16(rv[2], e, path, ln);
		i386_err_r16(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
		i386_inst_k16(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 48) == 16) {
		i386_err_r16(rv[1], e, path, ln);
		uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
		i386_err_k16(rv[3], e, path, ln);
		i386_err_r16(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, 103); //leg addr
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
		i386_inst_k16(bin, bn, rv[3]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) {
		i386_err_k32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 2, 5, rv[0]); //modrm
		i386_inst_k32(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 16) {
		i386_err_k16(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, 102); //leg op
		i386_inst_byt(bin, bn, op + 5); //op
		i386_inst_k16(bin, bn, rv[1]); //imm
		return 0;
	}
	return 1;
}

uint8_t i386_enc_32r(uint8_t* bin, uint64_t* bn, uint8_t op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 32 && (rv[0] & 7) != 4 && (rv[0] & 7) != 5) { //32 bit ar m0
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) {
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
		i386_inst_mod(bin, bn, 0, 4, 4); //sib
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 32) {
		i386_err_r32(rv[1], e, path, ln);
		i386_err_rsp(rv[1], e, path, ln);
		i386_err_r32(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
		i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 32) {
		i386_err_r32(rv[1], e, path, ln);
		i386_err_rsp(rv[1], e, path, ln);
		uint8_t s = i386_err_scl(rv[2], e, path, ln);
		i386_err_r32(rv[3], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
		i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 101) {
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
		i386_inst_k32(bin, bn, 0); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 101) {
		i386_err_k32(rv[1], e, path, ln);
		i386_err_r32(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 0, 5, rv[2]); //modrm
		i386_inst_k32(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 4 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 48) == 32) {
		i386_err_k32(0, e, path, ln); //rel todo
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 0, 5, rv[1]); //modrm
		i386_inst_k32(bin, bn, 0); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 32 && (rv[0] & 7) != 4 && rv[1] < 256) { //32 bit ar m1
		i386_err_r32(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
		i386_inst_k8(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) {
		i386_err_r32(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 1, 4, rv[1]); //modrm
		i386_inst_mod(bin, bn, 0, 4, 4); //sib
		i386_inst_k8(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 5 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 32 && rv[1] < 256) {
		i386_err_r32(rv[2], e, path, ln);
		i386_err_rsp(rv[2], e, path, ln);
		i386_err_r32(rv[3], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
		i386_inst_mod(bin, bn, 0, rv[0], rv[2]); //sib
		i386_inst_k8(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 5 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && (rv[0] & 48) == 32 && rv[1] < 256) {
		i386_err_r32(rv[2], e, path, ln);
		i386_err_rsp(rv[2], e, path, ln);
		uint8_t s = i386_err_scl(rv[3], e, path, ln);
		i386_err_r32(rv[4], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
		i386_inst_mod(bin, bn, s, rv[0], rv[2]); //sib
		i386_inst_k8(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 32 && (rv[0] & 7) != 4) { //32 bit ar m2
		i386_err_k32(rv[1], e, path, ln);
		i386_err_r32(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
		i386_inst_k32(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) {
		i386_err_k32(rv[1], e, path, ln);
		i386_err_r32(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 2, 4, rv[1]); //modrm
		i386_inst_mod(bin, bn, 0, 4, 4); //sib
		i386_inst_k32(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 5 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 32) {
		i386_err_k32(rv[1], e, path, ln);
		i386_err_r32(rv[2], e, path, ln);
		i386_err_rsp(rv[2], e, path, ln);
		i386_err_r32(rv[3], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
		i386_inst_mod(bin, bn, 0, rv[0], rv[2]); //sib
		i386_inst_k32(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 5 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && (rv[0] & 48) == 32) {
		i386_err_k32(rv[1], e, path, ln);
		i386_err_r32(rv[2], e, path, ln);
		i386_err_rsp(rv[2], e, path, ln);
		uint8_t s = i386_err_scl(rv[3], e, path, ln);
		i386_err_r32(rv[4], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
		i386_inst_mod(bin, bn, s, rv[0], rv[2]); //sib
		i386_inst_k32(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 32) { //32 bit rr mod3
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 1); //op
		i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 48) == 32 && (rv[1] & 7) != 4 && (rv[1] & 7) != 5) { //32 bit ra m0
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		return 0;
	}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) {
		i386_err_r32(rv[0], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
		i386_inst_mod(bin, bn, 0, 4, 4); //sib
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[0] & 48) == 32) {
		i386_err_r32(rv[2], e, path, ln);
		i386_err_rsp(rv[2], e, path, ln);
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
		i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 48) == 32) {
		i386_err_r32(rv[2], e, path, ln);
		i386_err_rsp(rv[2], e, path, ln);
		uint8_t s = i386_err_scl(rv[3], e, path, ln);
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
		i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 101) {
		i386_err_r32(rv[0], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
		i386_inst_k32(bin, bn, 0); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 101) {
		i386_err_k32(rv[2], e, path, ln);
		i386_err_r32(rv[0], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
		i386_inst_k32(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0 && (rv[0] & 48) == 32) {
		i386_err_k32(rv[2], e, path, ln); //rel todo
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 0, 5, rv[0]); //modrm
		i386_inst_k32(bin, bn, 0); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 32 && (rv[1] & 7) != 4 && rv[2] < 256) { //32 bit ra m1
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
		i386_inst_k8(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) {
		i386_err_r32(rv[0], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
		i386_inst_mod(bin, bn, 0, 4, 4); //sib
		i386_inst_k8(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 5 && rt[4] == 0 && (rv[0] & 48) == 32 && rv[2] < 256) {
		i386_err_r32(rv[3], e, path, ln);
		i386_err_rsp(rv[3], e, path, ln);
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
		i386_inst_mod(bin, bn, 0, rv[1], rv[3]); //sib
		i386_inst_k8(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 48) == 32 && rv[2] < 256) {
		i386_err_r32(rv[3], e, path, ln);
		i386_err_rsp(rv[3], e, path, ln);
		uint8_t s = i386_err_scl(rv[4], e, path, ln);
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
		i386_inst_mod(bin, bn, s, rv[1], rv[3]); //sib
		i386_inst_k8(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 32 && (rv[1] & 7) != 4) { //32 bit ra m2
		i386_err_r32(rv[0], e, path, ln);
		i386_err_k32(rv[2], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
		i386_inst_k32(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) {
		i386_err_k32(rv[2], e, path, ln);
		i386_err_r32(rv[0], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
		i386_inst_mod(bin, bn, 0, 4, 4); //sib
		i386_inst_k32(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 5 && rt[4] == 0 && (rv[0] & 48) == 32) {
		i386_err_k32(rv[2], e, path, ln);
		i386_err_r32(rv[3], e, path, ln);
		i386_err_rsp(rv[3], e, path, ln);
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
		i386_inst_mod(bin, bn, 0, rv[1], rv[3]); //sib
		i386_inst_k32(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 5 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 48) == 32) {
		i386_err_k32(rv[2], e, path, ln);
		i386_err_r32(rv[3], e, path, ln);
		i386_err_rsp(rv[3], e, path, ln);
		uint8_t s = i386_err_scl(rv[4], e, path, ln);
		i386_err_r32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 3); //op
		i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
		i386_inst_mod(bin, bn, s, rv[0], rv[2]); //sib
		i386_inst_k32(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 32) { //32 bit axk
		i386_err_k32(rv[1], e, path, ln);
		
		i386_inst_byt(bin, bn, op + 5); //op
		i386_inst_k32(bin, bn, rv[1]); //imm
		return 0;
	}
	return 1;
}

void i386_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		uint8_t eo = 1;
		if (eo) {
			eo = i386_enc_8r(bin, bn, 0, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = i386_enc_16r(bin, bn, 0, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = i386_enc_32r(bin, bn, 0, rt, rv, e, path, ln);
		}
		if (eo) {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
