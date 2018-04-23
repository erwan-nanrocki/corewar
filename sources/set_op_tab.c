/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_op_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 06:40:02 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/16 22:50:23 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_op_tab.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

static void		set_action(t_mem *mem)
{
	mem->op_tab[1].action = &(live);
	mem->op_tab[2].action = &(ld);
	mem->op_tab[3].action = &(st);
	mem->op_tab[4].action = &(add);
	mem->op_tab[5].action = &(sub);
	mem->op_tab[6].action = &(and);
	mem->op_tab[7].action = &(or);
	mem->op_tab[8].action = &(xor);
	mem->op_tab[9].action = &(zjmp);
	mem->op_tab[10].action = &(ldi);
	mem->op_tab[11].action = &(sti);
	mem->op_tab[12].action = &(fork_e);
	mem->op_tab[13].action = &(lld);
	mem->op_tab[14].action = &(lldi);
	mem->op_tab[15].action = &(lfork_e);
	mem->op_tab[16].action = &(aff);
}

void			set_op_tab(t_mem *mem)
{
	int		i;
	int		j;
	t_op	end;

	ft_bzero(&end, sizeof(t_op));
	i = 0;
	while (i < 256)
	{
		j = 0;
		while (ft_memcmp(&(g_op_tab[j]), &end, sizeof(t_op)) != NO_DIFF)
		{
			if (g_op_tab[j].opcode == i)
			{
				ft_memmove(&(mem->op_tab[i].data), &(g_op_tab[j]),
						sizeof(t_op));
				mem->op_tab[i].exist = TRUE;
			}
			j++;
		}
		i++;
	}
	set_action(mem);
}
