# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaiane <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 02:06:03 by jaiane            #+#    #+#              #
#    Updated: 2025/04/16 02:08:32 by jaiane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = algorithms/small_helpers.c  algorithms/small_set.c algorithms/big_helpers.c algorithms/big_set.c algorithms/sort_stack.c \
		input/utils.c input/validation.c input/parse.c \
		operations/basic.c operations/shared.c operations/stack_a.c operations/stack_b.c \
		stack_utils.c main.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libs/libft
LIBFT_A = $(LIBFT_DIR)/libft.a
LIBS = -Llibs/libft -llibft

NAME = push_swap

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libs/libft clean

fclean: clean
	rm -f $(NAME)
	make -C libs/libft fclean

re: fclean all

.PHONY: all clean fclean re
