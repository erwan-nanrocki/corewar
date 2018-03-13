/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:55:50 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/13 01:40:22 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_PROCESS_H
# define SET_PROCESS_H

# include "mem.h"
# include "libft.h"
# include "convert_pc_to_uint.h"

int		set_process(t_mem *mem);

extern t_op		op_tab[17];

#endif
