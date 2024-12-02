; a boot sector program that loops forever

;an infinite loop . program will always jump back to loop

loop:
        jmp loop

times 510 -($ - $$) db 0

dw 0xaa55