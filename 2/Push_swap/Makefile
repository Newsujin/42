# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 19:35:53 by spark2            #+#    #+#              #
#    Updated: 2023/08/24 22:29:47 by spark2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard *.c)

SRCS_BONUS = $(wildcard ./bonus/*.c)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS: .c=.o)

INCLUDE = push_swap.h
#bonus의 헤더는 어케 참조?

CC = cc -g -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^

bonus : $(OBJS) $(OBJS_BONUS)
	ar -rc $(NAME) $(OBJS) $(OBJS_BONUS)
	touch bonus
#touch ok?

%.o : %.c
	$(CC) -c $< -o $@ -I $(INCLUDE)

clean :
	rm -rf $(OBJS)
	rm -f bonus

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re