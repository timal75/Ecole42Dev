NAME	=	libft.a	
CC		=	gcc
AR		=	ar rc
INDEX	= 	ranlib

D_SRC	=	
D_INC	=	../includes
D_OBJ	=	../obj
D_LIB	=	../lib

O_FLAGS	=
W_FLAGS	=	-c -Wall -Wextra -Werror
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

F_SRC	:=	$(shell ls -1 | grep .c$$)
F_OBJ	:=	$(F_SRC:.c=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(D_OBJ)/%.o: %.c $(D_INC)/libft.h 
	@$(MKDIR) $(D_OBJ)
	$(CC) $(O_FLAGS) -I$(D_INC) $(W_FLAGS) -c $< -o $@ $(DEBUG)

$(NAME): $(F_OBJ) $(D_INC)/libft.h 
		@$(MKDIR) $(D_LIB)
		$(AR) $(D_LIB)/$(NAME) $(F_OBJ)
		$(INDEX) $(D_LIB)/$(NAME)
clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
