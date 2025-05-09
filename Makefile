# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 10:47:57 by ffebbrar          #+#    #+#              #
#    Updated: 2025/05/09 10:47:57 by ffebbrar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ift_printf

SRC = chunk_sort.c elem_list.c main_sorter.c stack_ops.c sort_utils.c \
	input_validation.c string_utils.c args_parser.c small_sort.c \
	ft_printf/ft_printf.c ft_printf/ft_printf_u.c ft_printf/ft_printf_esa.c \
	ft_printf/ft_printf_fun.c ft_printf/ft_printf_p.c \
	extra_utils.c \
	arg_helper.c \
	array_utils.c \
	sort_three_utils.c \
	sort_four_five.c \
	chunk_utils.c \

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)