NAME = pipex

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Werror -Wextra -g #-fsanitize=address

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ -L ./libft -lft

$(LIBFT) :
	@make -C ./libft all

%.o : %.c
	@$(CC) -c $< -o $@

clean :
	rm -rf $(OBJS)
	@make -C ./libft clean

fclean : clean
	rm -rf $(NAME)
	@make -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re