/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 01:23:44 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/15 16:02:53 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "live.h"

void	live(void *p1, void *p2, unsigned int arg[MAX_ARGS_NUMBER][5])
{
	unsigned int	i;
	t_local_memory	*read_head;
	t_mem			*mem;

	read_head = p1;
	mem = p2;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (arg[0][1] == convert_pc_to_uint(mem->champ[i].id))
		{
			mem->champ[i].last_live = mem->cycles + 1;
			ft_putstr("un processus dit que le joueur ");
			ft_putunbr(i + 1);
			ft_putchar('(');
			ft_putstr(mem->champ[i].name);
			ft_putendl(") est en vie");
		}
		i++;
	}
	read_head->last_live = mem->cycles + 1;
	(mem->current_nbr_live)++;
}
