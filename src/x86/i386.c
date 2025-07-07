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
}

void i386_err_r8(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 7) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_r16(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 23) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_r32(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 32 || r > 39) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_rsp(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 7) == 4) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_rbp(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 7) == 5) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_132(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 48) == 0) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_k8(uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 255) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void i386_err_k16(uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 65535) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void i386_err_k32(uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > 4294967295) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

void i386_err_lcp(uint8_t r, uint32_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if ((r & 48) == 0 && k > 255) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
	else if ((r & 48) == 16 && k > 65535) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
	else if ((r & 48) == 32 && k > 4294967295) {
		printf("[%s, %lu] error: immediate '%u' out of range\n", path, ln, k);
		*e = -1;
	}
}

uint8_t i386_err_s8(uint64_t k, uint8_t* e, int8_t* path, uint64_t ln) {
	if (k == 1) {
		return 0;
	}
	else if (k == 2) {
		return 1;
	}
	else if (k == 4) {
		return 2;
	}
	else if (k == 8) {
		return 3;
	}
	else {
		printf("[%s, %lu] error: illegal scalar '%u'\n", path, ln, k);
		*e = -1;
	}
}

uint8_t i386_err_a16(uint8_t b, uint8_t i, int8_t* e, int8_t* path, uint64_t ln) {
	if ((i & 48) != 16 && i != 8) {
		printf("[%s, %lu] error: illegal index '%u'\n", path, ln, i386_dec_reg(i));
		*e = -1;
	}
	b &= 15;
	i &= 15;
	if (b == 3 && i == 6) {
		return 0;
	}
	else if (b == 3 && i == 7) {
		return 1;
	}
	else if (b == 5 && i == 6) {
		return 2;
	}
	else if (b == 5 && i == 7) {
		return 3;
	}
	else if (b == 6 && i == 8) {
		return 4;
	}
	else if (b == 7 && i == 8) {
		return 5;
	}
	else if (b == 5 && i == 8) {
		return 6;
	}
	else if (b == 3 && i == 8) {
		return 7;
	}
	else if (i == 8) {
		printf("[%s, %lu] error: illegal base register '%u'\n", path, ln, i386_dec_reg(b));
	}
	else {
		printf("[%s, %lu] error: illegal base/index register pair '%u, (%u)'\n", path, ln, i386_dec_reg(b), i386_dec_reg(i));
		*e = -1;
	}
}

void i386_err_reg(uint8_t rd, uint8_t rs, int8_t* e, int8_t* path, uint64_t ln) {
	if ((rd & 48) != (rs & 48)) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(rs));
		*e = -1;
	}
}

void i386_prfx_leg(uint8_t* bin, uint64_t* bn, uint8_t r) {
	if ((r & 48) == 16) {
		bin[*bn] = 102;
		(*bn)++;
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

void i386_inst_lcp(uint8_t* bin, uint64_t* bn, uint8_t r, uint32_t k) {
	if ((r & 48) == 0) {
		i386_inst_byt(bin, bn, k);
	}
	else if ((r & 48) == 16) {
		i386_inst_k16(bin, bn, k);
	}
	else {
		i386_inst_k32(bin, bn, k);
	}
}

void i386_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 21) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 21) {
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) {
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 0 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 0 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 37) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 37) {
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 4 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) && rv[1] < 256) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_lcp(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r8(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "addb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "addw");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 'd' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "addd");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 21) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 21) {
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) {
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 8 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 8 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 37) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 37) {
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 12 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) && rv[1] < 256) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_lcp(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "or");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r8(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orb");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'w' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orw");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ord");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 21) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 21) {
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) {
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 16 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 16 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 37) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 37) {
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 20 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) && rv[1] < 256) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_lcp(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r8(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adcb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adcw");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 'd' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adcd");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 21) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 21) {
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) {
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 24 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 24 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 37) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 37) {
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 28 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) && rv[1] < 256) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_lcp(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r8(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbbb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbbw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 'd' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbbd");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 21) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 21) {
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) {
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 32 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 32 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 37) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 37) {
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 36 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) && rv[1] < 256) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_lcp(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r8(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "andb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "andw");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 'd' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "andd");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 21) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 21) {
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) {
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 40 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 40 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 37) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 37) {
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 44 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) && rv[1] < 256) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_lcp(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r8(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subb");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subw");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 'd' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "subd");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 21) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 21) {
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) {
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 48 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 48 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 37) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 37) {
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 52 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) && rv[1] < 256) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_lcp(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xor");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r8(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xorb");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xorw");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 'd' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xord");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[1]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 21) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 21) {
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 16)); //op
			i386_inst_mod(bin, bn, 0, 6, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) {
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 56 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 56 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 37) { //mod 0
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 37) {
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 15) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 60 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) && rv[1] < 256) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_lcp(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0 16 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0 32 bit
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r8(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmpb");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 'w' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k16(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k16(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r16(rv[0], e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmpw");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 'd' && op[4] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21 && rv[1] < 256) { //mod 0 16 bit
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21 && rv[2] < 256) {
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 21) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 21) {
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 6, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37 && rv[1] < 256) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37 && rv[2] < 256) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) {
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 37) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, 0); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 37) {
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmpd");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			i386_err_132(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 80 | (rv[0] & 7)); //op
		}
		else if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256) {
			i386_inst_byt(bin, bn, 106); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 104); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && rv[0] == 36) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "push");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			i386_err_132(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 88 | (rv[0] & 7)); //op
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && rv[0] == 36) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'o' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 112); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 128); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jo");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'o' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 113); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jno");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'b' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 114); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 130); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 130); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jb");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'a' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 114); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 130); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 130); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnae");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'c' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 114); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 130); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 130); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jc");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 115); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnb");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'a' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 115); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jae");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 115); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnc");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'z' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 116); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 132); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 132); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jz");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'e' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 116); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 132); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 132); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "je");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'z' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 117); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 133); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 133); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnz");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 117); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 133); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 133); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jne");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'b' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 118); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 134); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 134); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jbe");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'a' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 118); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 134); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 134); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jna");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'b' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 119); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 135); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 135); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnbe");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'a' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 119); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 135); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 135); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ja");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 's' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 120); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 136); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 136); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "js");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 121); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 137); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 137); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jns");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'p' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 122); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 138); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 138); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jp");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'p' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 122); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 138); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 138); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jpe");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 123); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 139); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 139); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnp");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'p' && op[2] == 'o' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 123); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 139); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 139); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jpo");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'l' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 124); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 140); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 140); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jl");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'g' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 124); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 140); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 140); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnge");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 125); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnl");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'g' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 125); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jge");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'l' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 126); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 142); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 142); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jle");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'g' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 126); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 142); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 142); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jng");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'n' && op[2] == 'l' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 127); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jnle");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'g' && op[2] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 127); //op
			i386_inst_byt(bin, bn, rv[0]);
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 15); //op
			i386_inst_byt(bin, bn, 143); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jg");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'c' && op[2] == 'h' && op[3] == 'g' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[1] & 15) == 0) { //ax
			i386_err_132(rv[0], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 144 + (rv[0] & 7)); //op
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //16 bit mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) { //32 bit mod 0
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 134 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xchg");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 136 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[3]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[2]); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 136 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36) { //mod 0 32 bit
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 136 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 136 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 136 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 136 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 136 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[0], rv[2]); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 136 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[3]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[4]);
			i386_inst_byt(bin, bn, 136 + !!(rv[4] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[4]); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) { //mod 0
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 138 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, (176 + (!!(rv[0] & 48) * 8)) | (rv[0] & 7)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 0
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] < 256) { //mod 1
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] < 256) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 198); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) { //mod 0
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_k32(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 199); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_k32(bin, bn, rv[4]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'e' && op[2] == 'a' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			i386_err_132(rv[0], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[1] & 48) == 16) {
			i386_err_132(rv[0], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			i386_err_132(rv[0], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			i386_err_132(rv[0], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16) { //mod 2
			i386_err_132(rv[0], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			i386_err_132(rv[0], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[1] == 36) { //mod 0
			i386_err_132(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 0, rv[1], rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_err_132(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && rv[4] < 256) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[1] == 36) { //mod 2
			i386_err_132(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[6]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 2, rv[1], rv[0]); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0) {
			i386_err_132(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 141); //op
			i386_inst_mod(bin, bn, 2, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lea");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) { //mod 0
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rol");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) { //mod 0
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ror");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) { //mod 0
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcl");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'c' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) { //mod 0
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rcr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) { //mod 0
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shl");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'h' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) { //mod 0
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "shr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) { //mod 0
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sal");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'a' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 209); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 208 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[0] == 36) { //mod 0
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			i386_err_k8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			i386_err_k8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 2 && rt[5] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			i386_err_k8(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 193); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
			i386_inst_byt(bin, bn, rv[4]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 192 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] == 1) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[2] == 1) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] == 1) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] == 1) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 36 && rv[1] == 1) { //mod 0
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[1] < 256 && rv[2] == 1) { //mod 1
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[3] < 256 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[0] == 36 && rv[2] == 1) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[2] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[3] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 1 && rt[5] == 0 && rv[4] == 1) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 211); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && rv[1] == 1) {
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 210 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sar");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k16(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 194); //op
			i386_inst_k16(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 195); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ret");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] == 3) {
			i386_inst_byt(bin, bn, 204); //op
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k8(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 205); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "int");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 't' && op[3] == 'o' && op[4] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 206); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "into");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'r' && op[2] == 'e' && op[3] == 't' && op[4] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 207); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "iret");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 'n' && op[5] == 'z' && op[6] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 224); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			i386_inst_byt(bin, bn, 224); //op
			i386_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loopnz");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 'n' && op[5] == 'e' && op[6] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 224); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			i386_inst_byt(bin, bn, 224); //op
			i386_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loopne");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 'z' && op[5] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 225); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			i386_inst_byt(bin, bn, 225); //op
			i386_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loopz");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 'e' && op[5] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 225); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			i386_inst_byt(bin, bn, 225); //op
			i386_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loope");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'o' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 226); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			i386_inst_byt(bin, bn, 226); //op
			i386_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "loop");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'e' && op[2] == 'c' && op[3] == 'x' && op[4] == 'z' && op[5] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 227); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			i386_inst_byt(bin, bn, 227); //op
			i386_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jecxz");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'c' && op[2] == 'x' && op[3] == 'z' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 102); //leg
			i386_inst_byt(bin, bn, 227); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1; //rel
			
			i386_inst_byt(bin, bn, 102); //leg
			i386_inst_byt(bin, bn, 227); //op
			i386_inst_byt(bin, bn, 0); //imm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jcxz");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 0) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 228); //op
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 16) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg
			i386_inst_byt(bin, bn, 229); //op
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && rv[0] == 32) {
			i386_err_k8(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 228); //op
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 0 && rv[1] == 18) {
			i386_inst_byt(bin, bn, 236); //op
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 16 && rv[1] == 18) {
			i386_inst_byt(bin, bn, 102); //leg
			i386_inst_byt(bin, bn, 237); //op
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && rv[0] == 32 && rv[1] == 18) {
			i386_inst_byt(bin, bn, 237); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "in");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'u' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 1 && rt[2] == 0 && rv[1] == 0) {
			i386_err_k8(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 230); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 2 && rt[1] == 1 && rt[2] == 0 && rv[1] == 16) {
			i386_err_k8(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 102); //leg
			i386_inst_byt(bin, bn, 231); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 2 && rt[1] == 1 && rt[2] == 0 && rv[1] == 32) {
			i386_err_k8(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 231); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 18 && rv[1] == 0) {
			i386_inst_byt(bin, bn, 238); //op
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 18 && rv[1] == 16) {
			i386_inst_byt(bin, bn, 102); //leg
			i386_inst_byt(bin, bn, 239); //op
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && rv[0] == 18 && rv[1] == 32) {
			i386_inst_byt(bin, bn, 239); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "out");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'a' && op[2] == 'l' && op[3] == 'l' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 232); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 232); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && rv[0] == 36) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			i386_err_132(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "call");
			*e = -1;
		}
	}
	else if (op[0] == 'j' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rv[0] < 256 && rv[0] > -128) {
			i386_inst_byt(bin, bn, 235); //op
			i386_inst_byt(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 2 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 233); //op
			i386_inst_k32(bin, bn, rv[0]); //imm
		}
		else if (rt[0] == 3 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3; //rel
			
			i386_inst_byt(bin, bn, 233); //op
			i386_inst_k32(bin, bn, 0); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && rv[0] == 36) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			i386_err_132(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "jmp");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'o' && op[2] == 'c' && op[3] == 'k' && op[4] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 240); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lock");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'c' && op[2] == 'e' && op[3] == 'b' && op[4] == 'p' && op[5] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 241); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "icebp");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 'n' && op[4] == 'z' && op[5] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 242); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "repnz");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 'n' && op[4] == 'e' && op[5] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 242); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "repne");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 'z' && op[4] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 243); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "repz");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 243); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "repe");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 243); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rep");
			*e = -1;
		}
	}
	else if (op[0] == 'h' && op[1] == 'l' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 244); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "hlt");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 245); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmc");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && rv[0] == 36) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 246 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "not");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'e' && op[2] == 'g' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && rv[0] == 36) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 246 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "neg");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 248); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "clc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 249); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stc");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 250); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cli");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 251); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sti");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'l' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 252); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cld");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 0) {
			i386_inst_byt(bin, bn, 253); //op
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "std");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) { //mod 0 16 bit
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) { //mod 2
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0 && rv[1] == 36) { //mod 0 32 bit
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, rv[1], 4); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[1], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[1], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[2] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, rv[1], 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && rv[3] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 15) == 0 && rv[4] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[1] == 36) { //mod 2
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, rv[1], 4); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 15) == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 246 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[1], 4); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mul");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'm' && op[2] == 'u' && op[3] == 'l' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) { //mod 0 16 bit
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) { //mod 2
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0 && rv[1] == 36) { //mod 0 32 bit
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, rv[1], 5); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[1], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[1], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[2] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, rv[1], 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && rv[3] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 15) == 0 && rv[4] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[1] == 36) { //mod 2
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, rv[1], 5); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 15) == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 246 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[1], 5); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "imul");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'i' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) { //mod 0 16 bit
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) { //mod 2
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0 && rv[1] == 36) { //mod 0 32 bit
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, rv[1], 6); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[1], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[1], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[2] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, rv[1], 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && rv[3] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 15) == 0 && rv[4] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[1] == 36) { //mod 2
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, rv[1], 6); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 15) == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 246 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[1], 6); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "div");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'd' && op[2] == 'i' && op[3] == 'v' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) { //mod 0 16 bit
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16 && rv[2] < 256) { //mod 1
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16 && rv[3] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) { //mod 2
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && (rv[1] & 48) == 16) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0 && rv[1] == 36) { //mod 0 32 bit
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, rv[1], 7); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[1], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[1], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[1] == 36 && rv[2] < 256) { //mod 1
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[2] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, rv[1], 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0 && rv[3] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 15) == 0 && rv[4] < 256) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_byt(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0 && rv[1] == 36) { //mod 2
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, rv[1], 7); //modrm
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 6 && rt[4] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 9 && rt[3] == 10 && rt[4] == 6 && rt[5] == 0 && (rv[0] & 15) == 0) {
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			uint8_t s = i386_err_s8(rv[3], e, path, ln);
			i386_err_k32(rv[4], e, path, ln);
			
			i386_inst_byt(bin, bn, 247); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, s, rv[1], rv[2]); //sib
			i386_inst_k32(bin, bn, rv[4]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 15) == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 246 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[1], 7); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "idiv");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'n' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && rv[0] == 36) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 254 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "inc");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'e' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && rv[0] == 36) { //mod 0 32 bit
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 2 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36 && rv[1] < 256) { //mod 1
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[0] == 36) { //mod 2
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 6 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 9 && rt[2] == 10 && rt[3] == 6 && rt[4] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			uint8_t s = i386_err_s8(rv[2], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, s, rv[0], rv[1]); //sib
			i386_inst_k32(bin, bn, rv[3]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 0) { //mod 3
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 254 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
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
