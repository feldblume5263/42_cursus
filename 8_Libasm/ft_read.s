# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark </var/mail/junhpark>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 01:30:38 by junhpark          #+#    #+#              #
#    Updated: 2021/02/24 01:30:43 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
			global	_ft_read
			extern ___error

_ft_read:
			mov		rax, 0x2000003
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
