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

uint8_t arm_reg(int8_t* r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r[0] == 'r' && r[1] == '0' && r[2] == 0) { //general purpose
		return 0;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == 0) {
		return 1;
	}
	else if (r[0] == 'r' && r[1] == '2' && r[2] == 0) {
		return 2;
	}
	else if (r[0] == 'r' && r[1] == '3' && r[2] == 0) {
		return 3;
	}
	else if (r[0] == 'r' && r[1] == '4' && r[2] == 0) {
		return 4;
	}
	else if (r[0] == 'r' && r[1] == '5' && r[2] == 0) {
		return 5;
	}
	else if (r[0] == 'r' && r[1] == '6' && r[2] == 0) {
		return 6;
	}
	else if (r[0] == 'r' && r[1] == '7' && r[2] == 0) {
		return 7;
	}
	else if (r[0] == 'r' && r[1] == '8' && r[2] == 0) {
		return 8;
	}
	else if (r[0] == 'r' && r[1] == '9' && r[2] == 0) {
		return 9;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '0' && r[3] == 0) {
		return 10;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '1' && r[3] == 0) {
		return 11;
	}
	else if (r[0] == 'r' && r[1] == '1' && r[2] == '2' && r[3] == 0) {
		return 12;
	}
	else if ((r[0] == 'r' && r[1] == '1' && r[2] == '3' && r[3] == 0) || (r[0] == 's' && r[1] == 'p')) {
		return 13;
	}
	else if ((r[0] == 'r' && r[1] == '1' && r[2] == '4' && r[3] == 0) || (r[0] == 'l' && r[1] == 'r')) {
		return 14;
	}
	else if ((r[0] == 'r' && r[1] == '1' && r[2] == '5' && r[3] == 0) || (r[0] == 'p' && r[1] == 'c')) {
		return 15;
	}
	else if (r[0] == 'l' && r[1] == 's' && r[2] == 'l' && r[3] == 0) { //shifts
		return 16;
	}
	else if (r[0] == 'l' && r[1] == 's' && r[2] == 'r' && r[3] == 0) { //shifts
		return 17;
	}
	else if (r[0] == 'a' && r[1] == 's' && r[2] == 'r' && r[3] == 0) { //shifts
		return 18;
	}
	else if (r[0] == 'r' && r[1] == 'o' && r[2] == 'r' && r[3] == 0) { //shifts
		return 19;
	}
	else {
		printf("[%s, %lu] error: unknown register '%s'\n", path, ln, r);
		*e = -1;
	}
}
