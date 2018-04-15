/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_argument_coding_bytes.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 21:40:05 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/15 21:46:12 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ARGUMENT_CODING_BYTES_H
# define TEST_ARGUMENT_CODING_BYTES_H

# include "mem.h"

typedef	struct		s_var
{
	unsigned int	arg[MAX_ARGS_NUMBER][5];
	unsigned int	pc;
	unsigned int	lag;
	int				is_error_registers;
}					t_var;

int					test_argument_coding_bytes(t_local_memory *read_head,
		t_mem *mem, t_var *var, unsigned int i);

#endif
