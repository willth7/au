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
	uint32_t addend;
} elf_r32_t;

typedef struct elf_r64_s {
	uint64_t offset;
	uint64_t info;
	uint64_t addend;
} elf_r64_t;

void elf_write(int8_t* path, uint8_t cls, void* ehp, void* php, void* shp, uint8_t* bits, uint64_t bn) {
	
	if (cls == 1) {
		elf_e32_t* eh = ehp;
		elf_p32_t* ph = php;
		elf_sh32_t* sh = shp;
		
		FILE* f = fopen(path, "w");
		
		fprintf(f, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 127, 'E', 'L', 'F', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0); //ident
		fprintf(f, "%c%c", (int8_t) (eh->type), (int8_t) (eh->type >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->machine), (int8_t) (eh->machine >> 8));
		fprintf(f, "%c%c%c%c", (int8_t) (eh->version), (int8_t) (eh->version >> 8), (int8_t) (eh->version >> 16), (int8_t) (eh->version >> 24));
		fprintf(f, "%c%c%c%c", (int8_t) (eh->entry), (int8_t) (eh->entry >> 8), (int8_t) (eh->entry >> 16), (int8_t) (eh->entry >> 24));
		fprintf(f, "%c%c%c%c", (int8_t) (eh->phoff), (int8_t) (eh->phoff >> 8), (int8_t) (eh->phoff >> 16), (int8_t) (eh->phoff >> 24));
		fprintf(f, "%c%c%c%c", (int8_t) (eh->shoff), (int8_t) (eh->shoff >> 8), (int8_t) (eh->shoff >> 16), (int8_t) (eh->shoff >> 24));
		fprintf(f, "%c%c%c%c", (int8_t) (eh->flags), (int8_t) (eh->flags >> 8), (int8_t) (eh->flags >> 16), (int8_t) (eh->flags >> 24));
		fprintf(f, "%c%c", (int8_t) (eh->ehsize), (int8_t) (eh->ehsize >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->phentsize), (int8_t) (eh->phentsize >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->phnum), (int8_t) (eh->phnum >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->shentsize), (int8_t) (eh->shentsize >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->shnum), (int8_t) (eh->shnum >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->shstrndx), (int8_t) (eh->shstrndx >> 8));
		
		for (uint32_t i = 0; i < eh->phnum; i++) {
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].type), (int8_t) (ph[i].type >> 8), (int8_t) (ph[i].type >> 16), (int8_t) (ph[i].type >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].offset), (int8_t) (ph[i].offset >> 8), (int8_t) (ph[i].offset >> 16), (int8_t) (ph[i].offset >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].vaddr), (int8_t) (ph[i].vaddr >> 8), (int8_t) (ph[i].vaddr >> 16), (int8_t) (ph[i].vaddr >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].paddr), (int8_t) (ph[i].paddr >> 8), (int8_t) (ph[i].paddr >> 16), (int8_t) (ph[i].paddr >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].filesz), (int8_t) (ph[i].filesz >> 8), (int8_t) (ph[i].filesz >> 16), (int8_t) (ph[i].filesz >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].memsz), (int8_t) (ph[i].memsz >> 8), (int8_t) (ph[i].memsz >> 16), (int8_t) (ph[i].memsz >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].flags), (int8_t) (ph[i].flags >> 8), (int8_t) (ph[i].flags >> 16), (int8_t) (ph[i].flags >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].align), (int8_t) (ph[i].align >> 8), (int8_t) (ph[i].align >> 16), (int8_t) (ph[i].align >> 24));
		}
		
		for (uint32_t i = 0; i < eh->shnum; i++) {
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].name), (int8_t) (sh[i].name >> 8), (int8_t) (sh[i].name >> 16), (int8_t) (sh[i].name >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].type), (int8_t) (sh[i].type >> 8), (int8_t) (sh[i].type >> 16), (int8_t) (sh[i].type >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].flags), (int8_t) (sh[i].flags >> 8), (int8_t) (sh[i].flags >> 16), (int8_t) (sh[i].flags >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].addr), (int8_t) (sh[i].addr >> 8), (int8_t) (sh[i].addr >> 16), (int8_t) (sh[i].addr >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].offset), (int8_t) (sh[i].offset >> 8), (int8_t) (sh[i].offset >> 16), (int8_t) (sh[i].offset >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].size), (int8_t) (sh[i].size >> 8), (int8_t) (sh[i].size >> 16), (int8_t) (sh[i].size >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].link), (int8_t) (sh[i].link >> 8), (int8_t) (sh[i].link >> 16), (int8_t) (sh[i].link >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].info), (int8_t) (sh[i].info >> 8), (int8_t) (sh[i].info >> 16), (int8_t) (sh[i].info >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].addralign), (int8_t) (sh[i].addralign >> 8), (int8_t) (sh[i].addralign >> 16), (int8_t) (sh[i].addralign >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].entsize), (int8_t) (sh[i].entsize >> 8), (int8_t) (sh[i].entsize >> 16), (int8_t) (sh[i].entsize >> 24));
		}
		
		for (uint32_t i = 0; i < bn; i++) {
			fprintf(f, "%c", bits[i]); //progbits
		}
		
		fclose(f);
	}
	
	else if (cls == 2) {
		elf_e64_t* eh = ehp;
		elf_p64_t* ph = php;
		elf_sh64_t* sh = shp;
		
		FILE* f = fopen(path, "w");
		
		fprintf(f, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 127, 'E', 'L', 'F', 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0); //ident
		fprintf(f, "%c%c", (int8_t) (eh->type), (int8_t) (eh->type >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->machine), (int8_t) (eh->machine >> 8));
		fprintf(f, "%c%c%c%c", (int8_t) (eh->version), (int8_t) (eh->version >> 8), (int8_t) (eh->version >> 16), (int8_t) (eh->version >> 24));
		fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (eh->entry), (int8_t) (eh->entry >> 8), (int8_t) (eh->entry >> 16), (int8_t) (eh->entry >> 24), (int8_t) (eh->entry >> 32), (int8_t) (eh->entry >> 40), (int8_t) (eh->entry >> 48), (int8_t) (eh->entry >> 56));
		fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (eh->phoff), (int8_t) (eh->phoff >> 8), (int8_t) (eh->phoff >> 16), (int8_t) (eh->phoff >> 24), (int8_t) (eh->phoff >> 32), (int8_t) (eh->phoff >> 40), (int8_t) (eh->phoff >> 48), (int8_t) (eh->phoff >> 56));
		fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (eh->shoff), (int8_t) (eh->shoff >> 8), (int8_t) (eh->shoff >> 16), (int8_t) (eh->shoff >> 24), (int8_t) (eh->shoff >> 32), (int8_t) (eh->shoff >> 40), (int8_t) (eh->shoff >> 48), (int8_t) (eh->shoff >> 56));
		fprintf(f, "%c%c%c%c", (int8_t) (eh->flags), (int8_t) (eh->flags >> 8), (int8_t) (eh->flags >> 16), (int8_t) (eh->flags >> 24));
		fprintf(f, "%c%c", (int8_t) (eh->ehsize), (int8_t) (eh->ehsize >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->phentsize), (int8_t) (eh->phentsize >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->phnum), (int8_t) (eh->phnum >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->shentsize), (int8_t) (eh->shentsize >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->shnum), (int8_t) (eh->shnum >> 8));
		fprintf(f, "%c%c", (int8_t) (eh->shstrndx), (int8_t) (eh->shstrndx >> 8));
		
		for (uint32_t i = 0; i < eh->phnum; i++) {
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].type), (int8_t) (ph[i].type >> 8), (int8_t) (ph[i].type >> 16), (int8_t) (ph[i].type >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (ph[i].flags), (int8_t) (ph[i].flags >> 8), (int8_t) (ph[i].flags >> 16), (int8_t) (ph[i].flags >> 24));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (ph[i].offset), (int8_t) (ph[i].offset >> 8), (int8_t) (ph[i].offset >> 16), (int8_t) (ph[i].offset >> 24), (int8_t) (ph[i].offset >> 32), (int8_t) (ph[i].offset >> 40), (int8_t) (ph[i].offset >> 48), (int8_t) (ph[i].offset >> 56));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (ph[i].vaddr), (int8_t) (ph[i].vaddr >> 8), (int8_t) (ph[i].vaddr >> 16), (int8_t) (ph[i].vaddr >> 24), (int8_t) (ph[i].vaddr >> 32), (int8_t) (ph[i].vaddr >> 40), (int8_t) (ph[i].vaddr >> 48), (int8_t) (ph[i].vaddr >> 56));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (ph[i].paddr), (int8_t) (ph[i].paddr >> 8), (int8_t) (ph[i].paddr >> 16), (int8_t) (ph[i].paddr >> 24), (int8_t) (ph[i].paddr >> 32), (int8_t) (ph[i].paddr >> 40), (int8_t) (ph[i].paddr >> 48), (int8_t) (ph[i].paddr >> 56));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (ph[i].filesz), (int8_t) (ph[i].filesz >> 8), (int8_t) (ph[i].filesz >> 16), (int8_t) (ph[i].filesz >> 24), (int8_t) (ph[i].filesz >> 32), (int8_t) (ph[i].filesz >> 40), (int8_t) (ph[i].filesz >> 48), (int8_t) (ph[i].filesz >> 56));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (ph[i].memsz), (int8_t) (ph[i].memsz >> 8), (int8_t) (ph[i].memsz >> 16), (int8_t) (ph[i].memsz >> 24), (int8_t) (ph[i].memsz >> 32), (int8_t) (ph[i].memsz >> 40), (int8_t) (ph[i].memsz >> 48), (int8_t) (ph[i].memsz >> 56));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (ph[i].align), (int8_t) (ph[i].align >> 8), (int8_t) (ph[i].align >> 16), (int8_t) (ph[i].align >> 24), (int8_t) (ph[i].align >> 32), (int8_t) (ph[i].align >> 40), (int8_t) (ph[i].align >> 48), (int8_t) (ph[i].align >> 56));
		}
		
		for (uint32_t i = 0; i < eh->shnum; i++) {
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].name), (int8_t) (sh[i].name >> 8), (int8_t) (sh[i].name >> 16), (int8_t) (sh[i].name >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].type), (int8_t) (sh[i].type >> 8), (int8_t) (sh[i].type >> 16), (int8_t) (sh[i].type >> 24));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (sh[i].flags), (int8_t) (sh[i].flags >> 8), (int8_t) (sh[i].flags >> 16), (int8_t) (sh[i].flags >> 24), (int8_t) (sh[i].flags >> 32), (int8_t) (sh[i].flags >> 40), (int8_t) (sh[i].flags >> 48), (int8_t) (sh[i].flags >> 56));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (sh[i].addr), (int8_t) (sh[i].addr >> 8), (int8_t) (sh[i].addr >> 16), (int8_t) (sh[i].addr >> 24), (int8_t) (sh[i].addr >> 32), (int8_t) (sh[i].addr >> 40), (int8_t) (sh[i].addr >> 48), (int8_t) (sh[i].addr >> 56));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (sh[i].offset), (int8_t) (sh[i].offset >> 8), (int8_t) (sh[i].offset >> 16), (int8_t) (sh[i].offset >> 24), (int8_t) (sh[i].offset >> 32), (int8_t) (sh[i].offset >> 40), (int8_t) (sh[i].offset >> 48), (int8_t) (sh[i].offset >> 56));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (sh[i].size), (int8_t) (sh[i].size >> 8), (int8_t) (sh[i].size >> 16), (int8_t) (sh[i].size >> 24), (int8_t) (sh[i].size >> 32), (int8_t) (sh[i].size >> 40), (int8_t) (sh[i].size >> 48), (int8_t) (sh[i].size >> 56));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].link), (int8_t) (sh[i].link >> 8), (int8_t) (sh[i].link >> 16), (int8_t) (sh[i].link >> 24));
			fprintf(f, "%c%c%c%c", (int8_t) (sh[i].info), (int8_t) (sh[i].info >> 8), (int8_t) (sh[i].info >> 16), (int8_t) (sh[i].info >> 24));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (sh[i].addralign), (int8_t) (sh[i].addralign >> 8), (int8_t) (sh[i].addralign >> 16), (int8_t) (sh[i].addralign >> 24), (int8_t) (sh[i].addralign >> 32), (int8_t) (sh[i].addralign >> 40), (int8_t) (sh[i].addralign >> 48), (int8_t) (sh[i].addralign >> 56));
			fprintf(f, "%c%c%c%c%c%c%c%c", (int8_t) (sh[i].entsize), (int8_t) (sh[i].entsize >> 8), (int8_t) (sh[i].entsize >> 16), (int8_t) (sh[i].entsize >> 24), (int8_t) (sh[i].entsize >> 32), (int8_t) (sh[i].entsize >> 40), (int8_t) (sh[i].entsize >> 48), (int8_t) (sh[i].entsize >> 56));
		}
		
		for (uint32_t i = 0; i < bn; i++) {
			fprintf(f, "%c", bits[i]); //progbits
		}
		
		fclose(f);
	}
}
