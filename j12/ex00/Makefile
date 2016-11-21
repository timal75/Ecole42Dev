NAME = ft_display_file
FLAGS=-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) main.c $(BINS) -o $(NAME)

clean:
	/bin/rm -f *.o 

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
