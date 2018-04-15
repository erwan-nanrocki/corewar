/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_and_complete_memory_space.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:20:35 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/15 21:02:14 by enanrock         ###   ########.fr       */
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

static int		ft_putstr_error_cant_t_read(t_mem *mem, unsigned int i)
{
	ft_putstr_fd("\033[31m""ERROR""\033[m"" : can't read \"", 2);
	ft_putstr_fd(mem->champ[i].file, 2);
	ft_putstr_fd("\"\n", 2);
	return (ERROR);
}

static int		ft_putstr_error_header(int version)
{
	ft_putstr_fd("\033[31m""ERROR""\033[m"" : ", 2);
	if (version == 1)
		ft_putendl_fd("header is wrong (the name one)", 2);
	if (version == 2)
	{
		ft_putstr_fd(" the magic number is not 0x", 2);
		ft_puthex_fd(COREWAR_EXEC_MAGIC, 2);
		ft_putchar_fd('\n', 2);
	}
	if (version == 3)
		ft_putendl_fd("header is wrong (the description one)", 2);
	return (ERROR);
}

int				complete_memory_space(t_mem *mem, int fd, unsigned int i,
		void *destination_of_champ_code)
{
	unsigned char	buf[BUF_SIZE];
	ssize_t			length;

	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if ((length = read(fd, buf, 4 + PROG_NAME_LENGTH + 4)) == ERROR)
		return (ft_putstr_error_cant_t_read(mem, i));
	if (length < (4 + PROG_NAME_LENGTH + 4))
		return (ft_putstr_error_header(1));
	if ((0x1000000 * buf[0]) + (0x10000 * buf[1]) + (0x100 * buf[2]) + buf[3]
			!= COREWAR_EXEC_MAGIC)
		return (ft_putstr_error_header(2));
	ft_strmove(mem->champ[i].name, (char *)(buf + 4));
	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if ((length = read(fd, buf, 4 + COMMENT_LENGTH + 4)) == ERROR)
		return (ft_putstr_error_cant_t_read(mem, i));
	if (length < (4 + COMMENT_LENGTH + 4))
		return (ft_putstr_error_header(3));
	ft_strmove(mem->champ[i].description, (char *)(buf + 4));
	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if ((length = read(fd, buf, CHAMP_MAX_SIZE + 1)) == ERROR)
		return (ft_putstr_error_cant_t_read(mem, i));
	if (length > CHAMP_MAX_SIZE)
		return (ft_putstr_error_too_fat(mem, i));
	ft_memmove(destination_of_champ_code, buf, CHAMP_MAX_SIZE);
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
		{
			ft_putstr_fd("\033[31m""ERROR""\033[m"" : can't open \"", 2);
			ft_putstr_fd(mem->champ[i].file, 2);
			ft_putstr_fd("\"\n", 2);
			return (ERROR);
		}
		if (complete_memory_space(mem, fd, i, &(mem->memory_space
						[MEM_SIZE * i / mem->number_champ])) == ERROR)
		{
			close(fd);
			return (ERROR);
		}
		close(fd);
		i++;
	}
	return (SUCCESS);
}
