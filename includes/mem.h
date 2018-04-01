/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:27:46 by enanrock          #+#    #+#             */
/*   Updated: 2018/03/29 03:35:54 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include "op.h"
# include "libft.h"

# define YES          1
# define NOPE         0

# define TRUE         1
# define FALSE        0

# define DUMP_NOPE    0
# define DUMP_SIMPLE  1
# define DUMP_MULTI   2

# define ERROR       -1
# define SUCCESS      0

# define NO_DIFF      0

# define ACB_RRR      (REG_CODE * 64 + REG_CODE * 16 + REG_CODE * 4)
# define ACB_RRD      (REG_CODE * 64 + REG_CODE * 16 + DIR_CODE * 4)
# define ACB_RRI      (REG_CODE * 64 + REG_CODE * 16 + IND_CODE * 4)
# define ACB_RDR      (REG_CODE * 64 + DIR_CODE * 16 + REG_CODE * 4)
# define ACB_RDD      (REG_CODE * 64 + DIR_CODE * 16 + DIR_CODE * 4)
# define ACB_RDI      (REG_CODE * 64 + DIR_CODE * 16 + IND_CODE * 4)
# define ACB_RIR      (REG_CODE * 64 + IND_CODE * 16 + REG_CODE * 4)
# define ACB_RID      (REG_CODE * 64 + IND_CODE * 16 + DIR_CODE * 4)
# define ACB_RII      (REG_CODE * 64 + IND_CODE * 16 + IND_CODE * 4)

# define ACB_DRR      (DIR_CODE * 64 + REG_CODE * 16 + REG_CODE * 4)
# define ACB_DRD      (DIR_CODE * 64 + REG_CODE * 16 + DIR_CODE * 4)
# define ACB_DRI      (DIR_CODE * 64 + REG_CODE * 16 + IND_CODE * 4)
# define ACB_DDR      (DIR_CODE * 64 + DIR_CODE * 16 + REG_CODE * 4)
# define ACB_DDD      (DIR_CODE * 64 + DIR_CODE * 16 + DIR_CODE * 4)
# define ACB_DDI      (DIR_CODE * 64 + DIR_CODE * 16 + IND_CODE * 4)
# define ACB_DIR      (DIR_CODE * 64 + IND_CODE * 16 + REG_CODE * 4)
# define ACB_DID      (DIR_CODE * 64 + IND_CODE * 16 + DIR_CODE * 4)
# define ACB_DII      (DIR_CODE * 64 + IND_CODE * 16 + IND_CODE * 4)

# define ACB_IRR      (IND_CODE * 64 + REG_CODE * 16 + REG_CODE * 4)
# define ACB_IRD      (IND_CODE * 64 + REG_CODE * 16 + DIR_CODE * 4)
# define ACB_IRI      (IND_CODE * 64 + REG_CODE * 16 + IND_CODE * 4)
# define ACB_IDR      (IND_CODE * 64 + DIR_CODE * 16 + REG_CODE * 4)
# define ACB_IDD      (IND_CODE * 64 + DIR_CODE * 16 + DIR_CODE * 4)
# define ACB_IDI      (IND_CODE * 64 + DIR_CODE * 16 + IND_CODE * 4)
# define ACB_IIR      (IND_CODE * 64 + IND_CODE * 16 + REG_CODE * 4)
# define ACB_IID      (IND_CODE * 64 + IND_CODE * 16 + DIR_CODE * 4)
# define ACB_III      (IND_CODE * 64 + IND_CODE * 16 + IND_CODE * 4)

# define ACB_RR       (REG_CODE * 64 + REG_CODE * 16)
# define ACB_RD       (REG_CODE * 64 + DIR_CODE * 16)
# define ACB_RI       (REG_CODE * 64 + IND_CODE * 16)
# define ACB_DR       (DIR_CODE * 64 + REG_CODE * 16)
# define ACB_DD       (DIR_CODE * 64 + DIR_CODE * 16)
# define ACB_DI       (DIR_CODE * 64 + IND_CODE * 16)
# define ACB_IR       (IND_CODE * 64 + REG_CODE * 16)
# define ACB_ID       (IND_CODE * 64 + DIR_CODE * 16)
# define ACB_II       (IND_CODE * 64 + IND_CODE * 16)

# define ACB_R       (REG_CODE * 64)
# define ACB_D       (DIR_CODE * 64)
# define ACB_I       (IND_CODE * 64)

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
	int				option_leaks;
	t_op_plus		op_tab[256];
}					t_mem;

#endif
