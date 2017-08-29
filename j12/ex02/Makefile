NAME = ft_tail

SRCS = main.c stdfct.c

EMACS = Makefile~ ft_tail.h~ $(SRCS:.c=.c~)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(EMACS)

fclean: clean
	rm -f $(NAME)

re: fclean all
