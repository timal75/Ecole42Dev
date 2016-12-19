NAME	=	fdf	
CC		=	gcc
AR		=	ar rc
INDEX	= 	ranlib

D_SRCS	=   srcs
D_INC 	=   includes
D_OBJ	=	obj
D_LIB	=	lib/	

O_FLAGS	=
W_FLAGS	=	-c -Wall -Wextra -Werror
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

F_SRC	:=	$(shell ls -1 $(D_SRCS)| grep .c$$)
F_OBJ	:=	$(F_SRC:.c=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))
F_INC	:=	$(shell ls -1 $(D_INC)| grep .h$$)
F_INC	:=	$(addprefix $(D_INC)/, $(F_INC))

.PHONY: all clean fclean re

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRCS)/%.c $(D_INC)
	@$(MKDIR) $(D_OBJ)
	$(CC) -I$(D_INC) $(O_FLAGS) $(W_FLAGS) -c $< -o $@ $(DEBUG)

$(NAME): $(F_OBJ) $(F_INC) 
		Make -C libft/
		$(CC) -o $(NAME) $(F_OBJ) -lm -L $(D_LIB) -lft -lmlx -framework OpenGL -framework AppKit
clean:
	Make -C libft/ clean
	$(RM) $(D_OBJ)

fclean: clean
	Make -C libft/ fclean
	$(RM) $(NAME)

re: fclean all
