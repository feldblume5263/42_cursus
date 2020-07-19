# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/08 17:24:05 by junhpark          #+#    #+#              #
#    Updated: 2020/07/04 22:37:06 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_itoa.c \
	ft_putendl_fd.c \
	ft_strlcat.c \
	ft_tolower.c \
	ft_atoi.c \
	ft_lltoa_base.c \
	ft_lstsize.c \
	ft_putnbr_fd.c \
	ft_strlcpy.c \
	ft_toupper.c \
	ft_bzero.c \
	ft_memccpy.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_utoa.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_split.c \
	ft_strmapi.c \
	ft_utoa_base.c \
	ft_isalnum.c \
	ft_memcmp.c \
	ft_strncmp.c \
	ft_utoa_base_up.c \
	ft_isalpha.c \
	ft_memcpy.c \
	ft_strchr.c \
	ft_strnstr.c \
	ft_isascii.c \
	ft_memmove.c \
	ft_strrchr.c \
	ft_isdigit.c \
	ft_memset.c \
	ft_strdup.c \
	ft_strtrim.c \
	ft_isprint.c \
	ft_putchar_fd.c \
	ft_strjoin.c \
	ft_substr.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJS	= $(SRCS:.c=.o)
INCS	= .
RM		= rm -f
LIBC	= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) $(bonus)

re : fclean all
