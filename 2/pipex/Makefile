NAME = pipex
BONUS_NAME = pipex_bonus

SRCS = M_check.c M_free.c M_main.c M_path.c M_run.c M_set_cmd.c
BONUS_SRCS = B_check_bonus.c B_free_bonus.c B_here_doc_bonus.c B_main_bonus.c \
B_path_bonus.c B_pipe_stream_bonus.c B_run_bonus.c B_set_cmd_bonus.c \
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc -Wall -Werror -Wextra -g

LIBFT = ./libft/libft.a

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