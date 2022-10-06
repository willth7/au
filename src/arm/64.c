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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

uint8_t arm_64_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r[0] == 'x' && r[1] == '0' && r[2] == 0) { //general purpose
		return 0;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == 0) {
		return 1;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == 0) {
		return 2;
	}
	else if (r[0] == 'x' && r[1] == '3' && r[2] == 0) {
		return 3;
	}
	else if (r[0] == 'x' && r[1] == '4' && r[2] == 0) {
		return 4;
	}
	else if (r[0] == 'x' && r[1] == '5' && r[2] == 0) {
		return 5;
	}
	else if (r[0] == 'x' && r[1] == '6' && r[2] == 0) {
		return 6;
	}
	else if (r[0] == 'x' && r[1] == '7' && r[2] == 0) {
		return 7;
	}
	else if (r[0] == 'x' && r[1] == '8' && r[2] == 0) {
		return 8;
	}
	else if (r[0] == 'x' && r[1] == '9' && r[2] == 0) {
		return 9;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '0' && r[3] == 0) {
		return 10;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '1' && r[3] == 0) {
		return 11;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '2' && r[3] == 0) {
		return 12;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '3' && r[3] == 0) {
		return 13;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '4' && r[3] == 0) {
		return 14;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '5' && r[3] == 0) {
		return 15;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '6' && r[3] == 0) {
		return 16;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '7' && r[3] == 0) {
		return 17;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '8' && r[3] == 0) {
		return 18;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '9' && r[3] == 0) {
		return 19;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '0' && r[3] == 0) {
		return 20;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '1' && r[3] == 0) {
		return 21;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '2' && r[3] == 0) {
		return 22;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '3' && r[3] == 0) {
		return 23;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '4' && r[3] == 0) {
		return 24;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '5' && r[3] == 0) {
		return 25;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '6' && r[3] == 0) {
		return 26;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '7' && r[3] == 0) {
		return 27;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '8' && r[3] == 0) {
		return 28;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '9' && r[3] == 0) {
		return 29;
	}
	else if ((r[0] == 'x' && r[1] == '3' && r[2] == '0' && r[3] == 0) || (r[0] == 'x' && r[1] == 'l' && r[2] == 'r' && r[3] == '0')) {
		return 30;
	}
	else if ((r[0] == 'x' && r[1] == '3' && r[2] == '1' && r[3] == 0) || (r[0] == 'x' && r[1] == 's' && r[2] == 'p' && r[3] == '0') || (r[0] == 'x' && r[1] == 'z' && r[2] == 'r' && r[3] == '0'))) {
		return 31;
	}
	else if (r[0] == 'w' && r[1] == '0' && r[2] == 0) { //general purpose 32-bit
		return 32;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == 0) {
		return 33;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == 0) {
		return 34;
	}
	else if (r[0] == 'w' && r[1] == '3' && r[2] == 0) {
		return 35;
	}
	else if (r[0] == 'w' && r[1] == '4' && r[2] == 0) {
		return 36;
	}
	else if (r[0] == 'w' && r[1] == '5' && r[2] == 0) {
		return 37;
	}
	else if (r[0] == 'w' && r[1] == '6' && r[2] == 0) {
		return 38;
	}
	else if (r[0] == 'w' && r[1] == '7' && r[2] == 0) {
		return 39;
	}
	else if (r[0] == 'w' && r[1] == '8' && r[2] == 0) {
		return 40;
	}
	else if (r[0] == 'w' && r[1] == '9' && r[2] == 0) {
		return 41;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '0' && r[3] == 0) {
		return 42;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '1' && r[3] == 0) {
		return 43;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '2' && r[3] == 0) {
		return 44;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '3' && r[3] == 0) {
		return 45;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '4' && r[3] == 0) {
		return 46;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '5' && r[3] == 0) {
		return 47;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '6' && r[3] == 0) {
		return 48;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '7' && r[3] == 0) {
		return 49;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '8' && r[3] == 0) {
		return 50;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '9' && r[3] == 0) {
		return 51;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '0' && r[3] == 0) {
		return 52;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '1' && r[3] == 0) {
		return 53;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '2' && r[3] == 0) {
		return 54;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '3' && r[3] == 0) {
		return 55;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '4' && r[3] == 0) {
		return 56;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '5' && r[3] == 0) {
		return 57;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '6' && r[3] == 0) {
		return 58;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '7' && r[3] == 0) {
		return 59;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '8' && r[3] == 0) {
		return 60;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '9' && r[3] == 0) {
		return 61;
	}
	else if ((r[0] == 'w' && r[1] == '3' && r[2] == '0' && r[3] == 0) || (r[0] == 'w' && r[1] == 'l' && r[2] == 'r' && r[3] == '0')) {
		return 62;
	}
	else if ((r[0] == 'w' && r[1] == '3' && r[2] == '1' && r[3] == 0) || (r[0] == 'w' && r[1] == 's' && r[2] == 'p' && r[3] == '0') || (r[0] == 'w' && r[1] == 'z' && r[2] == 'r' && r[3] == '0'))) {
		return 63;
	}

}

void arm_64_err_x5(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 31) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void arm_64_err_w5(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 32 || r > 63) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
		*e = -1;
	}
}

void arm_32a_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' &&  op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel todo
			arm_64_err_x5(rv[0], e, path, ln);

		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adr");
			*e = -1;
		}
	}
	else if (op[0] == 'a' &&  op[1] == 'd' && op[2] == 'r' && op[3] == 'p' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel todo
			arm_64_err_x5(rv[0], e, path, ln);

		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adrp");
			*e = -1;
		}
	} 
}
