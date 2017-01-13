.model small
.stack 100h
.data
msg_1 db 0dh,0ah,'nhap so thu nhat: $'
msg_2 db 0dh,0ah,'nhap so thu hai: $'
msg_e db 0dh,0ah,'$ '
a dw ?
b dw ?
.code
main proc
    mov ax,@data
    mov ds, ax
    ;nhap_a
    lea dx,msg_1
    mov ah,9
    int 21h
    ;
    mov ah,1
    int 21h
    sub al, 30h
    mov a, ax
    ;nhap_b
    lea dx,msg_2
    mov ah,9
    int 21h
    ;
    mov ah,1
    int 21h
    sub al, 30h
    mov b, ax
    ;chuyen
    mov ax, a
    sub ax,100h
    mov bx, b
    sub bx,100h
    ;div
    mov cx, 0h
    while_:
    cmp ax,bx
    jnge end_while
    add cx,1h
    sub ax, bx
    jmp while_
    end_while:
    ;
    lea dx,msg_e
    mov ah,9
    int 21h
    ;
    mov dx, cx
    add dl,30h
    mov ah,2
    int 21h
    ;dos
    mov ah,4ch
    int 21h
    main endp
end main
;Mã hoá thuật toán sau
;khởi tạo thương số bằng 0
;while số bị chia >= số chia
;tăng thương số
;trừ bớt số chia từ số bị chưa
;end_while
;AX: số bị chia, BX: số chia, CX: thương số
