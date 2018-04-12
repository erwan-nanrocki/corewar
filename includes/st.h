/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 08:24:59 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/12 20:55:23 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ST_H
# define ST_H

# include "mem.h"
# include "convert_pc_to_uint.h"

void	st(void *read_head, void *mem, unsigned int arg[MAX_ARGS_NUMBER][5]);

#endif
