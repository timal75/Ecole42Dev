# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblancha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 21:59:33 by jblancha          #+#    #+#              #
#    Updated: 2017/01/19 21:59:36 by jblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Array 

SRC = main.cpp 

BIN = $(SRC:.cpp=.o)

FLAG = -Wall -Wextra -Werror

Lib = -lncurses

$(NAME) : $(SRC)
	clang++ $(FLAG) -c $(SRC);
	clang++ $(FLAG) -o $(NAME) $(BIN) $(Lib)

.PHONY: all
all : $(NAME)

.PHONY: clean
clean :
	rm -f $(BIN)

.PHONY: fclean
fclean : clean
	rm -f $(NAME)

.PHONY: re
re : fclean all
