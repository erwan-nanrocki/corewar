/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:18:18 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/26 18:32:49 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		initialize(t_mem *mem, int argc, char **argv)
{
	int		i;
	int		j;

	ft_bzero(mem, sizeof(t_mem));
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
			mem->champ[i].id[0] = mem->champ[i - 1].id[0] - 1;
		i++;
	}
	i = 0;
	while (++i < argc)
		if (argv[i][0] == '-')
			set_options(argv, &i, mem);
		else
			set_champ(argv[i], mem);
	open_files_and_complete_memory_space(mem);
	set_process(mem);
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
	initialize(&mem, argc, argv);
	{
		unsigned int	i;
		unsigned int	j;
		int				size;

		ft_putstr("\n~~~~~~~~~\n");
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
				unsigned int	pc;

				process = mem.process;
				while (process != NULL)
				{
					pc = 0;
					j = REG_SIZE;
					while (j > 0)
					{
						pc = pc * 0xff + (((t_local_memory *)
									(process->content))->program_counter[j - 1])
							% 0xff;
						j--;
					}
					if (pc == i)
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
		ft_putstr("\n");
		ft_putstr("\n");
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
				ft_putstr(")\n");
				i++;
			}
		}
		ft_putstr("\n********\n");
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
				ft_putstr(" pc = ");
				ft_puthex(convert_pc_to_uint(((t_local_memory *)
								(process->content))->program_counter));
				ft_putchar('\n');
				ft_putstr(" carry = ");
				ft_putnbr(((t_local_memory *)(process->content))->carry);
				ft_putstr(" op_code=0x");
				ft_puthex(((t_local_memory *)(process->content))->op_code);
				ft_putstr(" cycle = ");
				ft_putunbr(((t_local_memory *)(process->content))->cycle_countdown);
				ft_putchar('\n');
				ft_putchar('\n');
				process = process->next;
			}
		}
	}
	terminate(&mem);
	return (0);
}
