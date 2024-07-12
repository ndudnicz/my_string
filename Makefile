SRCS =	my_string_operations.c \
		my_string_print.c \
		my_string_alloc.c \

O_FILES = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libstring.a

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $(NAME) $(O_FILES)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean
	rm -f $(NAME)
	make all

.PHONY:  all clean fclean re