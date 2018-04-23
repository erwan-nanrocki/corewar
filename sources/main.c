/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:18:18 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/18 18:10:27 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		initialize_mem_champ_ids(t_mem *mem)
{
	int		i;
	int		j;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		j = 0;
		while (j < REG_SIZE)
		{
			mem->champ[i].id[j] = 0xff;
			j++;
		}
		if (i > 0)
			mem->champ[i].id[j - 1] = mem->champ[i - 1].id[j - 1] - 1;
		i++;
	}
}

static int		initialize(t_mem *mem, int argc, char **argv)
{
	int		i;

	ft_bzero(mem, sizeof(t_mem));
	initialize_mem_champ_ids(mem);
	set_op_tab(mem);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (set_options(argv, &i, argc, mem) == ERROR)
				return (ERROR);
		}
		else if (set_champ(argv[i], mem) == ERROR)
			return (ERROR);
		i++;
	}
	if (open_files_and_complete_memory_space(mem) == ERROR)
		return (ERROR);
	if (set_process(mem) == ERROR)
		return (ERROR);
	mem->current_cycle_to_die = CYCLE_TO_DIE;
	mem->deadline_to_die = CYCLE_TO_DIE;
	return (SUCCESS);
}

static void		terminate(t_mem *mem)
{
	ft_lstdel(&(mem->process), ft_simple_del);
	if (mem->option_leaks == TRUE)
	{
		ft_bzero(mem, sizeof(t_mem));
		ft_putendl("\033[31m""leaks lest");
		read(1, NULL, 1);
	}
}

int				main(int argc, char **argv)
{
	t_mem	mem;

	if (argc == 1)
	{
		help_corewar(argv[0]);
		return (0);
	}
	if (secure_define() == ERROR)
		return (0);
	if (initialize(&mem, argc, argv) == ERROR)
	{
		terminate(&mem);
		return (0);
	}
	while (mem.is_end == FALSE)
	{
		cycle_plus_plus(&mem);
		if ((mem.option_dump != DUMP_NOPE)
				&& ((mem.value_dump == 0)
					|| (mem.cycles % mem.value_dump) == 0))
			dump(&mem);
	}
	terminate(&mem);
	return (0);
}
