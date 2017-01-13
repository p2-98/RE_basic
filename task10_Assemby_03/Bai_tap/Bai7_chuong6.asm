.model small
.stack 100h
.data
msg_1 db 0dh,0ah,'Cau a: $'
msg_2 db 0dh,0ah,'Cau b: $'
tmp dw ?
.code
main proc
    mov ax,@data
    mov ds,ax
    ;cau a
    lea dx,msg_1
    mov ah,9
    int 21h
    ;
    mov ax, 0h;
    mov tmp, ax
    cau_a:
        mov ah,1
        int 21h
        mov ax, tmp
        inc ax
        mov tmp, ax
        mov ax,tmp
        cmp ax,50h
    loope cau_a
        cmp al,' '
    loope cau_a
    ;finish_a
    ;cau_b
    lea dx,msg_2
    mov ah,9
    int 21h
    ;
    mov ax,0h
    mov tmp,ax
    cau_b:
        mov ah,1
        int 21h
        mov ax, tmp
        inc ax
        mov tmp, ax
        ;
        mov ax,tmp
        cmp ax,50h
    loopne cau_b
        cmp al,0dh
    loopne cau_b
    ;dos
    mov ah,4ch
    int 21h
   main endp
end main
    