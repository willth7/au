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

int8_t au_lex(int8_t* path) {
	printf("%s\n", path);
}

int8_t main(int32_t argc, int8_t** argv) {
	if (argc == 1) {
		//help
		return 0;
	}
	
	for (uint8_t ai = 1; ai < argc; ai++) {
		int8_t* path = malloc(strlen(argv[ai]) + 4);
		strcpy(path, argv[ai]);
		strcpy(path + strlen(path), ".au");
		au_lex(path);
		free(path);
	}
	
	return 0;
}
