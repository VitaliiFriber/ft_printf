CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
NAME = libftprintf.a

SRCS = ft_printf.c ft_print_string.c ft_print_digit.c ft_print_pointer.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

	ar rc $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re

.SILENT: