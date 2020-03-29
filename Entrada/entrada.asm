section .data
    msg1 db "Digite seu primeiro nome: "
    len1 equ $ - msg1
    msg2 db "Seu primeiro nome e: "
    len2 equ $ - msg2

section .bss
    nome resb 10

section .text
    global _start
    _start:
        
        mov eax, 4
        mov ebx, 1
        mov ecx, msg1
        mov edx, len1 
        int 0x80

        mov edx, 10
        mov ecx, nome
        mov ebx, 2
        mov eax, 3
        int 0x80

        mov eax, 4
        mov ebx, 1
        mov ecx, msg2
        mov edx, len2 
        int 0x80

        mov edx, 10
        mov ecx, nome
        mov ebx, 1
        mov eax, 4
        int 0x80

        mov ebx, 0
        mov eax, 1
        int 0x80