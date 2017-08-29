#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/15 16:50:13 by clhoffma          #+#    #+#              #
#    Updated: 2017/08/19 16:03:11 by clhoffma         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC_PATH = srcs

SRC_NAME = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c 

CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

all: $(NAME)

$(NAME): 
	gcc -c $(SRC)
	ar rc libft.a *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all