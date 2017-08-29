#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/15 16:50:13 by clhoffma          #+#    #+#              #
#    Updated: 2017/08/17 10:16:04 by clhoffma         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_advanced_do-op

SRC = operations.c ft_stdfct.c main.c

OBJS = operations.o ft_stdfct.o main.o

EMACS = operations.c~ ft_stdfct.c~ main.c~ advanced_do_op.h~ Makefile~

all: $(NAME)

$(NAME): 
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJS) $(EMACS)

fclean: clean
	rm -f $(NAME)

re: fclean all