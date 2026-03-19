##
## EPITECH PROJECT, 2025
## Day10
## File description:
## task01 Makefile
##

INCLUDE_PATH = ./include/
CFLAGS = -I$(INCLUDE_PATH)
NAME = libmy.a
EXE = my_radar
CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

SRC = build/main.c \
	build/my_str_to_word_array.c \
	build/airplane.c \
	build/destination.c \
	build/readfile.c \
	build/music_and_h_option.c \
	build/setup_plane.c \
	build/towers.c \
	build/event.c \
	build/timer.c \
	build/colision.c \
	build/storms.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C ./lib

all: $(NAME)
	clang $(OBJ) -o $(EXE) $(CSFML) -L./lib -lmy


push: fclean
	git add .
	git commit -m "$(COMMIT)"
	git push

clean:
	make clean -C ./lib
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
