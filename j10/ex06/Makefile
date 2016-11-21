# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblancha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 19:41:38 by jblancha          #+#    #+#              #
#    Updated: 2016/09/13 18:56:47 by jblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGSLIB = -c -W -Wall -Werror -Wextra
CFLAGS = -W -Wall -Werror -Wextra

NAME = do-op
LIBNAME = libft.a

functions = ft_atoi ft_putstr

SRC = 	srcs/ft_putchar.c \
	 	srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_putnbr.c \
		srcs/ft_strlen.c \
		srcs/ft_swap.c  \
		srcs/ft_atoi.c \
		srcs/ft_add.c \
		srcs/ft_sub.c \
		srcs/ft_mul.c \
		srcs/ft_div.c \
		srcs/ft_mod.c  

OBJ = 	ft_putchar.o \
	 	ft_putstr.o \
	 	ft_putnbr.o \
		ft_strcmp.o \
		ft_strlen.o \
		ft_swap.o \
		ft_atoi.o \
		ft_add.o \
		ft_sub.o \
		ft_mul.o \
		ft_div.o \
		ft_mod.o  

HPATH = -I includes

SRCDIR = srcs

AR = ar rc

RM = /bin/rm -rf

all : $(NAME)

$(LIBNAME) : 
				$(CC) $(CFLAGSLIB)  $(HPATH)  $(SRC)	
				$(AR) $(LIBNAME) $(OBJ) 

$(NAME) : $(LIBNAME)
				$(CC) $(CFLAGS) -L. -lft $(HPATH) -o $(NAME) main.c 

clean : 
		$(RM) $(OBJ) 

fclean : clean
		$(RM) $(LIBNAME)	

re : fclean all
