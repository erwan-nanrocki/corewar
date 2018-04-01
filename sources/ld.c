/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:26:42 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/01 13:52:13 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ld.h"

static int	ld_dr(t_local_memory *read_head, t_mem *mem,
		unsigned int pc, unsigned int r)
{
	unsigned int	i;

	i = 0;
	while (i < DIR_SIZE)
	{
		read_head->registers[r][i] = mem->memory_space[(pc + 2 + i) % MEM_SIZE];
		i++;
	}
	read_head->carry = convert_pc_to_uint(read_head->registers[r]);
	return (1 + 1 + DIR_SIZE + 1);
}

static int	ld_ir(t_local_memory *read_head, t_mem *mem,
		unsigned int r, unsigned int pc)
{
	unsigned int	i;
	int				t;

	t = 0;
	i = 0;
	while (i < IND_SIZE)
	{
		t = t * 0x100 + mem->memory_space[(pc + 2 + i) % MEM_SIZE];
		i++;
	}
	if (t >= (0x80 * ft_a_power_b(0x100, IND_SIZE - 1)))
		t -= ft_a_power_b(0x100, IND_SIZE);
	t %= IDX_MOD;
	i = 0;
	while (i < REG_SIZE)
	{
		read_head->registers[r][i] = mem->memory_space[(pc + t + i) % MEM_SIZE];
		i++;
	}
	read_head->carry = convert_pc_to_uint(read_head->registers[r]);
	return (1 + 1 + IND_SIZE + 1);
}

int			ld(void *p1, void *p2)
{
	t_local_memory	*read_head;
	t_mem			*mem;
	unsigned int	pc;

	read_head = p1;
	mem = p2;
	pc = convert_pc_to_uint(read_head->program_counter);
	if ((mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_DR) &&
			(mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_IR))
		return (1 + 1);
	if ((mem->memory_space[(pc + 1) % MEM_SIZE] == ACB_DR) &&
		((mem->memory_space[(pc + 1 + DIR_SIZE + 1) % MEM_SIZE] == 0) ||
		(mem->memory_space[(pc + 1 + DIR_SIZE + 1) % MEM_SIZE] > REG_NUMBER)))
		return (1 + 1 + DIR_SIZE + 1);
	if ((mem->memory_space[(pc + 1) % MEM_SIZE] == ACB_IR) &&
		((mem->memory_space[(pc + 1 + IND_SIZE + 1) % MEM_SIZE] == 0) ||
		(mem->memory_space[(pc + 1 + IND_SIZE + 1) % MEM_SIZE] > REG_NUMBER)))
		return (1 + 1 + IND_SIZE + 1);
	if (mem->memory_space[(pc + 1) % MEM_SIZE] == ACB_DR)
		return (ld_dr(read_head, mem, pc,
					mem->memory_space[(pc + 1 + DIR_SIZE + 1) % MEM_SIZE] - 1));
	else
		return (ld_ir(read_head, mem, pc,
					mem->memory_space[(pc + 2 + IND_SIZE) % MEM_SIZE] - 1));
}
