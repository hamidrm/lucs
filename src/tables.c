/*
 * tables.c
 *
 *  Created on: Oct 6, 2020
 *      Author: hamid
 */

#include "include/lucs.h"
#include "include/tokenizer.h"
#include "include/tables.h"
#include <stdlib.h>

void lucs_tables_init(lucs_tables_t	*tables)
{
	lucs_tidx_t	iter=0;
	for(iter=0; iter<LUCS_TABLE_FUNC_SIZE; iter++)
	{
		tables->lucs_function_table[iter].lucs_token_start = LUCS_TABLE_FUNC_START_NOT_SET;
	}
	for(iter=0; iter<LUCS_TABLE_CONST_SIZE; iter++)
	{
		tables->lucs_const_table[iter].type = LUCS_CONST_UNDEF;
	}
	for(iter=0; iter<LUCS_TABLE_VAR_SIZE; iter++)
	{
		tables->lucs_variable_table[iter].level = 0;
	}
}

lucs_i4_t lucs_constant_table_add(lucs_tables_t	*tables, lucs_ptr_t constant_value, lucs_size_t len, lucs_const_t type)
{
	lucs_tidx_t	iter=0;
	lucs_f8_t num;
	lucs_char_t	const_str[LUCS_MAX_IDENTIFIER_LEGTH];
	lucs_char_t	rec_const_str[LUCS_MAX_IDENTIFIER_LEGTH];

	memcpy(const_str, constant_value, len);
	const_str[len]=0;

	if(type == LUCS_CONST_NUMBER)
	{
		num = atof(const_str);
		for(iter=0; iter<tables->lucs_const_table_index; iter++)
		{
			if(tables->lucs_const_table[iter].type == LUCS_CONST_NUMBER)
			{
				if(tables->lucs_const_table[iter].value.val_number_double == num)
					return iter;
			}
		}
		if(tables->lucs_const_table_index == LUCS_TABLE_CONST_SIZE)
		{
			return LUCS_TABLE_STATUS_ERROR;
		}
		tables->lucs_const_table[tables->lucs_const_table_index].value.val_number_double = num;
		tables->lucs_const_table[tables->lucs_const_table_index++].type = LUCS_CONST_NUMBER;
		return (tables->lucs_const_table_index - 1);
	}
	else if(type == LUCS_CONST_STRING)
	{
		for(iter=0; iter<tables->lucs_const_table_index; iter++)
		{
			if(tables->lucs_const_table[iter].type == LUCS_CONST_STRING)
			{
				memcpy(rec_const_str, tables->lucs_const_table[iter].value.val_str.val_string, tables->lucs_const_table[iter].value.val_str.len);
				rec_const_str[tables->lucs_const_table[iter].value.val_str.len]=0;
				if(strcmp(const_str, rec_const_str) == 0)
					return iter;
			}
		}
		if(tables->lucs_const_table_index == LUCS_TABLE_CONST_SIZE)
		{
			return LUCS_TABLE_STATUS_ERROR;
		}
		tables->lucs_const_table[tables->lucs_const_table_index].value.val_str.val_string = constant_value;
		tables->lucs_const_table[tables->lucs_const_table_index].value.val_str.len = len;
		tables->lucs_const_table[tables->lucs_const_table_index++].type = LUCS_CONST_STRING;
		return (tables->lucs_const_table_index - 1);
	}

	return LUCS_TABLE_STATUS_ERROR;
}

lucs_i4_t lucs_function_table_add(lucs_tables_t	*tables, lucs_cstring_t func_name, lucs_ui4_t token_index, lucs_bool_t is_definition)
{
	lucs_ui4_t iter;
	for(iter=0; iter<tables->lucs_function_table_index; iter++)
	{
		if(strcmp(tables->lucs_function_table[iter].identifier_text, func_name) == 0)
		{
			if(is_definition)
			{
				if(tables->lucs_function_table[iter].lucs_token_start != LUCS_TABLE_FUNC_START_NOT_SET)
					return LUCS_TABLE_STATUS_ERROR_REDEFINITION;
				tables->lucs_function_table[iter].lucs_token_start = token_index;
			}
			return iter;
		}
	}
	if(tables->lucs_function_table_index == LUCS_TABLE_FUNC_SIZE)
	{
		return LUCS_TABLE_STATUS_ERROR;
	}
	if(is_definition)
	{
		tables->lucs_function_table[tables->lucs_function_table_index].lucs_token_start = token_index;
	}
	strcpy(tables->lucs_function_table[tables->lucs_function_table_index++].identifier_text, func_name);
	return (tables->lucs_function_table_index-1);
}

lucs_i4_t lucs_variable_table_add(lucs_tables_t	*tables, lucs_cstring_t var_name, lucs_ui4_t level, lucs_ui4_t block_num)
{
	lucs_ui4_t iter;
	lucs_size_t str_len = strlen(var_name);
	for(iter=0; iter<tables->lucs_variable_table_index; iter++)
	{
		if(strcmp(tables->lucs_variable_table[iter].identifier_text, var_name) == 0 &&
				tables->lucs_variable_table[iter].level == level &&
				tables->lucs_variable_table[iter].block_num == block_num)
		{
			return iter;
		}
	}
	tables->lucs_variable_table[tables->lucs_variable_table_index].level = level;
	tables->lucs_variable_table[iter].block_num = block_num;
	memcpy(tables->lucs_variable_table[tables->lucs_variable_table_index++].identifier_text, var_name, str_len < LUCS_MAX_IDENTIFIER_LEGTH ? str_len : LUCS_MAX_IDENTIFIER_LEGTH);
	return (tables->lucs_variable_table_index-1);
}
