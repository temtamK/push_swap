# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 16:04:02 by taemkim           #+#    #+#              #
#    Updated: 2021/06/01 00:08:15 by taemkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CHECKER = checker
SWAP = push_swap
SRC_PATH = srcs
HDR_PATH = includes
OBJ_PATH = obj
SWAP_PATH= $(OBJ_PATH)/swap_srcs


SRC_CODE= swap_srcs/errors.c\
			swap_srcs/simple_free.c\
			swap_srcs/use_libft1.c\
			swap_srcs/use_libft.c\
			swap_srcs/list_op.c\
			swap_srcs/to_use.c\
			swap_srcs/initial.c\
			swap_srcs/gen_sort.c\
			swap_srcs/list.c\
			swap_srcs/moves.c\
			swap_srcs/ok_ko.c\
			swap_srcs/algo_d.c\
			swap_srcs/algo_disp.c\
			swap_srcs/algo_min_d.c\
			swap_srcs/print.c\
			swap_srcs/swap_disp.c\
			swap_srcs/algo_500_c.c\
			swap_srcs/algo_min_c.c\
			swap_srcs/algo_c.c\
			swap_srcs/orderby.c\
			swap_srcs/checker_rd.c\
			swap_srcs/algo.c\
			swap_srcs/algo_use.c\
			swap_srcs/algo_500.c\
			swap_srcs/algo_min.c\
			swap_srcs/swap_case.c\
			swap_srcs/swap_op.c\
			swap_srcs/option_v.c\
			swap_srcs/algo_norm.c\
			swap_srcs/moves_nor.c\

SRC_CHECKER= checker.c  $(SRC_CODE)
SRC_SWAP=  swap.c $(SRC_CODE)
HDR_NAME= push_swap.h

OBJ_CHECKER= $(SRC_CHECKER:.c=.o)
OBJ1= $(addprefix $(OBJ_PATH)/,$(OBJ_CHECKER))
SRC1= $(addprefix $(SRC_PATH)/,$(SRC_CHECKER))

OBJ_SWAP= $(SRC_SWAP:.c=.o)
OBJ2= $(addprefix $(OBJ_PATH)/,$(OBJ_SWAP))
SRC2= $(addprefix $(SRC_PATH)/,$(SRC_SWAP))

HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))
FLAGS= -Wall -Wextra -Werror
H_FLAG= -I $(HDR_PATH)

COMP= gcc -g

all: $(CHECKER) $(SWAP)

$(CHECKER) :  $(OBJ1)
	@rm -rf $(CHECKER)
	@$(COMP) $(H_FLAG) $(OBJ1) -o $@
	@echo "	Compilation of  $(CHECKER):  \033[1;32mOK\033[m"

$(SWAP) : $(OBJ2)
	@rm -rf $(SWAP)
	@$(COMP)  $(H_FLAG) $(OBJ2) -o $@
	@echo "	Compilation of $(SWAP):  \033[1;32mOK\033[m"

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) $(SWAP_PATH)
	@$(COMP)  $(FLAGS) $(H_FLAG)  -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;33m>> all .o files are deleted.\033[0m"

fclean: clean
	@rm -rf $(CHECKER)
	@echo "\033[0;31m>> $(CHECKER)all obbjects are deleted.\033[0m"
	@rm -rf $(SWAP)
	@echo "\033[0;31m>> $(SWAP) all obbjects are deleted.\033[0m"

re : fclean all
