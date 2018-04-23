/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 08:25:19 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/16 22:29:20 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "st.h"

static void		st_ri(t_local_memory *read_head, t_mem *mem,
		unsigned int arg[MAX_ARGS_NUMBER][5])
{
	unsigned int	pc;
	unsigned int	i;

	pc = convert_pc_to_uint(read_head->program_counter);
	i = 0;
	while (i < REG_SIZE)
	{
		mem->memory_space[(pc + arg[1][2] + i) % MEM_SIZE] =
			read_head->registers[arg[0][0]][i];
		i++;
	}
}

static void		st_rr(t_local_memory *read_head,
		unsigned int arg[MAX_ARGS_NUMBER][5])
{
	unsigned int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		read_head->registers[arg[1][0]][i] = read_head->registers[arg[0][0]][i];
		i++;
	}
}

void			st(void *p1, void *p2, unsigned int arg[MAX_ARGS_NUMBER][5])
{
	t_local_memory	*read_head;
	t_mem			*mem;

	read_head = p1;
	mem = p2;
	if (arg[1][0] == NOT_REG)
		st_ri(read_head, mem, arg);
	else
		st_rr(read_head, arg);
}
