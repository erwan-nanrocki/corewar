/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pc_to_uint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:48:52 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/09 12:09:32 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_pc_to_uint.h"

unsigned int	convert_pc_to_uint(unsigned char pc[REG_SIZE])
{
	unsigned int	result;
	unsigned int	i;

	result = 0;
	i = 0;
	while (i < REG_SIZE)
	{
		result = (result * 0x100) + pc[i];
		i++;
	}
	return (result);
}
