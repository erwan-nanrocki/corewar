/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_argument_coding_bytes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 21:39:46 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/16 22:30:25 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_argument_coding_bytes.h"

int		test_argument_coding_bytes(t_local_memory *read_head, t_mem *mem,
		t_var *var, unsigned int i)
{
	if (((mem->op_tab[read_head->opcode].data.type_of_parameters[i]
					& T_REG) == 0)
			&& (((mem->memory_space[(var->pc + 1) % MEM_SIZE]
						>> (2 * (MAX_ARGS_NUMBER - 1 - i))) % 4) == REG_CODE))
		return (FAIL);
	else if (((mem->op_tab[read_head->opcode].data.type_of_parameters[i]
					& T_DIR) == 0)
			&& (((mem->memory_space[(var->pc + 1) % MEM_SIZE]
						>> (2 * (MAX_ARGS_NUMBER - 1 - i))) % 4) == DIR_CODE))
		return (FAIL);
	else if (((mem->op_tab[read_head->opcode].data.type_of_parameters[i]
					& T_IND) == 0)
			&& (((mem->memory_space[(var->pc + 1) % MEM_SIZE]
						>> (2 * (MAX_ARGS_NUMBER - 1 - i))) % 4) == IND_CODE))
		return (FAIL);
	else
		return (SUCCESS);
}
