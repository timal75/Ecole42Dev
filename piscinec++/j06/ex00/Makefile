# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 09:04:35 by cdrouet           #+#    #+#              #
#    Updated: 2017/01/18 21:22:09 by jblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert 

SRC = main.cpp \
	  Convert.cpp \

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
