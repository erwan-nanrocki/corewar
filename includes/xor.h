/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 06:47:53 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/18 07:00:23 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XOR_H
# define XOR_H

# include "mem.h"
# include "libft.h"
# include "convert_pc_to_uint.h"

void	xor(void *read_head, void *mem, unsigned int arg[MAX_ARGS_NUMBER][5]);

#endif
