# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark </var/mail/junhpark>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 01:32:03 by junhpark          #+#    #+#              #
#    Updated: 2021/02/24 01:32:15 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
			global	_ft_write
			extern	___error

_ft_write:
			mov		rax, 0x2000004
			syscall
			jc		error
			ret

error:
			push	rax
			call	___error
			pop		rdx
			mov		[rax], rdx
			mov		rax, -1
			ret
