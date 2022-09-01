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

void arm_v6m_err_r3(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 7) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void arm_v6m_err_r4(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r > 15) {
		printf("[%s, %lu] error: illegal register 'r%u'\n", path, ln, r);
		*e = -1;
	}
}

void arm_v6m_err_k3(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -4 || k > 7) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v6m_err_k5(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -16 || k > 31) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v6m_err_k8(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128 || k > 255) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v6m_inst_lsl_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 0;
	
	k &= 31;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_lsr_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 8;
	
	k &= 31;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_asr_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 16;
	
	k &= 31;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_add_reg0(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 24;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_sub_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 26;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_add_imm3(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 28;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_sub_imm3(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 30;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_mov_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 32;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_cmp_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 40;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_add_imm8(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 48;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_sub_imm8(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 56;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_and(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 64;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_eor(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 64;
	bin[*bn + 1] = 64;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_lsl_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 128;
	bin[*bn + 1] = 64;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_lsr_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 192;
	bin[*bn + 1] = 64;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_asr_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 65;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_adc(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 64;
	bin[*bn + 1] = 65;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_sbc(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 128;
	bin[*bn + 1] = 65;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_ror(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 192;
	bin[*bn + 1] = 65;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_tst(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 66;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_rsb(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 64;
	bin[*bn + 1] = 66;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_cmp_reg0(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 128;
	bin[*bn + 1] = 66;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_cmn(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 192;
	bin[*bn + 1] = 66;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_orr(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 67;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_mul(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 64;
	bin[*bn + 1] = 67;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_bic(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 128;
	bin[*bn + 1] = 67;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_mvn(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 192;
	bin[*bn + 1] = 67;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_add_reg1(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 68;
	
	bin[*bn] |= rd & 3;
	bin[*bn] |= rs << 3;
	bin[*bn] |= (rd << 4) & 128;
	
	*bn += 2;
}

void arm_v6m_inst_cmp_reg1(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 69;
	
	bin[*bn] |= rd & 3;
	bin[*bn] |= rs << 3;
	bin[*bn] |= (rd << 4) & 128;
	
	*bn += 2;
}

void arm_v6m_inst_mov_reg0(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 70;
	
	bin[*bn] |= rd & 3;
	bin[*bn] |= rs << 3;
	bin[*bn] |= (rd << 4) & 128;
	
	*bn += 2;
}

void arm_v6m_inst_mov_reg1(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 0;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_bx(uint8_t* bin, uint64_t* bn, uint8_t rd) { //todo
	bin[*bn] = 0;
	bin[*bn + 1] = 71;
	
	bin[*bn] |= rd << 3;
	
	*bn += 2;
}

void arm_v6m_inst_blx(uint8_t* bin, uint64_t* bn, uint8_t rd) { //todo
	bin[*bn] = 128;
	bin[*bn + 1] = 71;
	
	bin[*bn] |= rd << 3;
	
	*bn += 2;
}

void arm_v6m_inst_ldr_lit(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 72;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_str_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 72;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_strh_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 82;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_strb_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 84;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_ldrsb_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 86;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_ldr_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 88;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_ldrh_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 90;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_ldrb_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 92;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_ldrsh_reg(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t r0, uint8_t r1) {
	bin[*bn] = 0;
	bin[*bn + 1] = 94;
	
	bin[*bn] |= rd;
	bin[*bn] |= r0 << 3;
	bin[*bn] |= r1 << 6;
	bin[*bn + 1] |= r1 >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_str_imm0(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 96;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_ldr_imm0(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 104;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_strb_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 112;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_ldrb_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 120;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_strh_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 128;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_ldrh_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 136;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_str_imm1(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 144;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_ldr_imm1(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 152;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (*bn % 2) {
		printf("[%s, %lu] error: instruction out of alignment\n", path, ln);
		*e = -1;
	}
	
	if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_lsl_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_lsl_reg(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsl");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_lsr_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_lsr_reg(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "lsr");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_asr_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_asr_reg(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "asr");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_add_reg0(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k3(rv[2], e, path, ln);
			arm_v6m_inst_add_imm3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[1], e, path, ln);
			arm_v6m_inst_add_imm8(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_err_r4(rv[1], e, path, ln);
			arm_v6m_inst_add_reg1(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "add");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'u' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_sub_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k3(rv[2], e, path, ln);
			arm_v6m_inst_sub_imm3(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[1], e, path, ln);
			arm_v6m_inst_sub_imm8(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sub");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[1], e, path, ln);
			arm_v6m_inst_mov_imm(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //todo
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_err_r4(rv[1], e, path, ln);
			arm_v6m_inst_mov_reg0(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //todo
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[1], e, path, ln);
			arm_v6m_inst_mov_reg1(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[1], e, path, ln);
			arm_v6m_inst_cmp_imm(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //todo
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_cmp_reg0(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //todo
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_err_r4(rv[1], e, path, ln);
			arm_v6m_inst_cmp_reg1(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmp");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'n' && op[2] == 'd' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_and(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "and");
			*e = -1;
		}
	}
	else if (op[0] == 'e' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_eor(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "eor");
			*e = -1;
		}
	}
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_adc(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adc");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'b' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_sbc(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sbc");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'o' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_ror(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ror");
			*e = -1;
		}
	}
	else if (op[0] == 't' && op[1] == 's' && op[2] == 't' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_tst(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "tst");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 's' && op[2] == 'b' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_rsb(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rsb");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'n' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_cmn(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cmn");
			*e = -1;
		}
	}
	else if (op[0] == 'o' && op[1] == 'r' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_orr(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "orr");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'u' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_mul(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mul");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'i' && op[2] == 'c' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_bic(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bic");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'v' && op[2] == 'n' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_mvn(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mvn");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'x' && op[2] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_inst_bx(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bx");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'x' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0 && rt[2] == 0) {
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_inst_blx(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "blx");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[1], e, path, ln);
			arm_v6m_inst_ldr_lit(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_ldr_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) { //todo
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_ldr_imm0(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) { //todo
			arm_v6m_err_r3(rv[0], e, path, ln);
			//arm_v6m_err_sp(rv[1], e, path, ln);
			arm_v6m_err_k8(rv[2], e, path, ln);
			arm_v6m_inst_ldr_imm1(bin, bn, rv[0], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_str_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) { //todo
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_str_imm0(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) { //todo
			arm_v6m_err_r3(rv[0], e, path, ln);
			//arm_v6m_err_sp(rv[1], e, path, ln);
			arm_v6m_err_k8(rv[2], e, path, ln);
			arm_v6m_inst_str_imm1(bin, bn, rv[0], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "str");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_strh_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_strh_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strh");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_strb_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_strb_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "strb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'b' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_ldrsb_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_ldrh_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_ldrh_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrh");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_ldrb_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3)) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_ldrb_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrb");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's' && op[4] == 'h' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_ldrsh_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrsh");
			*e = -1;
		}
	}
}
