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

uint8_t x86_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
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
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
		return 0;
	}
}

int8_t* x86_dec_reg(uint8_t r) {
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
}

void x86_err_r8(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_dec_reg(r));
		*e = -1;
	}
}

void x86_err_r16(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 31) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_dec_reg(r));
		*e = -1;
	}
}

void x86_err_k8(uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 255) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void x86_err_k16(uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 65535) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void x86_err_lcp(uint8_t r, uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 16) == 0 && k > 255) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
	else if ((r & 16) == 16 && k > 65535) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

uint8_t x86_err_a16(uint8_t rb, uint8_t ri, int8_t* e, int8_t* path, uint64_t ln) {
	rb &= 15;
	ri &= 15;
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
	else if (ri == 8) {
		printf("[%s, %lu] error: illegal base register '%s'\n", path, ln, x86_dec_reg(rb + 16));
		*e = -1;
	}
	else {
		printf("[%s, %lu] error: illegal base/index register pair '%s, (%s)'\n", path, ln, x86_dec_reg(rb + 16), x86_dec_reg(ri + 16));
		*e = -1;
	}
}

void x86_err_reg(uint8_t rd, uint8_t rs, int8_t* e, int8_t* path, uint64_t ln) {
	if ((rd & 32) != (rs & 32)) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, x86_dec_reg(rs));
		*e = -1;
	}
}

void x86_inst_byt(uint8_t* bin, uint64_t* bn, uint8_t a) {
	bin[*bn] = a;
	(*bn)++;
}

void x86_inst_mod(uint8_t* bin, uint64_t* bn, uint8_t m, uint8_t rd, uint8_t rs) {
	bin[*bn] = (m << 6) | ((rs & 7) << 3) | (rd & 7);
	(*bn)++;
}

void x86_inst_k16(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = k;
	bin[*bn + 1] = k >> 8;
	*bn += 2;
}

void x86_inst_lcp(uint8_t* bin, uint64_t* bn, uint8_t r, uint32_t k) {
	if ((r & 16) == 0) {
		x86_inst_byt(bin, bn, k);
	}
	else if ((r & 16) == 16) {
		x86_inst_k16(bin, bn, k);
	}
}

void x86_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 4 + !!(rv[0] & 16)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 16) && rv[1] < 256) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "addb");
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0  && rv[1] < 256) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "addw");
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 0) {
		if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 12 + !!(rv[0] & 16)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 16) && rv[1] < 256) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "or");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orb");
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'w' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orw");
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 20 + !!(rv[0] & 16)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 16) && rv[1] < 256) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adcb");
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adcw");
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 28 + !!(rv[0] & 16)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 16) && rv[1] < 256) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbbb");
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbbw");
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 36 + !!(rv[0] & 16)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 16) && rv[1] < 256) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "andb");
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "andw");
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 44 + !!(rv[0] & 16)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 16) && rv[1] < 256) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subb");
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subw");
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 52 + !!(rv[0] & 16)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 16) && rv[1] < 256) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xor");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xorb");
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xorw");
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 60 + !!(rv[0] & 16)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 16) && rv[1] < 256) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_lcp(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmpb");
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmpw");
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 80 | (rv[0] & 7)); //op
		}
		else if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256) {
			x86_inst_byt(bin, bn, 106); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 104); //op
			x86_inst_k16(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "push");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 'f' && op[5] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 156); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pushf");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 88 | (rv[0] & 7)); //op
		}
		else if (rt[0] == 6 && rt[1] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 'f' && op[4] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 157); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "popf");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 's' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 23 && rv[1] == 18) {
			x86_inst_byt(bin, bn, 108); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "insb");
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 's' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 23 && rv[1] == 18) {
			x86_inst_byt(bin, bn, 109); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "insw");
		}
	}
	else if (op[0] == 'o' && op[1] == 'u' && op[2] == 't' && op[3] == 's' && op[4] == 'b' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 18 && rv[1] == 22) {
			x86_inst_byt(bin, bn, 110); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "outsb");
		}
	}
	else if (op[0] == 'o' && op[1] == 'u' && op[2] == 't' && op[3] == 's' && op[4] == 'w' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 18 && rv[1] == 22) {
			x86_inst_byt(bin, bn, 111); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "outsw");
		}
	}
	else if (op[0] == 'j' && op[1] == 'o' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 112); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 112); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jo");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'o' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 113); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 113); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jno");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'b' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 114); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 114); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jb");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'a' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 114); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 114); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnae");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'c' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 114); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 114); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jc");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 115); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 115); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnb");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'a' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 115); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 115); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jae");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 115); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 115); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnc");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'z' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 116); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 116); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jz");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'e' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 116); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 116); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "je");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'z' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 117); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 117); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnz");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 117); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 117); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jne");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'b' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 118); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 118); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jbe");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'a' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 118); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 118); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jna");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'b' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 119); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 119); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnbe");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'a' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 119); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 119); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ja");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 's' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 120); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 120); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "js");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 121); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 121); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jns");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'p' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 122); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 122); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jp");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'p' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 122); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 122); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jpe");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 123); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 123); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnp");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'p' && op[2] == 'o' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 123); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 123); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jpo");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'l' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 124); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 124); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jl");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'g' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 124); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 124); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnge");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 125); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 125); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnl");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'g' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 125); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 125); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jge");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'l' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 126); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 126); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jle");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'g' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 126); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 126); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jng");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'l' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 127); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 127); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnle");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'g' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 127); //op
			x86_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 127); //op
			x86_inst_byt(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jg");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'h' && op[3] == 'f' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rv[0] == 4) {
			x86_inst_byt(bin, bn, 158); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sahf");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'a' && op[2] == 'h' && op[3] == 'f' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rv[0] == 4) {
			x86_inst_byt(bin, bn, 159); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lahf");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'c' && op[2] == 'h' && op[3] == 'g' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 15) == 0) { //ax
			x86_err_r16(rv[0], e, path, ln);
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 144 + (rv[0] & 7)); //op
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 134 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 134 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 134 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 134 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 134 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 134 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 134 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 134 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[1], rv[0]); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xchg");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[2] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[3] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			x86_inst_byt(bin, bn, (176 + (!!(rv[0] & 16) * 8)) | (rv[0] & 7)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "movb");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) { //mod 0
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "movw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'e' && op[2] == 'a' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) { //mod 0
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			x86_err_r16(rv[0], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			x86_err_r16(rv[0], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) { //mod 1
			x86_err_r16(rv[0], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			x86_err_r16(rv[0], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			x86_err_r16(rv[0], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			x86_err_r16(rv[0], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lea");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 's' && op[4] == 'b' && op[5] == 0) {
		if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0 && rv[0] == 23 && rv[1] == 22) {
			x86_inst_byt(bin, bn, 164); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "movsb");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 's' && op[4] == 'w' && op[5] == 0) {
		if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0 && rv[0] == 23 && rv[1] == 22) {
			x86_inst_byt(bin, bn, 165); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "movsw");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 's' && op[4] == 'b' && op[5] == 0) {
		if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0 && rv[0] == 23 && rv[1] == 22) {
			x86_inst_byt(bin, bn, 166); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmpsb");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 's' && op[4] == 'w' && op[5] == 0) {
		if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0 && rv[0] == 23 && rv[1] == 22) {
			x86_inst_byt(bin, bn, 167); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmpsw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'o' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 23 && (rv[1] & 7) == 0) {
			x86_inst_byt(bin, bn, 170 + !!(rv[0] & 16)); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stos");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'd' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 7) == 0 && rv[1] == 22) {
			x86_inst_byt(bin, bn, 172 + !!(rv[1] & 16)); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lods");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'c' && op[2] == 'a' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 23 && (rv[1] & 7) == 0) {
			x86_inst_byt(bin, bn, 174 + !!(rv[0] & 16)); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "scas");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 208 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 210 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rol");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'l' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rolb");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'l' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rolw");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 208 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 210 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ror");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rorb");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rorw");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 208 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 210 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcl");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'l' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rclb");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'l' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rclw");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 208 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 210 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcr");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcrb");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'r' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcrw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 208 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 210 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shl");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'l' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shlb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'l' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shlw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 208 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 210 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shrb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'r' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shrw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 208 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 210 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sal");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'l' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "salb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'l' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "salw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 208 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_inst_byt(bin, bn, 210 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sar");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 208); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 192); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 210); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sarb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'r' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 209); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			x86_err_k8(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k8(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 193); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 211); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sarw");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 194); //op
			x86_inst_k16(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 195); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ret");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] == 3) {
			x86_inst_byt(bin, bn, 204); //op
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_err_k8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 205); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "int");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 't' && op[3] == 'o' && op[4] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 206); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "into");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'r' && op[2] == 'e' && op[3] == 't' && op[4] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 207); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "iret");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 'n' && op[5] == 'z' && op[6] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 224); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rv[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 224); //op
			x86_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loopnz");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 'n' && op[5] == 'e' && op[6] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 224); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rv[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 224); //op
			x86_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loopne");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 'z' && op[5] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 225); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rv[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 225); //op
			x86_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loopz");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 'e' && op[5] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 225); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rv[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 225); //op
			x86_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loope");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 226); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rv[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 226); //op
			x86_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loop");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'c' && op[2] == 'x' && op[3] == 'z' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 227); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			x86_inst_byt(bin, bn, 227); //op
			x86_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jcxz");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 0) {
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 228); //op
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 16) {
			x86_err_k8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 229); //op
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 0 && rv[1] == 18) {
			x86_inst_byt(bin, bn, 236); //op
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16 && rv[1] == 18) {
			x86_inst_byt(bin, bn, 237); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "in");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'u' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 1 && rt[2] == 0 && rv[1] == 0) {
			x86_err_k8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 230); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 2 && rt[1] == 1 && rt[2] == 0 && rv[1] == 16) {
			x86_err_k8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 231); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 18 && rv[1] == 0) {
			x86_inst_byt(bin, bn, 238); //op
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 18 && rv[1] == 16) {
			x86_inst_byt(bin, bn, 239); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "out");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'a' && op[2] == 'l' && op[3] == 'l' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 232); //op
			x86_inst_k16(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 2; //rel
			
			x86_inst_byt(bin, bn, 232); //op
			x86_inst_k16(bin, bn, 0); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "call");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			x86_inst_byt(bin, bn, 235); //op
			x86_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 233); //op
			x86_inst_k16(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 2; //rel
			
			x86_inst_byt(bin, bn, 233); //op
			x86_inst_k16(bin, bn, 0); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jmp");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'c' && op[3] == 'k' && op[4] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 240); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lock");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 'n' && op[4] == 'z' && op[5] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 242); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "repnz");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 'n' && op[4] == 'e' && op[5] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 242); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "repne");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 'z' && op[4] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 243); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "repz");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 243); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "repe");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 243); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rep");
			*e = -1;
		}
	}
	else if (op[0] == 'h' && op[1] == 'l' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 244); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "hlt");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 245); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmc");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_inst_byt(bin, bn, 246 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "not");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 't' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "notb");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 't' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "notw");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'e' && op[2] == 'g' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_inst_byt(bin, bn, 246 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "neg");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'e' && op[2] == 'g' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "negb");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'e' && op[2] == 'g' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "negw");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_inst_byt(bin, bn, 246 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[1], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mul");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16) { //mod 0
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16 && rv[2] < 256) { //mod 1
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16 && rv[3] < 256) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16) { //mod 2
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_err_r8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 3, rv[1], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mulb");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16) { //mod 0
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16 && rv[2] < 256) { //mod 1
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16 && rv[3] < 256) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16) { //mod 2
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_err_r16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 3, rv[1], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mulw");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_inst_byt(bin, bn, 246 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[1], 5); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "imul");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'b' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16) { //mod 0
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16 && rv[2] < 256) { //mod 1
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16 && rv[3] < 256) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16) { //mod 2
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_err_r8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 3, rv[1], 5); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "imulb");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 'w' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16) { //mod 0
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16 && rv[2] < 256) { //mod 1
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16 && rv[3] < 256) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16) { //mod 2
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_err_r16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 3, rv[1], 5); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "imulw");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'i' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_inst_byt(bin, bn, 246 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[1], 6); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "div");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'i' && op[2] == 'v' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16) { //mod 0
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16 && rv[2] < 256) { //mod 1
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16 && rv[3] < 256) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16) { //mod 2
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_err_r8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 3, rv[1], 6); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "divb");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'i' && op[2] == 'v' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16) { //mod 0
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16 && rv[2] < 256) { //mod 1
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16 && rv[3] < 256) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16) { //mod 2
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_err_r16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 3, rv[1], 6); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "divw");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'd' && op[2] == 'i' && op[3] == 'v' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_inst_byt(bin, bn, 246 + !!(rv[1] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[1], 7); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "idiv");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'd' && op[2] == 'i' && op[3] == 'v' && op[4] == 'b' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16) { //mod 0
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16 && rv[2] < 256) { //mod 1
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16 && rv[3] < 256) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16) { //mod 2
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_err_r8(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 246); //op
			x86_inst_mod(bin, bn, 3, rv[1], 7); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "idivb");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'd' && op[2] == 'i' && op[3] == 'v' && op[4] == 'w' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16) { //mod 0
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16 && rv[2] < 256) { //mod 1
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16 && rv[3] < 256) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[0] == 16) { //mod 2
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[0] == 16) {
			x86_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[0] == 16) { //mod 3
			x86_err_r16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 247); //op
			x86_inst_mod(bin, bn, 3, rv[1], 7); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "idivw");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 248); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "clc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 249); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stc");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 250); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cli");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 251); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sti");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 252); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cld");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 0) {
			x86_inst_byt(bin, bn, 253); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "std");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_inst_byt(bin, bn, 254 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "inc");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "incb");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "incw");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_inst_byt(bin, bn, 254 + !!(rv[0] & 16)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "dec");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r8(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 254); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "decb");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "decw");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
