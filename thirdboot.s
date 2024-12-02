[org 0x7c00]
mov bx, hello
call print_function

mov bx, goodbye
call print_function

jmp $

print_function:
    pusha
    mov ah , 0x0e

print_char:
    mov al, [bx]
    cmp al, 0 
    je end_print
    int 0x10
    inc bx
    jmp print_char

end_print:

    popa
    ret

hello:
    
    db "Hello, World!",0xa,0x0d,0

goodbye:
    
    db "Goodbye!",0,0xa


times 510 - ($ - $$) db 0
dw 0xaa55
