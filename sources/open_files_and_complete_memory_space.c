/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_and_complete_memory_space.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:20:35 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/09 13:39:41 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files_and_complete_memory_space.h"

static int		ft_putstr_error_too_fat(t_mem *mem, unsigned int i)
{
	ft_putstr_fd("\033[31m""ERROR""\033[m"" : the champion \"", 2);
	ft_putstr_fd(mem->champ[i].file, 2);
	ft_putstr_fd("\" is too fat\n", 2);
	return (ERROR);
}

static int		ft_putstr_error_cant_t_open(t_mem *mem, unsigned int i)
{
	ft_putstr_fd("\033[31m""ERROR""\033[m"" : can't open \"", 2);
	ft_putstr_fd(mem->champ[i].file, 2);
	ft_putstr_fd("\"\n", 2);
	return (ERROR);
}

static int		ft_putstr_error_cant_t_read(t_mem *mem, unsigned int i)
{
	ft_putstr_fd("\033[31m""ERROR""\033[m"" : can't read \"", 2);
	ft_putstr_fd(mem->champ[i].file, 2);
	ft_putstr_fd("\"\n", 2);
	return (ERROR);
}

int				complete_memory_space(t_mem *mem, int fd, unsigned int i)
{
	unsigned char	buf[BUF_SIZE];
	ssize_t			length;

	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if (read(fd, buf, 4 + PROG_NAME_LENGTH + 4) == ERROR)
		return (ft_putstr_error_cant_t_read(mem, i));
	ft_strmove(mem->champ[i].name, (char *)(buf + 4));
	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if (read(fd, buf, 4 + COMMENT_LENGTH + 4) == ERROR)
		return (ft_putstr_error_cant_t_read(mem, i));
	ft_strmove(mem->champ[i].description, (char *)(buf + 4));
	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if ((length = read(fd, buf, CHAMP_MAX_SIZE + 1)) == ERROR)
		return (ft_putstr_error_cant_t_read(mem, i));
	if (length > CHAMP_MAX_SIZE)
		return (ft_putstr_error_too_fat(mem, i));
	ft_memmove(&(mem->memory_space[i * MEM_SIZE / mem->number_champ]), buf,
			CHAMP_MAX_SIZE);
	return (SUCCESS);
}

int				open_files_and_complete_memory_space(t_mem *mem)
{
	int				fd;
	unsigned int	i;

	i = 0;
	while (i < mem->number_champ)
	{
		if ((fd = open(mem->champ[i].file, O_RDONLY)) == ERROR)
			return (ft_putstr_error_cant_t_open(mem, i));
		else
		{
			if (complete_memory_space(mem, fd, i) == ERROR)
			{
				close(fd);
				return (ERROR);
			}
			else
				close(fd);
		}
		i++;
	}
	return (SUCCESS);
}
