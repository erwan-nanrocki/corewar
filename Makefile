# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enanrock <marvin42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 11:41:31 by enanrock          #+#    #+#              #
#    Updated: 2017/12/03 14:48:17 by enanrock         ###   ########.fr        #
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

.PHONY: all leaks clean fclean re norme victory where_is_malloc tuto_corewar

all: $(LIB) author .gitignore .gitmodules
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_001)
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_002)

$(NAME_001): $(LIB)
	@make $(addprefix ../, $@) -C dir_of_makefile -f Makefile_$@

$(NAME_002): $(LIB)
	@make $(addprefix ../, $@) -C dir_of_makefile -f Makefile_$@

leaks:
	clear
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_001)
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_002)

clean: $(LIB)
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_001)
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_002)
ifneq ("$(OBJ_DIR)", "./")
	@echo "\033[1;31m""\c"
	@rm -fdv $(OBJ_DIR)
	@echo "\033[m""\c"
endif

fclean: $(LIB)
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_001)
	@make $@ -C dir_of_makefile -f Makefile_$(NAME_002)
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
	@echo "\033[m"

.gitmodules:
	@echo "\033[1;37m""\c"
	echo '[submodule "libft"]'                           > $@
	echo '	path = libft'                                >> $@
	echo '	url = git://github.com/erwan-nanrocki/libft' >> $@
	@echo "\033[m"

.gitignore:
	@echo "\033[1;37m""\c"
	echo "$(OBJ_DIR)"   > $@
	echo "$(NAME_ALL)" >> $@
	echo "*.swp"       >> $@
	echo "*.o"         >> $@
	echo "*.a"         >> $@
	echo "*.cor"       >> $@
	echo "*_DONE"      >> $@
	@echo "\033[m"

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

tuto_corewar:
	clear
	@echo "( ^v^ )/ < Hi !"
	@read
	clear
	@echo "( O.O )  < I'll explain how work the vm (virtuel machine)"
	@read
	clear
	@echo "( o.o )  < The vm simulate a processor who run several process\c"
	@read
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
	@echo "00 \033[7m00\033[m 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "\033[7m00\033[m 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@read
	clear
	@echo "( o_o )  < The vm simulate a processor who run several process"
	@echo "           here 1 processor, 2 process and some code (in hex)"
	@echo ""
	@echo "00 \033[7m01\033[m ff ff ff ff 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "\033[7m01\033[m ff ff ff fe 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
	@echo "00 00 00 00 00 00 00 00 00 00"
