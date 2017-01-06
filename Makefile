# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 14:58:02 by myoung            #+#    #+#              #
#    Updated: 2017/01/05 16:26:00 by myoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES	=	main.c
FILES	+=	fdf.c			# Top level fdf functions
FILES	+=	parse.c			# Parse out the map files into vertexs
FILES	+=	zoom.c			# Zoom and translate functions
FILES	+=	wireframe.c		# view and local_to_world_to_aligned_to_projected	
FILES	+=	hooks.c			# Loop, exit, expose and key hooks
FILES	+=	draw_fdf.c		# Connect the vertexs with lines
FILES	+=	color_fdf.c		# color random for fdf

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(addprefix build/, $(FILES:.c=.o))

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

re: fclean all

regfx:
	make -C libgfx re
	make re
	
libgfx/libgfx.a:
	make -C libgfx re

minilibx/libmlx.a:
	make -C minilibx re

$(NAME): libft/libft.a libgfx/libgfx.a minilibx/libmlx.a $(OBJS)
	@$(CC) $(CFLAGS) $(MINILIBX) $(FT) $(GFX) \
		-I . $(FRAMEWORKS) $(OBJS) -o $(NAME)
	@echo "$@ Has been created, run with ./$@"

build:
	mkdir build

build/%.o: srcs/%.c | build
	@echo "Building $@"
	@$(CC) $(CFLAGS) $(INC_MINILIBX) $(LIBFT) $(LIBGFX) -I . -c $< -o $@

clean:
	rm -rf build

tclean:
	make -C libft fclean
	make -C libgfx fclean
	make -C minilibx clean
	make fclean

fclean: clean
	rm -f $(NAME)

