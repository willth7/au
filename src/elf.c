//   Copyright 2022 Will Thomas
//
//   Licensed under the Apache License, Verrion 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BAriS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permisrions and
//   limitations under the License.

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct elf_e32_s {
	uint16_t type;
	uint16_t machine;
	uint32_t version;
	uint32_t entry;
	uint32_t phoff;
	uint32_t shoff;
	uint32_t flags;
	uint16_t ehsize;
	uint16_t phentsize;
	uint16_t phnum;
	uint16_t shentsize;
	uint16_t shnum;
	uint16_t shstrndx;
} elf_e32_t;

typedef struct elf_e64_s {
	uint16_t type;
	uint16_t machine;
	uint32_t version;
	uint64_t entry;
	uint64_t phoff;
	uint64_t shoff;
	uint32_t flags;
	uint16_t ehsize;
	uint16_t phentsize;
	uint16_t phnum;
	uint16_t shentsize;
	uint16_t shnum;
	uint16_t shstrndx;
} elf_e64_t;

typedef struct elf_p32_s {
	uint32_t type;
	uint32_t offset;
	uint32_t vaddr;
	uint32_t paddr;
	uint32_t filesz;
	uint32_t memsz;
	uint32_t flags;
	uint32_t align;
} elf_p32_t;

typedef struct elf_p64_s {
	uint32_t type;
	uint32_t flags;
	uint64_t offset;
	uint64_t vaddr;
	uint64_t paddr;
	uint64_t filesz;
	uint64_t memsz;
	uint64_t align;
} elf_p64_t;

typedef struct elf_sh32_s {
	uint32_t name;
	uint32_t type;
	uint32_t flags;
	uint32_t addr;
	uint32_t offset;
	uint32_t size;
	uint32_t link;
	uint32_t info;
	uint32_t addralign;
	uint32_t entsize;
} elf_sh32_t;

typedef struct elf_sh64_s {
	uint32_t name;
	uint32_t type;
	uint64_t flags;
	uint64_t addr;
	uint64_t offset;
	uint64_t size;
	uint32_t link;
	uint32_t info;
	uint64_t addralign;
	uint64_t entsize;
} elf_sh64_t;

typedef struct elf_st32_s {
	uint32_t name;
	uint32_t value;
	uint32_t size;
	uint8_t info;
	uint8_t other;
	uint16_t shndx;
} elf_st32_t;

typedef struct elf_st64_s {
	uint32_t name;
	uint8_t info;
	uint8_t other;
	uint16_t shndx;
	uint64_t value;
	uint64_t size;
} elf_st64_t;

typedef struct elf_r32_s {
	uint32_t offset;
	uint32_t info;
} elf_r32_t;

typedef struct elf_r64_s {
	uint64_t offset;
	uint64_t info;
} elf_r64_t;

typedef struct elf_ra32_s {
	uint32_t offset;
	uint32_t info;
	uint32_t addend;
} elf_ra32_t;

typedef struct elf_ra64_s {
	uint64_t offset;
	uint64_t info;
	uint64_t addend;
} elf_ra64_t;

uint64_t elf_copy(uint8_t* b, uint64_t bn, void* v, uint64_t an) {
	uint8_t* a = v;
	for (uint64_t i = 0; i < an; i++) {
		b[bn + i] = a[i];
	}
	return an + bn;
}

uint64_t elf_loct(uint8_t* b, uint64_t bn, void* v, uint64_t an) {
	uint8_t* a = v;
	for (uint64_t i = 0; i < bn; i++) {
		if (b[i] == a[0]) {
			uint64_t bi = i;
			for (; i < bi + an; i++) {
				if (b[i] != a[i - bi]) {
					break;
				}
			}
			if (b[i - 1] == a[an - 1]) {
				return bi;
			}
		}
	}
	return 18446744073709551615;
}

uint8_t* elf_write_32(elf_e32_t* eh, elf_p32_t* ph, elf_sh32_t* sh, uint8_t* bits, uint32_t bn) {
	uint8_t* elf = malloc(eh->ehsize + (eh->phentsize * eh->phnum) + (eh->shentsize * eh->shnum) + bn);
	uint64_t esz;
	
	uint8_t sig[] = {127, 'E', 'L', 'F', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	esz = elf_copy(elf, 0, sig, 16);
	esz = elf_copy(elf, esz, eh, eh->ehsize - 16);
	esz = elf_copy(elf, esz, ph, eh->phentsize * eh->phnum);
	esz = elf_copy(elf, esz, sh, eh->shentsize * eh->shnum);
	esz = elf_copy(elf, esz, bits, bn);
	
	return elf;
}

uint8_t* elf_write_64(elf_e64_t* eh, elf_p64_t* ph, elf_sh64_t* sh, uint8_t* bits, uint64_t bn) {
	uint8_t* elf = malloc(eh->ehsize + (eh->phentsize * eh->phnum) + (eh->shentsize * eh->shnum) + bn);
	uint64_t esz;
	
	uint8_t sig[] = {127, 'E', 'L', 'F', 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	esz = elf_copy(elf, 0, sig, 16);
	esz = elf_copy(elf, esz, eh, eh->ehsize - 16);
	esz = elf_copy(elf, esz, ph, eh->phentsize * eh->phnum);
	esz = elf_copy(elf, esz, sh, eh->shentsize * eh->shnum);
	esz = elf_copy(elf, esz, bits, bn);
	
	return elf;
}
