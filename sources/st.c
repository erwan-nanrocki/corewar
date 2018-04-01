/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 08:25:19 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/01 13:05:54 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "st.h"

static int		st_ri(t_local_memory *read_head, t_mem *mem, unsigned int pc)
{
	unsigned int	r;
	unsigned int	i;
	int				t;

	t = 0;
	i = 0;
	while (i < IND_SIZE)
	{
		t = t * 0x100 + mem->memory_space[(pc + 3 + i) % MEM_SIZE];
		i++;
	}
	if (t >= (0x80 * ft_a_power_b(0x100, IND_SIZE - 1)))
		t -= ft_a_power_b(0x100, IND_SIZE);
	t %= IDX_MOD;
	r = mem->memory_space[(pc + 2) % MEM_SIZE] - 1;
	i = 0;
	while (i < REG_SIZE)
	{
		mem->memory_space[(pc + t + i) % MEM_SIZE] = read_head->registers[r][i];
		i++;
	}
	return (1 + 1 + 1 + IND_SIZE);
}

static int		st_rr(t_local_memory *read_head, t_mem *mem, unsigned int pc)
{
	unsigned int	r1;
	unsigned int	r2;
	unsigned int	i;

	r1 = mem->memory_space[(pc + 2) % MEM_SIZE] - 1;
	r2 = mem->memory_space[(pc + 3) % MEM_SIZE] - 1;
	i = 0;
	while (i < REG_SIZE)
	{
		read_head->registers[r2][i] = read_head->registers[r1][i];
		i++;
	}
	return (1 + 1 + 1 + 1);
}

int				st(void *p1, void *p2)
{
	t_local_memory	*read_head;
	t_mem			*mem;
	unsigned int	pc;

	read_head = p1;
	mem = p2;
	pc = convert_pc_to_uint(read_head->program_counter);
	if (mem->memory_space[(pc + 1) % MEM_SIZE] == ACB_RI)
	{
		if ((mem->memory_space[(pc + 2) % MEM_SIZE] == 0) ||
				(mem->memory_space[(pc + 2) % MEM_SIZE] >= REG_SIZE))
			return (1 + 1 + 1 + IND_SIZE);
		else
			return (st_ri(read_head, mem, pc));
	}
	else if (mem->memory_space[(pc + 1) % MEM_SIZE] == ACB_RR)
	{
		if ((mem->memory_space[(pc + 2) % MEM_SIZE] == 0) ||
				(mem->memory_space[(pc + 2) % MEM_SIZE] >= REG_SIZE) ||
				(mem->memory_space[(pc + 3) % MEM_SIZE] == 0) ||
				(mem->memory_space[(pc + 3) % MEM_SIZE] >= REG_SIZE))
			return (1 + 1 + 1 + 1);
		else
			return (st_rr(read_head, mem, pc));
	}
	else
		return (1 + 1);
}
