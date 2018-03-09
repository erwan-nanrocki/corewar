/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 06:11:39 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/09 13:26:04 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_options.h"

static int		complete_new_id(char *str_cp, unsigned char new_id[REG_SIZE],
		int i, int j)
{
	if (ft_isdigit(str_cp[j]) == TRUE)
		new_id[i] = 0x10 * new_id[i] + (str_cp[j] - '0');
	else if ((ft_isalpha(str_cp[j]) == TRUE)
			&& (str_cp[j] <= 'f'))
		new_id[i] = 0x10 * new_id[i] + (10 + str_cp[j] - 'a');
	else
		return (ERROR);
	return (SUCCESS);
}

static int		a_to_hex(char *str, unsigned char new_id[REG_SIZE])
{
	char		str_cp[(2 * REG_SIZE) + 1];
	ssize_t		i;

	ft_strset(str_cp, '0', 2 * REG_SIZE * sizeof(char));
	str_cp[2 * REG_SIZE - 1] = '\0';
	i = ft_strlen(str);
	if (i > (2 * REG_SIZE))
		return (ERROR);
	ft_bzero(new_id, REG_SIZE * sizeof(unsigned char));
	ft_strmove(str_cp + ((2 * REG_SIZE) - i), str);
	ft_strlower(str_cp);
	i = 0;
	while (i < REG_SIZE)
	{
		if (complete_new_id(str_cp, new_id, i, 2 * i) == ERROR)
			return (ERROR);
		if (complete_new_id(str_cp, new_id, i, 2 * i + 1) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static int		ft_putstr_error_option(char *str)
{
	ft_putstr_fd("\033[31m""ERROR""\033[m"" : the option \"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\" does not exit, or it's incomplete\n", 2);
	return (ERROR);
}

static int		ft_putstr_error_number(char *str)
{
	ft_putstr_fd("\033[31m""ERROR""\033[m"" : the number \"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\" is not an hexadecimal, or it's too long (", 2);
	ft_putunbr_fd(2 * REG_SIZE, 2);
	ft_putstr_fd(" chars)\n", 2);
	return (ERROR);
}

int				set_options(char **argv, int *i, int argc, t_mem *mem)
{
	if ((ft_strequ(argv[*i], "--aff") == TRUE) ||
			(ft_strequ(argv[*i], "-a") == TRUE))
		mem->option_aff = TRUE;
	else if ((*i + 1 < argc) && ((ft_strequ(argv[*i], "--dump") == TRUE)
				|| (ft_strequ(argv[*i], "-d") == TRUE)))
	{
		mem->option_dump = DUMP_SIMPLE;
		mem->value_dump = ft_atoui(argv[++(*i)]);
	}
	else if ((*i + 1 < argc) && ((ft_strequ(argv[*i], "--multi_dump") == TRUE)
				|| (ft_strequ(argv[*i], "-m") == TRUE)))
	{
		mem->option_dump = DUMP_MULTI;
		mem->value_dump = ft_atoui(argv[++(*i)]);
	}
	else if ((*i + 2 < argc) && ((ft_strequ(argv[*i], "--number") == TRUE)
				|| (ft_strequ(argv[*i], "-n") == TRUE)))
	{
		mem->champ[mem->number_champ].id_perso = TRUE;
		if (a_to_hex(argv[++(*i)], mem->champ[mem->number_champ].id) == ERROR)
			return (ft_putstr_error_number(argv[*i]));
	}
	else
		return (ft_putstr_error_option(argv[*i]));
	return (SUCCESS);
}
