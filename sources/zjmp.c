/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 13:35:20 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/04 17:51:14 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zjmp.h"

static unsigned int		new_pc(t_mem *mem, unsigned int pc)
{
	int				t;
	unsigned int	i;

	t = 0;
	i = 0;
	while (i < IND_SIZE)
	{
		t = t * 0x100 + mem->memory_space[(pc + 1 + i) % MEM_SIZE];
		i++;
	}
	if (t >= (0x80 * ft_a_power_b(0x100, IND_SIZE - 1)))
		t -= ft_a_power_b(0x100, IND_SIZE);
	t %= IDX_MOD;
	return ((pc + t) % MEM_SIZE);
}

int						zjmp(void *p1, void *p2)
{
	t_local_memory	*read_head;
	t_mem			*mem;
	unsigned int	pc;
	unsigned int	i;

	read_head = p1;
	mem = p2;
	pc = convert_pc_to_uint(read_head->program_counter);
	if (read_head->carry == 0)
	{
		pc = (new_pc(mem, pc) - 1) % MEM_SIZE;
		i = 0;
		while (i < REG_SIZE)
		{
			read_head->program_counter[i] =
				(pc / ft_a_power_b(0x100, REG_SIZE - 1 - i)) % 0x100;
			i++;
		}
		return (0 + 1);
	}
	else
		return (1 + IND_SIZE);
}
