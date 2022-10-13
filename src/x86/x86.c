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

void x86_inst_byt(uint8_t* bin, uint64_t* bn, uint8_t a) {
	bin[*bn] = a;
	(*bn)++;
}

void x86_inst_mod(uint8_t* bin, uint64_t* bn, uint8_t m, uint8_t rd, uint8_t rs) {
	bin[*bn] = (m << 6) | ((rs & 7) << 3) | (rd & 7);
	(*bn)++;
}

void x86_inst_k8(uint8_t* bin, uint64_t* bn, uint8_t k) {
	*(bin + *bn) = k;
	*bn += 1;
}

void x86_inst_k16(uint8_t* bin, uint64_t* bn, uint16_t k) {
	*((uint16_t*) bin + (*bn / 2)) = k;
	*bn += 2;
}

uint8_t x86_enc_8r(uint8_t* bin, uint64_t* bn, uint8_t op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 0) {
		x86_err_r8(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, op); //op
		x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 0) {
		x86_err_k8(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 4); //op
		x86_inst_k8(bin, bn, rv[1]); //imm
		return 0;
	}
	return 1;
}

uint8_t x86_enc_16r(uint8_t* bin, uint64_t* bn, uint8_t op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
		uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
		x86_err_r16(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
		x86_err_r16(rv[1], e, path, ln);
		uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
		x86_err_r16(rv[2], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		return 0;
	}
	else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 48) == 16) {
		x86_err_k16(rv[0], e, path, ln);
		
		x86_inst_byt(bin, bn, 102); //leg op
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
		x86_inst_k16(bin, bn, rv[0]); //disp
		return 0;
	}
	else if (rt[0] == 7 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 48) == 16) {
		x86_err_k16(rv[0], e, path, ln); //rel todo
		
		x86_inst_byt(bin, bn, 102); //leg op
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
		x86_inst_k16(bin, bn, 0); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
		uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
		x86_err_r16(rv[2], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 1, a, rv[2]); //modrm
		x86_inst_k8(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
		x86_err_r16(rv[1], e, path, ln);
		uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
		x86_err_r16(rv[3], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 1, a, rv[3]); //modrm
		x86_inst_k8(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
		uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
		x86_err_k16(rv[1], e, path, ln);
		x86_err_r16(rv[2], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
		x86_inst_k16(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 7 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
		uint8_t a = x86_err_a16(rv[0], 8, e, path, ln);
		x86_err_k16(rv[1], e, path, ln); //rel todo
		x86_err_r16(rv[2], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 2, a, rv[2]); //modrm
		x86_inst_k16(bin, bn, 0); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
		x86_err_r16(rv[1], e, path, ln);
		uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
		x86_err_k16(rv[2], e, path, ln);
		x86_err_r16(rv[3], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
		x86_inst_k16(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 7 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
		x86_err_r16(rv[1], e, path, ln);
		uint8_t a = x86_err_a16(rv[0], rv[1], e, path, ln);
		x86_err_k16(rv[2], e, path, ln); //rel todo
		x86_err_r16(rv[3], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 2, a, rv[3]); //modrm
		x86_inst_k16(bin, bn, 0); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 3
		x86_err_r16(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 1); //op
		x86_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
		uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
		x86_err_r16(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[0] & 48) == 16) {
		x86_err_r16(rv[1], e, path, ln);
		uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
		x86_err_r16(rv[2], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) {
		x86_err_k16(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, 102); //leg op
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
		x86_inst_k16(bin, bn, rv[1]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 7 && rt[2] == 0 && (rv[0] & 48) == 16) {
		x86_err_k16(rv[1], e, path, ln); //rel todo
		
		x86_inst_byt(bin, bn, 102); //leg op
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
		x86_inst_k16(bin, bn, 0); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 1
		uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
		x86_err_r16(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
		x86_inst_k8(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
		x86_err_r16(rv[1], e, path, ln);
		uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
		x86_err_r16(rv[3], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 1, a, rv[0]); //modrm
		x86_inst_k8(bin, bn, rv[3]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
		uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
		x86_err_k16(rv[2], e, path, ln);
		x86_err_r16(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
		x86_inst_k16(bin, bn, rv[2]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 7 && rt[3] == 0 && (rv[0] & 48) == 16) {
		uint8_t a = x86_err_a16(rv[1], 8, e, path, ln);
		x86_err_k16(rv[2], e, path, ln); //rel todo
		x86_err_r16(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
		x86_inst_k16(bin, bn, 0); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 48) == 16) {
		x86_err_r16(rv[1], e, path, ln);
		uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
		x86_err_k16(rv[3], e, path, ln);
		x86_err_r16(rv[2], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
		x86_inst_k16(bin, bn, rv[3]); //disp
		return 0;
	}
	else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 7 && rt[4] == 0 && (rv[0] & 48) == 16) {
		x86_err_r16(rv[1], e, path, ln);
		uint8_t a = x86_err_a16(rv[1], rv[2], e, path, ln);
		x86_err_k16(rv[3], e, path, ln); //rel todo
		x86_err_r16(rv[2], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 3); //op
		x86_inst_mod(bin, bn, 2, a, rv[0]); //modrm
		x86_inst_k16(bin, bn, 0); //disp
		return 0;
	}

	else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 16) { //axk
		x86_err_k16(rv[1], e, path, ln);
		
		x86_inst_byt(bin, bn, op + 5); //op
		x86_inst_k16(bin, bn, rv[1]); //imm
		return 0;
	}
	return 1;
}

void x86_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		uint8_t eo = 1;
		if (eo) {
			eo = x86_enc_8r(bin, bn, 0, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = x86_enc_16r(bin, bn, 0, rt, rv, e, path, ln);
		}
		if (eo) {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 0) {
		uint8_t eo = 1;
		if (eo) {
			eo = x86_enc_8r(bin, bn, 8, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = x86_enc_16r(bin, bn, 8, rt, rv, e, path, ln);
		}
		if (eo) {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "or");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		uint8_t eo = 1;
		if (eo) {
			eo = x86_enc_8r(bin, bn, 16, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = x86_enc_16r(bin, bn, 16, rt, rv, e, path, ln);
		}
		if (eo) {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 0) {
		uint8_t eo = 1;
		if (eo) {
			eo = x86_enc_8r(bin, bn, 24, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = x86_enc_16r(bin, bn, 24, rt, rv, e, path, ln);
		}
		if (eo) {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		uint8_t eo = 1;
		if (eo) {
			eo = x86_enc_8r(bin, bn, 32, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = x86_enc_16r(bin, bn, 32, rt, rv, e, path, ln);
		}
		if (eo) {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		uint8_t eo = 1;
		if (eo) {
			eo = x86_enc_8r(bin, bn, 40, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = x86_enc_16r(bin, bn, 40, rt, rv, e, path, ln);
		}
		if (eo) {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		uint8_t eo = 1;
		if (eo) {
			eo = x86_enc_8r(bin, bn, 48, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = x86_enc_16r(bin, bn, 48, rt, rv, e, path, ln);
		}
		if (eo) {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xor");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		uint8_t eo = 1;
		if (eo) {
			eo = x86_enc_8r(bin, bn, 56, rt, rv, e, path, ln);
		}
		if (eo) {
			eo = x86_enc_16r(bin, bn, 56, rt, rv, e, path, ln);
		}
		if (eo) {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
