# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblancha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/17 15:07:21 by jblancha          #+#    #+#              #
#    Updated: 2016/09/17 15:48:07 by jblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr


SRC_DIR = srcs/
INCLUDES_DIR = include/
FUNCTIONS = ft_add ft_atoi ft_div ft_mod ft_mul ft_putchar ft_putnbr ft_putstr \
		   	ft_strcmp ft_strlen ft_sub ft_swap ft_strcat ft_strdup ft_itoa ft_strrev
BINS = $(patsubst %,%.o,$(FUNCTIONS))

.PHONY: all clean fclean re

all: $(NAME)


$(BINS):
		gcc -I$(INCLUDES_DIR) -Wall -Wextra -Werror -c $(patsubst %.o,$(SRC_DIR)%.c,$@)

$(NAME): $(BINS)
		gcc -I$(INCLUDES_DIR) $(FLAGS) main.c $(BINS) -o $(NAME)

clean:
		/bin/rm -f $(BINS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
