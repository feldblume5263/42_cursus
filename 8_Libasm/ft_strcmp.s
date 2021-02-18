section	.text
			global _ft_strcmp

_ft_strcmp:
			mov		rcx, 0
			mov		rdx, 0
			cmp		rdi, 0
			jz		return
			cmp		rsi, 0
			jz		return
			jmp		check_final

encrease:
			add		rcx, 1

check_final:
			cmp		BYTE[rdi + rcx], 0
			je		final
			cmp		BYTE[rsi + rcx], 0
			je		final
			jmp		compare

compare:
			mov		dl, BYTE[rdi + rcx]
			cmp		BYTE[rsi + rcx], dl
			jz		encrease
			jnz		subnum

subnum:
			mov		dl, BYTE[rdi + rcx]
			sub		dl, BYTE[rsi + rcx]
			jl		lowcase
			jnz		upcase
			ret

lowcase:
			mov		rax, -1
			ret
same:
			mov		rax, 0
			ret
final:
			mov		dl, BYTE[rdi + rcx]
			sub		dl, BYTE[rsi + rcx]
			cmp		dl, 0
			jz		same
			jl		lowcase
upcase:
			mov		rax, 1
			ret
return:
			mov		rax, rdi
			ret
