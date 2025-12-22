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

//   agnus dei, qui tollis peccata mundi

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

uint8_t arm_64a_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r[0] == 'w' && r[1] == '0' && (r[2] == 0 || r[2] == ')')) { //32 bit general purpose
		return 0;
	}
	else if (r[0] == 'w' && r[1] == '1' && (r[2] == 0 || r[2] == ')')) {
		return 1;
	}
	else if (r[0] == 'w' && r[1] == '2' && (r[2] == 0 || r[2] == ')')) {
		return 2;
	}
	else if (r[0] == 'w' && r[1] == '3' && (r[2] == 0 || r[2] == ')')) {
		return 3;
	}
	else if (r[0] == 'w' && r[1] == '4' && (r[2] == 0 || r[2] == ')')) {
		return 4;
	}
	else if (r[0] == 'w' && r[1] == '5' && (r[2] == 0 || r[2] == ')')) {
		return 5;
	}
	else if (r[0] == 'w' && r[1] == '6' && (r[2] == 0 || r[2] == ')')) {
		return 6;
	}
	else if (r[0] == 'w' && r[1] == '7' && (r[2] == 0 || r[2] == ')')) {
		return 7;
	}
	else if (r[0] == 'w' && r[1] == '8' && (r[2] == 0 || r[2] == ')')) {
		return 8;
	}
	else if (r[0] == 'w' && r[1] == '9' && (r[2] == 0 || r[2] == ')')) {
		return 9;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 10;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 11;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 12;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) {
		return 13;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) {
		return 14;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) {
		return 15;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '6' && (r[3] == 0 || r[3] == ')')) {
		return 16;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '7' && (r[3] == 0 || r[3] == ')')) {
		return 17;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '8' && (r[3] == 0 || r[3] == ')')) {
		return 18;
	}
	else if (r[0] == 'w' && r[1] == '1' && r[2] == '9' && (r[3] == 0 || r[3] == ')')) {
		return 19;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 20;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 21;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 22;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) {
		return 23;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) {
		return 24;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) {
		return 25;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '6' && (r[3] == 0 || r[3] == ')')) {
		return 26;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '7' && (r[3] == 0 || r[3] == ')')) {
		return 27;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '8' && (r[3] == 0 || r[3] == ')')) {
		return 28;
	}
	else if (r[0] == 'w' && r[1] == '2' && r[2] == '9' && (r[3] == 0 || r[3] == ')')) {
		return 29;
	}
	else if (r[0] == 'w' && r[1] == '3' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 30;
	}
	else if (r[0] == 'w' && r[1] == '3' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 31;
	}
	else if (r[0] == 'x' && r[1] == '0' && (r[2] == 0 || r[2] == ')')) { //64 bit general purpose
		return 128;
	}
	else if (r[0] == 'x' && r[1] == '1' && (r[2] == 0 || r[2] == ')')) {
		return 129;
	}
	else if (r[0] == 'x' && r[1] == '2' && (r[2] == 0 || r[2] == ')')) {
		return 130;
	}
	else if (r[0] == 'x' && r[1] == '3' && (r[2] == 0 || r[2] == ')')) {
		return 131;
	}
	else if (r[0] == 'x' && r[1] == '4' && (r[2] == 0 || r[2] == ')')) {
		return 132;
	}
	else if (r[0] == 'x' && r[1] == '5' && (r[2] == 0 || r[2] == ')')) {
		return 133;
	}
	else if (r[0] == 'x' && r[1] == '6' && (r[2] == 0 || r[2] == ')')) {
		return 134;
	}
	else if (r[0] == 'x' && r[1] == '7' && (r[2] == 0 || r[2] == ')')) {
		return 135;
	}
	else if (r[0] == 'x' && r[1] == '8' && (r[2] == 0 || r[2] == ')')) {
		return 136;
	}
	else if (r[0] == 'x' && r[1] == '9' && (r[2] == 0 || r[2] == ')')) {
		return 137;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 138;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 139;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 140;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) {
		return 141;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) {
		return 142;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) {
		return 143;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '6' && (r[3] == 0 || r[3] == ')')) {
		return 144;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '7' && (r[3] == 0 || r[3] == ')')) {
		return 145;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '8' && (r[3] == 0 || r[3] == ')')) {
		return 146;
	}
	else if (r[0] == 'x' && r[1] == '1' && r[2] == '9' && (r[3] == 0 || r[3] == ')')) {
		return 147;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) {
		return 148;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) {
		return 149;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '2' && (r[3] == 0 || r[3] == ')')) {
		return 150;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '3' && (r[3] == 0 || r[3] == ')')) {
		return 151;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '4' && (r[3] == 0 || r[3] == ')')) {
		return 152;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '5' && (r[3] == 0 || r[3] == ')')) {
		return 153;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '6' && (r[3] == 0 || r[3] == ')')) {
		return 154;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '7' && (r[3] == 0 || r[3] == ')')) {
		return 155;
	}
	else if (r[0] == 'x' && r[1] == '2' && r[2] == '8' && (r[3] == 0 || r[3] == ')')) {
		return 156;
	}
	else if ((r[0] == 'x' && r[1] == '2' && r[2] == '9' && (r[3] == 0 || r[3] == ')')) || (r[0] == 's' && r[1] == 'p' && (r[2] == 0 || r[2] == ')'))) {
		return 157;
	}
	else if ((r[0] == 'x' && r[1] == '3' && r[2] == '0' && (r[3] == 0 || r[3] == ')')) || (r[0] == 'l' && r[1] == 'r' && (r[2] == 0 || r[2] == ')'))) {
		return 158;
	}
	else if ((r[0] == 'x' && r[1] == '3' && r[2] == '1' && (r[3] == 0 || r[3] == ')')) || (r[0] == 'p' && r[1] == 'c' && (r[2] == 0 || r[2] == ')'))) {
		return 159;
	}
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
	}
}

void arm_32a_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'a' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, op);
		*e = -1;
	}
}
