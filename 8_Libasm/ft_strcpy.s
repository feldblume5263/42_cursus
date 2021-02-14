section .text
			global _ft_strcpy

_ft_strcpy:
			mov		rcx, 0
			mov		rdx, 0
			jmp		compare

encrease:
			add		rcx, 1

putchar:
			mov		dl, BYTE[rsi + rcx]
			mov		BYTE[rdi + rcx], dl
			cmp		dl, 0
			jnz		encrease

compare:
			cmp		rsi, 0
			jz		return
			jne		putchar
return:
			mov		rax, rdi
			ret
