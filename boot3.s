; tell nasm to produce 16 bit code
bits 16
; memory offset from where the bootloader is loaded
[org 0x7c00]

; Main boot

boot:
    ;point si register to our message
    mov si, hello
    ; set character teletype mode
    mov ah, 0x0e
    ;loop for printing 

loop:
    ;load next byte pointed to be si register
    lodsb
    ; check if end of string
    cmp al, 0
    ; if end, jump to halt
    je halt
    ;ask bios to print chatacter
    int 0x10
    ;loop
    jmp loop 
;end of program
halt:
    ;clear interrupting flah
    cli
    ;halt execution
    hlt

;hello message
hello:
    db "hello, world!", 0xd,0xa,
    db "goodbye, world!",0xd,0xa,

;fill rest of boot sector
times 510-($ - $$) db 0
dw 0xaa55