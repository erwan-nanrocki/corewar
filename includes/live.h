/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 01:36:12 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/19 23:06:54 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIVE_H
# define LIVE_H

# include "mem.h"
# include "convert_pc_to_uint.h"

# define CA_VA_ETRE_TOUT_NOIR 0
# define TA_GUEULE            1

void	live(void *read_head, void *mem, unsigned int arg[MAX_ARGS_NUMBER][5]);

#endif
