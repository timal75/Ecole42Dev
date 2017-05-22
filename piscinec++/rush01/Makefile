# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblancha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/21 20:03:43 by jblancha          #+#    #+#              #
#    Updated: 2017/01/21 22:33:29 by jblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_gkrellm	
CC		=	clang++

D_SRC	= 	srcs
D_INC	=	includes
D_OBJ	=	obj

O_FLAGS	=
W_FLAG	=	-Wall -Wextra -Werror `pkg-config --cflags gtk+-3.0`
W_FLAGS	=	`pkg-config --cflags gtk+-3.0`
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

F_SRC	:=	$(shell ls -1 $(D_SRC) | grep .cpp$$)
F_HPP	:=	$(shell ls -1 $(D_INC) | grep .hpp$$)
F_OBJ	:=	$(F_SRC:.cpp=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/%.cpp $(D_INC)
	@$(MKDIR) $(D_OBJ)
	$(CC) -I$(D_INC) $(O_FLAGS) $(W_FLAGS) -c $< -o $@ $(DEBUG)

$(NAME): $(F_OBJ) 
	$(CC) -I$(D_INC) $(O_FLAGS) $(W_FLAGS) $(F_OBJ) -lncurses `pkg-config --libs gtk+-3.0` -o $@ $(DEBUG)

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

exec: re
	  ./$(NAME)
