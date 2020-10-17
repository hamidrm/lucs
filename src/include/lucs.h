/*
 * lucs.h
 *
 *  Created on: Sep 5, 2020
 *      Author: hamid
 */

#ifndef LUCS_H_
#define LUCS_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "include/lucs_config.h"
#include "include/lucs_types.h"
#include "include/tables.h"
#include "include/tokenizer.h"

typedef struct
{
	lucs_cstring_t	script;
	lucs_ui4_t		length;
	lucs_ui4_t		offset;
	lucs_ptr_t	 	stack;
	lucs_ui4_t		stack_size;
	lucs_ui4_t		stack_pointer;
	lucs_size_t		tokens_buffer_length;
	lucs_byte_t		*tokens_buffer;
	lucs_tables_t	lucs_tables;
} lucs_ctx_t;

void lucs_init(lucs_ctx_t *ctx);

#endif /* LUCS_H_ */
