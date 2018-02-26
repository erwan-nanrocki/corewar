/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 07:31:11 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/16 08:25:28 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_champ.h"

void	set_champ(char *file, t_mem *mem)
{
	if (mem->number_champ < MAX_PLAYERS)
	{
		mem->champ[mem->number_champ].file = ft_strdup(file);
		mem->number_champ++;
	}
	else
	{
		ft_putstr_fd("ERROR : too many champ (MAX_PLAYRES = ", 2);
		ft_putunbr_fd(MAX_PLAYERS, 2);
		ft_putendl_fd(")", 2);
	}
}
