# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 19:35:53 by spark2            #+#    #+#              #
#    Updated: 2023/08/28 12:50:37 by spark2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

BONUS_DIR = ./push_swap_bonus/

SRCS = array.c command_1.c command_2.c command_3.c free.c greedy.c hard_coding.c \
lst_func.c main.c move.c pivot_indexing.c set_min_top.c setting.c sort_2345_element.c utils.c
SRCS_BONUS = $(BONUS_DIR)array_bonus.c $(BONUS_DIR)command_1_bonus.c $(BONUS_DIR)command_2_bonus.c \
$(BONUS_DIR)command_3_bonus.c $(BONUS_DIR)error_bonus.c $(BONUS_DIR)free_bonus.c \
$(BONUS_DIR)get_next_line.c $(BONUS_DIR)get_next_line_utils.c $(BONUS_DIR)lst_func_bonus.c \
$(BONUS_DIR)main_bonus.c $(BONUS_DIR)numbering_bonus.c $(BONUS_DIR)run_command_bonus.c \
$(BONUS_DIR)setting_bonus.c $(BONUS_DIR)utils_bonus.c

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