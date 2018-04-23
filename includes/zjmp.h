/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 13:35:34 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/18 07:00:30 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZJMP_H
# define ZJMP_H

# include "mem.h"
# include "libft.h"
# include "convert_pc_to_uint.h"

void	zjmp(void *read_head, void *mem, unsigned int arg[MAX_ARGS_NUMBER][5]);

#endif
