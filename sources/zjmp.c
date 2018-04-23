/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 13:35:20 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/17 05:13:56 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zjmp.h"

void	zjmp(void *p1, void *p2, unsigned int arg[MAX_ARGS_NUMBER][5])
{
	t_local_memory	*read_head;
	t_mem			*mem;
	unsigned int	pc;
	unsigned int	i;

	read_head = p1;
	mem = p2;
	if (read_head->carry == 0)
	{
		pc = convert_pc_to_uint(read_head->program_counter);
		i = DIR_SIZE;
		while (i > 0)
		{
			read_head->program_counter[DIR_SIZE - i] =
				((pc + arg[0][1] - 1 - IND_SIZE) / ft_a_power_b(0x100, i - 1))
				% 0x100;
			i--;
		}
	}
}
