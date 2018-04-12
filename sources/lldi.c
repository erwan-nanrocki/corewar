/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:26:42 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/12 23:06:49 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lldi.h"

void	lldi(void *p1, void *p2, unsigned int arg[MAX_ARGS_NUMBER][5])
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
		read_head->registers[arg[2][0]][i] =
			mem->memory_space[(pc + arg[0][3] + arg[1][3] + i) % MEM_SIZE];
		i++;
	}
	read_head->carry = convert_pc_to_uint(read_head->registers[arg[1][0]]);
}
