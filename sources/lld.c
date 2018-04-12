/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:26:42 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/12 22:51:24 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lld.h"

void	lld(void *p1, void *p2, unsigned int arg[MAX_ARGS_NUMBER][5])
{
	t_local_memory	*read_head;
	t_mem			*mem;
	unsigned int	i;

	read_head = p1;
	mem = p2;
	i = 0;
	while (i < DIR_SIZE)
	{
		read_head->registers[arg[1][0]][i] =
			(arg[0][3] / ft_a_power_b(0x100, REG_SIZE - 1 - i)) % 0x100;
		i++;
	}
	read_head->carry = convert_pc_to_uint(read_head->registers[arg[1][0]]);
}
