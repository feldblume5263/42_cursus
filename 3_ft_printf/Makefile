# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/04 21:28:10 by junhpark          #+#    #+#              #
#    Updated: 2020/07/04 22:41:55 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ft_printf \
			get_conv_tool.c \
			flag_utils.c \
			write_utils.c \
			print_int.c \
			print_unsigned_int.c \
			print_char.c \
			print_string.c \
			print_hexa_l.c \
			print_hexa_u.c \
			print_pointer.c \
			print_percent.c

OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus .c.o
