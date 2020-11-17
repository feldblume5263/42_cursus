# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 16:03:57 by junhpark          #+#    #+#              #
#    Updated: 2020/11/17 15:50:07 by Feldblume        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

SRC_NAME = cub3d.c \
			gnl.c \
			gnl_util.c \
			init.c \
			parsing.c \
			config.c \
			get_color.c \
			map_parsing.c \
			parse_utils.c \
			map.c \
			map_valid.c \
			player.c \
			ray.c \
			ray_detail.c \
			render.c \
			textures.c \
			utils.c \
			system.c \
			screenshot.c \
			sprite.c

SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

HEADER	= -I./includes

CFLAG	= -Wall -Wextra -Werror

LIBFT	= libft.a

LIBMLX	= mlx.a

MLX	= -framework OpenGL -framework Appkit

LIBS	= -Llibft -lft -Lmlx -lmlx

RM	= rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(LIBMLX)
	gcc -o $(NAME) $(OBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)

$(LIBFT):
	$(MAKE) -C libft

$(LIBMLX):
	$(MAKE) -C mlx

clean	:
	$(MAKE) -C libft clean
	$(MAKE) -C ./mlx clean
	rm -rf $(OBJ_PATH)

fclean	: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re
