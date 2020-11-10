# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/08 17:24:05 by junhpark          #+#    #+#              #
#    Updated: 2020/04/10 15:53:39 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CFLAGS	=	-Wall -Wextra -Werror
$(NAME):
		gcc $(CFLAGS) -c *.c
		ar rc $(NAME) *.o
all:	$(NAME)
bonus:	all
so:
		gcc $(CFLAGS) -fPIC -c *.c
		gcc -shared -o libft.so *.o
clean:
		rm -f *.o
fclean: clean
		rm -f *.a
re:		fclean all
