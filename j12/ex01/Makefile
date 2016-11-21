NAME = ft_cat
SRC_DIR = srcs/
INCLUDES_DIR = .  
FUNCTIONS=
FLAGS=-Wall -Wextra -Werror
BINS = $(patsubst %,%.o,$(FUNCTIONS))

.PHONY: all clean fclean re

all: $(NAME)

$(BINS):
	gcc -I$(INCLUDES_DIR) $(FLAGS) -c $(patsubst %.o,$(SRC_DIR)%.c,$@)

$(NAME): $(BINS)
	gcc -I$(INCLUDES_DIR) $(FLAGS) ft_strlen.c main.c $(BINS) -o $(NAME)

clean:
	/bin/rm -f *.o 

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
