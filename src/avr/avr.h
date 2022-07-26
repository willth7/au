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

typedef struct enc_s {
	uint8_t x[4];
	uint8_t n;
} enc_t;

uint8_t avr_reg3(uint8_t*);

uint8_t avr_reg4(uint8_t*);

uint8_t avr_reg5(uint8_t*);

uint8_t avr_reg4p(int8_t*);

uint8_t avr_imm4(int8_t*);

uint8_t avr_imm6(int8_t*);

uint8_t avr_imm8(int8_t*);

enc_t avr_enc(int8_t*, int8_t*, int8_t*);
