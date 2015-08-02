# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 01:49:54 by amaurer           #+#    #+#              #
#    Updated: 2015/04/29 19:09:09 by amaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=	src/
OBJ_DIR		=	build/
INC_DIR		=	include libft/includes minilibx
BIN_DIR		=	bin/

NAME		=	fdf
BIN_NAME	=	$(BIN_DIR)$(NAME)
SRC_FILES	=	main.c \
				util.c \
				draw.c \
				actions1.c \
				actions2.c \
				actions3.c \
				parser/parse.c \
				parser/file.c \
				mlx/mlx.c \
				mlx/hooks.c \
				mlx/pt.c \
				mlx/color1.c \
				mlx/color2.c \
				mlx/draw_pixel.c \
				mlx/draw_rect.c \
				mlx/draw_line.c \
				mlx/draw_line_gradient.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

CC			=	clang
CC_FLAGS	=	-Wall -Werror -Wextra
CC_LIBS		=	-lft -Llibft -lmlx -Lminilibx -framework OpenGL -framework AppKit

all: libft minilibx $(BIN_NAME)
	@echo "\033[32m•\033[0m $(NAME) is ready."

$(BIN_NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $(BIN_NAME) $(CC_LIBS) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) $(subst $() $(), -I, $(INC_DIR)) -o $@ -c $<

clean:
	make -C libft clean
	make -C minilibx clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libft fclean
	rm -rf $(BIN_NAME)

re: fclean all

libft:
	@make -C libft

minilibx:
	@make -C minilibx

.PHONY: all re fclean clean libft minilibx