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

uint8_t i386_err_a16(uint8_t b, uint8_t i, int8_t* e, int8_t* path, uint64_t ln) {
	if (i < 16 || i > 23) {
		printf("[%s, %lu] error: illegal index '%s'\n", path, ln, i386_dec_reg(i));
		*e = -1;
	}
	b &= 7;
	i &= 7;
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
	else {
		printf("[%s, %lu] error: illegal base/index register pair '%u, %u'\n", path, ln, i386_dec_reg(b), i386_dec_reg(i));
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

void i386_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, int64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 0 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 4 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 0); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 0); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 0); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0 32 bit
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 0 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			i386_err_r32(rv[1], e, path, ln);
			i386_err_rbp(rv[1], e, path, ln);
			
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 2 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 0); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
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
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);

			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 0); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 0); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 8 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 12 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 1); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 1); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 1); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0 32 bit
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 8 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			i386_err_r32(rv[1], e, path, ln);
			i386_err_rbp(rv[1], e, path, ln);
			
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 10 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 1); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
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
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);

			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 1); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 1); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "or");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 16 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 20 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 2); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 2); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 2); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0 32 bit
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 16 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			i386_err_r32(rv[1], e, path, ln);
			i386_err_rbp(rv[1], e, path, ln);
			
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 18 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 2); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
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
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);

			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 2); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 2); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 24 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 28 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 3); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 3); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 3); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0 32 bit
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 24 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			i386_err_r32(rv[1], e, path, ln);
			i386_err_rbp(rv[1], e, path, ln);
			
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 26 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 3); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
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
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);

			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 3); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 3); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbb");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 32 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 36 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 4); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 4); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 4); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0 32 bit
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 32 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			i386_err_r32(rv[1], e, path, ln);
			i386_err_rbp(rv[1], e, path, ln);
			
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 34 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 4); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
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
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);

			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 4); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 4); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 40 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 44 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 5); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 5); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 5); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0 32 bit
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 40 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			i386_err_r32(rv[1], e, path, ln);
			i386_err_rbp(rv[1], e, path, ln);
			
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 42 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 5); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
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
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);

			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 5); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 5); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'x' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 48 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 52 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 6); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0 32 bit
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 48 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			i386_err_r32(rv[1], e, path, ln);
			i386_err_rbp(rv[1], e, path, ln);
			
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 50 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 6); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
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
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);

			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "xor");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0 16 bit
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[2]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[3]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 56 + !!(rv[3] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[3]); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, a, rv[0]); //modrm
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[1], 8, e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, a, rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && (rv[1] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[1], rv[2], e, path, ln);
			i386_err_k16(rv[3], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 2, a, rv[0]); //modrm
			i386_inst_k16(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 0) { //axk
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 60 + !!(rv[0] & 48)); //op
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[3]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) { //mod 2
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k16(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[3] < 256 && rv[3] > -128) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) != 0 && rv[1] < 256 && rv[1] > -128) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 48) == 16) { //mod 0
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 0, a, 7); //modrm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, a, 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			i386_err_k32(rv[3], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 2, a, 7); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 1 && rt[1] == 2 && rt[2] == 0) { //mod 3
			i386_err_reg(rv[0], rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 128 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 3, rv[0], 7); //modrm
			i386_inst_lcp(bin, bn, rv[0], rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0 32 bit
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 1 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[1]);
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 1 && rt[3] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 1 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[1] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[1]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[2]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[2]);
			i386_inst_byt(bin, bn, 56 + !!(rv[2] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[0], rv[2]); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 1 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 1 && rt[4] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 0 && (rv[1] & 7) == 4) { //mod 0
			i386_err_r32(rv[1], e, path, ln);
			i386_err_rbp(rv[1], e, path, ln);
			
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 0) {
			i386_err_r32(rv[1], e, path, ln);
			i386_err_r32(rv[2], e, path, ln);
			i386_err_reg(rv[1], rv[2], e, path, ln);
			i386_err_rsp(rv[2], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, rv[1], rv[2]); //sib
		}
		else if (rt[0] == 1 && rt[1] == 6 && rt[2] == 0) {
			i386_err_k32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 0, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, 4, rv[0]); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[1], e, path, ln);
			
			i386_prfx_leg(bin, bn, rv[0]);
			i386_inst_byt(bin, bn, 58 + !!(rv[0] & 48)); //op
			i386_inst_mod(bin, bn, 1, rv[1], rv[0]); //modrm
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[1] & 7) == 4) { //mod 2
			i386_err_r32(rv[1], e, path, ln);
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
		else if (rt[0] == 1 && rt[1] == 5 && rt[2] == 5 && rt[3] == 6 && rt[4] == 0) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_byt(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[2] < 256 && rv[2] > -128) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 2, rv[0], 7); //modrm
			i386_inst_k32(bin, bn, rv[1]); //disp
			i386_inst_byt(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[3] < 256 && rv[3] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 2 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 0
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 2 && rt[3] == 0) {
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
		else if (rt[0] == 6 && rt[1] == 2 && rt[2] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			i386_err_k32(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 131); //op
			i386_inst_mod(bin, bn, 0, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
			i386_inst_k32(bin, bn, rv[1]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);

			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, 4, 7); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_k32(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 129); //op
			i386_inst_mod(bin, bn, 1, rv[0], 7); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
			i386_inst_k32(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 2 && rt[3] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 2 && rt[4] == 0) {
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, a, 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 48) == 16 && rv[1] < 256 && rv[1] > -128) { //mod 1
			uint8_t a = i386_err_a16(rv[0], 8, e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, a, 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16 && rv[2] < 256 && rv[2] > -128) {
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && (rv[0] & 48) == 16) {
			uint8_t a = i386_err_a16(rv[0], rv[1], e, path, ln);
			i386_err_k16(rv[2], e, path, ln);
			
			i386_inst_byt(bin, bn, 103); //leg addr
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 2, a, 6); //modrm
			i386_inst_k16(bin, bn, rv[2]); //imm
		}
		else if (rt[0] == 5 && rt[1] == 0 && (rv[0] & 7) == 4) { //mod 0 32 bit
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
		}
		else if (rt[0] == 5 && rt[1] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_rbp(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, rv[0], 6); //modrm
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 0) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
		}
		else if (rt[0] == 6 && rt[1] == 0) {
			i386_err_k32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 0, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 5, 4); //sib
			i386_inst_k32(bin, bn, rv[0]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4 && rv[1] < 256 && rv[1] > -128) { //mod 1
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, 4, 4); //sib
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && rv[1] < 256 && rv[1] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, rv[0], 6); //modrm
			i386_inst_byt(bin, bn, rv[1]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0 && rv[2] < 256 && rv[2] > -128) {
			i386_err_r32(rv[0], e, path, ln);
			i386_err_r32(rv[1], e, path, ln);
			i386_err_reg(rv[0], rv[1], e, path, ln);
			i386_err_rsp(rv[1], e, path, ln);
		
			i386_inst_byt(bin, bn, 255); //op
			i386_inst_mod(bin, bn, 1, 4, 6); //modrm
			i386_inst_mod(bin, bn, 0, rv[0], rv[1]); //sib
			i386_inst_byt(bin, bn, rv[2]); //disp
		}
		else if (rt[0] == 5 && rt[1] == 6 && rt[2] == 0 && (rv[0] & 7) == 4) { //mod 2
			i386_err_r32(rv[0], e, path, ln);
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
		else if (rt[0] == 5 && rt[1] == 5 && rt[2] == 6 && rt[3] == 0) {
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
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
