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

void x86_err_k8(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128 || k > 255) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void x86_err_k16(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32768 || k > 65535) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

uint8_t x86_err_a16(uint8_t rb, uint8_t ri, int8_t* e, int8_t* path, uint64_t ln) {
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
	*((uint16_t*) bin + (*bn / 2)) = k;
	*bn += 2;
}

void x86_inst_lcp(uint8_t* bin, uint64_t* bn, uint8_t r, uint32_t k) {
	if ((r & 32) == 0) {
		x86_inst_byt(bin, bn, k);
	}
	else if ((r & 32) == 16) {
		x86_inst_k16(bin, bn, k);
	}
}

void x86_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 4 + !!(rv[0] & 48)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 12 + !!(rv[0] & 48)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 1); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "or");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 20 + !!(rv[0] & 48)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 2); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 2); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 28 + !!(rv[0] & 48)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 3); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 3); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 3); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 36 + !!(rv[0] & 48)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 4); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 4); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 44 + !!(rv[0] & 48)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 5); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 5); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 5); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 52 + !!(rv[0] & 48)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 6); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xor");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			x86_inst_byt(bin, bn, 60 + !!(rv[0] & 48)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 131); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 0, 6, 7); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 1, a, 7); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 129); //op
			x86_inst_mod(bin, bn, 2, a, 7); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
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
		else if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, 6, 6); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 6); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
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
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			x86_err_r16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 88 | (rv[0] & 7)); //op
		}
		else if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 143); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
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
	else if (op[0] == 'x' && op[1] == 'c' && op[2] == 'h' && op[3] == 'g' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 15) == 0) { //ax
			x86_err_r16(rv[0], e, path, ln);
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 144 + (rv[0] & 7)); //op
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xchg");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[3] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			x86_err_reg(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) { //mod 2
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			x86_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //axk
			x86_inst_byt(bin, bn, (176 + (!!(rv[0] & 48) * 8)) | (rv[0] & 7)); //op
			x86_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			x86_err_k16(rv[0], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //disp
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 198); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			x86_err_k16(rv[0], e, path, ln);
			x86_err_k16(rv[1], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 0, 6, 0); //modrm
			x86_inst_k16(bin, bn, rv[0]); //disp
			x86_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[2]); //imm
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			x86_err_k16(rv[3], e, path, ln);
			
			x86_inst_byt(bin, bn, 199); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'e' && op[2] == 'a' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) { //mod 0
			x86_err_r16(rv[0], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) { //mod 1
			x86_err_r16(rv[0], e, path, ln);
			uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 141); //op
			x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			x86_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 2); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
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
		if (rt[0] == 2 && rt[1] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 4); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
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
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 0); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 0); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_inst_byt(bin, bn, 254 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "inc");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0) { //mod 0
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 1, a, 1); //modrm
			x86_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
			x86_err_k16(rv[2], e, path, ln);
			
			x86_inst_byt(bin, bn, 255); //op
			x86_inst_mod(bin, bn, 2, a, 1); //modrm
			x86_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			x86_inst_byt(bin, bn, 254 + !!(rv[0] & 48)); //op
			x86_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "dec");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
