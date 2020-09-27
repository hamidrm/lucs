/*
 * lucs.h
 *
 *  Created on: Sep 5, 2020
 *      Author: hamid
 */

#ifndef LUCS_H_
#define LUCS_H_

#define		LUCS_TOK_TYPE				uint16_t
#define		LUCS_TABLE_IDX_TYPE		uint16_t
#define		LUCS_TABLE_VAR_SIZE	32
#define		LUCS_TABLE_FUNC_SIZE	32
#define		LUCS_TABLE_CONST_SIZE	32
#define		LUCS_TABLE_JSON_SIZE	32

#define		LUCS_UNDEFINED_TOKEN LUCS_TOKEN_LAST
#define		LUCS_IS_LOWER(x)	((x <= 'z') && (x >= 'a'))
#define		LUCS_IS_UPPER(x)	((x <= 'Z') && (x >= 'A'))
#define		LUCS_IS_LETTER(x) (LUCS_IS_LOWER(x) || LUCS_IS_UPPER(x))
#define		LUCS_IS_DIGIT(x)	   ((x <= '9') && (x >= '0'))

#define	MEMCPY(dst, src, size) memcpy(dst, src, size)
#define MEMCPY4(dst, src) *((uint32_t *)(dst)) = *((uint32_t *)(src))
#define MEMCPY2(dst, src) *((uint16_t *)(dst)) = *((uint16_t *)(src))
#define MEMCPY1(dst, src) *((uint8_t *)(dst)) = *((uint8_t *)(src))

#define	LUCS_MAX_IDENTIFIER_LEGTH 128

#define LUCS_TOKEN_BLANK1_STR ' '
#define LUCS_TOKEN_BLANK2_STR '\t'
#define LUCS_TOKEN_CR_STR '\r'
#define LUCS_TOKEN_LF_STR '\n'
#define LUCS_TOKEN_PAREN_OPEN_STR '('
#define LUCS_TOKEN_PAREN_CLOSE_STR ')'
#define LUCS_TOKEN_BRACES_OPEN_STR '{'
#define LUCS_TOKEN_BRACES_CLOSE_STR '}'
#define LUCS_TOKEN_DOT_STR '.'
#define LUCS_TOKEN_SEMICOLON_STR ';'
#define LUCS_TOKEN_COLON_STR ':'
#define LUCS_TOKEN_SEPR_STR ','
#define LUCS_TOKEN_QUOTATION_STR '\''
#define LUCS_TOKEN_DQUOTATION_STR '\"'

#define LUCS_TOKEN_OP_INC_STR "++"
#define LUCS_TOKEN_OP_DEC_STR "--"
#define LUCS_TOKEN_OP_ASSIGN_STR '='
#define LUCS_TOKEN_OP_PLUS_STR '+'
#define LUCS_TOKEN_OP_MINUS_STR '-'
#define LUCS_TOKEN_OP_MUL_STR '*'
#define LUCS_TOKEN_OP_DIV_STR '/'
#define LUCS_TOKEN_OP_POW_STR '^'
#define LUCS_TOKEN_OP_NOT_STR '!'
#define LUCS_TOKEN_OP_NEG_STR '~'
#define LUCS_TOKEN_OP_RSHIFT_STR ">>"
#define LUCS_TOKEN_OP_LSHIFT_STR "<<"
#define LUCS_TOKEN_OP_AND_STR '&'
#define LUCS_TOKEN_OP_OR_STR '|'
#define LUCS_TOKEN_OP_XOR_STR '#'

#define LUCS_TOKEN_OP_PLUS_ASSIGN_STR "+="
#define LUCS_TOKEN_OP_MINUS_ASSIGN_STR "-="
#define LUCS_TOKEN_OP_MUL_ASSIGN_STR "*="
#define LUCS_TOKEN_OP_DIV_ASSIGN_STR "/="
#define LUCS_TOKEN_OP_POW_ASSIGN_STR "^="
#define LUCS_TOKEN_OP_NEG_ASSIGN_STR "~="
#define LUCS_TOKEN_OP_RSHIFT_ASSIGN_STR ">>="
#define LUCS_TOKEN_OP_LSHIFT_ASSIGN_STR "<<="
#define LUCS_TOKEN_OP_AND_ASSIGN_STR "&="
#define LUCS_TOKEN_OP_OR_ASSIGN_STR "|="
#define LUCS_TOKEN_OP_XOR_ASSIGN_STR "#="

#define LUCS_TOKEN_COP_EQU_STR "=="
#define LUCS_TOKEN_COP_NEQU_STR "!="
#define LUCS_TOKEN_COP_LESS_STR '<'
#define LUCS_TOKEN_COP_GREA_STR '>'
#define LUCS_TOKEN_COP_LESSEQ_STR ">="
#define LUCS_TOKEN_COP_GREAEQ_STR "<="
#define LUCS_TOKEN_COP_AND_STR "&&"
#define LUCS_TOKEN_COP_OR_STR "||"
#define LUCS_TOKEN_COP_XOR_STR "##"

#define LUCS_TOKEN_VAR_STR "var"
#define LUCS_TOKEN_LIV_STR "liv"
#define LUCS_TOKEN_IF_STR "if"
#define LUCS_TOKEN_FOR_STR "for"
#define LUCS_TOKEN_NEW_STR "new"
#define LUCS_TOKEN_WHILE_STR "while"
#define LUCS_TOKEN_SWITCH_STR "switch"
#define LUCS_TOKEN_BREAK_STR "break"
#define LUCS_TOKEN_CONTINUE_STR "continue"
#define LUCS_TOKEN_FOREACH_STR "foreach"
#define LUCS_TOKEN_WHERE_STR "where"
#define LUCS_TOKEN_FUNCTION_STR "function"
#define LUCS_TOKEN_CLASS_STR "class"
#define LUCS_TOKEN_RETURN_STR "return"
#define LUCS_TOKEN_RUN_STR "run"
#define LUCS_TOKEN_UNDEFINED_STR "undefined"
#define LUCS_TOKEN_TYPEOF_STR "typeof"
#define LUCS_TOKEN_NAN_STR "NaN"
#define LUCS_TOKEN_INF_STR "INF"
#define LUCS_TOKEN_NULL_STR "null"


#define LUCS_TOKEN_BLANK1_DBG_STR " "
#define LUCS_TOKEN_BLANK2_DBG_STR "\t"
#define LUCS_TOKEN_CR_DBG_STR "\r"
#define LUCS_TOKEN_LF_DBG_STR "\n"
#define LUCS_TOKEN_PAREN_OPEN_DBG_STR "("
#define LUCS_TOKEN_PAREN_CLOSE_DBG_STR ")"
#define LUCS_TOKEN_BRACES_OPEN_DBG_STR "{"
#define LUCS_TOKEN_BRACES_CLOSE_DBG_STR "}"
#define LUCS_TOKEN_DOT_DBG_STR "."
#define LUCS_TOKEN_SEMICOLON_DBG_STR ";"
#define LUCS_TOKEN_COLON_DBG_STR ":"
#define LUCS_TOKEN_SEPR_DBG_STR ","
#define LUCS_TOKEN_QUOTATION_DBG_STR "'"
#define LUCS_TOKEN_DQUOTATION_DBG_STR "\""

#define LUCS_TOKEN_OP_INC_DBG_STR "++"
#define LUCS_TOKEN_OP_DEC_DBG_STR "--"
#define LUCS_TOKEN_OP_ASSIGN_DBG_STR "="
#define LUCS_TOKEN_OP_PLUS_DBG_STR "+"
#define LUCS_TOKEN_OP_MINUS_DBG_STR "-"
#define LUCS_TOKEN_OP_MUL_DBG_STR "*"
#define LUCS_TOKEN_OP_DIV_DBG_STR "/"
#define LUCS_TOKEN_OP_POW_DBG_STR "^"
#define LUCS_TOKEN_OP_NOT_DBG_STR "!"
#define LUCS_TOKEN_OP_NEG_DBG_STR "~"
#define LUCS_TOKEN_OP_RSHIFT_DBG_STR ">>"
#define LUCS_TOKEN_OP_LSHIFT_DBG_STR "<<"
#define LUCS_TOKEN_OP_AND_DBG_STR "&"
#define LUCS_TOKEN_OP_OR_DBG_STR "|"
#define LUCS_TOKEN_OP_XOR_DBG_STR "#"

#define LUCS_TOKEN_OP_PLUS_ASSIGN_DBG_STR "+="
#define LUCS_TOKEN_OP_MINUS_ASSIGN_DBG_STR "-="
#define LUCS_TOKEN_OP_MUL_ASSIGN_DBG_STR "*="
#define LUCS_TOKEN_OP_DIV_ASSIGN_DBG_STR "/="
#define LUCS_TOKEN_OP_POW_ASSIGN_DBG_STR "^="
#define LUCS_TOKEN_OP_NEG_ASSIGN_DBG_STR "~="
#define LUCS_TOKEN_OP_RSHIFT_ASSIGN_DBG_STR ">>="
#define LUCS_TOKEN_OP_LSHIFT_ASSIGN_DBG_STR "<<="
#define LUCS_TOKEN_OP_AND_ASSIGN_DBG_STR "&="
#define LUCS_TOKEN_OP_OR_ASSIGN_DBG_STR "|="
#define LUCS_TOKEN_OP_XOR_ASSIGN_DBG_STR "#="

#define LUCS_TOKEN_COP_EQU_DBG_STR "=="
#define LUCS_TOKEN_COP_NEQU_DBG_STR "!="
#define LUCS_TOKEN_COP_LESS_DBG_STR "<"
#define LUCS_TOKEN_COP_GREA_DBG_STR ">"
#define LUCS_TOKEN_COP_LESSEQ_DBG_STR ">="
#define LUCS_TOKEN_COP_GREAEQ_DBG_STR "<="
#define LUCS_TOKEN_COP_AND_DBG_STR "&&"
#define LUCS_TOKEN_COP_OR_DBG_STR "||"
#define LUCS_TOKEN_COP_XOR_DBG_STR "##"

#define LUCS_TOKEN_VAR_DBG_STR "VAR"
#define LUCS_TOKEN_LIV_DBG_STR "LIV"
#define LUCS_TOKEN_IF_DBG_STR "IF"
#define LUCS_TOKEN_FOR_DBG_STR "FOR"
#define LUCS_TOKEN_NEW_DBG_STR "NEW"
#define LUCS_TOKEN_WHILE_DBG_STR "WHILE"
#define LUCS_TOKEN_SWITCH_DBG_STR "SWITCH"
#define LUCS_TOKEN_BREAK_DBG_STR "BREAK"
#define LUCS_TOKEN_CONTINUE_DBG_STR "CONTINUE"
#define LUCS_TOKEN_FOREACH_DBG_STR "FOREACH"
#define LUCS_TOKEN_WHERE_DBG_STR "WHERE"
#define LUCS_TOKEN_FUNCTION_DBG_STR "FUNCTION"
#define LUCS_TOKEN_CLASS_DBG_STR "CLASS"
#define LUCS_TOKEN_RETURN_DBG_STR "RETURN"
#define LUCS_TOKEN_RUN_DBG_STR "RUN"
#define LUCS_TOKEN_UNDEFINED_DBG_STR "UNDEFINED"
#define LUCS_TOKEN_TYPEOF_DBG_STR "TYPEOF"
#define LUCS_TOKEN_NAN_DBG_STR "NAN"
#define LUCS_TOKEN_INF_DBG_STR "INF"
#define LUCS_TOKEN_NULL_DBG_STR "NULL"

#define LUCS_KEYWORDS_LIST {{LUCS_TOKEN_VAR, LUCS_TOKEN_VAR_STR},\
{LUCS_TOKEN_LIV, LUCS_TOKEN_LIV_STR},\
{LUCS_TOKEN_IF, LUCS_TOKEN_IF_STR},\
{LUCS_TOKEN_FOR, LUCS_TOKEN_FOR_STR},\
{LUCS_TOKEN_NEW, LUCS_TOKEN_NEW_STR},\
{LUCS_TOKEN_WHILE, LUCS_TOKEN_WHILE_STR},\
{LUCS_TOKEN_SWITCH, LUCS_TOKEN_SWITCH_STR},\
{LUCS_TOKEN_BREAK, LUCS_TOKEN_BREAK_STR},\
{LUCS_TOKEN_CONTINUE, LUCS_TOKEN_CONTINUE_STR},\
{LUCS_TOKEN_FOREACH, LUCS_TOKEN_FOREACH_STR},\
{LUCS_TOKEN_WHERE, LUCS_TOKEN_WHERE_STR},\
{LUCS_TOKEN_FUNCTION, LUCS_TOKEN_FUNCTION_STR},\
{LUCS_TOKEN_CLASS, LUCS_TOKEN_CLASS_STR},\
{LUCS_TOKEN_RETURN, LUCS_TOKEN_RETURN_STR},\
{LUCS_TOKEN_RUN, LUCS_TOKEN_RUN_STR},\
{LUCS_TOKEN_UNDEFINED, LUCS_TOKEN_UNDEFINED_STR},\
{LUCS_TOKEN_TYPEOF, LUCS_TOKEN_TYPEOF_STR},\
{LUCS_TOKEN_NAN, LUCS_TOKEN_NAN_STR},\
{LUCS_TOKEN_INF, LUCS_TOKEN_INF_STR},\
{LUCS_TOKEN_INF, LUCS_TOKEN_INF_STR},\
LUCS_LAST_KEYWORD_TOKEN}

#define LUCS_LAST_KEYWORD_TOKEN {LUCS_UNDEFINED_TOKEN, NULL}

typedef struct lucs_json_t  lucs_json_var_t;
typedef LUCS_TOK_TYPE lucs_tok_t;
typedef LUCS_TABLE_IDX_TYPE lucs_tidx_t;

typedef enum {
	/* General Tokens */
	LUCS_TOKEN_BLANK1,
	LUCS_TOKEN_BLANK2,
	LUCS_TOKEN_CR,
	LUCS_TOKEN_LF,
	LUCS_TOKEN_PAREN_OPEN,
	LUCS_TOKEN_PAREN_CLOSE,
	LUCS_TOKEN_BRACES_OPEN,
	LUCS_TOKEN_BRACES_CLOSE,
	LUCS_TOKEN_DOT,
	LUCS_TOKEN_SEMICOLON,
	LUCS_TOKEN_COLON,
	LUCS_TOKEN_SEPR,

	/* General Operator Tokens */
	LUCS_TOKEN_OP_INC,
	LUCS_TOKEN_OP_DEC,

	/* Other Operator Tokens */
	LUCS_TOKEN_OP_ASSIGN,
	LUCS_TOKEN_OP_PLUS,
	LUCS_TOKEN_OP_MINUS,
	LUCS_TOKEN_OP_MUL,
	LUCS_TOKEN_OP_DIV,
	LUCS_TOKEN_OP_POW,
	LUCS_TOKEN_OP_NOT,
	LUCS_TOKEN_OP_NEG,
	LUCS_TOKEN_OP_RSHIFT,
	LUCS_TOKEN_OP_LSHIFT,
	LUCS_TOKEN_OP_AND,
	LUCS_TOKEN_OP_OR,
	LUCS_TOKEN_OP_XOR,

	/* Concurrent Assign and Operator Tokens */
	LUCS_TOKEN_OP_PLUS_ASSIGN,
	LUCS_TOKEN_OP_MINUS_ASSIGN,
	LUCS_TOKEN_OP_MUL_ASSIGN,
	LUCS_TOKEN_OP_DIV_ASSIGN,
	LUCS_TOKEN_OP_POW_ASSIGN,
	LUCS_TOKEN_OP_NEG_ASSIGN,
	LUCS_TOKEN_OP_RSHIFT_ASSIGN,
	LUCS_TOKEN_OP_LSHIFT_ASSIGN,
	LUCS_TOKEN_OP_AND_ASSIGN,
	LUCS_TOKEN_OP_OR_ASSIGN,
	LUCS_TOKEN_OP_XOR_ASSIGN,

	/* Conditional Operator Tokens */
	LUCS_TOKEN_COP_EQU,
	LUCS_TOKEN_COP_NEQU,
	LUCS_TOKEN_COP_LESS,
	LUCS_TOKEN_COP_GREA,
	LUCS_TOKEN_COP_LESSEQ,
	LUCS_TOKEN_COP_GREAEQ,
	LUCS_TOKEN_COP_AND,
	LUCS_TOKEN_COP_OR,
	LUCS_TOKEN_COP_XOR,

	/* Keyword Tokens */
	LUCS_TOKEN_VAR,
	LUCS_TOKEN_LIV,
	LUCS_TOKEN_IF,
	LUCS_TOKEN_FOR,
	LUCS_TOKEN_NEW,
	LUCS_TOKEN_WHILE,
	LUCS_TOKEN_SWITCH,
	LUCS_TOKEN_BREAK,
	LUCS_TOKEN_CONTINUE,
	LUCS_TOKEN_FOREACH,
	LUCS_TOKEN_WHERE,
	LUCS_TOKEN_FUNCTION,
	LUCS_TOKEN_CLASS,
	LUCS_TOKEN_RETURN,
	LUCS_TOKEN_RUN,
	LUCS_TOKEN_UNDEFINED,
	LUCS_TOKEN_TYPEOF,
	LUCS_TOKEN_NAN,
	LUCS_TOKEN_INF,
	LUCS_TOKEN_NULL,

	/* Other Tokens */
	LUCS_TOKEN_IDENTIFIER,
	LUCS_TOKEN_ID_CONST,
	LUCS_TOKEN_ID_VARIABLE,
	LUCS_TOKEN_ID_FUNCTION,


	/* Last Token */
	LUCS_TOKEN_LAST,
}lucs_tokens_t;

typedef enum {
	LUCS_TOKENIZER_STATE_CODE,
	LUCS_TOKENIZER_STATE_COMMENT1,
	LUCS_TOKENIZER_STATE_COMMENT2,
	LUCS_TOKENIZER_STATE_STRING1,
	LUCS_TOKENIZER_STATE_STRING2,
}lucs_tokenizer_state_t;

typedef enum {
	LUCS_VAR_TYPE_STRING,
	LUCS_VAR_TYPE_FLOAT,
	LUCS_VAR_TYPE_INTEGER,
	LUCS_VAR_TYPE_JSON,
}lucs_var_t;

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
	uint16_t		identifier_started;
	uint16_t  	prev_token;
	uint32_t		index;
	uint32_t			length;
	char identifier_text[LUCS_MAX_IDENTIFIER_LEGTH];
}lucs_identifier_t;

typedef struct
{
	lucs_tok_t  	token;
	lucs_tidx_t	table_index;
}lucs_id_token_t;

typedef struct
{
	uint32_t  	keyword_token;
	const char *keyword_str;
}lucs_keywords_token_t;

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
	void *ptr;
	size_t elem_size;
	size_t index;
	size_t length;
}lucs_stack_t;

typedef struct
{
	const char *script;
	uint32_t		length;
	uint32_t		offset;
	void	*stack;
	uint32_t		stack_size;
	uint32_t		stack_pointer;

} lucs_ctx_t;

#endif /* LUCS_H_ */