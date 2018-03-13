/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_plus_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:18:01 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/13 01:28:42 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle_plus_plus.h"

static void		game_over(t_mem *mem)
{
	mem->cycles++;
}

int				cycle_plus_plus(t_mem *mem)
{
	t_list			*read_head;
	unsigned int	skip;

	read_head = mem->process;
	while (read_head != NULL)
	{
		if (((t_local_memory *)(read_head->content))->cycle_countdown > 0)
			((t_local_memory *)(read_head->content))->cycle_countdown--;
		if (((t_local_memory *)(read_head->content))->cycle_countdown <= 0)
		{
			if ((skip = do_op(read_head->content, mem)) > 0)
				change_op(read_head->content, mem, skip);
		}
		read_head = read_head->next;
	}
	game_over(mem);
	return (0);
}
