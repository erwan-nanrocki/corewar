/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_and_complete_memory_space.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:20:35 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/19 19:13:44 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files_and_complete_memory_space.h"

static int		ft_putstr_error_no_code(t_mem *mem, unsigned int i)
{
	ft_putstr_fd("\033[31m""ERROR""\033[m"" : the champion \"", 2);
	ft_putstr_fd(mem->champ[i].file, 2);
	ft_putstr_fd("\" have no code, and it's sad \033[1;36m"":'(""\033[m\n", 2);
	return (ERROR);
}

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

int				complete_memory_space(t_mem *mem, int fd, unsigned int i,
		void *destination_of_champ_code)
{
	unsigned char	buf[CHAMP_MAX_SIZE + 1];
	ssize_t			length_code;
	ssize_t			length_read;

	if (check_the_header(mem, fd, i, &length_code) == ERROR)
		return (ERROR);
	ft_bzero(buf, (CHAMP_MAX_SIZE + 1) * sizeof(unsigned char));
	if ((length_read = read(fd, buf, CHAMP_MAX_SIZE + 1)) == ERROR)
		return (ft_putstr_error_cant_t_read(mem, i));
	if (length_read > CHAMP_MAX_SIZE)
		return (ft_putstr_error_too_fat(mem, i));
	if (length_read == 0)
		return (ft_putstr_error_no_code(mem, i));
	if (length_read != length_code)
	{
		ft_putstr_fd("\033[31m""ERROR""\033[m"" : ", 2);
		ft_putstr_fd("the size in the description's part is not egual to ", 2);
		ft_putendl_fd("the real size of the code", 2);
		return (ERROR);
	}
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
