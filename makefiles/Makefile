# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enanrock <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/26 06:35:09 by enanrock          #+#    #+#              #
#    Updated: 2018/04/19 19:45:58 by enanrock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= corewar

FILES		:= main help_corewar set_options set_champ set_process change_op   \
			open_files_and_complete_memory_space convert_pc_to_uint do_op      \
			cycle_plus_plus set_op_tab dump test_argument_coding_bytes         \
			live ld st add sub and or xor zjmp ldi sti fork_e lld lldi lfork_e \
			aff secure_define check_the_header

LIBFT_DIR	:= ../libft/
SRC_DIR		:= ../sources/
OBJ_DIR		:= ../objects/
HDR_DIR		:= ../includes/
DEP_DIR		:= ../dependencies/

SRC			:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ			:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
DEP			:= $(addprefix $(DEP_DIR), $(addsuffix .d, $(FILES)))

LIB_FLAGS	:= -L$(LIBFT_DIR) -lft

GCC_FLAGS	:= -Wall -Wextra -Werror -I$(HDR_DIR) -I$(LIBFT_DIR)

.PHONY:	all leaks clean fclean re always_do_it

all: ../$(NAME)

leaks:
	leaks $(NAME)

$(LIBFT_DIR)libft.a: always_do_it
	@make libft.a -C $(LIBFT_DIR)

$(NAME): ../$(NAME)

../$(NAME): $(LIBFT_DIR)libft.a $(OBJ)
	@gcc $(GCC_FLAGS) $(LIB_FLAGS) $^ -o $@
	@echo "\033[0;32m""created: $@""\033[m"
	@echo "\033[1;36m""flags i use are ""\033[0;36m""$(GCC_FLAGS)""\033[m"
	@echo "\033[1;36m""and ""\033[0;36m""$(LIB_FLAGS)""\033[1;36m"" too, ""\c"
	@echo "but only when i link $@""\033[m"
	@cp $@ ../../$@

$(DEP_DIR)%.d: $(SRC_DIR)%.c
	@mkdir -p $(DEP_DIR) 2> /tmp/a.del
	@mkdir -p $(OBJ_DIR) 2> /tmp/a.del
	@gcc $(GCC_FLAGS) -MM $< -MT $(<:$(SRC_DIR)%c=$(OBJ_DIR)%o) -MF $@
	@echo "	@gcc $(GCC_FLAGS) -c $< -o $(@:$(DEP_DIR)%d=$(OBJ_DIR)%o)"     >> $@
	@echo "	@echo \"\\\033[0;33m\"\"\c"                                    >> $@
	@echo "created: $(@:$(DEP_DIR)%d=$(OBJ_DIR)%o)\"\c"                    >> $@
	@echo "\"\\\033[m\""                                                   >> $@
	@echo ""                                                               >> $@
#	@cat $@

-include $(DEP)

clean:
	@echo "\033[0;31m""deleted all these files :""\033[m"
	@make $@ -C $(LIBFT_DIR)
	@echo "\033[1;31m""\c"
	@rm -fv $(OBJ) | column
	@rm -dv $(OBJ_DIR) | column
	@rm -fv $(DEP) | column
	@rm -dv $(DEP_DIR) | column
	@echo "\033[m""\c"

fclean:
	@make clean
	@make $@ -C $(LIBFT_DIR)
	@echo "\033[0;31m""\c"
	@rm -fv ../$(NAME)
	@echo "\033[m""\c"

re:
	@make fclean
	@make all
