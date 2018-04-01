/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_op_tab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 06:42:07 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/01 13:35:16 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_OP_TAB_H
# define SET_OP_TAB_H

# include "op.h"
# include "mem.h"

# include "live.h"
# include "ld.h"
# include "st.h"
# include "add.h"
# include "zjmp.h"

void	set_op_tab(t_mem *mem);

#endif
