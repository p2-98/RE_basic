.model small
.stack 100h
.data
msg_1 db 0dh,0ah,'Nhap so thu nhat: $'
msg_2 db 0dh,0ah,'Nhap so thu hai: $'
msg_3 db 0dh,0ah,'RES: $'
a dw ?
b dw ?
.code
main proc
    mov ax,@data
    mov ds,ax
    ;Enter_1
    lea dx,msg_1;
    mov ah,9
    int 21h
    ;
    mov ah,1
    int 21h
    sub ax, 30h
    mov a, ax;
    ;Enter_2
    lea dx,msg_2
    mov ah,9
    int 21h
    ;
    mov ah,1
    int 21h
    sub ax, 30h
    mov b, ax
    ;mul
    ;
    mov ax, a
    mov bx, b
    ;
    mov cx,0h
    repeat_:
    add cx, ax
    dec bx
    cmp bx, 0
    jg repeat_
    ;
    ;print_res
    lea dx,msg_3
    mov ah,9
    int 21h
    ;
    mov dx,cx
    add dl,30h
    mov ah,2
    int 21h
    ;dos
    mov ah,4ch
    int 21h
    main endp
end main