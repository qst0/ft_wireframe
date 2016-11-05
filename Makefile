#Makefile by Mason

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = main.c parse.c wireframe.c hooks.c zoom.c draw_fdf.c fdf.c

SRCS = $(addprefix srcs/, $(FILES))

FRAMEWORKS = -framework OpenGL -framework AppKit

INC_MINILIBX = -I minilibx
LINK_MINILIBX = -L minilibx -lmlx
MINILIBX = $(INC_MINILIBX) $(LINK_MINILIBX)

LIBFT = -I libft
LINK_FT = -L libft/ -lft
FT = $(LIBFT) $(LINK_FT)

LIBGFX = -I libgfx
LINK_GFX = -L libgfx -lgfx
GFX = $(LIBGFX) $(LINK_GFX)

all: $(NAME)

libft/libft.a:
	make -C libft re

regfx:
	make -C libgfx re
	make re
	
libgfx/libgfx.a:
	make -C libgfx re

minilibx/libmlx.a:
	make -C minilibx re

$(NAME): libft/libft.a libgfx/libgfx.a minilibx/libmlx.a
	$(CC) $(CFLAGS) $(MINILIBX) $(FT) $(GFX) \
		-I . $(FRAMEWORKS) $(SRCS) -o $(NAME)

build:
	mkdir build

clean:
	rm -rf build

tclean:
	make -C libft fclean
	make -C libgfx fclean
	make -C minilibx clean
	make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
