# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enanrock <marvin42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 11:41:31 by enanrock          #+#    #+#              #
#    Updated: 2018/01/11 15:59:41 by enanrock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = corewar
NAME_001 = $(NAME)
NAME_002 = asm
NAME_ALL = $(NAME_001) $(NAME_002)

LIBFT_DIR = ./libft/
SRC_DIR   = ./srcs/
OBJ_DIR   = ./objs/
HDR_DIR   = ./includes/

LIB = $(addsuffix Makefile, $(LIBFT_DIR))

.PHONY: all leaks clean fclean re norme victory where_is_malloc tuto           \
		tuto_corewar

all: $(LIB) author .gitignore .gitmodules
#	@make $@ -C dir_of_makefile -f Makefile_$(NAME_001)
#	@make $@ -C dir_of_makefile -f Makefile_$(NAME_002)

$(NAME_001): $(LIB)
#	@make $(addprefix ../, $@) -C dir_of_makefile -f Makefile_$@

$(NAME_002): $(LIB)
#	@make $(addprefix ../, $@) -C dir_of_makefile -f Makefile_$@

leaks:
	clear
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_001)
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_002)

clean: $(LIB)
#	@make $@ -C dir_of_makefile -f Makefile_$(NAME_001)
#	@make $@ -C dir_of_makefile -f Makefile_$(NAME_002)
ifneq ("$(OBJ_DIR)", "./")
	@echo "\033[1;31m""\c"
	@rm -fdv $(OBJ_DIR)
	@echo "\033[m""\c"
endif

fclean: $(LIB)
#	@make $@ -C dir_of_makefile -f Makefile_$(NAME_001)
#	@make $@ -C dir_of_makefile -f Makefile_$(NAME_002)
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
	echo "fmasiala" >> author
	echo "mbenjell" >> author
	@echo "\033[m"

.gitmodules:
	@echo "\033[1;37m""\c"
	echo '[submodule "libft"]'                            > $@
	echo '	path = libft'                                >> $@
	echo '	url = git://github.com/erwan-nanrocki/libft' >> $@
	@echo "\033[m"

.gitignore:
	@echo "\033[1;37m""\c"
	echo "$(OBJ_DIR)"   > $@
	echo "$(NAME_001)" >> $@
	echo "$(NAME_002)" >> $@
	echo "*.swp"       >> $@
	echo "*.o"         >> $@
	echo "*.a"         >> $@
	echo "*.cor"       >> $@
	echo "*_DONE"      >> $@
	@echo "\033[m"

reset:
	rm -Rf author
	rm -Rf .gitmodules
	rm -Rf .gitignore
	rm -Rf $(LIBFT_DIR)
	mkdir $(LIBFT_DIR)

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

victory:
	@echo "\r  ( '_' )           < .                                    \c"
	@sleep 1
	@echo "\r  ( -_- )           < ..                                   \c"
	@sleep 0.2
	@echo "\r  ( '_' )           < ...                                  \c"
	@sleep 1.5
	@echo "\r  ( ^_^ )           < cool, you did it !                   \c"
	@sleep 3
	@echo "\r  /)^3^(\           < So Awesome !                         \c"
	@sleep 3
	@num=1;\
		while [[ $$num -le 50 ]];do\
		echo "\r ʕ•̫͡•ʕ*̫͡*ʕ•͓͡•ʔʕ•̫͡•ʔ*̫͡*ʔ  < The local crowd into a frenzy        \c";\
		sleep 0.1;\
		echo "\r  ʕ•̫͡•ʕ*̫͡*ʕ•͓͡•ʔʕ•̫͡•ʔ*̫͡*ʔ < The local crowd into a frenzy        \c";\
		sleep 0.1;\
		((num = num + 1));\
		done
	@echo "\r ᕦ(ˇò_ó)ᕤ           < You're the best !                    \c"
	@sleep 3
	@num=1;\
		while [[ $$num -le 20 ]];do\
		echo "\r | ( ^.^ ) |        < Dance                                \c";\
		sleep 0.1;\
		echo "\r  /(  ^.^)  /       <        to                            \c";\
		sleep 0.1;\
		echo "\r | ( ^.^ ) |        <           death                      \c";\
		sleep 0.1;\
		echo "\r\  (^.^  )\         <                 !                    \c";\
		sleep 0.1;\
		((num = num + 1));\
		done
	@echo "\r \ (O.O  )\         < oops...                              \c"
	@sleep 1.5
	@echo "\r  ( ╥﹏╥ )          < Time to work now...                  \c"

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
