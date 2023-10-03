NAME = pipex
BONUS_NAME = pipex_bonus

SRCS = $(wildcard M*.c)
BONUS_SRCS = $(wildcard *bonus.c) $(wildcard get_next_line/*.c)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc -Wall -Werror -Wextra -g

LIBFT = ./libft/libft.a
# GNL = ./get_next_line

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ -L ./libft -lft

$(BONUS_NAME) : $(BONUS_OBJS) $(LIBFT)
	$(CC) -o $@ $^ -L ./libft -lft

$(LIBFT) :
	make -C ./libft all

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)
	make -C ./libft clean

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)
	make -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re bonus