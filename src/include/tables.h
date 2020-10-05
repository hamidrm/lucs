/*
 * tables.h
 *
 *  Created on: Oct 6, 2020
 *      Author: hamid
 */

#ifndef SRC_INCLUDE_TABLES_H_
#define SRC_INCLUDE_TABLES_H_

typedef struct lucs_json_t  lucs_json_var_t;


typedef enum {
	LUCS_VAR_TYPE_STRING,
	LUCS_VAR_TYPE_FLOAT,
	LUCS_VAR_TYPE_INTEGER,
	LUCS_VAR_TYPE_JSON,
}lucs_var_t;

typedef enum {
	LUCS_CONST_STRING,
	LUCS_CONST_NUMBER,
}lucs_const_t;

typedef enum {
	LUCS_FUNC_LUCS_SCRIPT,
	LUCS_FUNC_C_LANG,
}lucs_func_t;

typedef enum {
	LUCS_VAR_FLAG_ARRAY = (1<<0),
	LUCS_VAR_FLAG_CONST = (1<<1),
	LUCS_VAR_FLAG_JSON = (1<<2),
	LUCS_VAR_FLAG_LIV = (1<<3),
}lucs_var_flags_t;


typedef struct
{
	uint8_t	flags;
	lucs_var_t	type;
	char identifier_text[LUCS_MAX_IDENTIFIER_LEGTH];
	union
	{
		const char * val_string;
		int32_t		 val_integer;
		float	val_float;
//		lucs_json_var_t lucs_json;
	}value;
}lucs_variable_rec_t;

typedef struct
{
	lucs_const_t	type;
	union
	{
		double	val_number_double;
		long	val_number_integer;
		const char *val_string;
	}value;
}lucs_constant_rec_t;

typedef struct
{
	lucs_func_t	type;
	char identifier_text[LUCS_MAX_IDENTIFIER_LEGTH];
	union
	{
		uint32_t c_func_ptr;
		uint32_t lucs_token;
	}start_address;
	union
	{
		uint32_t c_func_ptr;
		uint32_t lucs_token;
	}end_address;
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
	lucs_tok_t  	token;
	lucs_tidx_t	table_index;
}lucs_id_token_t;
#endif /* SRC_INCLUDE_TABLES_H_ */
