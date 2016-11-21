NAME = libft.a

CC = gcc
CFLAGS = -c -W -Wall -Werror -Wextra
RM = /bin/rm -rf
AR = ar rc
SRCS = ./srcs/ft_putchar.c \
	   ./srcs/ft_putstr.c \
	   ./srcs/ft_strcmp.c \
	   ./srcs/ft_strlen.c \
	   ./srcs/ft_swap.c

OBJ = ft_putchar.o \
	   ft_putstr.o \
	   ft_strcmp.o \
	   ft_strlen.o \
	   ft_swap.o
INC = ./includes

INDEX = ranlib

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(INC) 
		$(AR) $(NAME) $(OBJ)
		$(INDEX) $(NAME)

%.o : ./srcs/%.c $(INC)
		$(CC) -I$(INC) $(CFLAGS) $< -o $@  

clean : 
		$(RM) $(OBJ)

fclean : clean
		 $(RM) $(NAME)	

re : fclean all

	 
