# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 19:35:53 by spark2            #+#    #+#              #
#    Updated: 2023/08/25 21:43:12 by spark2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

HEADER = push_swap.h

SRCS = $(wildcard *.c)
SRCS_BONUS = $(wildcard ./push_swap_bonus/*.c)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDE = push_swap.h

CC = cc -Wall -Wextra -Werror

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re bonus