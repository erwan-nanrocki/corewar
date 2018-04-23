/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_op_tab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 06:42:07 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/18 06:59:21 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_OP_TAB_H
# define SET_OP_TAB_H

# include "mem.h"
# include "libft.h"

# include "live.h"
# include "ld.h"
# include "st.h"
# include "add.h"
# include "sub.h"
# include "and.h"
# include "or.h"
# include "xor.h"
# include "zjmp.h"
# include "ldi.h"
# include "sti.h"
# include "fork_e.h"
# include "lld.h"
# include "lldi.h"
# include "lfork_e.h"
# include "aff.h"

void	set_op_tab(t_mem *mem);

#endif
