/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 04:17:49 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/12 21:18:19 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STI_H
# define STI_H

# include "mem.h"
# include "convert_pc_to_uint.h"

void	sti(void *read_head, void *mem, unsigned int arg[MAX_ARGS_NUMBER][5]);

#endif
