/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:43:45 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/04 19:21:51 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "and.h"

static unsigned int		get_register_or_direct(t_mem *mem, unsigned int pc,
		unsigned int pc_plus_lag, unsigned int *rx)
{
	unsigned int	i;

	if (((mem->memory_space[(pc + 1) % MEM_SIZE] >> 6) % 4) == REG_CODE)
	{
		if ((mem->memory_space[pc_plus_lag % MEM_SIZE] == 0) ||
				(mem->memory_space[pc_plus_lag % MEM_SIZE] > REG_SIZE))
			rx[2] = 1 + (rx[3])++ + (rx[4])++;
		*rx = mem->memory_space[pc_plus_lag % MEM_SIZE];
		return (1);
	}
	else
	{
		*rx = 0;
		i = 0;
		while (i < DIR_SIZE)
		{
			*rx += mem->memory_space[(pc_plus_lag + i) % MEM_SIZE] *
				ft_a_power_b(0x100, (REG_SIZE - 1) - i);
			i++;
		}
		return (DIR_SIZE);
	}
}

static unsigned int		get_indirect(t_mem *mem, unsigned int pc,
		unsigned pc_plus_lag, unsigned int *rx)
{
	unsigned int	i;
	int				t;

	t = 0;
	i = 0;
	while (i < IND_SIZE)
	{
		t = t * 0x100 + mem->memory_space[(pc_plus_lag + i) % MEM_SIZE];
		i++;
	}
	if (t >= (0x80 * ft_a_power_b(0x100, IND_SIZE - 1)))
		t -= ft_a_power_b(0x100, IND_SIZE);
	t %= IDX_MOD;
	*rx = 0;
	i = 0;
	while (i < DIR_SIZE)
	{
		*rx += mem->memory_space[(pc + t + i) % MEM_SIZE] *
			ft_a_power_b(0x100, (REG_SIZE - 1) - i);
		i++;
	}
	return (IND_SIZE);
}

static int				do_and(t_local_memory *read_head,
		t_mem *mem, unsigned int pc, unsigned int r[3 + 2])
{
	unsigned int	i;
	unsigned int	pc_plus_lag;
	pc_plus_lag = pc + 2;
	if ((((mem->memory_space[(pc + 1) % MEM_SIZE] >> 6) % 4) == REG_CODE) ||
			(((mem->memory_space[(pc + 1) % MEM_SIZE] >> 6) % 4) == DIR_CODE))
		pc_plus_lag += get_register_or_direct(mem, pc, pc_plus_lag, &(r[0]));
	else if (((mem->memory_space[(pc + 1) % MEM_SIZE] >> 6) % 4) == IND_CODE)
		pc_plus_lag += get_indirect(mem, pc, pc_plus_lag, &(r[0]));
	if ((((mem->memory_space[(pc + 1) % MEM_SIZE] >> 4) % 4) == REG_CODE) ||
			(((mem->memory_space[(pc + 1) % MEM_SIZE] >> 4) % 4) == DIR_CODE))
		pc_plus_lag += get_register_or_direct(mem, pc, pc_plus_lag, &(r[1]));
	else if (((mem->memory_space[(pc + 1) % MEM_SIZE] >> 4) % 4) == IND_CODE)
		pc_plus_lag += get_indirect(mem, pc, pc_plus_lag, &(r[1]));
	if (r[2] != 0)
		return (pc_plus_lag - pc);
	r[2] = r[1] & r[0];
	i = REG_SIZE;
	while (i > 0)
	{
		read_head->registers[mem->memory_space[pc_plus_lag % MEM_SIZE] - 1][--i]
			= r[2] % 0x100;
		r[2] /= 0x100;
	}
	return (pc_plus_lag - pc + 1);
}

int						and(void *p1, void *p2)
{
	t_local_memory	*read_head;
	t_mem			*mem;
	unsigned int	pc;
	unsigned int	r[3 + 2];

	read_head = p1;
	mem = p2;
	pc = convert_pc_to_uint(read_head->program_counter);
	if ((mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_RRR) &&
			(mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_DRR) &&
			(mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_IRR) &&
			(mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_RDR) &&
			(mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_DDR) &&
			(mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_IDR) &&
			(mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_RIR) &&
			(mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_DIR) &&
			(mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_IIR))
		return (1 + 1);
	else
	{
		ft_bzero(r, 3 * sizeof(unsigned int));
		return (do_and(read_head, mem, pc, r));
	}
}
