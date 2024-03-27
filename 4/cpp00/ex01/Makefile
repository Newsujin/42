NAME = phonebook

SRCS = src/main.cpp src/phonebook.cpp src/contact.cpp
OBJS = $(SRCS:.cpp=.o)

CPP = c++ -Wall -Wextra -Werror
INCS = -I include

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) -o $@ $^ $(INCS)

%.o : %.cpp
	$(CPP) -c $< -o $@ $(INCS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re