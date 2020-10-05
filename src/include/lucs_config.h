/*
 * lucs_config.h
 *
 *  Created on: Oct 6, 2020
 *      Author: hamid
 */

#ifndef SRC_INCLUDE_LUCS_CONFIG_H_
#define SRC_INCLUDE_LUCS_CONFIG_H_

#ifndef LUCS_TOK_TYPE
#define		LUCS_TOK_TYPE				uint16_t
#endif

#ifndef LUCS_TABLE_IDX_TYPE
#define		LUCS_TABLE_IDX_TYPE		uint16_t
#endif

#ifndef LUCS_TABLE_VAR_SIZE
#define		LUCS_TABLE_VAR_SIZE	32
#endif

#ifndef LUCS_TABLE_FUNC_SIZE
#define		LUCS_TABLE_FUNC_SIZE	32
#endif

#ifndef LUCS_TABLE_CONST_SIZE
#define		LUCS_TABLE_CONST_SIZE	32
#endif

#ifndef LUCS_TABLE_JSON_SIZE
#define		LUCS_TABLE_JSON_SIZE	32
#endif

#ifndef LUCS_MAX_IDENTIFIER_LEGTH
#define	LUCS_MAX_IDENTIFIER_LEGTH 128
#endif

#ifndef	LUCS_DBG_PRINTF
#define	LUCS_DBG_PRINTF	printf
#endif

#ifndef	LUCS_DBG_MODE
#define	LUCS_DBG_MODE	0
#endif

#endif /* SRC_INCLUDE_LUCS_CONFIG_H_ */
