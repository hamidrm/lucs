/*
 * stack.c
 *
 *  Created on: Oct 6, 2020
 *      Author: hamid
 */
#include "include/lucs.h"
#include "include/stack.h"

static void lucs_stack_init(lucs_stack_t *stack_params)
{
	stack_params->index = 0;
}
static void lucs_stack_push(lucs_stack_t *stack, void *data_ptr)
{
	if((stack->index + stack->elem_size) <= stack->length)
	{
		switch(stack->elem_size )
		{
		case sizeof(uint32_t):
			MEMCPY4(&((uint8_t *)stack->ptr)[stack->index], data_ptr);
		break;
		case sizeof(uint16_t):
			MEMCPY2(&((uint8_t *)stack->ptr)[stack->index], data_ptr);
		break;
		case sizeof(uint8_t):
			MEMCPY1(&((uint8_t *)stack->ptr)[stack->index], data_ptr);
		break;
		default:
			MEMCPY(&((uint8_t *)stack->ptr)[stack->index], data_ptr, stack->elem_size);
		}
		stack->index += stack->elem_size;
	}// TODO-else raise an overflow error

}
static void *lucs_stack_pop(lucs_stack_t *stack)
{
	if((stack->index - stack->elem_size) >= 0)
	{
		void *res = &(((uint8_t *)stack->ptr)[stack->index]);
		stack->index -= stack->elem_size;
		return res;
	}// TODO-else raise an underflow error
	return 0;
}

