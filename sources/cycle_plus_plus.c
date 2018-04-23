/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_plus_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:18:01 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/19 23:28:05 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle_plus_plus.h"

static void		you_win(t_mem *mem)
{
	unsigned int	i;
	unsigned int	oldest_live;

	oldest_live = 0;
	i = 0;
	while (i < mem->number_champ)
	{
		if (mem->champ[i].last_live > oldest_live)
			oldest_live = mem->champ[i].last_live;
		i++;
	}
	i = 0;
	while (i < mem->number_champ)
	{
		if (mem->champ[i].last_live == oldest_live)
		{
			ft_putstr("le joueur ");
			ft_putunbr(i + 1);
			ft_putchar('(');
			ft_putstr(mem->champ[i].name);
			ft_putendl(") a gagne");
		}
		i++;
	}
}

static void		increment_deadline_to_die(t_mem *mem)
{
	mem->last_deadline_to_die = mem->deadline_to_die;
	if ((mem->current_cycle_to_die > CYCLE_DELTA)
			&& (mem->current_nbr_live > NBR_LIVE))
	{
		mem->current_cycle_to_die -= CYCLE_DELTA;
		mem->current_checks = 0;
	}
	else if (((mem->current_cycle_to_die <= CYCLE_DELTA))
			&& (mem->current_nbr_live > NBR_LIVE))
		mem->current_checks++;
	else if (((mem->current_cycle_to_die > CYCLE_DELTA))
			|| ((mem->current_checks + 1) > MAX_CHECKS))
	{
		mem->current_cycle_to_die--;
		mem->current_checks = 0;
	}
	else
		mem->current_checks++;
	mem->current_nbr_live = 0;
	mem->deadline_to_die += mem->current_cycle_to_die;
}

static void		fatality(t_mem *mem)
{
	t_list	**p_process;

	p_process = &(mem->process);
	while (*p_process != NULL)
	{
		if (((t_local_memory *)((*p_process)->content))->last_live
				< mem->last_deadline_to_die)
			ft_lstdelhead(p_process, ft_simple_del);
		else
			p_process = &((*p_process)->next);
	}
	if (mem->process == NULL)
	{
		mem->is_end = TRUE;
		you_win(mem);
	}
	increment_deadline_to_die(mem);
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
	mem->cycles++;
	if (mem->cycles == mem->deadline_to_die)
		fatality(mem);
	return (0);
}
