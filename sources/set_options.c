/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 06:11:39 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/04 00:46:55 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_options.h"

static void		a_to_hex(char *str, unsigned char new_id[REG_SIZE])
{
	ssize_t		i;
	ssize_t		j;

	i = ft_strlen(str);
	j = REG_SIZE - 1;
	while ((ft_isdigit((str[i]) == TRUE) ||
				(ft_isalpha((str[i]) == TRUE) && (str[i] <= 'f')))
			&& ((i > 0) && (j > 0)))
	{
		new_id[j] = str[i];
		i--;
		new_id[j] = 16 * str[i];
		i--;
		j--;
	}
}

static int		ft_putstr_error(char *str)
{
	ft_putstr_fd("\033[31m""ERROR""\033[m"" : the option \"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\" doesn't not exit\n", 2);
	return (ERROR);
}

int				set_options(char **argv, int *i, t_mem *mem)
{
	if ((ft_strequ(argv[*i], "--aff") == TRUE) ||
			(ft_strequ(argv[*i], "-a") == TRUE))
		mem->option_aff = TRUE;
	else if ((ft_strequ(argv[*i], "--dump") == TRUE) ||
			(ft_strequ(argv[*i], "-d") == TRUE))
	{
		mem->option_dump = DUMP_SIMPLE;
		mem->value_dump = ft_atoui(argv[++(*i)]);
	}
	else if ((ft_strequ(argv[*i], "--multi_dump") == TRUE) ||
			(ft_strequ(argv[*i], "-m") == TRUE))
	{
		mem->option_dump = DUMP_MULTI;
		mem->value_dump = ft_atoui(argv[++(*i)]);
	}
	else if ((ft_strequ(argv[*i], "--number") == TRUE) ||
			(ft_strequ(argv[*i], "-n") == TRUE))
	{
		mem->champ[mem->number_champ].id_perso = TRUE;
		a_to_hex(argv[++(*i)], mem->champ[mem->number_champ].id);
	}
	else
		return (ft_putstr_error(argv[*i]));
	return (SUCCESS);
}
