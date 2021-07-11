NAME = libftprintf.a
SRC = ft_printf.c ft_print_un_int.c ft_print_str.c ft_print_ptr.c ft_print_int.c ft_print_hexa_min.c ft_print_hexa_maj.c ft_print_char.c Utils/ft_atoi.c \
	Utils/ft_strlen.c Utils/ft_putnbr.c Utils/ft_putchar.c Utils/ft_isdigit.c Utils/ft_utils.c Utils/ft_utils_bis.c Utils/ft_utils_ter.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: ${NAME}
bonus: ${NAME}

$(NAME): ${OBJ}
	ar rc ${NAME} ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $?

clean:
	/bin/rm -f ${OBJ}

fclean:	clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
