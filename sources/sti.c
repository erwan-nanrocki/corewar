/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:26:42 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/12 23:09:54 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sti.h"

void	sti(void *p1, void *p2, unsigned int arg[MAX_ARGS_NUMBER][5])
{
	t_local_memory	*read_head;
	t_mem			*mem;
	unsigned int	pc;
	unsigned int	i;

	read_head = p1;
	mem = p2;
	i = 0;
	pc = convert_pc_to_uint(read_head->program_counter);
	while (i < REG_SIZE)
	{
		mem->memory_space[(pc + arg[1][1] + arg[2][1] + i) % MEM_SIZE] =
			read_head->registers[arg[0][0]][i];
		i++;
	}
	read_head->carry = convert_pc_to_uint(read_head->registers[arg[1][0]]);
}
