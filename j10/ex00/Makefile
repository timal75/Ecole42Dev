# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblancha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 19:41:38 by jblancha          #+#    #+#              #
#    Updated: 2016/09/18 19:29:01 by jblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -W -Wall -Werror -Wextra

LIBNAME = libft.a

SRC = 	srcs/ft_putchar.c \
	 	srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strlen.c \
		srcs/ft_swap.c

OBJ = 	ft_putchar.o \
	 	ft_putstr.o \
		ft_strcmp.o \
		ft_strlen.o \
		ft_swap.o
HPATH = -I includes

SRCDIR = srcs

AR = ar rc

RM = /bin/rm -rf

all : $(LIBNAME)

$(LIBNAME) : 
				$(CC) $(CFLAGS)  $(HPATH)  $(SRC)	
				$(AR) $(LIBNAME) $(OBJ) 
clean : 
		$(RM) $(OBJ) 

fclean : clean
		$(RM) $(LIBNAME)	

re : fclean all
