# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 19:35:53 by spark2            #+#    #+#              #
#    Updated: 2023/08/06 17:41:39 by spark2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

INCLUDE = push_swap.h

CC = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^

%.o : %.c
# make -C ./libft
	$(CC) -c $< -o $@ -I $(INCLUDE)

clean :
# make -C ./libft clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re