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

TRAIN				=	train
TRAINCPP		=	main.cpp
PREDICT			= predict
PREDICTCPP	= predict.cpp
CC					=	clang++

D_SRC	= .
D_INC	= .
D_OBJ	=	obj

O_FLAGS	=
W_FLAG	=	-Wall -Wextra -Werror
W_FLAGS	=
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

F_SRC	:=	$(shell ls -1 $(D_SRC) | grep .cpp$$)
F_HPP	:=	$(shell ls -1 $(D_INC) | grep .hpp$$)
F_OBJ	:=	$(F_SRC:.cpp=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

.PHONY: all clean fclean re

all: $(TRAIN) $(PREDICT)

$(D_OBJ)/%.o: $(D_SRC)/%.cpp $(D_INC)
	@$(MKDIR) $(D_OBJ)
	$(CC) -I$(D_INC) $(O_FLAGS) $(W_FLAGS) -c $< -o $@ $(DEBUG)

$(TRAIN): $(TRAINCPP)
	$(CC) -I$(D_INC) $(O_FLAGS) $(W_FLAGS)  $(TRAINCPP) -o $@ $(DEBUG)

$(PREDICT): $(PREDICTCPP)
		$(CC) -I$(D_INC) $(O_FLAGS) $(W_FLAGS)  $(PREDICTCPP) -o $@ $(DEBUG)

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(TRAIN)
	$(RM) $(PREDICT)

re: fclean all
