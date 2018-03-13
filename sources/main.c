/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:18:18 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/13 01:55:24 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include "op.c"

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
	i = 0;
	while (++i < argc)
		if (argv[i][0] == '-')
		{
			if (set_options(argv, &i, argc, mem) == ERROR)
				return (ERROR);
		}
		else if (set_champ(argv[i], mem) == ERROR)
			return (ERROR);
	if (open_files_and_complete_memory_space(mem) == ERROR)
		return (ERROR);
	if (set_process(mem) == ERROR)
		return (ERROR);
	mem->current_cycle_to_die = CYCLE_TO_DIE;
	return (SUCCESS);
}

static void		terminate(t_mem *mem)
{
	int		i;

	ft_lstdel(&(mem->process), ft_simple_del);
	i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_strdel(&(mem->champ[i].file));
		i++;
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
	if (initialize(&mem, argc, argv) == ERROR)
	{
		ft_putendl("NOOOOOOOOOOOOOOOO");
		terminate(&mem);
		return (0);
	}
	else
		ft_putendl("YEEEEEEEEEEEEEEEEES");
	if (mem.value_dump == 0)
		ft_putendl("\033[7m""Please add \"-d 123\" to view the result");
	while (mem.cycles < mem.value_dump)
	{
		unsigned int	i;
		unsigned int	j;
		int				size;

		read(1, NULL, 1);
		cycle_plus_plus(&mem);
		ft_putstr("\n~~~~~~~~~ map info ~~~~~~~~~\n");
		size = 64;
		i = 0;
		while (i < MEM_SIZE)
		{
			if ((i < MEM_SIZE) && (i % size) == 0)
			{
				ft_putstr("\n0x");
				if (i < 0x10)
					ft_putstr("0");
				if (i < 0x100)
					ft_putstr("0");
				if (i < 0x1000)
					ft_putstr("0");
				ft_puthex(i);
				ft_putstr(" : ");
			}
			{
				t_list			*process;

				process = mem.process;
				while (process != NULL)
				{
					if (convert_pc_to_uint(((t_local_memory *)
								(process->content))->program_counter) == i)
						ft_putstr("\033[7m");
					process = process->next;
				}
			}
			if (mem.memory_space[i] < 16)
				ft_putstr("0");
			ft_puthex(mem.memory_space[i]);
			ft_putstr("\033[m");
			ft_putstr(" ");
			i++;
		}
		ft_putstr("\n\n");
		ft_putstr("@@@@@@@@@ champ info @@@@@@@@@");
		ft_putstr("\n\n");
		{
			i = 0;
			while (i < MAX_PLAYERS)
			{
				ft_putstr("file : \"");
				ft_putstr(mem.champ[i].file);
				ft_putstr("\" name : \"");
				ft_putstr(mem.champ[i].name);
				ft_putstr("\" desc : \"");
				ft_putstr(mem.champ[i].description);
				ft_putstr("\" id : \"");
				ft_puthex(convert_pc_to_uint(mem.champ[i].id));
				ft_putstr("\"(");
				ft_putnbr(mem.champ[i].id_perso);
				ft_putstr(")  | last live = ");
				ft_putnbr(mem.champ[i].last_live);
				ft_putstr("\n");
				i++;
			}
		}
		ft_putstr("\n****** local memory info (olddest > youngest) ******\n\n");
		{
			t_list			*process;

			process = mem.process;
			while (process != NULL)
			{
				j = 0;
				while (j < REG_NUMBER)
				{
					ft_putstr(" r");
					ft_putnbr(j + 1);
					ft_putstr("=");
					ft_puthex(convert_pc_to_uint(((t_local_memory *)
									(process->content))->registers[j]));
					j++;
				}
				ft_putstr("\n carry = ");
				ft_putnbr(((t_local_memory *)(process->content))->carry);
				ft_putstr(" | \033[7m""pc = ");
				ft_puthex(convert_pc_to_uint(((t_local_memory *)
								(process->content))->program_counter));
				ft_putstr("\033[m | \033[7m""opcode=0x");
				ft_puthex(((t_local_memory *)(process->content))->opcode);
				ft_putstr("\033[7m | \033[7m""cycle_countdown = ");
				ft_putunbr(((t_local_memory *)
							(process->content))->cycle_countdown);
				ft_putstr("\033[m");
				ft_putchar('\n');
				ft_putchar('\n');
				process = process->next;
			}
		}
		ft_putstr("\n!!!!!! other info !!!!!!\n");
		{
			ft_putstr("\n""number_champ         = ");
			ft_putunbr(mem.number_champ);
			ft_putstr("\n""current_cycle_to_die = ");
			ft_putunbr(mem.current_cycle_to_die);
			ft_putstr("\n""current_nbr_live     = ");
			ft_putunbr(mem.current_nbr_live);
			ft_putstr("\n""\033[7m""cycles                = ");
			ft_putunbr(mem.cycles);
			ft_putstr("\033[m""\n""option_aff           = ");
			ft_putnbr(mem.option_aff);
			ft_putstr("\n""option_dump          = ");
			ft_putnbr(mem.option_dump);
			ft_putstr("\n""value_dump           = ");
			ft_putunbr(mem.value_dump);
			ft_putstr("\n");
		}
	}
	terminate(&mem);
	return (0);
}
