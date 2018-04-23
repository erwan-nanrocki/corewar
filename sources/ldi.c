/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:26:42 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/17 04:31:19 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ldi.h"

void	ldi(void *p1, void *p2, unsigned int arg[MAX_ARGS_NUMBER][5])
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
			mem->memory_space[(pc + arg[0][1] + arg[1][1] + i) % MEM_SIZE];
		i++;
	}
}
