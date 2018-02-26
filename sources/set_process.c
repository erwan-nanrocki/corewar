/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:52:20 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/26 18:05:12 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_process.h"

void	set_process(t_mem *mem)
{
	t_list			*new_process;
	t_local_memory	content;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < mem->number_champ)
	{
		ft_bzero(&content, sizeof(t_local_memory));
		j = 0;
		while (j < REG_SIZE)
		{
			content.registers[0][j] = mem->champ[i].id[j];
			content.program_counter[j] = ((i * MEM_SIZE / mem->number_champ) /
					ft_a_power_b(0xff, j)) % 0xff;
			j++;
		}
		content.carry = 1;
		content.op_code =
			mem->memory_space[convert_pc_to_uint(content.program_counter)];
		content.cycle_countdown = 424242;
		new_process = ft_lstnew(&content, sizeof(t_local_memory));
		ft_lstadd(&(mem->process), new_process);
		i++;
	}
}
