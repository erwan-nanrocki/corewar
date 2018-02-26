/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 06:11:39 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/16 08:41:16 by enanrock         ###   ########.fr       */
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

void			set_options(char **argv, int *i, t_mem *mem)
{
	int		should_i_increment_this_int;

	should_i_increment_this_int = NOPE;
	if ((ft_strequ(argv[*i], "--aff") == TRUE) ||
			((argv[*i][1] != '-') && (ft_strchr(argv[*i], 'a') != NULL)))
		mem->option_aff = TRUE;
	if ((ft_strequ(argv[*i], "--multi_dump") == TRUE) ||
			(ft_strequ(argv[*i], "--dump") == TRUE) ||
			((argv[*i][1] != '-') && (ft_strchr(argv[*i], 'm') != NULL)) ||
			((argv[*i][1] != '-') && (ft_strchr(argv[*i], 'd') != NULL)))
	{
		mem->option_dump = DUMP_SIMPLE;
		if (ft_strchr(argv[*i], 'm') != NULL)
			mem->option_dump = DUMP_MULTI;
		mem->value_dump = ft_atoui(argv[*i + 1]);
		should_i_increment_this_int = YES;
	}
	if ((ft_strequ(argv[*i], "--number") == TRUE) ||
			((argv[*i][1] != '-') && (ft_strchr(argv[*i], 'n') != NULL)))
	{
		a_to_hex(argv[*i + 1], mem->champ[mem->number_champ].id);
		mem->champ[mem->number_champ].id_perso = TRUE;
		should_i_increment_this_int = YES;
	}
	*i = (should_i_increment_this_int == YES) ? (*i + 1) : (*i);
}
