NAME = phonebook

SRCS = src/main.cpp src/Phonebook.cpp src/Contact.cpp
OBJS = $(SRCS:.cpp=.o)

CPP = c++ -Wall -Wextra -Werror -std=c++98
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