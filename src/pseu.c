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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void au_enc_k8(uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > ((uint8_t) -1)) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", path, ln, k);
		*e = -1;
	}
}

void au_enc_k16(uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > ((uint16_t) -1)) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", path, ln, k);
		*e = -1;
	}
}

void au_enc_k32(uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > ((uint32_t) -1)) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", path, ln, k);
		*e = -1;
	}
}

void au_enc_k64(uint64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k > ((uint64_t) -1)) {
		printf("[%s, %lu] error: immediate '%lu' out of range\n", path, ln, k);
		*e = -1;
	}
}

void au_enc_k8s(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -128) {
		printf("[%s, %li] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void au_enc_k16s(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -32768) {
		printf("[%s, %li] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void au_enc_k32s(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -2147483648) {
		printf("[%s, %li] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void au_enc_k64s(int64_t k, int8_t* e, int8_t* path, uint64_t ln) {
	if (k < -9223372036854775808) {
		printf("[%s, %li] error: immediate '%li' out of range\n", path, ln, k);
		*e = -1;
	}
}

void au_enc_byte(uint8_t* bin, uint64_t* bn, int8_t k) {
	bin[*bn] = k;
	
	*bn += 1;
}

void au_enc_byt2(uint8_t* bin, uint64_t* bn, int16_t k) {
	bin[*bn] = k;
	bin[*bn + 1] = k >> 8;
	
	*bn += 2;
}

void au_enc_byt4(uint8_t* bin, uint64_t* bn, int32_t k) {
	bin[*bn] = k;
	bin[*bn + 1] = k >> 8;
	bin[*bn + 2] = k >> 16;
	bin[*bn + 3] = k >> 24;
	
	*bn += 4;
}

void au_enc_byt8(uint8_t* bin, uint64_t* bn, int64_t k) {
	bin[*bn] = k;
	bin[*bn + 1] = k >> 8;
	bin[*bn + 2] = k >> 16;
	bin[*bn + 3] = k >> 24;
	bin[*bn + 4] = k >> 32;
	bin[*bn + 5] = k >> 40;
	bin[*bn + 6] = k >> 48;
	bin[*bn + 7] = k >> 56;
	
	*bn += 8;
}

void au_pseu_op(uint8_t* bin, uint64_t* bn, int8_t* op, uint8_t* rt, uint64_t* rv, int8_t* e, int8_t* path, uint64_t ln) {
	if (op[0] == 'b' && op[1] == 'y' && op[2] == 't' && op[3] == 'e' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rt[2] == 0) {
			au_enc_k8(rv[0], e, path, ln);
			au_enc_byte(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0 && rt[2] == 0) {
			au_enc_k8s(rv[0], e, path, ln);
			au_enc_byte(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "byte");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'y' && op[2] == 't' && op[3] == '2' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rt[2] == 0) {
			au_enc_k16(rv[0], e, path, ln);
			au_enc_byt2(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0 && rt[2] == 0) {
			au_enc_k16s(rv[0], e, path, ln);
			au_enc_byt2(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "byt2");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'y' && op[2] == 't' && op[3] == '4' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rt[2] == 0) {
			au_enc_k32(rv[0], e, path, ln);
			au_enc_byt4(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0 && rt[2] == 0) {
			au_enc_k32s(rv[0], e, path, ln);
			au_enc_byt4(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "byt4");
			*e = -1;
		}
	}
	else if (op[0] == 'b' && op[1] == 'y' && op[2] == 't' && op[3] == '8' && op[4] == 0) {
		if (rt[0] == 2 && rt[1] == 0 && rt[2] == 0) {
			au_enc_k64(rv[0], e, path, ln);
			au_enc_byt8(bin, bn, rv[0]);
		}
		else if (rt[0] == 3 && rt[1] == 0 && rt[2] == 0) {
			au_enc_k64s(rv[0], e, path, ln);
			au_enc_byt8(bin, bn, rv[0]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "byt8");
			*e = -1;
		}
	}
	else {
		printf("[%s, %lu] error: unknown pseudo-op '%s'\n", path, ln, op);
		*e = -1;
	}
}
