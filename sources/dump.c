/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 21:11:33 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/19 23:01:05 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dump.h"

static void		show_process(t_mem *mem, unsigned int i)
{
	t_list			*process;

	process = mem->process;
	while ((process != NULL) && (mem->option_process == TRUE))
	{
		if (convert_pc_to_uint(((t_local_memory *)(process->content))
					->program_counter) == i)
			ft_putstr("\033[7m");
		process = process->next;
	}
}

static void		mini_header(unsigned int i)
{
	if ((i < MEM_SIZE) && (i % 64) == 0)
	{
		ft_putstr("\n0x");
		if (i < 0x10)
			ft_putchar('0');
		if (i < 0x100)
			ft_putchar('0');
		if (i < 0x1000)
			ft_putchar('0');
		ft_puthex(i);
		ft_putstr(" : ");
	}
}

static void		other_info(t_mem *mem)
{
	ft_putstr("\n\nlast deadline = ");
	ft_putunbr(mem->last_deadline_to_die);
	ft_putstr("\ncycles        = ");
	ft_putunbr(mem->cycles);
	ft_putstr("\ndeadline      = ");
	ft_putunbr(mem->deadline_to_die);
	ft_putstr("\ncycles to die = ");
	ft_putunbr(mem->current_cycle_to_die);
	ft_putstr("\nnbr lives     = ");
	ft_putunbr(mem->current_nbr_live);
	ft_putchar('\n');
}

void			dump(t_mem *mem)
{
	unsigned int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		mini_header(i);
		show_process(mem, i);
		if (mem->memory_space[i % MEM_SIZE] < 16)
			ft_putstr("0");
		ft_puthex(mem->memory_space[i % MEM_SIZE]);
		if (mem->option_process == TRUE)
			ft_putstr("\033[m");
		ft_putchar(' ');
		i++;
	}
	other_info(mem);
	if (mem->option_dump == DUMP_SIMPLE)
		mem->is_end = TRUE;
	else
		read(1, NULL, 1);
}
