##
## EPITECH PROJECT, 2025
## Day10
## File description:
## task01 Makefile
##

INCLUDE_PATH = ./include/
CFLAGS = -I$(INCLUDE_PATH) -g -Wall
NAME = libmy.a
EXE = setting_up
COMMIT ?=

SRC	= main.c \
	map.c \
	algorithm.c \
	mark_biggest_square.c \
	row_and_col.c \
	matrice_generation.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib
	clang $(SRC) $(CFLAGS) -L./lib -o $(EXE) -lmy

push: fclean
	git add .
	git commit -m "$(COMMIT)"
	git push

clean:
	rm -f $(OBJ)
	make clean -C ./lib
fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib


re: fclean all
