# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 20:35:02 by spark2            #+#    #+#              #
#    Updated: 2023/09/29 15:57:48 by spark2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_strlen.c ft_memset.c ft_strncmp.c \
 ft_strchr.c ft_strdup.c ft_strjoin.c ft_split.c

OBJS = $(SRCS:.c=.o)

INCLUDE = libft.h

CC = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $@ $^

%.o : %.c
	$(CC) -c $< -o $@ -I $(INCLUDE)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
