# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enanrock <marvin42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 11:41:31 by enanrock          #+#    #+#              #
#    Updated: 2018/04/20 01:30:37 by mbenjell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= corewar
NAME_001	:= $(NAME)
NAME_ALL	:= $(NAME_001)

LIBFT_DIR	:= ./libft/
SRC_DIR		:= ./sources/
OBJ_DIR		:= ./objects/
HDR_DIR		:= ./includes/

LIB			:= $(addsuffix Makefile, $(LIBFT_DIR))

.PHONY:	all clean fclean re always_do_it leaks norme where_is_malloc           \
		tuto tuto_corewar
all: $(LIB) $(NAME_ALL)

$(NAME_001): $(LIB) always_do_it
	@make $@ -C Makefiles

clean: $(LIB)
	@make $@ -C Makefiles
ifneq ("$(OBJ_DIR)", "./")
	@echo "\033[1;31m""\c"
	@rm -fdv $(OBJ_DIR)
	@echo "\033[m""\c"
endif

fclean: $(LIB)
	@make $@ -C Makefiles
ifneq ("$(OBJ_DIR)", "./")
	@echo "\033[1;31m""\c"
	@rm -fdv $(OBJ_DIR)
	@echo "\033[m""\c"
endif

re:
	@make fclean
	@make all

where_is_malloc: $(LIB)
	@make $@ -C ./libft/

$(LIB):
	git clone https://github.com/erwan-nanrocki/libft.git $(LIBFT_DIR)

author:
	@echo "\033[1;37m""\c"
	echo "enanrock"  > author
	echo "mbenjell" >> author
	echo "mbriffau" >> author
	@echo "\033[m"

leaks:
	clear
	leaks $(NAME_001)

norme: $(LIB)
	@make norme -C $(LIBFT_DIR)
	@echo "\033[1;37m""norminette on $(SRC_DIR)""\033[m"
	@norminette $(SRC_DIR)                               \
		| sed ''s/Error/`echo "\033[0;31mError"`/g''     \
		| sed ''s/Warning/`echo "\033[0;33mWarning"`/g'' \
		| sed ''s/Norme/`echo "\033[0;32mNorme"`/g''
	@echo "\033[1;37m""norminette on $(HDR_DIR)""\033[m"
	@norminette $(HDR_DIR)                               \
		| sed ''s/Error/`echo "\033[0;31mError"`/g''     \
		| sed ''s/Warning/`echo "\033[0;33mWarning"`/g'' \
		| sed ''s/Norme/`echo "\033[1;34mNorme"`/g''
	@echo "\033[m""\c"

tuto:
	@echo "do make tuto_corewar"

tuto_corewar:
	clear
	@echo "( ^v^ )/ < Hi !"
	@read
	clear
	@echo "( O.O )  < I'll explain how work the vm (virtuel machine)"
	@read
	clear
	@echo "( o.o )  < The vm simulate a processor who run several process."
	@echo "           here 1 processor..."
	@echo ""
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@read
	clear
	@echo "( o_o )  < The vm simulate a processor who run several process"
	@echo "           here 1 processor, 2 process..."
	@echo ""
	@echo "00 \033[41m00\033[m 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "\033[42m00\033[m 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo ""
	@echo "\033[31m[ 0.0 ] < i am the process ff ff ff ff"
	@echo "\033[32m[ +_+ ] < i am the process ff ff ff fe"
	@read
	clear
	@echo "\033[m( o_o )  < The vm simulate a processor who run several process"
	@echo "           here 1 processor, 2 process and some code (in hex)"
	@echo "\033[m"
	@echo "00 \033[41;1m01\033[m\033[1m ff ff ff ff\033[m 09 ff fb 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "\033[42;1m01\033[m\033[1m ff ff ff fe\033[m 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo ""
	@echo "\033[31m[ 0.0 ] < stil the process ff ff ff ff"
	@echo "\033[32m[ +_+ ] < stil the process ff ff ff fe"
	@read
	clear
	@echo "\033[31m[ 0.0 ] < i took 10 cycle to execute 01 ff ff ff ff (= live)"
	@echo "\033[32m[ +_+ ] < i took 10 cycle to execute 01 ff ff ff fe (= live)"
	@echo "\033[m"
	@echo "00 01 ff ff ff ff \033[41;1m09\033[m\033[1m ff fb\033[m 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "01 ff ff ff fe \033[42;1m00\033[m 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@read
	clear
	@echo "\033[31m[ 0.0 ] < i took  1 cycle ..."
	@echo "\033[32m[ +_+ ] < i took  1 cycle ..."
	@echo "\033[m"
	@echo "00 01 ff ff ff ff \033[41;1m09\033[m\033[1m ff fb\033[m 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "01 ff ff ff fe 00 \033[42;1m00\033[m 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@read
	clear
	@echo "\033[31m[ 0.0 ] < i took  2 cycles ..."
	@echo "\033[32m[ +_+ ] < i took  2 cycle  ..."
	@echo "\033[m"
	@echo "00 01 ff ff ff ff \033[41;1m09\033[m\033[1m ff fb\033[m 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "01 ff ff ff fe 00 00 \033[42;1m00\033[m 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@read
	clear
	@echo "\033[31m[ 0.0 ] < i took  5 cycles ..."
	@echo "\033[32m[ +_+ ] < i took  5 cycles ..."
	@echo "\033[m"
	@echo "00 01 ff ff ff ff \033[41;1m09\033[m\033[1m ff fb\033[m 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "01 ff ff ff fe 00 00 00 00 00"
	@echo "\033[42;1m00\033[m 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@read
	clear
	@echo "\033[31m[ 0.0 ] < i took 10 cycles ..."
	@echo "\033[32m[ +_+ ] < i took 10 cycles ..."
	@echo "\033[m"
	@echo "00 01 ff ff ff ff \033[41;1m09\033[m\033[1m ff fb\033[m 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "01 ff ff ff fe 00 00 00 00 00"
	@echo "00 00 00 00 00 \033[42;1m00\033[m 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@read
	clear
	@echo "\033[31m[ 0.0 ] < i took 20 cycles to execute 09 ff fb (= zjmp -5)"
	@echo "\033[32m[ +_+ ] < i took 20 cycles to skip twenty 00"
	@echo "\033[m"
	@echo "00 01 ff ff ff ff 09 ff fb \033[m\033[41;1m00\033[m"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "01 ff ff ff fe 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 \033[42;1m00\033[m 00 00 00 00"
