NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g
LIB = "libft/libft.a"
SRC = ft_conflit_checker.c \
	  ft_init.c \
	  ft_flag_writer.c \
	  ft_param_checker.c \
	  ft_param_writer.c \
	  ft_printf.c \
	  ft_putnbr_base.c \
	  ft_putnbr_base_hex.c \
	  ft_set_specifier_1.c \
	  ft_set_specifier_2.c \
	  ft_write_char.c \
	  ft_write_hex.c \
	  ft_write_integer.c \
	  ft_write_pointer.c \
	  ft_write_str.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

bonus: $(NAME)

$(NAME) : $(OBJ) $(LIB)
	cp $(LIB) $(NAME)
	ar rs $(NAME) $(OBJ)

$(LIB) :
	$(MAKE) -C $$(dirname $@)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C $$(dirname $(LIB));
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIB)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
