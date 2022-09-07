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

void arm_v6m_err_rl(uint64_t* r, uint8_t rn, uint8_t ex, int8_t* e, int8_t* path, uint64_t ln) {
	for (uint8_t i = 0; i < rn; i++) {
		if (r[i] != ex) {
			arm_v6m_err_r3(r[i], e, path, ln);
		}
		for (uint8_t j = 0; j < rn; j++) {
			if (r[i] == r[j] && i != j) {
				printf("[%s, %lu] error: duplicate register 'r%u'\n", path, ln, (uint32_t) r[i]);
				*e = -1;
			}
		}
	}
}

void arm_v6m_err_rs(uint8_t r, int8_t* e, int8_t* path, uint64_t ln) {
	if (r < 15 || (r > 24 && r != 32 && r != 36)) {
		printf("[%s, %lu] error: illegal register\n", path, ln);
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

void arm_v6m_err_k7(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -64 || k > 127) {
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

void arm_v6m_err_k11(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -1024 || k > 2047) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v6m_err_k16(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32768 || k > 65535) {
		printf("[%s, %lu] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void arm_v6m_err_k24(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -8388608 || k > 16777215) {
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

void arm_v6m_inst_bx(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 0;
	bin[*bn + 1] = 71;
	
	bin[*bn] |= rd << 3;
	
	*bn += 2;
}

void arm_v6m_inst_blx(uint8_t* bin, uint64_t* bn, uint8_t rd) {
	bin[*bn] = 128;
	bin[*bn + 1] = 71;
	
	bin[*bn] |= rd << 3;
	
	*bn += 2;
}

void arm_v6m_inst_ldr_pc(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
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

void arm_v6m_inst_str_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 96;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	bin[*bn] |= k << 6;
	bin[*bn + 1] |= k >> 2;
	
	*bn += 2;
}

void arm_v6m_inst_ldr_imm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs, uint8_t k) {
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

void arm_v6m_inst_str_sp(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 144;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_ldr_sp(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 152;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_adr(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 160;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_add_sp0(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 168;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_add_sp1(uint8_t* bin, uint64_t* bn, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 176;
	
	bin[*bn] |= k;
	
	*bn += 2;
}

void arm_v6m_inst_sub_sp(uint8_t* bin, uint64_t* bn, uint8_t k) {
	bin[*bn] = 128;
	bin[*bn + 1] = 176;
	
	bin[*bn] |= k;
	
	*bn += 2;
}

void arm_v6m_inst_sxth(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 178;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_sxtb(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 64;
	bin[*bn + 1] = 178;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_uxth(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 128;
	bin[*bn + 1] = 178;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_uxtb(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 192;
	bin[*bn + 1] = 178;
	
	bin[*bn] |= rd;
	bin[*bn] |= rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_push(uint8_t* bin, uint64_t* bn, uint64_t* rl, uint8_t rn) {
	bin[*bn] = 0;
	bin[*bn + 1] = 180;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn] |= 128;
		}
		else if (rl[i] == 14) {
			bin[*bn + 1] |= 1;
		}
	}
	
	*bn += 2;
}

void arm_v6m_inst_cps(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) { //todo
	bin[*bn] = 0;
	bin[*bn + 1] = 182;
	
	*bn += 2;
}

void arm_v6m_inst_rev(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 0;
	bin[*bn + 1] = 186;
	
	bin[*bn] = rd;
	bin[*bn] = rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_rev16(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 64;
	bin[*bn + 1] = 186;
	
	bin[*bn] = rd;
	bin[*bn] = rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_revsh(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 192;
	bin[*bn + 1] = 186;
	
	bin[*bn] = rd;
	bin[*bn] = rs << 3;
	
	*bn += 2;
}

void arm_v6m_inst_pop(uint8_t* bin, uint64_t* bn, uint64_t* rl, uint8_t rn) {
	bin[*bn] = 0;
	bin[*bn + 1] = 188;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn] |= 128;
		}
		else if (rl[i] == 15) {
			bin[*bn + 1] |= 1;
		}
	}
	
	*bn += 2;
}

void arm_v6m_inst_bkpt(uint8_t* bin, uint64_t* bn, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 190;
	
	bin[*bn] = k;
	
	*bn += 2;
}

void arm_v6m_inst_nop(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 0;
	bin[*bn + 1] = 191;
	
	*bn += 2;
}

void arm_v6m_inst_yield(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 16;
	bin[*bn + 1] = 191;
	
	*bn += 2;
}

void arm_v6m_inst_wfe(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 32;
	bin[*bn + 1] = 191;
	
	*bn += 2;
}

void arm_v6m_inst_wfi(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 48;
	bin[*bn + 1] = 191;
	
	*bn += 2;
}

void arm_v6m_inst_sev(uint8_t* bin, uint64_t* bn) {
	bin[*bn] = 64;
	bin[*bn + 1] = 191;
	
	*bn += 2;
}

void arm_v6m_inst_stm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint64_t* rl, uint8_t rn) {
	bin[*bn] = 0;
	bin[*bn + 1] = 192;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn] |= 128;
		}
	}
	
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_ldm(uint8_t* bin, uint64_t* bn, uint8_t rd, uint64_t* rl, uint8_t rn) {
	bin[*bn] = 0;
	bin[*bn + 1] = 200;
	
	for (uint8_t i = 0; i < rn; i++) {
		if (rl[i] == 0) {
			bin[*bn] |= 1;
		}
		else if (rl[i] == 1) {
			bin[*bn] |= 2;
		}
		else if (rl[i] == 2) {
			bin[*bn] |= 4;
		}
		else if (rl[i] == 3) {
			bin[*bn] |= 8;
		}
		else if (rl[i] == 4) {
			bin[*bn] |= 16;
		}
		else if (rl[i] == 5) {
			bin[*bn] |= 32;
		}
		else if (rl[i] == 6) {
			bin[*bn] |= 64;
		}
		else if (rl[i] == 7) {
			bin[*bn] |= 128;
		}
	}
	
	bin[*bn + 1] |= rd;
	
	*bn += 2;
}

void arm_v6m_inst_b_cond(uint8_t* bin, uint64_t* bn, uint8_t c, uint8_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 208;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= c;
	
	*bn += 2;
}

void arm_v6m_inst_b(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = 0;
	bin[*bn + 1] = 224;
	
	bin[*bn] |= k;
	bin[*bn + 1] |= k >> 8;
	
	*bn += 2;
}

void arm_v6m_inst_msr(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 128;
	bin[*bn + 1] = 243;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 136;
	
	rs -= 16;
	
	bin[*bn] |= rd;
	bin[*bn + 2] |= rs;
	
	*bn += 4;
}

void arm_v6m_inst_dsb(uint8_t* bin, uint64_t* bn) { //todo
	bin[*bn] = 176;
	bin[*bn + 1] = 243;
	bin[*bn + 2] = 64;
	bin[*bn + 3] = 128;
	
	*bn += 4;
}

void arm_v6m_inst_dmb(uint8_t* bin, uint64_t* bn) { //todo
	bin[*bn] = 176;
	bin[*bn + 1] = 243;
	bin[*bn + 2] = 80;
	bin[*bn + 3] = 128;
	
	*bn += 4;
}

void arm_v6m_inst_isb(uint8_t* bin, uint64_t* bn) { //todo
	bin[*bn] = 176;
	bin[*bn + 1] = 243;
	bin[*bn + 2] = 96;
	bin[*bn + 3] = 128;
	
	*bn += 4;
}

void arm_v6m_inst_mrs(uint8_t* bin, uint64_t* bn, uint8_t rd, uint8_t rs) {
	bin[*bn] = 239;
	bin[*bn + 1] = 243;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 128;
	
	rs -= 16;
	
	bin[*bn + 3] |= rd;
	bin[*bn + 2] |= rs;
	
	*bn += 4;
}

void arm_v6m_inst_udf(uint8_t* bin, uint64_t* bn, uint16_t k) {
	bin[*bn] = 240;
	bin[*bn + 1] = 247;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 160;
	
	bin[*bn] |= k >> 12;
	bin[*bn + 2] |= k;
	bin[*bn + 3] |= (k >> 8) & 15;
	
	*bn += 4;
}

void arm_v6m_inst_bl(uint8_t* bin, uint64_t* bn, int32_t k) { //todo
	bin[*bn] = 0;
	bin[*bn + 1] = 240;
	bin[*bn + 2] = 0;
	bin[*bn + 3] = 248;
	
	k |= (k >> 8) & 8388608;
	
	bin[*bn + 2] |= k;
	bin[*bn + 3] |= (k >> 8) & 7;
	bin[*bn] |= k >> 11;
	bin[*bn + 1] |= k >> 19;
	
	*bn += 4;
}

void arm_v6m_enc(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (*bn % 2) {
		printf("[%s, %lu] error: instruction out of alignment\n", path, ln);
		*e = -1;
	}
	
	if (op[0] == 'l' && op[1] == 's' && op[2] == 'l' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
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
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
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
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
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
		if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[2], e, path, ln);
			arm_v6m_inst_add_sp0(bin, bn, rv[0], rv[2]);
		}
		else if ((rt[0] == 1 && rv[0] == 13) && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v6m_err_k7(rv[2], e, path, ln);
			arm_v6m_inst_add_sp1(bin, bn, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_add_reg0(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
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
		if ((rt[0] == 1 && rv[0] == 13) && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v6m_err_k7(rv[2], e, path, ln);
			arm_v6m_inst_sub_sp(bin, bn, rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_sub_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
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
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_err_r4(rv[1], e, path, ln);
			arm_v6m_inst_mov_reg0(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mov");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'o' && op[2] == 'v' && op[3] == 's' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_mov_reg1(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "movs");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'm' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 2 || rt[1] == 3) && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[1], e, path, ln);
			arm_v6m_inst_cmp_imm(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0 && ((rv[0] > 7) ^ (rv[1] > 7))) {
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_err_r4(rv[1], e, path, ln);
			arm_v6m_inst_cmp_reg1(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_cmp_reg0(bin, bn, rv[0], rv[1]);
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
		if (rt[0] == 1 && rt[1] == 0) {
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_inst_bx(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bx");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'x' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_inst_blx(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "blx");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 15) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[2], e, path, ln);
			arm_v6m_inst_ldr_pc(bin, bn, rv[0], rv[1]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 2;
			arm_v6m_inst_ldr_pc(bin, bn, rv[0], 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_ldr_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[2], e, path, ln);
			arm_v6m_inst_ldr_sp(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_ldr_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_str_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 13) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[2], e, path, ln);
			arm_v6m_inst_str_sp(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_k5(rv[2], e, path, ln);
			arm_v6m_inst_str_imm(bin, bn, rv[0], rv[1], rv[2]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "str");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'r' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_strh_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
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
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_strb_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
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
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
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
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_ldrh_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
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
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_err_r3(rv[2], e, path, ln);
			arm_v6m_inst_ldrb_reg(bin, bn, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
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
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
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
	else if (op[0] == 'a' && op[1] == 'd' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && (rt[1] == 1 && rv[1] == 15) && (rt[2] == 2 || rt[2] == 3) && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_k8(rv[2], e, path, ln);
			arm_v6m_inst_adr(bin, bn, rv[0], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			*((uint8_t*) rv[1]) |= 2;
			arm_v6m_inst_adr(bin, bn, rv[0], 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "adr");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'x' && op[2] == 't' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_sxth(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sxth");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'x' && op[2] == 't' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_sxth(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sxtb");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'x' && op[2] == 't' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_uxth(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uxth");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'x' && op[2] == 't' && op[3] == 'b' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_uxtb(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "uxtb");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'u' && op[2] == 's' && op[3] == 'h' && op[4] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_v6m_err_rl(rv, 1, 14, e, path, ln);
			arm_v6m_inst_push(bin, bn, rv, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_rl(rv, 2, 14, e, path, ln);
			arm_v6m_inst_push(bin, bn, rv, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_rl(rv, 3, 14, e, path, ln);
			arm_v6m_inst_push(bin, bn, rv, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v6m_err_rl(rv, 4, 14, e, path, ln);
			arm_v6m_inst_push(bin, bn, rv, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v6m_err_rl(rv, 5, 14, e, path, ln);
			arm_v6m_inst_push(bin, bn, rv, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v6m_err_rl(rv, 6, 14, e, path, ln);
			arm_v6m_inst_push(bin, bn, rv, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v6m_err_rl(rv, 7, 14, e, path, ln);
			arm_v6m_inst_push(bin, bn, rv, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v6m_err_rl(rv, 8, 14, e, path, ln);
			arm_v6m_inst_push(bin, bn, rv, 8);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v6m_err_rl(rv, 9, 14, e, path, ln);
			arm_v6m_inst_push(bin, bn, rv, 9);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "push");
			*e = -1;
		}
	}
	else if (op[0] == 'c' && op[1] == 'p' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) { //todo
			arm_v6m_inst_cps(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "cps");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_rev(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rev");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'v' && op[3] == '1' && op[4] == '6' && op[5] == '0') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_rev16(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "rev16");
			*e = -1;
		}
	}
	else if (op[0] == 'r' && op[1] == 'e' && op[2] == 'v' && op[3] == 's' && op[4] == 'h' && op[5] == '0') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_r3(rv[1], e, path, ln);
			arm_v6m_inst_revsh(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "revsh");
			*e = -1;
		}
	}
	else if (op[0] == 'p' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 0) {
			arm_v6m_err_rl(rv, 1, 15, e, path, ln);
			arm_v6m_inst_pop(bin, bn, rv, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_rl(rv, 2, 15, e, path, ln);
			arm_v6m_inst_pop(bin, bn, rv, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_rl(rv, 3, 15, e, path, ln);
			arm_v6m_inst_pop(bin, bn, rv, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v6m_err_rl(rv, 4, 15, e, path, ln);
			arm_v6m_inst_pop(bin, bn, rv, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v6m_err_rl(rv, 5, 15, e, path, ln);
			arm_v6m_inst_pop(bin, bn, rv, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v6m_err_rl(rv, 6, 15, e, path, ln);
			arm_v6m_inst_pop(bin, bn, rv, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v6m_err_rl(rv, 7, 15, e, path, ln);
			arm_v6m_inst_pop(bin, bn, rv, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v6m_err_rl(rv, 8, 15, e, path, ln);
			arm_v6m_inst_pop(bin, bn, rv, 8);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v6m_err_rl(rv, 9, 15, e, path, ln);
			arm_v6m_inst_pop(bin, bn, rv, 9);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "pop");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'k' && op[2] == 'p' && op[3] == 't' && op[4] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_bkpt(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bkpt");
			*e = -1;
		}
	}
	else if (op[0] == 'n' && op[1] == 'o' && op[2] == 'p' && op[3] == 0) {
		if (rt[0] == 0) {
			arm_v6m_inst_nop(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "nop");
			*e = -1;
		}
	}
	else if (op[0] == 'y' && op[1] == 'i' && op[2] == 'e' && op[3] == 'l' && op[4] == 'd' && op[5] == 0) {
		if (rt[0] == 0) {
			arm_v6m_inst_yield(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "yield");
			*e = -1;
		}
	}
	else if (op[0] == 'w' && op[1] == 'f' && op[2] == 'e' && op[3] == 0) {
		if (rt[0] == 0) {
			arm_v6m_inst_wfe(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "wfe");
			*e = -1;
		}
	}
	else if (op[0] == 'w' && op[1] == 'f' && op[2] == 'i' && op[3] == 0) {
		if (rt[0] == 0) {
			arm_v6m_inst_wfi(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "wdi");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'e' && op[2] == 'v' && op[3] == 0) {
		if (rt[0] == 0) {
			arm_v6m_inst_sev(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "sev");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stm");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmia");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 't' && op[2] == 'm' && op[3] == 'e' && op[4] == 'a' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v6m_inst_stm(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "stmea");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldm");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'i' && op[4] == 'a' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmia");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'm' && op[3] == 'f' && op[4] == 'd' && op[5] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 1, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 1);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 2, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 2);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 3, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 3);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 4, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 4);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 5, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 5);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 6, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 6);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 0) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 7, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 7);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 1 && rt[5] == 1 && rt[6] == 1 && rt[7] == 1 && rt[8] == 1) {
			arm_v6m_err_r3(rv[0], e, path, ln);
			arm_v6m_err_rl(rv + 1, 8, 0, e, path, ln);
			arm_v6m_inst_ldm(bin, bn, rv[0], rv + 1, 8);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldmfd");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'e' && op[2] == 'q' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 0, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 0, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "beq");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'n' && op[2] == 'e' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 1, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 1, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bne");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'c' && op[2] == 's' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 2, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 2, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bcs");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'h' && op[2] == 's' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 2, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 2, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bhs");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'c' && op[2] == 'c' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 3, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 3, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bcc");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'o' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 3, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 3, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "blo");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'm' && op[2] == 'i' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 4, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 4, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bmi");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'p' && op[2] == 'l' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 5, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 5, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bpl");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'v' && op[2] == 's' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 6, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 6, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bvs");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'v' && op[2] == 'c' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 7, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 7, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bvc");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'h' && op[2] == 'i' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 8, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 8, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bhi");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 's' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 9, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 9, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bls");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'g' && op[2] == 'e' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 10, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 10, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bge");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 't' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 11, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 11, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "blt");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'g' && op[2] == 't' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 12, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 12, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bgt");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 'e' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 13, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 1;
			arm_v6m_inst_b_cond(bin, bn, 13, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ble");
			*e = -1;
		}
	}
	else if (op[0] == 'u' && op[1] == 'd' && op[2] == 'f' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rv[0] < 256 && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 14, rv[0]);
		}
		else if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k16(rv[0], e, path, ln);
			arm_v6m_inst_udf(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "udf");
			*e = -1;
		}
	}
	else if (op[0] == 's' && op[1] == 'v' && op[2] == 'c' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k8(rv[0], e, path, ln);
			arm_v6m_inst_b_cond(bin, bn, 15, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "svc");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'a' && op[2] == 'l' && op[3] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k11(rv[0], e, path, ln);
			arm_v6m_inst_b(bin, bn, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3;
			arm_v6m_inst_b(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bal");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k11(rv[0], e, path, ln);
			arm_v6m_inst_b(bin, bn, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 3;
			arm_v6m_inst_b(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "b");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 's' && op[2] == 'r' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_err_rs(rv[1], e, path, ln);
			arm_v6m_inst_msr(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "msr");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 's' && op[2] == 'b' && op[3] == 0) { //todo
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			arm_v6m_inst_dsb(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "dsb");
			*e = -1;
		}
	}
	else if (op[0] == 'd' && op[1] == 'm' && op[2] == 'b' && op[3] == 0) { //todo
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			arm_v6m_inst_dmb(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "dmb");
			*e = -1;
		}
	}
	else if (op[0] == 'i' && op[1] == 'm' && op[2] == 'b' && op[3] == 0) { //todo
		if (rt[0] == 0 && rt[1] == 0 && rt[2] == 0) {
			arm_v6m_inst_isb(bin, bn);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "isb");
			*e = -1;
		}
	}
	else if (op[0] == 'm' && op[1] == 'r' && op[2] == 's' && op[3] == 0) {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 0) {
			arm_v6m_err_r4(rv[0], e, path, ln);
			arm_v6m_err_rs(rv[1], e, path, ln);
			arm_v6m_inst_mrs(bin, bn, rv[0], rv[1]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "mrs");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'l' && op[2] == 0) {
		if ((rt[0] == 2 || rt[0] == 3) && rt[1] == 0) {
			arm_v6m_err_k24(rv[0], e, path, ln);
			arm_v6m_inst_bl(bin, bn, rv[0]);
		}
		else if (rt[0] == 4 && rt[1] == 0) {
			*((uint8_t*) rv[0]) |= 4;
			arm_v6m_inst_bl(bin, bn, 0);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "bl");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown opcode '%s'\n", path, ln, "sbrs");
			*e = -1;
	}
}
