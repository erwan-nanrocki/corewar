/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_and_complete_memory_space.h             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:23:17 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/24 14:35:47 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_FILES_AND_COMPLETE_MEMORY_SPACE_H
# define OPEN_FILES_AND_COMPLETE_MEMORY_SPACE_H

# include <fcntl.h>
# include <unistd.h>

# include "op.h"
# include "mem.h"
# include "open_files_and_complete_memory_space.h"

void	open_files_and_complete_memory_space(t_mem *mem);

#endif