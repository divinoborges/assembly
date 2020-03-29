section .data
    msg1 db "Digite um numero: "
    len1 equ $ - msg1
    msg2 db "Digite outro numero: "
    len2 equ $ - msg2
    msg3 db "O resultado e: "
    len3 equ $ - msg3
    br db 10, 0
    lenbr equ $ - br

section .bss
    num1 resb 2
    num2 resb 2 
    resultado resb 1

section .text
    global _start
    _start:
        mov edx, len1
        mov ecx, msg1
        mov ebx, 1
        mov eax, 4
        int 0x80

        mov edx, 2
        mov ecx, num1
        mov ebx, 2
        mov eax, 3
        int 0x80

        mov edx, len2
        mov ecx, msg2
        mov ebx, 1
        mov eax, 4
        int 0x80

        mov edx, 2
        mov ecx, num2
        mov ebx, 2
        mov eax, 3
        int 0x80

        mov edx, len3
        mov ecx, msg3
        mov ebx, 1
        mov eax, 4
        int 0x80

        ;calculo
        mov eax, [num1]
        sub eax, '0'
        mov ebx, [num2]
        sub ebx, '0'
        sub eax, ebx
        add eax, '0'
        mov [resultado], eax
        int 0x80

        mov edx, 1
        mov ecx, resultado
        mov ebx, 1
        mov eax, 4
        int 0x80

        ;quebra de linha
        mov edx, lenbr 
        mov ecx, br
        mov ebx, 1
        mov eax, 4
        int 0x80

        mov ebx, 0
        mov eax, 1
        int 0x80

