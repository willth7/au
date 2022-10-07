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
	if (r[0] == 'a' && r[1] == 'l' && r[2] == 0) { //8 bit
		return 0;
	}
	else if (r[0] == 'c' && r[1] == 'l' && r[2] == 0) {
		return 1;
	}
	else if (r[0] == 'd' && r[1] == 'l' && r[2] == 0) {
		return 2;
	}
	else if (r[0] == 'b' && r[1] == 'l' && r[2] == 0) {
		return 3;
	}
	else if (r[0] == 'a' && r[1] == 'h' && r[2] == 0) {
		return 4;
	}
	else if (r[0] == 'c' && r[1] == 'h' && r[2] == 0) {
		return 5;
	}
	else if (r[0] == 'd' && r[1] == 'h' && r[2] == 0) {
		return 6;
	}
	else if (r[0] == 'b' && r[1] == 'h' && r[2] == 0) {
		return 7;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 'b' && r[3] == 0) {
		return 8;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 'b' && r[3] == 0) {
		return 9;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 'b' && r[4] == 0) {
		return 10;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 'b' && r[4] == 0) {
		return 11;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 'b' && r[4] == 0) {
		return 12;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 'b' && r[4] == 0) {
		return 13;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 'b' && r[4] == 0) {
		return 14;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 'b' && r[4] == 0) {
		return 15;
	}	
	else if (r[0] == 'a' && r[1] == 'x' && r[2] == 0) { //16 bit
		return 16;
	}
	else if (r[0] == 'c' && r[1] == 'x' && r[2] == 0) {
		return 17;
	}
	else if (r[0] == 'd' && r[1] == 'x' && r[2] == 0) {
		return 18;
	}
	else if (r[0] == 'b' && r[1] == 'x' && r[2] == 0) {
		return 19;
	}
	else if (r[0] == 's' && r[1] == 'p' && r[2] == 0) {
		return 20;
	}
	else if (r[0] == 'b' && r[1] == 'p' && r[2] == 0) {
		return 21;
	}
	else if (r[0] == 's' && r[1] == 'i' && r[2] == 0) {
		return 22;
	}
	else if (r[0] == 'd' && r[1] == 'i' && r[2] == 0) {
		return 23;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 'w' && r[3] == 0) {
		return 24;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 'w' && r[3] == 0) {
		return 25;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 'w' && r[4] == 0) {
		return 26;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 'w' && r[4] == 0) {
		return 27;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 'w' && r[4] == 0) {
		return 28;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 'w' && r[4] == 0) {
		return 29;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 'w' && r[4] == 0) {
		return 30;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 'w' && r[4] == 0) {
		return 31;
	}
	else if (r[0] == 'e' && r[1] == 'a' && r[2] == 'x' && r[3] == 0) { //32 bit
		return 32;
	}
	else if (r[0] == 'e' && r[1] == 'c' && r[2] == 'x' && r[3] == 0) {
		return 33;
	}
	else if (r[0] == 'e' && r[1] == 'd' && r[2] == 'x' && r[3] == 0) {
		return 34;
	}
	else if (r[0] == 'e' && r[1] == 'b' && r[2] == 'x' && r[3] == 0) {
		return 35;
	}
	else if (r[0] == 'e' && r[1] == 's' && r[2] == 'p' && r[3] == 0) {
		return 36;
	}
	else if (r[0] == 'e' && r[1] == 'b' && r[2] == 'p' && r[3] == 0) {
		return 37;
	}
	else if (r[0] == 'e' && r[1] == 's' && r[2] == 'i' && r[3] == 0) {
		return 38;
	}
	else if (r[0] == 'e' && r[1] == 'd' && r[2] == 'i' && r[3] == 0) {
		return 39;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 'd' && r[3] == 0) {
		return 40;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 'd' && r[3] == 0) {
		return 41;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 'd' && r[4] == 0) {
		return 42;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 'd' && r[4] == 0) {
		return 43;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 'd' && r[4] == 0) {
		return 44;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 'd' && r[4] == 0) {
		return 45;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 'd' && r[4] == 0) {
		return 46;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 'd' && r[4] == 0) {
		return 47;
	}
	else if (r[0] == 'r' && r[1] == 'a' && r[2] == 'x' && r[3] == 0) { //64 bit
		return 48;
	}
	else if (r[0] == 'r' && r[1] == 'c' && r[2] == 'x' && r[3] == 0) {
		return 49;
	}
	else if (r[0] == 'r' && r[1] == 'd' && r[2] == 'x' && r[3] == 0) {
		return 50;
	}
	else if (r[0] == 'r' && r[1] == 'b' && r[2] == 'x' && r[3] == 0) {
		return 51;
	}
	else if (r[0] == 'r' && r[1] == 's' && r[2] == 'p' && r[3] == 0) {
		return 52;
	}
	else if (r[0] == 'r' && r[1] == 'b' && r[2] == 'p' && r[3] == 0) {
		return 53;
	}
	else if (r[0] == 'r' && r[1] == 's' && r[2] == 'i' && r[3] == 0) {
		return 54;
	}
	else if (r[0] == 'r' && r[1] == 'd' && r[2] == 'i' && r[3] == 0) {
		return 55;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 0) {
		return 56;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 0) {
		return 57;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 0) {
		return 58;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 0) {
		return 59;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 0) {
		return 60;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 0) {
		return 61;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 0) {
		return 62;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 0) {
		return 63;
	}
	else if (r[0] == 's' && r[1] == 'p' && r[2] == 'l' && r[3] == 0) { //8 bit rex
		return 68;
	}
	else if (r[0] == 'b' && r[1] == 'p' && r[2] == 'l' && r[3] == 0) {
		return 69;
	}
	else if (r[0] == 's' && r[1] == 'i' && r[2] == 'l' && r[3] == 0) {
		return 70;
	}
	else if (r[0] == 'd' && r[1] == 'i' && r[2] == 'l' && r[3] == 0) {
		return 71;
	}
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
	}
}

void x86_err_r8h(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_err_r8l(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r == 4 || r == 5 || r == 6 || r == 7 || (r > 15 && r != 68 && r != 69 && r != 70 && r != 71)) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_err_r16(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 16 || r > 31) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_err_r32(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 32 || r > 47) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_err_r64(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 48 || r > 63) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void x86_inst_op(uint8_t* bin, uint64_t* bn, uint8_t a) {
	bin[*bn] = a;
	(*bn)++;
}

void x86_pfx_rex(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	if (((rd & 112) == 64) || ((rs & 112) == 64)){
		bin[*bn] = 64;
		if (rd & 8) {
			bin[*bn] |= 1;
		}
		if (rs & 8) {
			bin[*bn] |= 4;
		}
		(*bn)++;
	}	
	else if ((rd & 112) == 48) {
		bin[*bn] = 72;
		if (rd & 8) {
			bin[*bn] |= 1;
		}
		if (rs & 8) {
			bin[*bn] |= 4;
		}
		(*bn)++;
	}
	else if ((rd & 8) || (rs & 8)) {
		bin[*bn] = 64;
		if (rd & 8) {
			bin[*bn] |= 1;
		}
		if (rs & 8) {
			bin[*bn] |= 4;
		}
		(*bn)++;
	}

}

void x86_inst_r2(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = (rd & 7) | ((rs & 7) << 3) | 192;
	(*bn)++;
}

void x86_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 112) == 0 && (rv[1] & 112) == 0) {
			x86_err_r8h(rv[0], e, path, ln);
			x86_err_r8h(rv[1], e, path, ln);
			
			x86_pfx_rex(bin, bn, rv[0], rv[1]);
			x86_inst_op(bin, bn, 0);
			x86_inst_r2(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && ((rv[0] & 112) == 64 || (rv[1] & 112) == 64)) {
			x86_err_r8l(rv[0], e, path, ln);
			x86_err_r8l(rv[1], e, path, ln);
			
			x86_pfx_rex(bin, bn, rv[0], rv[1]);
			x86_inst_op(bin, bn, 0);
			x86_inst_r2(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 112) == 16) {
			x86_err_r16(rv[1], e, path, ln);
			
			x86_inst_op(bin, bn, 102);
			x86_pfx_rex(bin, bn, rv[0], rv[1]);
			x86_inst_op(bin, bn, 1);
			x86_inst_r2(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 112) == 32) {
			x86_err_r32(rv[1], e, path, ln);
			
			x86_pfx_rex(bin, bn, rv[0], rv[1]);
			x86_inst_op(bin, bn, 1);
			x86_inst_r2(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && (rv[0] & 112) == 48) {
			x86_err_r64(rv[1], e, path, ln);
			
			x86_pfx_rex(bin, bn, rv[0], rv[1]);
			x86_inst_op(bin, bn, 1);
			x86_inst_r2(bin, bn, rv[0], rv[1]);
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
