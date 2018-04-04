/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:03:09 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/24 01:13:12 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		do_op(t_local_memory *read_head, t_mem *mem)
{
	if (mem->op_tab[read_head->opcode].action == NULL)
		return (1);
	else
		return (mem->op_tab[read_head->opcode].action(read_head, mem));
}