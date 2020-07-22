# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slisandr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:25:21 by slisandr          #+#    #+#              #
#    Updated: 2020/02/26 12:34:10 by slisandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re libftprintf norm push_swap checker test

CC = gcc
CFLAGS = -Wall -Werror -Wextra

# --------------- PUSH_SWAP: PREREQUISITES ------------------

EXEC_PS = push_swap.out

SRC_DIR_PS = src/push_swap
SRC_RAW_PS = \
		swap.c \
		swap_both.c \
		push.c \
		rotate.c \
		rotate_both.c \
		reverse_rotate.c \
		reverse_rotate_both.c \
		init_stack.c \
		print_stack.c
SRC_PS = $(addprefix $(SRC_DIR_PS)/,$(SRC_RAW_PS))

OBJ_DIR = obj
OBJ_PS = $(addprefix $(OBJ_DIR)/,$(SRC_RAW_PS:.c=.o))

MAIN_RAW_PS = main.c
MAIN_PS = $(addprefix $(SRC_DIR_PS)/,$(MAIN_RAW_PS))

# --------------- PUSH_SWAP: COMPILATION --------------------

all: push_swap

push_swap: libftprintf $(OBJ_DIR) $(OBJ_PS)
	$(CC) $(CFLAGS) -o $(EXEC_PS) $(OBJ_PS) $(MAIN_PS) \
		-I "includes/" \
		-I "ft_printf/includes/" \
		-I "ft_printf/libft/includes/" \
		-L "ft_printf/" -lftprintf \
		-L "ft_printf/libft/" -lft
$(OBJ_DIR)/%.o: $(SRC_DIR_PS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ \
		-I "includes/" \
		-I "ft_printf/includes/" \
		-I "ft_printf/libft/includes/" 
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
libftprintf:
	@ make -C ft_printf/

# --------------- CLEANUP -----------------------------------

clean:
	@ rm -rf $(OBJ_DIR)
	@ make -C ft_printf/ clean
	@ make -C ft_printf/libft/ clean
fclean: clean
	@ rm -f $(EXEC_PS)
	@ make -C ft_printf/libft/ fclean

# --------------- OTHER -------------------------------------

re: fclean all

norm: fclean
	@ make -C ft_printf/ norm
	@ make -C ft_printf/libft/ norm
	@ norminette includes/ src/
test: all
	@ ceedling
