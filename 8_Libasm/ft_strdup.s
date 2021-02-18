section .text
			global _ft_strdup
			extern _ft_strlen
			extern _malloc

_ft_strdup:
			call	_ft_strlen
			push	rdi
			mov		rdi, rax
			call	_malloc
			pop		rdi
			cmp		rax, 0
			jz		error

