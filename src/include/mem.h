/*
 * mem.h
 *
 *  Created on: Sep 26, 2020
 *      Author: hamid
 */

#ifndef SRC_INCLUDE_MEM_H_
#define SRC_INCLUDE_MEM_H_

#define	MEM_CALC_BUFF_SIZE(block_size, block_cnt)	((block_size * block_cnt) + sizeof(mem_slot_t) * block_cnt)
#define	MEM_TABLE_REC_UNUSED_ID		0
#define	MEM_CALC_BLOCKS(block_size, s)	((s - 1) / block_size + 1)
#define	MEM_CALC_ACTUAL_SIZE(block_size, s)	(((s - 1) / block_size + 1) * block_size)
#define	MEM_GET_SLOT_ID(x)		((x->slot_id[2] << 16) | (x->slot_id[1] << 8) | (x->slot_id[0]))
#define	MEM_SET_SLOT_ID(x, id)		(x)->slot_id[0] = (id) & 0x000000FF;\
	(x)->slot_id[1] = (((id) & 0x0000FF00) >> 8);\
	(x)->slot_id[2] = (((id) & 0x00FF0000) >> 16)
#define	MEM_IS_FREE_SLOT(x)	(*(uint32_t *)x == 0)
#define	MEM_ERROR		(~0)
#define	MEM_MAX_SLOT_ID	0x01000000
#define	MEM_MAX_READY_NEXT_SLOTS	16
#define	MEM_UNASSIGNED	(~0)
typedef struct
{
	uint8_t		slot_id[3];
	uint8_t		count;
}mem_slot_t;

typedef struct
{
	size_t	slot_id;
	size_t	blocks_num;
	size_t	blocks_length;
	void		*heaps_start_ptr;
	mem_slot_t		*heaps_table_ptr;
	size_t	free_slots_num;
	size_t next_free_slots[MEM_MAX_READY_NEXT_SLOTS];
}mem_ctx_t;

#endif /* SRC_INCLUDE_MEM_H_ */
