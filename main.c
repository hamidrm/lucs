/*
 * main.c
 *
 *  Created on: Sep 5, 2020
 *      Author: hamid
 */

#include <stdio.h>
#include <stdint.h>
#include "include/lucs.h"
#include "mem/inc/mem.h"
#include "include/lucs.h"

void lucs_dbg_print_tokens(const lucs_tok_t *tokens, lucs_tables_t *tables);
int main(char *argc, char *argv){
	mem_ctx_t mem;
	lucs_ctx_t  ctx;
	void *a_ptr,*b_ptr,*c_ptr;
	uint8_t	heap_buff[MEM_CALC_BUFF_SIZE(32,256)];
	const char *code = "hesi =\"Salam\"\n"\
			"function hamid(a,b) {\n"\
			"return (a+b)*2\n"\
			"}\n"\
			"function getGrades() {\n"\
			"    liv args = Array.prototype.slice.call(arguments, 1, 3);\n"\
			"    a = 6;\n"\
			"    return args;\n"\
			"}";
	lucs_tok_t lucs_tokens[1024];
	ctx.script = code;
	ctx.tokens_buffer = lucs_tokens;
	ctx.tokens_buffer_length = 1024;
	lucs_init(&ctx);

	lucs_dbg_print_tokens(lucs_tokens, &(ctx.lucs_tables));

	mem_create(&mem, heap_buff, 32, 256);

	a_ptr = mem_alloc(&mem, 16);
	b_ptr = mem_alloc(&mem, 160);
	c_ptr = mem_alloc(&mem, 1600);
	mem_free(&mem, b_ptr);
	b_ptr = mem_alloc(&mem, 257);
	b_ptr = mem_alloc(&mem, 257);

	return 0;
}

