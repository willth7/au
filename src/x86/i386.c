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

void i386_err_r8h(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register '%s'\n", path, ln, i386_dec_reg(r));
		*e = -1;
	}
}

void i386_err_r8l(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r == 4 || r == 5 || r == 6 || r == 7 || (r > 15 && r != 68 && r != 69 && r != 70 && r != 71)) {
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

void i386_inst_byt(uint8_t* bin, uint64_t* bn, uint8_t a) {
	bin[*bn] = a;
	(*bn)++;
}

void i386_prfx_rex(uint8_t* bin, uint64_t* bn, uint8_t r0, uint8_t r1, uint8_t r2) {
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

void i386_inst_mod(uint8_t* bin, uint64_t* bn, uint8_t m, uint8_t rd, uint8_t rs) {
	bin[*bn] = (m << 6) | ((rs & 7) << 3) | (rd & 7);
	(*bn)++;
}

void i386_inst_k8(uint8_t* bin, uint64_t* bn, uint8_t k) {
	*(bin + *bn) = k;
	*bn += 1;
}

void i386_inst_k16(uint8_t* bin, uint64_t* bn, uint16_t k) {
	*((uint16_t*) bin + (*bn / 2)) = k;
	*bn += 2;
}

void i386_inst_k32(uint8_t* bin, uint64_t* bn, uint32_t k) {
	*((uint32_t*) bin + (*bn / 4)) = k;
	*bn += 4;
}

void i386_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
