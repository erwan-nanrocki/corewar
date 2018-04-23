/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:03:09 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/18 05:00:42 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

static unsigned int		get_register(t_local_memory *read_head, t_mem *mem,
		t_var *var, unsigned int i)
{
	if ((mem->memory_space[(var->pc + var->lag) % MEM_SIZE] == 0)
			|| (mem->memory_space[(var->pc + var->lag) % MEM_SIZE]
				> REG_NUMBER))
	{
		var->is_error_registers = TRUE;
		var->arg[i][0] = mem->memory_space[(var->pc + var->lag) % MEM_SIZE];
	}
	else
	{
		var->arg[i][0] = mem->memory_space[(var->pc + var->lag) % MEM_SIZE];
		var->arg[i][1] =
			convert_pc_to_uint(read_head->registers[var->arg[i][0]]);
		var->arg[i][3] = var->arg[i][1];
	}
	return (1);
}

static unsigned int		get_indirect(t_mem *mem, t_var *var, unsigned int i)
{
	unsigned int	j;
	int				t;

	var->arg[i][0] = NOT_REG;
	t = 0;
	j = 0;
	while (j < IND_SIZE)
		t = (t * 0x100)
			+ mem->memory_space[(var->pc + var->lag + (j++)) % MEM_SIZE];
	if (t >= (0x80 * ft_a_power_b(0x100, IND_SIZE - 1)))
		t -= ft_a_power_b(0x100, IND_SIZE);
	var->arg[i][1] = 0;
	var->arg[i][2] = t % IDX_MOD;
	var->arg[i][3] = 0;
	var->arg[i][4] = t;
	j = 0;
	while (j < DIR_SIZE)
	{
		var->arg[i][1] += ft_a_power_b(0x100, (REG_SIZE - 1) - j)
			* mem->memory_space[(var->pc + (t % IDX_MOD) + j) % MEM_SIZE];
		var->arg[i][3] += ft_a_power_b(0x100, (REG_SIZE - 1) - j)
			* mem->memory_space[(var->pc + t + j) % MEM_SIZE];
		j++;
	}
	return (IND_SIZE);
}

static unsigned int		get_direct(t_local_memory *read_head, t_mem *mem,
		t_var *var, unsigned int i)
{
	unsigned int	j;

	var->arg[i][0] = NOT_REG;
	var->arg[i][1] = 0;
	if (mem->op_tab[read_head->opcode].data.boolean_length_direct == 0)
	{
		j = 0;
		while (j < DIR_SIZE)
		{
			var->arg[i][1] +=
				mem->memory_space[(var->pc + var->lag + j) % MEM_SIZE]
				* ft_a_power_b(0x100, (REG_SIZE - 1) - j);
			j++;
		}
		var->arg[i][3] = var->arg[i][1];
		return (DIR_SIZE);
	}
	else
	{
		get_indirect(mem, var, i);
		var->arg[i][1] = var->arg[i][2];
		var->arg[i][3] = var->arg[i][4];
		return (IND_SIZE);
	}
}

static int				get_arguments(t_local_memory *read_head, t_mem *mem,
		t_var *var)
{
	unsigned int	i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (test_argument_coding_bytes(read_head, mem, var, i) == FAIL)
			return (FAIL);
		if (((mem->memory_space[(var->pc + 1) % MEM_SIZE]
						>> (2 * (MAX_ARGS_NUMBER - 1 - i))) % 4) == REG_CODE)
			var->lag += get_register(read_head, mem, var, i);
		if (((mem->memory_space[(var->pc + 1) % MEM_SIZE]
						>> (2 * (MAX_ARGS_NUMBER - 1 - i))) % 4) == DIR_CODE)
			var->lag += get_direct(read_head, mem, var, i);
		if (((mem->memory_space[(var->pc + 1) % MEM_SIZE]
						>> (2 * (MAX_ARGS_NUMBER - 1 - i))) % 4) == IND_CODE)
			var->lag += get_indirect(mem, var, i);
		i++;
	}
	return (SUCCESS);
}

int						do_op(t_local_memory *read_head, t_mem *mem)
{
	t_var	var;

	ft_bzero(&var, sizeof(t_var));
	if (mem->op_tab[read_head->opcode].exist == FALSE)
		return (1);
	var.pc = convert_pc_to_uint(read_head->program_counter);
	if (mem->op_tab[read_head->opcode].data.boolean_argument_coding_byte == 1)
	{
		var.lag = 1 + 1;
		var.is_error_registers = FALSE;
		if (get_arguments(read_head, mem, &var) == FAIL)
			return (1 + 1);
		if (var.is_error_registers == TRUE)
			return (var.lag);
	}
	else
	{
		var.lag = 1;
		var.lag += get_direct(read_head, mem, &var, 0);
	}
	if (mem->op_tab[read_head->opcode].action == NULL)
		return (var.lag);
	mem->op_tab[read_head->opcode].action(read_head, mem, var.arg);
	return (var.lag);
}
