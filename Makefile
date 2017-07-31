NAME = ft_printf

NAME2 = libftprintf.a

COMPIL = gcc

SRCS = ft_printf.c main.c parse.c flags.c flags2.c flags3.c process.c printflags.c dispatcher.c precision.c

OBJ = ft_printf.o main.o parse.o flags.o flags2.o flags3.o process.o printflags.o dispatcher.o precision.o

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

lib: fclean
	@gcc -c $(FLAGS) $(INCLUDES) $(SRC)
	@ar rc $(NAME2)
	@ranlib $(NAME2)
	@mkdir TMP
	@mv $(OBJ) TMP

git:
	@git add .
	@echo "Enter your Commit :"
	@read var1 ; git commit -m "$$var1"
	@git push

.PHONY: all clean fclean re
