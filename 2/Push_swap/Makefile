# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 19:35:53 by spark2            #+#    #+#              #
#    Updated: 2023/08/04 17:53:07 by spark2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c ft_strdup.c ft_strchr.c ft_strlen.c ft_strjoin.c ft_split_org.c \
check_valid.c ft_atoi.c ft_lstnew.c ft_lstlast.c ft_lstadd_back.c \
stack_command.c


OBJS = $(SRCS:.c=.o)

INCLUDE = push_swap.h

CC = cc -Wall -Wextra -Werror
# CC = cc -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -c $< -o $@ -I $(INCLUDE)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re