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
