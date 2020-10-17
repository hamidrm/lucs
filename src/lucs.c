/*
 * lucs.c
 *
 *  Created on: Sep 5, 2020
 *      Author: hamid
 */
#include "include/lucs.h"


void lucs_init(lucs_ctx_t *ctx)
{
	lucs_tables_init(&(ctx->lucs_tables));
	lucs_tokenizer(ctx->script, ctx->tokens_buffer, ctx->tokens_buffer_length, &(ctx->lucs_tables));
}
