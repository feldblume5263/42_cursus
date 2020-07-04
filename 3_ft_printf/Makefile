# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/04 21:28:10 by junhpark          #+#    #+#              #
#    Updated: 2020/07/04 21:49:23 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a

AR = ar
ARFLAGS = rcs

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./libft
LIB_FLAGS = -L./libft -lft -L. -lftprintf

RM = rm -f

FILES = ft_printf \
	get_conv_tool \
	flag_utils \
	write_utils \
	print_int \
	print_unsigned_int \
	print_char \
	print_string \
	print_hexa_l \
	print_hexa_u \
	print_pointer \
	print_percent

SRC_DIR = ./srcs/
SRCS = $(addprefix ($SRC_DIR), $(addsuffix .c, $(FILES)))

OBJ_DIR = ./objs/
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

$(NAME): $(LIBFT) $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./libft all
	$(MAKE) -C ./libft bonus

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean
	$(RM) -r a.out a.out.dSYM leaks_result

re: clean all

test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_FLAGS) test_main.c && ./a.out

.PHONY: test bonus all clean fclean re
