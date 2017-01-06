# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 15:36:22 by myoung            #+#    #+#              #
#    Updated: 2017/01/05 16:08:41 by myoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.a

FILES =		draw.c			# Draw points and lines
FILES +=	matrix.c		# Matrix functions: bzero id mult scale trans
FILES +=	matrix_rot.c	# Matrix functions:
FILES +=	vertex.c		# Vertex creation:
FILES +=	image.c			# easier image creation
FILES +=	color.c			# color table
FILES +=	toggle_keys.c

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(addprefix build/, $(FILES:.c=.o))

GFX = -I .
FT = -I ../libft
MLX = -I ../minilibx

.PHONY: all re clean fclean

all: $(NAME)

re: fclean all

clean:
	rm -rf build

fclean: clean
	rm -rf $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	@echo "Making $@"
	ar rcs $(NAME) $(OBJS)

build/%.o: srcs/%.c | build
	@echo "Building $@"
	gcc $(FLAGS) $(FT) $(MLX) $(GFX) -c $< -o $@
