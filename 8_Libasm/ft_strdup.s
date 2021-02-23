# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark </var/mail/junhpark>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 01:31:36 by junhpark          #+#    #+#              #
#    Updated: 2021/02/24 01:31:38 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
			global _ft_strdup
			extern _ft_strlen
			extern _ft_strcpy
			extern _malloc

_ft_strdup:
			cmp		rdi, 0
			jz		error
			call	_ft_strlen
			mov		rcx, rax
			inc		rcx
			push	rdi
			mov		rdi, rcx
			call	_malloc
			cmp		rax, 0
			je		error
			mov		rdi, rax
			pop		rsi

copy:
			call	_ft_strcpy
			ret

error:
			mov		rax, 0
			ret
