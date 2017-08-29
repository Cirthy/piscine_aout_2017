NAME = ft_display_file

SRCS = main.c

EMACS = Makefile~ display_file~ $(SRCS:.c=.c~)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(EMACS)

fclean: clean
	rm -f $(NAME)

re: fclean all