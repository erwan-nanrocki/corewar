/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 01:23:44 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/12 23:34:48 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aff.h"

void	aff(void *p1, void *p2, unsigned int arg[MAX_ARGS_NUMBER][5])
{
	t_local_memory	*read_head;
	t_mem			*mem;

	read_head = p1;
	mem = p2;
	if (mem->option_aff == TRUE)
	{
		if (ft_isprint(arg[0][1]) == TRUE)
			ft_putchar(arg[0][1]);
		else
			ft_putchar('.');
	}
}
