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

void arm_v6m_inst_lsl_imm(uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 0;
	
	rd &= 7;
	rs &= 7;
	k &= 31;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_lsr_imm(uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 8;
	
	rd &= 7;
	rs &= 7;
	k &= 31;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (*bn % 2) {
		printf("[%s, %lu] error: instruction out of alignment\n", path, ln);
		*e = -1;
	}
	
	if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2) {
			//rv0 r3
			//rv1 r3
			//rv2 k5
			arm_v6m_inst_lsl_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsl");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2) {
			//rv0 r3
			//rv1 r3
			//rv2 k5
			arm_v6m_inst_lsr_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsl");
			*e = -1;
		}
	}
}
