/*
 * tokenizer.c
 *
 *  Created on: Sep 26, 2020
 *      Author: hamid
 */

#include "include/lucs.h"
#include "include/tokenizer.h"
#include "include/stack.h"

static const lucs_keywords_token_t lucs_keyword_list[] = LUCS_KEYWORDS_LIST;

void lucs_tokenizer(const char *input, lucs_tok_t *tokens, size_t max_length, lucs_tables_t *tables)
{
#define PUSH_TOKEN(x)	lucs_stack_push(&lucs_stack, x)
#define POP_TOKEN()	((lucs_tok_t *)lucs_stack_pop(&lucs_stack))
	lucs_ui4_t lucs_level = 0;
	lucs_ui4_t lucs_block_num = 0;
	lucs_stack_t	lucs_stack;
	lucs_tokens_t	prev_token = LUCS_UNDEFINED_TOKEN;
	lucs_tokenizer_state_t lucs_tokenizer_state;
	lucs_tok_t lucs_token;
	lucs_identifier_t lucs_identifier;
	const char	*string_start_point;
	size_t string_length;
	const lucs_keywords_token_t *lucs_keyword_item;
	lucs_tok_t last_token = LUCS_TOKEN_LAST;
	lucs_tokenizer_state = LUCS_TOKENIZER_STATE_CODE;
	lucs_stack.elem_size = sizeof(lucs_tok_t);
	lucs_stack.ptr = tokens;
	lucs_stack.length = max_length;
	lucs_stack_init(&lucs_stack);
	memset(&lucs_identifier, 0, sizeof(lucs_identifier));

	while(*input)
	{

		if(lucs_tokenizer_state != LUCS_TOKENIZER_STATE_CODE)
		{
			switch (lucs_tokenizer_state) {
			case LUCS_TOKENIZER_STATE_COMMENT1:
				if(*input ==  LUCS_TOKEN_LF_STR)
				{
					// End Of Comment
					lucs_tokenizer_state = LUCS_TOKENIZER_STATE_CODE;
				}
				break;
			case LUCS_TOKENIZER_STATE_COMMENT2:
				if(*input ==  LUCS_TOKEN_OP_DIV_STR &&
						*(input-1) ==  LUCS_TOKEN_OP_MUL_STR )
				{
					// End Of Comment
					lucs_tokenizer_state = LUCS_TOKENIZER_STATE_CODE;
				}
				break;
			case LUCS_TOKENIZER_STATE_STRING1:
				if(*input ==  LUCS_TOKEN_QUOTATION_STR &&
						*(input-1) !=  LUCS_TOKEN_OP_DIV_STR)
				{
					// End Of String
					//Add it to string table (string_start_point, string_length)
					lucs_tok_t table_index =lucs_constant_table_add(tables, string_start_point, string_length, LUCS_CONST_STRING);
					PUSH_TOKEN(&table_index);
					lucs_tokenizer_state = LUCS_TOKENIZER_STATE_CODE;
				}
				else
					string_length++;
				break;
			case LUCS_TOKENIZER_STATE_STRING2:
				if(*input ==  LUCS_TOKEN_DQUOTATION_STR &&
						*(input-1) !=  LUCS_TOKEN_OP_DIV_STR)
				{
					// End Of String
					//Add it to string table.(string_start_point, string_length)
					lucs_tok_t table_index = lucs_constant_table_add(tables, string_start_point, string_length, LUCS_CONST_STRING);
					PUSH_TOKEN(&table_index);
					lucs_tokenizer_state = LUCS_TOKENIZER_STATE_CODE;
				}
				else
					string_length++;
				break;

				//TODO-default: Raise an error! Undefined state
			}
			input++;
			continue;
		}

		// First, Ignore all white-spaces
		if(*input == LUCS_TOKEN_BLANK1_STR ||
				*input == LUCS_TOKEN_BLANK2_STR)
		{

			if(lucs_identifier.identifier_started)
				lucs_token = LUCS_TOKEN_BLANK1;
			else
			{
				input++;
				continue;
			}
		}
		else
			// Start with undefined token
			lucs_token = LUCS_UNDEFINED_TOKEN;

		//  Looking for non-keyword tokens
		switch (*input) {
		case LUCS_TOKEN_QUOTATION_STR:
			lucs_tokenizer_state = LUCS_TOKENIZER_STATE_STRING1;
			lucs_token = LUCS_TOKEN_ID_CONST;
			string_start_point = input+1;
			string_length = 0;
			break;
		case LUCS_TOKEN_DQUOTATION_STR:
			lucs_tokenizer_state = LUCS_TOKENIZER_STATE_STRING2;
			lucs_token = LUCS_TOKEN_ID_CONST;
			string_start_point = input+1;
			string_length = 0;
			break;
		case LUCS_TOKEN_CR_STR:
		case LUCS_TOKEN_LF_STR:
			if (prev_token == LUCS_TOKEN_LF)
				POP_TOKEN();
			lucs_token = LUCS_TOKEN_LF;
			break;
		case LUCS_TOKEN_PAREN_OPEN_STR:
			lucs_token = LUCS_TOKEN_PAREN_OPEN;
			break;
		case LUCS_TOKEN_PAREN_CLOSE_STR:
			lucs_token = LUCS_TOKEN_PAREN_CLOSE;
			break;
		case LUCS_TOKEN_SEMICOLON_STR:
			if (prev_token == LUCS_TOKEN_LF)
				POP_TOKEN();
			lucs_token = LUCS_TOKEN_LF;
			break;
		case LUCS_TOKEN_COLON_STR:
			lucs_token = LUCS_TOKEN_COLON;
			break;
		case LUCS_TOKEN_SEPR_STR:
			lucs_token = LUCS_TOKEN_SEPR;
			break;
		case LUCS_TOKEN_BRACES_OPEN_STR:
			lucs_token = LUCS_TOKEN_BRACES_OPEN;
			lucs_level++;
			break;
		case LUCS_TOKEN_BRACES_CLOSE_STR:
			lucs_token = LUCS_TOKEN_BRACES_CLOSE;
			lucs_level--;
			lucs_block_num++;
			break;
		case LUCS_TOKEN_OP_ASSIGN_STR:
			switch (prev_token)
			{
			case LUCS_TOKEN_OP_ASSIGN:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_COP_EQU;
				break;
			case LUCS_TOKEN_OP_PLUS:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_PLUS_ASSIGN;
				break;
			case LUCS_TOKEN_OP_MINUS:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_MINUS_ASSIGN;
				break;
			case LUCS_TOKEN_OP_MUL:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_MUL_ASSIGN;
				break;
			case LUCS_TOKEN_OP_DIV:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_DIV_ASSIGN;
				break;
			case LUCS_TOKEN_OP_POW:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_POW_ASSIGN;
				break;
			case LUCS_TOKEN_OP_NOT:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_COP_NEQU;
				break;
			case LUCS_TOKEN_OP_NEG:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_NEG_ASSIGN;
				break;
			case LUCS_TOKEN_OP_RSHIFT:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_RSHIFT_ASSIGN;
				break;
			case LUCS_TOKEN_OP_LSHIFT:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_LSHIFT_ASSIGN;
				break;
			case LUCS_TOKEN_OP_AND:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_AND_ASSIGN;
				break;
			case LUCS_TOKEN_OP_OR:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_OR_ASSIGN;
				break;
			case LUCS_TOKEN_OP_XOR:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_XOR_ASSIGN;
				break;
			case LUCS_TOKEN_COP_LESS:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_COP_LESSEQ;
				break;
			case LUCS_TOKEN_COP_GREA:
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_COP_GREAEQ;
				break;
			default:
				lucs_token = LUCS_TOKEN_OP_ASSIGN;
			}
			break;
		case LUCS_TOKEN_OP_PLUS_STR:
			if (prev_token == LUCS_TOKEN_OP_PLUS)
			{
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_INC;
			}else
				lucs_token = LUCS_TOKEN_OP_PLUS;
			break;
		case LUCS_TOKEN_OP_MINUS_STR:
			if (prev_token == LUCS_TOKEN_OP_MINUS)
			{
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_DEC;
			}else
				lucs_token = LUCS_TOKEN_OP_MINUS;
			break;
		case LUCS_TOKEN_OP_MUL_STR:
			if (prev_token == LUCS_TOKEN_OP_DIV)
			{
				POP_TOKEN();
				lucs_tokenizer_state = LUCS_TOKENIZER_STATE_COMMENT2;
				input++;
				continue;
			}else
				lucs_token = LUCS_TOKEN_OP_MUL;
			break;
		case LUCS_TOKEN_OP_DIV_STR:
			if (prev_token == LUCS_TOKEN_OP_DIV)
			{
				POP_TOKEN();
				lucs_tokenizer_state = LUCS_TOKENIZER_STATE_COMMENT1;
				input++;
				continue;
			}else
				lucs_token = LUCS_TOKEN_OP_DIV;
			break;
		case LUCS_TOKEN_OP_POW_STR:
			lucs_token = LUCS_TOKEN_OP_POW;
			break;
		case LUCS_TOKEN_OP_NOT_STR:
			lucs_token = LUCS_TOKEN_OP_NOT;
			break;
		case LUCS_TOKEN_OP_NEG_STR:
			lucs_token = LUCS_TOKEN_OP_NEG;
			break;
		case LUCS_TOKEN_OP_AND_STR:
			if (prev_token == LUCS_TOKEN_OP_AND)
			{
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_COP_AND;
			}else
				lucs_token = LUCS_TOKEN_OP_AND;
			break;
		case LUCS_TOKEN_OP_OR_STR:
			if (prev_token == LUCS_TOKEN_OP_OR)
			{
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_COP_OR;
			}else
				lucs_token = LUCS_TOKEN_OP_OR;
			break;
		case LUCS_TOKEN_OP_XOR_STR:
			if (prev_token == LUCS_TOKEN_OP_XOR)
			{
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_COP_XOR;
			}else
				lucs_token = LUCS_TOKEN_OP_XOR;
			break;
		case LUCS_TOKEN_COP_LESS_STR:
			if (prev_token == LUCS_TOKEN_COP_LESS)
			{
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_LSHIFT;
			}else
				lucs_token = LUCS_TOKEN_COP_LESS;
			break;
		case LUCS_TOKEN_COP_GREA_STR:
			if (prev_token == LUCS_TOKEN_COP_GREA)
			{
				POP_TOKEN();
				lucs_token = LUCS_TOKEN_OP_RSHIFT;
			}else
				lucs_token = LUCS_TOKEN_COP_GREA;
			break;
		}

		if(lucs_token != LUCS_UNDEFINED_TOKEN && lucs_identifier.identifier_started == 0)
		{
			// Save last token
			prev_token = lucs_token;

			// Push detected token
			PUSH_TOKEN(&lucs_token);

			input++;
		}
		else
		{
			if ((lucs_token != LUCS_UNDEFINED_TOKEN || lucs_token == LUCS_TOKEN_BLANK1)
					&& lucs_identifier.identifier_started == 1)
			{
				lucs_tok_t last_token = lucs_token;
				lucs_tidx_t identifier_index;
				// Identifier completed! put a null character  as terminate character into the identifier array and start to find out what was that identifier.
				lucs_identifier.identifier_text[lucs_identifier.index] = 0;
				lucs_identifier.length = lucs_identifier.index;
				if (LUCS_IS_DIGIT(lucs_identifier.identifier_text[0])
						|| (lucs_identifier.identifier_text[0] == '.')) {
					// It's a constant number.
					identifier_index= lucs_constant_table_add(tables, (char *)(input - lucs_identifier.length), lucs_identifier.length, LUCS_CONST_NUMBER);
					lucs_token = LUCS_TOKEN_ID_CONST;
				} else {
					/* It's a keyword or variable or function name */

					//Is  it a keyword token?
					lucs_keyword_item = lucs_keyword_list;
					while (lucs_keyword_item->keyword_str) {
						if (strcmp(lucs_keyword_item->keyword_str,
								lucs_identifier.identifier_text) == 0) {
							lucs_token = lucs_keyword_item->keyword_token;
							break;
						}
						lucs_keyword_item++;
					}

					if (lucs_keyword_item->keyword_str == NULL) {
						//Is  it a function name  token?
						if (lucs_identifier.prev_token == LUCS_TOKEN_FUNCTION
								|| lucs_token == LUCS_TOKEN_PAREN_OPEN) {
							lucs_token = LUCS_TOKEN_ID_FUNCTION;
							identifier_index = lucs_function_table_add(tables, lucs_identifier.identifier_text, lucs_stack.index, lucs_identifier.prev_token == LUCS_TOKEN_FUNCTION ? 1 : 0);
						} else {
							//OK! It's a variable.
							lucs_token = LUCS_TOKEN_ID_VARIABLE;
							identifier_index =  lucs_variable_table_add(tables, lucs_identifier.identifier_text, lucs_level, lucs_block_num);
						}
					}
				}

				// Identifier detected.
				lucs_identifier.identifier_started = 0;

				// Push detected token
				PUSH_TOKEN(&lucs_token);
				if(lucs_token >= LUCS_TOKEN_ID_CONST  &&  lucs_token <= LUCS_TOKEN_ID_FUNCTION)
				{
					PUSH_TOKEN(&identifier_index);
				}
				if(last_token != LUCS_TOKEN_BLANK1)
				{
					// Save last token
					prev_token = last_token;
					PUSH_TOKEN(&prev_token);
				}
				else
				{
					prev_token = lucs_token;
				}
				input++;
			} else {
				if (lucs_identifier.identifier_started == 0) {
					lucs_identifier.identifier_started = 1;
					lucs_identifier.index = 0;
					lucs_identifier.length = 0;
					lucs_identifier.prev_token = prev_token;
				}
				if (lucs_identifier.index < (LUCS_MAX_IDENTIFIER_LEGTH - 1))
					lucs_identifier.identifier_text[lucs_identifier.index++] =
							*input++;

				//TODO-else raise overflow error
			}
		}

	}

	PUSH_TOKEN(&last_token);
#undef PUSH_TOKEN
#undef POP_TOKEN
}
