/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:30:22 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/19 18:53:13 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_the_header.h"

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
		ft_putendl_fd("header is wrong (name's part)", 2);
	if (version == 2)
	{
		ft_putstr_fd("the magic number is not equal to 0x", 2);
		ft_puthex_fd(COREWAR_EXEC_MAGIC, 2);
		ft_putchar_fd('\n', 2);
	}
	if (version == 3)
		ft_putendl_fd("the end of name's part is not equal to zero", 2);
	if (version == 5)
		ft_putendl_fd("header is wrong (description's part)", 2);
	if (version == 6)
		ft_putendl_fd("the end of description's part is not equal to zero", 2);
	return (ERROR);
}

static int		check_the_name(t_mem *mem, int fd, unsigned int i)
{
	unsigned char	buf[4 + PROG_NAME_LENGTH + 4 + 1];
	ssize_t			length;

	ft_bzero(buf, (4 + PROG_NAME_LENGTH + 4 + 1) * sizeof(unsigned char));
	if ((length = read(fd, buf, 4 + PROG_NAME_LENGTH + 4)) == ERROR)
		return (ft_putstr_error_cant_t_read(mem, i));
	if (length != (4 + PROG_NAME_LENGTH + 4))
		return (ft_putstr_error_header(1));
	if ((0x1000000 * buf[0])
			+ (0x10000 * buf[1])
			+ (0x100 * buf[2])
			+ buf[3] != COREWAR_EXEC_MAGIC)
		return (ft_putstr_error_header(2));
	if ((0x1000000 * buf[4 + PROG_NAME_LENGTH])
			+ (0x10000 * buf[4 + PROG_NAME_LENGTH + 1])
			+ (0x100 * buf[4 + PROG_NAME_LENGTH + 2])
			+ buf[4 + PROG_NAME_LENGTH + 3] != 0x00000000)
		return (ft_putstr_error_header(3));
	ft_strmove(mem->champ[i].name, (char *)(buf + 4));
	return (SUCCESS);
}

static int		check_the_description(t_mem *mem, int fd, unsigned int i,
		ssize_t *length_code)
{
	unsigned char	buf[4 + COMMENT_LENGTH + 4 + 1];
	ssize_t			length;

	ft_bzero(buf, (4 + COMMENT_LENGTH + 4 + 1) * sizeof(unsigned char));
	if ((length = read(fd, buf, 4 + COMMENT_LENGTH + 4)) == ERROR)
		return (ft_putstr_error_cant_t_read(mem, i));
	if (length != (4 + COMMENT_LENGTH + 4))
		return (ft_putstr_error_header(5));
	*length_code =
		(0x1000000 * buf[0]) + (0x10000 * buf[1]) + (0x100 * buf[2]) + buf[3];
	if ((0x1000000 * buf[4 + COMMENT_LENGTH])
			+ (0x10000 * buf[4 + COMMENT_LENGTH + 1])
			+ (0x100 * buf[4 + COMMENT_LENGTH + 2])
			+ buf[4 + COMMENT_LENGTH + 3] != 0x00000000)
		return (ft_putstr_error_header(6));
	ft_strmove(mem->champ[i].description, (char *)(buf + 4));
	return (SUCCESS);
}

int				check_the_header(t_mem *mem, int fd, unsigned int i,
		ssize_t *length_code)
{
	if (check_the_name(mem, fd, i) == ERROR)
		return (ERROR);
	if (check_the_description(mem, fd, i, length_code) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
