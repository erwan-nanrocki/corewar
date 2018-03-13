/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:52:20 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/13 01:40:13 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_process.h"

static void		initialize(t_local_memory *content, int i, t_mem *mem)
{
	unsigned int	j;

	ft_bzero(content, sizeof(t_local_memory));
	j = 0;
	while (j < REG_SIZE)
	{
		content->registers[0][j] = mem->champ[i].id[j];
		content->program_counter[j] = ((i * (MEM_SIZE / mem->number_champ))
				/ ft_a_power_b(0x100, REG_SIZE - 1 - j)) % 0x100;
		j++;
	}
	content->carry = 1;
	content->opcode =
		mem->memory_space[convert_pc_to_uint(content->program_counter)];
	i = 0;
	while ((i < 16) && (op_tab[i].opcode != content->opcode))
		i++;
	if (i < 17)
		content->cycle_countdown = op_tab[i].cycle_duration;
	else
		content->cycle_countdown = 1;
}

static int		create_new_process(int i, t_mem *mem)
{
	t_list			*new_process;
	t_local_memory	content;

	initialize(&content, i, mem);
	new_process = ft_lstnew(&content, sizeof(t_local_memory));
	if (new_process == NULL)
	{
		ft_putstr_fd("\033[31m""FAIL""\033[31m : lstnew (1st malloc)\n", 2);
		return (ERROR);
	}
	else if (new_process->content == NULL)
	{
		ft_putstr_fd("\033[31m""FAIL""\033[31m : lstnew (2nd malloc)\n", 2);
		ft_lstdelone(&new_process, ft_simple_del);
		return (ERROR);
	}
	ft_lstadd(&(mem->process), new_process);
	return (SUCCESS);
}

int				set_process(t_mem *mem)
{
	unsigned int	i;

	i = 0;
	while (i < mem->number_champ)
	{
		if (create_new_process(i, mem) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
