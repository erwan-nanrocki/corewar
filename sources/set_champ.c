/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 07:31:11 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/15 05:46:29 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_champ.h"

int		set_champ(char *file, t_mem *mem)
{
	if (mem->number_champ < MAX_PLAYERS)
	{
		mem->champ[mem->number_champ].file = file;
		mem->number_champ++;
	}
	else
	{
		ft_putstr_fd("\033[31m""ERROR""\033[m", 2);
		ft_putstr_fd(" : too many champ (MAX_PLAYRES = ", 2);
		ft_putunbr_fd(MAX_PLAYERS, 2);
		ft_putstr_fd(")\n", 2);
		return (ERROR);
	}
	return (SUCCESS);
}
