NAME	=	libft.a
CC		=	gcc
AR		=	ar rc
INDEX	= 	ranlib

D_OBJ	=	obj

O_FLAGS	=
W_FLAGS	=	-c -Wall -Wextra -Werror
I_FLAGS = -I includes
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf
INC   =includes


F_SRC	:=	$(shell ls -1 | grep .c$$)
F_OBJ	:=	$(F_SRC:.c=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(D_OBJ)/%.o: %.c $(INC)/libft.h
	@$(MKDIR) $(D_OBJ)
	$(CC) $(I_FLAGS) $(O_FLAGS) $(W_FLAGS) -c $< -o $@ $(DEBUG)

$(NAME): $(F_OBJ) $(INC)/libft.h
		$(AR) $(NAME) $(F_OBJ)
		$(INDEX) $(NAME)
clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
