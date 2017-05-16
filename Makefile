NAME = ft_printf

COMPIL = gcc

SRCS = ft_printf.c main.c parse.c

OBJ = ft_printf.o main.o arse.o

INCLUDES = -I ./

LIB = Libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) :
	@clear
	@echo "\033[38;5;33m===Printf : Compilation ...\033[0m"
	@make -C Libft
	@clear
	@echo "\033[38;5;33m===Printf : Compilation ...\033[0m"
	@echo "\033[38;5;33m[======                        ]\033[0m"
	@gcc -c $(SRCS) $(INCLUDES)
	@clear
	@echo "\033[38;5;33m===Printf : Compilation ...\033[0m"
	@echo "\033[38;5;33m[============                  ]\033[0m"
	@$(COMPIL) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@clear
	@echo "\033[38;5;33m===Printf : Compilation ...\033[0m"
	@echo "\033[38;5;33m[==================            ]\033[0m"
	@mkdir -p TMP
	@clear
	@echo "\033[38;5;33m===Printf : Compilation ...\033[0m"
	@echo "\033[38;5;33m[========================      ]\033[0m"
	@mv $(OBJ) TMP
	@clear
	@echo "\033[38;5;33m===Printf : Compilation ...\033[0m"
	@echo "\033[38;5;33m[==============================]\033[0m"
	@echo "\033[38;5;33m===Printf : Done\033[0m"

clean:
	@make clean -C Libft
	@echo "\033[38;5;1m===Printf : Deleting .o Files...\033[0m"
	@rm -rf TMP

fclean: clean
	@make fclean -C Libft
	@echo "\033[38;5;1m===Printf : Deleting Printf3D executable...\033[0m"
	@rm -rf $(NAME)
	@echo "\033[38;5;1m===Printf : Deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re
