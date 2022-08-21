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

int8_t au_lex(int8_t* path, uint8_t* bin, uint64_t* bn) {
	printf("%s\n", path);
	return 0;
}

int8_t main(int32_t argc, int8_t** argv) {
	if (argc != 3) {
		printf("usage: au [source.au] [binary.bin]\n");
		return -1;
	}
	
	if (strcmp(argv[1] + strlen(argv[1]) - 3, ".au")) {
		printf("error: expected .au file\n");
		return -1;
	}
	if (strcmp(argv[2] + strlen(argv[2]) - 4, ".bin")) {
		printf("error: expected .bin file\n");
		return -1;
	}
	
	uint8_t* bin;
	uint64_t bn = 0;
	if(au_lex(argv[1], bin, &bn)) {
		printf("failed to assemble binary\n");
		return -1;
	}
	
	FILE* f = fopen(argv[2], "w");
	fwrite(bin, bn, 1, f);
	fclose(f);
	
	return 0;
}
