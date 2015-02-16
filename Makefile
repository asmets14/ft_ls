NAME = ft_ls

CC = gcc

FLAGS = -Wall -Werror -Wextra

HEAD = -I . 

LIB = libft/libft.a -L liba -la
LIB_H = -I libft -I liba

SRC = *.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) -c $(SRC) $(HEAD)  $(LIB_H) 
	$(CC) $(LIB_H) $(HEAD) $(LIB) -o $(NAME) $(OBJ) 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
