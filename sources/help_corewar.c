/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 23:26:59 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/16 07:24:42 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help_corewar.h"

void	help_corewar(char *name)
{
	ft_putstr("### MANUEL ### #########################");
	ft_putstr("########################################\n");
	ft_putstr("Usage : ");
	ft_putstr(name);
	ft_putstr(" [--aff] [--dump N] <[--number N] champion.cor (1 to 4)>\n");
	ft_putstr("\n");
	ft_putstr("    --aff (-a)            : Prints output from \"aff\"\n");
	ft_putstr("    --dump N (-d N)       : Dumps memory after N cycles,");
	ft_putstr(" then exits\n");
	ft_putstr("    --multi_dump N (-m N) : Dumps memory after N cycles,");
	ft_putstr(" pauses, then repeats\n");
	ft_putstr("    --number Hex (-n Hex) : Change the ID's number of");
	ft_putstr(" the next champion\n");
	ft_putstr("########################################");
	ft_putstr("########################################\n");
}
