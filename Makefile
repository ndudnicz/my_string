SRCS = my_string.c
  
OFILES = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libstring.a

all: $(NAME) clean

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES) 

clean:
	rm -f $(OFILES)

fclean:
	clean rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re