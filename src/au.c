//   Copyright 2022 Will Thomas
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
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

#include "avr/avr.h"

int8_t main(int32_t argc, int8_t** argv) {
	if (argc < 2) {
		return -1;
	}
	
	uint16_t b;
	if (argc == 2) {
		b = avr_enc(argv[1], 0, 0);
	}
	else if (argc == 3) {
		b = avr_enc(argv[1], argv[2], 0);
	}
	else if (argc == 4) {
		b = avr_enc(argv[1], argv[2], argv[3]);
	}
	printf("0x%04x\n", b);
	
	return 0;
}
