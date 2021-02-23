# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark </var/mail/junhpark>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 01:31:50 by junhpark          #+#    #+#              #
#    Updated: 2021/02/24 01:31:54 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
			global	_ft_strlen
_ft_strlen:
			mov		rax, 0
			jmp		compare
increase:
			inc		rax
compare:
			cmp		BYTE[rdi + rax], 0
			jne		increase
done:
			ret
