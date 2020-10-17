/*
 * tables.h
 *
 *  Created on: Oct 6, 2020
 *      Author: hamid
 */

#ifndef SRC_INCLUDE_TABLES_H_
#define SRC_INCLUDE_TABLES_H_

#define	LUCS_TABLE_FUNC_START_NOT_SET	(0)
typedef struct lucs_json_t  lucs_json_var_t;

typedef enum {
	LUCS_TABLE_STATUS_ERROR = (-1),
	LUCS_TABLE_STATUS_ERROR_REDEFINITION = (-2),
}lucs_table_status_t;

typedef enum {
	LUCS_CONST_STRING,
	LUCS_CONST_NUMBER,
	LUCS_CONST_UNDEF,
}lucs_const_t;

typedef enum {
	LUCS_FUNC_LUCS_SCRIPT,
	LUCS_FUNC_C_LANG,
}lucs_func_t;

typedef struct
{
	char identifier_text[LUCS_MAX_IDENTIFIER_LEGTH];
	lucs_ui4_t	level;
	lucs_ui4_t	block_num;
}lucs_variable_rec_t;

typedef struct
{
	lucs_const_t	type;
	union
	{
		double	val_number_double;
		struct
		{
			const char *val_string;
			lucs_size_t len;
		}val_str;
	}value;
}lucs_constant_rec_t;

typedef struct
{
	char identifier_text[LUCS_MAX_IDENTIFIER_LEGTH];
	uint32_t lucs_token_start;
}lucs_function_rec_t;

struct lucs_json_t
{
	uint16_t  	json_table_index;
	union
	{
		lucs_variable_rec_t var_type;
		lucs_variable_rec_t func_type;
	}value;
	lucs_json_var_t *next_param;
};

typedef struct
{
	lucs_function_rec_t lucs_function_table[LUCS_TABLE_FUNC_SIZE];
	lucs_variable_rec_t lucs_variable_table[LUCS_TABLE_VAR_SIZE];
	lucs_constant_rec_t lucs_const_table[LUCS_TABLE_CONST_SIZE];
	//lucs_json_rec_t lucs_json_table[LUCS_TABLE_JSON_SIZE];

	lucs_ui4_t	lucs_function_table_index;
	lucs_ui4_t	lucs_variable_table_index;
	lucs_ui4_t	lucs_const_table_index;
}lucs_tables_t;

//typedef struct
//{
//	lucs_tok_t  	token;
//	lucs_tidx_t	table_index;
//}lucs_id_token_t;





void lucs_tables_init(lucs_tables_t	*tables);
lucs_i4_t lucs_constant_table_add(lucs_tables_t	*tables, lucs_ptr_t constant_value, lucs_size_t len, lucs_const_t type);
lucs_i4_t lucs_function_table_add(lucs_tables_t	*tables, lucs_cstring_t func_name, lucs_ui4_t token_index, lucs_bool_t	is_definition);
lucs_i4_t lucs_variable_table_add(lucs_tables_t	*tables, lucs_cstring_t var_name, lucs_ui4_t level, lucs_ui4_t block_num);
#endif /* SRC_INCLUDE_TABLES_H_ */
