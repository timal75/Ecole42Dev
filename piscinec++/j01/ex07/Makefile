NAME	=	replacestring	
CC		=	clang++	

SRCC	= main.cpp
SRCO	= $(SRCC:.cpp=.o)

W_FLAGS	=	-Wall -Wextra -Werror
DEBUG	=

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.cpp 
	$(CC) $(W_FLAGS) -c $< -o $@ $(DEBUG)

$(NAME): $(SRCO)
	$(CC) $(W_FLAGS) $(SRCO) -o $@ $(DEBUG)

clean:
	$(RM) $(SRCO)

fclean: clean
	$(RM) $(NAME)

re: fclean all
