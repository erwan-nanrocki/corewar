/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 06:48:30 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/01 13:51:59 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add.h"

static void		r1_plus_r2_in_r3(t_local_memory *read_head,
		unsigned char r1, unsigned char r2, unsigned char r3)
{
	unsigned int	temp;
	unsigned int	i;

	r1--;
	r2--;
	r3--;
	temp = 0;
	i = REG_SIZE;
	while (i > 0)
	{
		i--;
		temp = read_head->registers[r1][i] + read_head->registers[r2][i] + temp;
		read_head->registers[r3][i] = temp % 0x100;
		temp = temp / 0x100;
	}
	read_head->carry = convert_pc_to_uint(read_head->registers[r3]);
}

int				add(void *p1, void *p2)
{
	unsigned int	pc;
	t_local_memory	*read_head;
	t_mem			*mem;

	read_head = p1;
	mem = p2;
	pc = convert_pc_to_uint(read_head->program_counter);
	if (mem->memory_space[(pc + 1) % MEM_SIZE] != ACB_RRR)
		return (1 + 1);
	else if ((mem->memory_space[(pc + 2) % MEM_SIZE] == 0) ||
			(mem->memory_space[(pc + 3) % MEM_SIZE] == 0) ||
			(mem->memory_space[(pc + 4) % MEM_SIZE] == 0) ||
			(mem->memory_space[(pc + 2) % MEM_SIZE] > REG_NUMBER) ||
			(mem->memory_space[(pc + 3) % MEM_SIZE] > REG_NUMBER) ||
			(mem->memory_space[(pc + 4) % MEM_SIZE] > REG_NUMBER))
		return (1 + 1 + 3);
	else
	{
		r1_plus_r2_in_r3(read_head, mem->memory_space[(pc + 2) % MEM_SIZE],
				mem->memory_space[(pc + 3) % MEM_SIZE],
				mem->memory_space[(pc + 4) % MEM_SIZE]);
		return (1 + 1 + 3);
	}
}
