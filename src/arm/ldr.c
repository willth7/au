	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'p' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrps");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'w' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrws");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 't' && op[4] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 48;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrts");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 's') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrs");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'p') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrp");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 'w') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 5;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 7;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrw");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r' && op[3] == 't') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 4, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 176;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldrt");
			*e = -1;
		}
	}
	else if (op[0] == 'l' && op[1] == 'd' && op[2] == 'r') {
		if (rt[0] == 1 && rt[1] == 1 && rt[2] == 2 && rt[3] == 0) {
			arm_v7a_err_r4_r4_k12(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], rv[1], rv[2]);
		}
		else if (rt[0] == 1 && rt[1] == 4 && rt[2] == 0) { //rel
			arm_v7a_err_r4(rv[0], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 16;
			bin[*bn + 3] = 4;
			arm_v7a_inst_c4_r4_r4_k12(bin, bn, c, rv[0], 15, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 5, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], 0, 0);
		}
		else if (rt[0] == 1 && rt[1] == 1 && rt[2] == 1 && rt[3] == 1 && rt[4] == 2 && rt[5] == 0) {
			arm_v7a_err_r4_r4_r4(rv[0], rv[1], rv[2], e, path, ln);
			arm_v7a_err_sh(rv[3], rv[4], e, path, ln);
			uint8_t c = arm_v7a_cond(op + 3, e, path, ln);
			
			bin[*bn] = 0;
			bin[*bn + 1] = 0;
			bin[*bn + 2] = 144;
			bin[*bn + 3] = 6;
			arm_v7a_inst_c4_r4_r4_r4_t2_k5(bin, bn, c, rv[0], rv[1], rv[2], rv[3], rv[4]);
		}
		else {
			printf("[%s, %lu] error: illegal usage of opcode '%s'\n", path, ln, "ldr");
			*e = -1;
		}
	}
