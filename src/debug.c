/*
 * debug.c
 *
 *  Created on: Sep 26, 2020
 *      Author: hamid
 */

#include "include/lucs.h"
#include "include/debug.h"
#include "include/tokenizer.h"
#define LUCS_DBG_MODE 1
#if LUCS_DBG_MODE
static const char *tokens_str[] = {
		/* General Tokens */
		LUCS_TOKEN_BLANK1_DBG_STR,
		LUCS_TOKEN_BLANK2_DBG_STR,
		LUCS_TOKEN_CR_DBG_STR,
		LUCS_TOKEN_LF_DBG_STR,
		LUCS_TOKEN_PAREN_OPEN_DBG_STR,
		LUCS_TOKEN_PAREN_CLOSE_DBG_STR,
		LUCS_TOKEN_BRACES_OPEN_DBG_STR,
		LUCS_TOKEN_BRACES_CLOSE_DBG_STR,
		LUCS_TOKEN_DOT_DBG_STR,
		LUCS_TOKEN_SEMICOLON_DBG_STR,
		LUCS_TOKEN_COLON_DBG_STR,
		LUCS_TOKEN_SEPR_DBG_STR,

		/* General Operator Tokens */
		LUCS_TOKEN_OP_INC_DBG_STR,
		LUCS_TOKEN_OP_DEC_DBG_STR,

		/* Other Operator Tokens */
		LUCS_TOKEN_OP_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_PLUS_DBG_STR,
		LUCS_TOKEN_OP_MINUS_DBG_STR,
		LUCS_TOKEN_OP_MUL_DBG_STR,
		LUCS_TOKEN_OP_DIV_DBG_STR,
		LUCS_TOKEN_OP_POW_DBG_STR,
		LUCS_TOKEN_OP_NOT_DBG_STR,
		LUCS_TOKEN_OP_NEG_DBG_STR,
		LUCS_TOKEN_OP_RSHIFT_DBG_STR,
		LUCS_TOKEN_OP_LSHIFT_DBG_STR,
		LUCS_TOKEN_OP_AND_DBG_STR,
		LUCS_TOKEN_OP_OR_DBG_STR,
		LUCS_TOKEN_OP_XOR_DBG_STR,

		/* Concurrent Assign and Operator Tokens */
		LUCS_TOKEN_OP_PLUS_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_MINUS_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_MUL_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_DIV_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_POW_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_NEG_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_RSHIFT_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_LSHIFT_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_AND_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_OR_ASSIGN_DBG_STR,
		LUCS_TOKEN_OP_XOR_ASSIGN_DBG_STR,

		/* Conditional Operator Tokens */
		LUCS_TOKEN_COP_EQU_DBG_STR,
		LUCS_TOKEN_COP_NEQU_DBG_STR,
		LUCS_TOKEN_COP_LESS_DBG_STR,
		LUCS_TOKEN_COP_GREA_DBG_STR,
		LUCS_TOKEN_COP_LESSEQ_DBG_STR,
		LUCS_TOKEN_COP_GREAEQ_DBG_STR,
		LUCS_TOKEN_COP_AND_DBG_STR,
		LUCS_TOKEN_COP_OR_DBG_STR,
		LUCS_TOKEN_COP_XOR_DBG_STR,

		/* Keyword Tokens */
		LUCS_TOKEN_VAR_DBG_STR,
		LUCS_TOKEN_LIV_DBG_STR,
		LUCS_TOKEN_IF_DBG_STR,
		LUCS_TOKEN_FOR_DBG_STR,
		LUCS_TOKEN_NEW_DBG_STR,
		LUCS_TOKEN_WHILE_DBG_STR,
		LUCS_TOKEN_SWITCH_DBG_STR,
		LUCS_TOKEN_BREAK_DBG_STR,
		LUCS_TOKEN_CONTINUE_DBG_STR,
		LUCS_TOKEN_FOREACH_DBG_STR,
		LUCS_TOKEN_WHERE_DBG_STR,
		LUCS_TOKEN_FUNCTION_DBG_STR,
		LUCS_TOKEN_CLASS_DBG_STR,
		LUCS_TOKEN_RETURN_DBG_STR,
		LUCS_TOKEN_RUN_DBG_STR,
		LUCS_TOKEN_UNDEFINED_DBG_STR,
		LUCS_TOKEN_TYPEOF_DBG_STR,
		LUCS_TOKEN_NAN_DBG_STR,
		LUCS_TOKEN_INF_DBG_STR,
		LUCS_TOKEN_NULL_DBG_STR,
};

void lucs_dbg_print_tokens(const lucs_tok_t *tokens, lucs_tables_t *tables)
{
	const lucs_tok_t * cur_tok = tokens;
	while(*cur_tok != LUCS_TOKEN_LAST)
	{
		if(*cur_tok == LUCS_TOKEN_ID_VARIABLE)
		{
			uint8_t table_index = *(cur_tok+1);
			LUCS_DBG_PRINTF("[VAR %i] ", table_index);
			cur_tok+=2;
			continue;
		}
		if(*cur_tok == LUCS_TOKEN_ID_FUNCTION)
		{
			uint8_t table_index = *(cur_tok+1);
			if(tables->lucs_function_table[table_index].lucs_token_start != LUCS_TABLE_FUNC_START_NOT_SET)
			{
				LUCS_DBG_PRINTF("[FUNC %s Defined At %i] ", tables->lucs_function_table[table_index].identifier_text, tables->lucs_function_table[table_index].lucs_token_start);
			}
			else
			{
				LUCS_DBG_PRINTF("[FUNC %s Call] ", tables->lucs_function_table[table_index].identifier_text);
			}
			cur_tok+=2;
			continue;
		}
		if(*cur_tok == LUCS_TOKEN_ID_CONST)
		{
			uint8_t table_index = *(cur_tok+1);
			if(tables->lucs_const_table[table_index].type == LUCS_CONST_STRING)
			{
				char temp[128];
				memcpy(temp, tables->lucs_const_table[table_index].value.val_str.val_string, tables->lucs_const_table[table_index].value.val_str.len);
				temp[tables->lucs_const_table[table_index].value.val_str.len] = 0;
				LUCS_DBG_PRINTF("[CONST (%s) ] ", temp);
			}
			else
			{
				LUCS_DBG_PRINTF("[CONST (%f) ] ", tables->lucs_const_table[table_index].value.val_number_double);
			}
			cur_tok+=2;
			continue;
		}
		LUCS_DBG_PRINTF("%s ", tokens_str[*cur_tok]);
		cur_tok++;
	}
}
#endif
