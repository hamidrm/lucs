/*
 * main.c
 *
 *  Created on: Sep 5, 2020
 *      Author: hamid
 */

#include <stdio.h>
#include <stdint.h>
#include "include/lucs.h"
#include "include/mem.h"

 void lucs_dbg_print_tokens(const lucs_tok_t *tokens);
int main(char *argc, char *argv){
	mem_ctx_t mem;
	void *a_ptr,*b_ptr,*c_ptr;
	uint8_t	heap_buff[MEM_CALC_BUFF_SIZE(256,32)];
	const char *code = "//hesi =\"Salam\"\n"\
			"function hamid(a,b) {\n"\
			"return (a+b)*2\n"\
			"}\n"\
			"function getGrades() {\n"\
			"    liv args = Array.prototype.slice.call(arguments, 1, 3);\n"\
			"    return args;\n"\
			"}";
	lucs_tok_t lucs_tokens[1024];
	lucs_tokenizer(code, lucs_tokens, 1024);
	lucs_dbg_print_tokens(lucs_tokens);

	mem_create(&mem, heap_buff, 256, 32);

	a_ptr = mem_alloc(&mem, 16);
	b_ptr = mem_alloc(&mem, 160);
	c_ptr = mem_alloc(&mem, 1600);
	mem_free(&mem, b_ptr);
	b_ptr = mem_alloc(&mem, 257);
	b_ptr = mem_alloc(&mem, 257);

	return 0;
}

