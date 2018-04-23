/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:57:49 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/19 18:46:56 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_THE_HEADER_H
# define CHECK_THE_HEADER_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "mem.h"
# include "libft.h"

int		check_the_header(t_mem *mem, int fd, unsigned int i,
		ssize_t *length_code);

#endif
