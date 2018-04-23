/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_define.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:52:13 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/18 16:15:34 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "secure_define.h"

int		secure_define(void)
{
	if ((REG_SIZE != DIR_SIZE) || (REG_SIZE <= 0) || (DIR_SIZE <= 0)
			|| (IND_SIZE <= 0) || (REG_CODE >= 4) || (DIR_CODE >= 4)
			|| (IND_CODE >= 4) || (IDX_MOD <= 0) || (REG_NUMBER <= 0)
			|| (REG_CODE < 0) || (DIR_CODE < 0) || (IND_CODE < 0)
			|| (REG_CODE > 3) || (DIR_CODE > 3) || (IND_CODE > 3)
			|| (CHAMP_MAX_SIZE > (MEM_SIZE / MAX_PLAYERS)) || (CYCLE_TO_DIE < 0)
			|| (CYCLE_DELTA < 0) || (NBR_LIVE < 0) || (MAX_CHECKS < 0)
			|| (((T_REG % 2) != 0) && (T_REG != 1))
			|| (((T_DIR % 2) != 0) && (T_DIR != 1))
			|| (((T_IND % 2) != 0) && (T_IND != 1))
			|| (PROG_NAME_LENGTH < 0) || (COMMENT_LENGTH < 0))
	{
		ft_putstr_fd("\033[31m""ERROR""\033[m", 2);
		ft_putendl_fd(" : please, don't try to break my code 💜 ", 2);
		ft_putendl_fd(" (\\   /)", 2);
		ft_putendl_fd("  \\\\ //", 2);
		ft_putendl_fd(" (=^w^=)", 2);
		ft_putendl_fd("  / _ \\", 2);
		ft_putendl_fd("  \\m_m/*", 2);
		return (ERROR);
	}
	return (SUCCESS);
}
