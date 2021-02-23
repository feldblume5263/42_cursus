# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark </var/mail/junhpark>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 01:31:11 by junhpark          #+#    #+#              #
#    Updated: 2021/02/24 01:31:18 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
			global _ft_strcpy

_ft_strcpy:
			mov		rcx, 0
			cmp		rsi, 0
			jz		return
			jnz		putchar

encrease:
			add		rcx, 1

putchar:
			mov		dl, BYTE[rsi + rcx]
			mov		BYTE[rdi + rcx], dl
			cmp		dl, 0
			jnz		encrease

return:
			mov		rax, rdi
			ret
