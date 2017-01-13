.model small
.stack 100h
.data
msg     db 'Nhap 1 ky tu: $' 
msg2    db 0dh,0ah,'Mat khau: $'
sum dw ?
a db ?,'$'
.code
main proc
    mov ax,@data
    mov ds,ax
    ;nhap 50 phan tu
    ;init Sum
    mov dx, 1
    mov sum, dx
    ; loop
    mov cx,50
    Loop_:
    mov dx, sum
    add dx, 4
    mov sum, dx
    loop Loop_
    ;thong bao nhap
    lea dx, msg
    mov ah,9
    int 21h
    ;nhap 1 ky tu
    mov ah, 1
    int 21h
    mov a, al
    ;in 80 lan
    mov dl,0dh
    mov ah,2
    int 21h
    ;
    mov dl,0ah
    mov ah,2
    int 21h
    ;
    mov cx, 80
    Loop2_:
    mov dl, a
    mov ah,2
    int 21h
    loop Loop2_
    ;password
    lea dx,msg2
    mov ah,9
    int 21h;
    mov cx, 5
    Loop3_:
    mov ah,1
    int 21h
    loop loop3_ 
    ;
    mov dl,0dh
    mov ah,2
    int 21h
    ;
    mov cx,5
    loop4_:
    mov dl,'x'
    mov ah,2
    int 21h
    loop loop4_
    ;dos
    mov ah,4ch
    int 21h
main endp
end main