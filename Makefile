NAME = ft_ls

cc = GCC

FLAGS = -Wall -Werror -Wextra

HEAD = -I .

LIB = libft/libft.a
LIB_H = -I libft

SRC = *.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) -c $(SRC) $(LIB_H) $(HEAD)
	$(CC) $(OBJ) $(LIB_H) $(LIB) $(HEAD) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
