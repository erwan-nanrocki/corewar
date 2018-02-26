/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_and_complete_memory_space.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:20:35 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/26 14:51:05 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files_and_complete_memory_space.h"

static void		ft_putstr_error_too_fat(t_mem *mem, unsigned int i)
{
	ft_putstr_fd("ERROR : this champion is too fat : \"", 2);
	ft_putstr_fd(mem->champ[i].file, 2);
	ft_putstr_fd("\"\n", 2);
}

static void		ft_putstr_error_cant_t_open(t_mem *mem, unsigned int i)
{
	ft_putstr_fd("ERROR : can't open \"", 2);
	ft_putstr_fd(mem->champ[i].file, 2);
	ft_putstr_fd("\"\n", 2);
}

static void		ft_putstr_error_cant_t_read(t_mem *mem, unsigned int i)
{
	ft_putstr_fd("ERROR : can't read \"", 2);
	ft_putstr_fd(mem->champ[i].file, 2);
	ft_putstr_fd("\"\n", 2);
}

void			complete_memory_space(t_mem *mem, int fd, unsigned int i)
{
	unsigned char	buf[BUF_SIZE];
	ssize_t			length;

	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if (read(fd, buf, 4 + PROG_NAME_LENGTH + 4) == ERROR)
		ft_putstr_error_cant_t_read(mem, i);
	else
		ft_strmove(mem->champ[i].name, (char *)(buf + 4));
	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if (read(fd, buf, 4 + COMMENT_LENGTH + 4) == ERROR)
		ft_putstr_error_cant_t_read(mem, i);
	else
		ft_strmove(mem->champ[i].description, (char *)(buf + 4));
	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if ((length = read(fd, buf, CHAMP_MAX_SIZE + 1)) == ERROR)
		ft_putstr_error_cant_t_read(mem, i);
	else if (length == CHAMP_MAX_SIZE + 1)
		ft_putstr_error_too_fat(mem, i);
	else
		ft_memmove(&(mem->memory_space[i * MEM_SIZE / mem->number_champ]), buf,
				CHAMP_MAX_SIZE);
}

void			open_files_and_complete_memory_space(t_mem *mem)
{
	int				fd;
	unsigned int	i;

	i = 0;
	while (i < mem->number_champ)
	{
		if ((fd = open(mem->champ[i].file, O_RDONLY)) == ERROR)
			ft_putstr_error_cant_t_open(mem, i);
		else
		{
			complete_memory_space(mem, fd, i);
			close(fd);
		}
		i++;
	}
}
