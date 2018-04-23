/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:57:04 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/18 06:37:23 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "change_op.h"

void			change_op(t_local_memory *read_head,
		t_mem *mem, unsigned int skip)
{
	unsigned int	i;
	unsigned int	k;

	k = 0;
	while (k < skip)
	{
		if (convert_pc_to_uint(read_head->program_counter) + 1 == MEM_SIZE)
		{
			i = REG_SIZE;
			while (i > 0)
				read_head->program_counter[--i] = 0x00;
		}
		else
		{
			i = REG_SIZE;
			while (i > 0)
				if (read_head->program_counter[--i]++ != 0xff)
					i = 0;
		}
		k++;
	}
	read_head->opcode = mem->memory_space
		[convert_pc_to_uint(read_head->program_counter) % MEM_SIZE];
	read_head->cycle_countdown =
		mem->op_tab[read_head->opcode].data.cycle_duration;
}
