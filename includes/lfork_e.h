/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork_e.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 01:36:12 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/12 23:14:04 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFORK_E_H
# define LFORK_E_H

# include "mem.h"
# include "libft.h"
# include "convert_pc_to_uint.h"

void	lfork_e(void *read_head, void *mem,
		unsigned int arg[MAX_ARGS_NUMBER][5]);

#endif
