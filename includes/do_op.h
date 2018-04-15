/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:06:55 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/15 21:45:04 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include "mem.h"
# include "convert_pc_to_uint.h"
# include "test_argument_coding_bytes.h"

int		do_op(t_local_memory *read_head, t_mem *mem);

#endif
