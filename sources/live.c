/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 01:23:44 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/01 13:43:50 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "live.h"

static void		live_a_champ(t_mem *mem, unsigned int pc, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while ((j < DIR_SIZE) &&
			(mem->memory_space[(pc + 1 + j) % MEM_SIZE] == mem->champ[i].id[j]))
		j++;
	if (j == DIR_SIZE)
		mem->champ[i].last_live = mem->cycles + 1;
}

int				live(void *p1, void *p2)
{
	unsigned int	i;
	unsigned int	pc;
	t_local_memory	*read_head;
	t_mem			*mem;

	read_head = p1;
	mem = p2;
	pc = convert_pc_to_uint(read_head->program_counter);
	i = 0;
	while (i < MAX_PLAYERS)
	{
		live_a_champ(mem, pc, i);
		i++;
	}
	(mem->current_nbr_live)++;
	return (1 + DIR_SIZE);
}
