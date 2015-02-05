NAME = ft_ls

cc = GCC

FLAGS = -Wall -Weror -Wextra

SRC = check_arg.c\
      create_space.c\
      final_string.c\
      ft_print_list.c\
      get_alignement.c\
      get_mode.c\
      get_stat.c\
      init_opt.c\
      main.c\
      opening.c\
      print.c\
      split_date.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) -c $(FLAGS) $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
