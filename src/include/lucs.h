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

typedef struct
{
	lucs_cstring_t	script;
	lucs_ui4_t		length;
	lucs_ui4_t		offset;
	lucs_ptr_t	 	stack;
	lucs_ui4_t		stack_size;
	lucs_ui4_t		stack_pointer;
} lucs_ctx_t;

#endif /* LUCS_H_ */
