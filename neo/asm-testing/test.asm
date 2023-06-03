[org 0x7C00]
bits 16

init:
    jmp main


print:
    push si
    push ax

.loop:
    lodsb
    or al,al
    jz .done

    mov ah, 0x0e
    mov bh, 0
    int 0x10

    jmp .loop

.done:
    pop ax
    pop si
    ret

main:
    mov ax, 0
    mov ds, ax
    mov es, ax

    mov ss, sp
    mov sp, 0x7C00

    mov si, msg_hello
    call print

    hlt

.halt:
    jmp .halt

msg_hello: db 'Hello, world!', 0x0D, 0x0A, 0

times 510-($-$$) db 0
dw 0AA55h