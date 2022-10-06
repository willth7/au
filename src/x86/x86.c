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
	else if (r[0] == 's' && r[1] == 'p' && r[2] == 'l' && r[3] == 0) { //8 bit rex
		return 20;
	}
	else if (r[0] == 'b' && r[1] == 'p' && r[2] == 'l' && r[3] == 0) {
		return 21;
	}
	else if (r[0] == 's' && r[1] == 'i' && r[2] == 'l' && r[3] == 0) {
		return 22;
	}
	else if (r[0] == 'd' && r[1] == 'i' && r[2] == 'l' && r[3] == 0) {
		return 23;
	}
	else if (r[0] == 'a' && r[1] == 'x' && r[2] == 0) { //16 bit
		return 32;
	}
	else if (r[0] == 'c' && r[1] == 'x' && r[2] == 0) {
		return 33;
	}
	else if (r[0] == 'd' && r[1] == 'x' && r[2] == 0) {
		return 34;
	}
	else if (r[0] == 'b' && r[1] == 'x' && r[2] == 0) {
		return 35;
	}
	else if (r[0] == 's' && r[1] == 'p' && r[2] == 0) {
		return 36;
	}
	else if (r[0] == 'b' && r[1] == 'p' && r[2] == 0) {
		return 37;
	}
	else if (r[0] == 's' && r[1] == 'i' && r[2] == 0) {
		return 38;
	}
	else if (r[0] == 'd' && r[1] == 'i' && r[2] == 0) {
		return 39;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 'w' && r[3] == 0) {
		return 40;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 'w' && r[3] == 0) {
		return 41;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 'w' && r[4] == 0) {
		return 42;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 'w' && r[4] == 0) {
		return 43;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 'w' && r[4] == 0) {
		return 44;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 'w' && r[4] == 0) {
		return 45;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 'w' && r[4] == 0) {
		return 46;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 'w' && r[4] == 0) {
		return 47;
	}
	else if (r[0] == 'e' && r[1] == 'a' && r[2] == 'x' && r[3] == 0) { //32 bit
		return 48;
	}
	else if (r[0] == 'e' && r[1] == 'c' && r[2] == 'x' && r[3] == 0) {
		return 49;
	}
	else if (r[0] == 'e' && r[1] == 'd' && r[2] == 'x' && r[3] == 0) {
		return 50;
	}
	else if (r[0] == 'e' && r[1] == 'b' && r[2] == 'x' && r[3] == 0) {
		return 51;
	}
	else if (r[0] == 'e' && r[1] == 's' && r[2] == 'p' && r[3] == 0) {
		return 52;
	}
	else if (r[0] == 'e' && r[1] == 'b' && r[2] == 'p' && r[3] == 0) {
		return 53;
	}
	else if (r[0] == 'e' && r[1] == 's' && r[2] == 'i' && r[3] == 0) {
		return 54;
	}
	else if (r[0] == 'e' && r[1] == 'd' && r[2] == 'i' && r[3] == 0) {
		return 55;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 'd' && r[3] == 0) {
		return 56;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 'd' && r[3] == 0) {
		return 57;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 'd' && r[4] == 0) {
		return 58;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 'd' && r[4] == 0) {
		return 59;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 'd' && r[4] == 0) {
		return 60;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 'd' && r[4] == 0) {
		return 61;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 'd' && r[4] == 0) {
		return 62;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 'd' && r[4] == 0) {
		return 63;
	}
	else if (r[0] == 'r' && r[1] == 'a' && r[2] == 'x' && r[3] == 0) { //32 bit
		return 64;
	}
	else if (r[0] == 'r' && r[1] == 'c' && r[2] == 'x' && r[3] == 0) {
		return 65;
	}
	else if (r[0] == 'r' && r[1] == 'd' && r[2] == 'x' && r[3] == 0) {
		return 66;
	}
	else if (r[0] == 'r' && r[1] == 'b' && r[2] == 'x' && r[3] == 0) {
		return 67;
	}
	else if (r[0] == 'r' && r[1] == 's' && r[2] == 'p' && r[3] == 0) {
		return 68;
	}
	else if (r[0] == 'r' && r[1] == 'b' && r[2] == 'p' && r[3] == 0) {
		return 69;
	}
	else if (r[0] == 'r' && r[1] == 's' && r[2] == 'i' && r[3] == 0) {
		return 70;
	}
	else if (r[0] == 'r' && r[1] == 'd' && r[2] == 'i' && r[3] == 0) {
		return 71;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 0) {
		return 72;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 0) {
		return 73;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 0) {
		return 74;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 0) {
		return 75;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 0) {
		return 76;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 0) {
		return 77;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 0) {
		return 78;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 0) {
		return 79;
	}
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
	}
}
