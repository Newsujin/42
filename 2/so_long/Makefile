# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 18:32:50 by spark2            #+#    #+#              #
#    Updated: 2023/08/01 21:02:14 by spark2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c check.c set_mlx.c image.c path.c key.c \
get_next_line.c get_next_line_utils.c ft_split.c utils.c

OBJS = $(SRCS:.c=.o)

INCLUDE = so_long.h

CC = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o : %.c
	make -C ./mlx
	$(CC) -Imlx -c $< -o $@ -I $(INCLUDE)

clean :
	make -C ./mlx clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
