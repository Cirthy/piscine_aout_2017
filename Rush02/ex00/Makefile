NAME = colle-2

SRCS = main.c \
		read_lengths.c \
		test_corners.c \
		test_line.c

EMACS = Makefile~ colle02.h~ $(SRCS:.c=.c~)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -L. -lft $(SRCS) -o $(NAME)

clean:
	rm -f $(EMACS)

fclean: clean
	rm -f $(NAME)

re: fclean all