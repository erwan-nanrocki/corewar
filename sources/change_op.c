/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:57:04 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/13 01:41:10 by enanrock         ###   ########.fr       */
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
		i = REG_SIZE;
		if (convert_pc_to_uint(read_head->program_counter) + 1 == MEM_SIZE)
			while (i > 0)
				read_head->program_counter[--i] = 0x00;
		else
			while (i > 0)
				if (read_head->program_counter[--i]++ != 0xff)
					i = 0;
		k++;
	}
	read_head->opcode =
		mem->memory_space[convert_pc_to_uint(read_head->program_counter)];
	i = 0;
	while ((i < 16) && (op_tab[i].opcode != read_head->opcode))
		i++;
	if (i < 17)
		read_head->cycle_countdown = op_tab[i].cycle_duration;
	else
		read_head->cycle_countdown = 1;
}
