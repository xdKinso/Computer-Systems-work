;a boot loader that prints a message

mov ah, 0x0e
mov al,"h"
int 0x10
mov al, "e"
int 0x10
mov al, "l"
int 0x10
mov al, "l"
int 0x10
mov al, "o"
int 0x10
mov al, ","
int 0x10
mov al, " "
int 0x10
mov al, "w"
int 0x10
mov al, "o"
int 0x10
mov al, "r"
int 0x10
mov al, "l"
int 0x10
mov al, "d"
int 0x10
mov al, "!"
int 0x10

jmp $

times 510 - ($- $$) db 0

dw 0xaa55