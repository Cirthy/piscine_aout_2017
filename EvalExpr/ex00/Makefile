#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 11:10:39 by clhoffma          #+#    #+#              #
#    Updated: 2017/08/19 12:53:32 by clhoffma         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = eval_expr

SRC = main.c eval_expr.c do_operation.c

OBJ = main.o eval_expr.o do_operation.o

EMACS = Makefile~ eval_expr.h~ eval_expr.c~ do_operation.c~ main.c~ 

all: $(NAME)

$(NAME):
	gcc -L. -lft -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ) $(EMACS)

fclean: clean
	rm -f $(NAME)

re: fclean all