/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 01:23:44 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/17 01:46:33 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lfork_e.h"

static void		set_pc(t_mem *mem, t_local_memory *new_content,
		unsigned int new_pc)
{
	unsigned int	i;

	new_content->program_counter = new_content->registers[0];
	i = 0;
	while (i < REG_SIZE)
	{
		new_content->program_counter[i] =
			(new_pc / ft_a_power_b(0x100, DIR_SIZE - 1 - i)) % 0x100;
		i++;
	}
	new_content->opcode = mem->memory_space[new_pc % MEM_SIZE];
	new_content->cycle_countdown =
		mem->op_tab[new_content->opcode].data.cycle_duration;
}

void			lfork_e(void *p1, void *p2,
		unsigned int arg[MAX_ARGS_NUMBER][5])
{
	t_local_memory	*read_head;
	t_mem			*mem;
	t_list			*new_process;
	unsigned int	pc;

	read_head = p1;
	mem = p2;
	new_process = ft_lstnew(read_head, sizeof(t_local_memory));
	if (new_process == NULL)
	{
		ft_putstr_fd("\033[33m""Warning""\033[m", 2);
		ft_putendl_fd(" : ft_lstnew fail in lfork (the first one)", 2);
	}
	else if (new_process->content == NULL)
	{
		ft_lstdelone(&new_process, ft_simple_del);
		ft_putstr_fd("\033[33m""Warning""\033[m", 2);
		ft_putendl_fd(" : ft_lstnew fail in lfork (the second one)", 2);
	}
	else
	{
		pc = convert_pc_to_uint(read_head->program_counter);
		set_pc(mem, new_process->content, pc + arg[0][3]);
		ft_lstadd(&(mem->process), new_process);
	}
}
