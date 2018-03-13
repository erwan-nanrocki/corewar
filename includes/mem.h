/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:27:46 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/13 00:48:17 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include "op.h"
# include "libft.h"

# define YES                   1
# define NOPE                  0

# define TRUE                  1
# define FALSE                 0

# define DUMP_NOPE             0
# define DUMP_SIMPLE           1
# define DUMP_MULTI            2

# define ERROR                -1
# define SUCCESS               0

# define BUF_SIZE   (CHAMP_MAX_SIZE + 4 + PROG_NAME_LENGTH + COMMENT_LENGTH+ 4)

typedef	struct		s_local_memory
{
	unsigned char	registers[REG_NUMBER][REG_SIZE];
	unsigned char	program_counter[REG_SIZE];
	int				carry;
	unsigned char	opcode;
	unsigned int	cycle_countdown;
}					t_local_memory;

typedef	struct		s_champ
{
	char			*file;
	char			name[PROG_NAME_LENGTH + 1];
	char			description[COMMENT_LENGTH + 1];
	unsigned char	id[REG_SIZE];
	int				id_perso;
	unsigned int	last_live;
}					t_champ;

typedef	struct		s_mem
{
	unsigned char	memory_space[MEM_SIZE];
	t_list			*process;
	unsigned int	number_champ;
	t_champ			champ[MAX_PLAYERS];
	unsigned int	current_cycle_to_die;
	unsigned int	deadline_to_die;
	unsigned int	current_nbr_live;
	unsigned int	cycles;
	int				option_aff;
	int				option_dump;
	unsigned int	value_dump;
}					t_mem;

#endif
