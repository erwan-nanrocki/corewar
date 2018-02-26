/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pc_to_uint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:48:52 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/26 18:32:12 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_pc_to_uint.h"

unsigned int	convert_pc_to_uint(unsigned char pc[REG_SIZE])
{
	unsigned int	result;
	unsigned int	i;

	result = 0;
	i = REG_SIZE;
	while (i > 0)
	{
		result = (result * 0x100) + (pc[i - 1]);
		i--;
	}
	return (result);
}
