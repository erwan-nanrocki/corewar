/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:06:55 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/12 20:53:52 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include "mem.h"
# include "convert_pc_to_uint.h"

typedef	struct		s_var
{
	unsigned int	arg[MAX_ARGS_NUMBER][5];
	unsigned int	pc;
	unsigned int	lag;
	int				is_error_registers;
}					t_var;

int					do_op(t_local_memory *read_head, t_mem *mem);

#endif
