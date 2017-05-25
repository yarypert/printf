NAME = ft_printf

COMPIL = gcc

SRCS = ft_printf.c main.c parse.c analyse.c dispatcher.c flags.c flags2.c flags3.c

OBJ = ft_printf.o main.o parse.o analyse.o dispatcher.o flags.o flags2.o flags3.o

INCLUDES = -I ./

LIB = Libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) :
	@clear
	@make -C Libft
	@gcc -c $(SRCS) $(INCLUDES)
	@$(COMPIL) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@mkdir -p TMP
	@mv $(OBJ) TMP
	@echo "\033[38;5;33m===Printf : Compilation ...\033[0m"
	@echo "\033[38;5;33m[==============================]\033[0m"
	@echo "\033[38;5;33m===Printf : Done\033[0m"

clean:
	@make clean -C Libft
	@rm -rf TMP

fclean: clean
	@make fclean -C Libft
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
