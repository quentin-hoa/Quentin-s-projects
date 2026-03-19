##
## EPITECH PROJECT, 2025
## Day10
## File description:
## task01 Makefile
##

INCLUDE_PATH = ./include/
CFLAGS = -I$(INCLUDE_PATH)
NAME = libmy.a
EXE = my_hunter
CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

SRC = build/main.c \
	build/xwing.c \
	build/levels.c \
	build/my_put_decimal.c \
	build/text.c \
	build/game_function.c \
	build/strcpy_strdup.c \
	build/hit_xwing.c \
	build/init_wing.c \
	build/destroy.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	clang $(OBJ) -o $(EXE) $(CSFML)

push: fclean
	git add .
	git commit -m "$(COMMIT)"
	git push

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
