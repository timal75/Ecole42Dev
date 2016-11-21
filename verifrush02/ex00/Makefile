NAME	=	colle\-2	
CC		=	gcc

HPATH	=	-I ./includes

W_FLAGS	=	-Wall -Wextra -Werror
RM		=	/bin/rm -rf

SRC		=	srcs/colle00.c srcs/colle01.c srcs/colle02.c \
			srcs/colle03.c srcs/colle04.c srcs/ft_putchar.c \
		   	srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_strcat.c \
	   		srcs/ft_strcmp.c srcs/ft_strcpy.c	   


.PHONY: all clean fclean re

all : $(NAME)

$(NAME) :
	         $(CC) $(W_FLAGS)  $(HPATH)  $(SRC) main.c -o $(NAME)
fclean :
			$(RM) $(NAME)

re: fclean all
