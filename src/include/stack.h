/*
 * stack.h
 *
 *  Created on: Oct 6, 2020
 *      Author: hamid
 */

#ifndef SRC_INCLUDE_STACK_H_
#define SRC_INCLUDE_STACK_H_

#define	MEMCPY(dst, src, size) memcpy(dst, src, size)
#define MEMCPY4(dst, src) *((uint32_t *)(dst)) = *((uint32_t *)(src))
#define MEMCPY2(dst, src) *((uint16_t *)(dst)) = *((uint16_t *)(src))
#define MEMCPY1(dst, src) *((uint8_t *)(dst)) = *((uint8_t *)(src))

typedef struct
{
	void *ptr;
	size_t elem_size;
	size_t index;
	size_t length;
}lucs_stack_t;

#endif /* SRC_INCLUDE_STACK_H_ */
