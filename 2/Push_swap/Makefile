# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 19:35:53 by spark2            #+#    #+#              #
#    Updated: 2023/06/29 16:34:31 by spark2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

INCLUDE = push_swap.h

LIBFT = ./libft/libft.a

CC = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	ar -rc $@ $^

%.o : %.c
	$(CC) -c $< -o $@ -I $(INCLUDE)

clean :
	make -C ./libft fclean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re