global _start

_start:
		mov rax, 1 ; 문자열을 출력하는 시스템콜
		mov rdi, 1
		mov rsi, mes ; 메세지가 어딨는지 알려준다
		mov rdx, len ; 메세지 길이를 알려준다.
		syscall
		mov rax, 60
		mov rdi, 0
		syscall

section .data
		mes : db 'hello world', 0x0A
		len : equ $-mes
