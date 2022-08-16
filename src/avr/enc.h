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

typedef uint64_t (*avr_op_f) (uint8_t*, uint64_t, uint16_t, uint16_t);
typedef uint16_t (*avr_reg_f) (int8_t*, int8_t*, int8_t*);

typedef struct avr_s {
	avr_op_f op;
	avr_reg_f rd;
	avr_reg_f rs;
	uint8_t rel;
} avr_t;

avr_t avr_enc(int8_t*, int8_t*);

