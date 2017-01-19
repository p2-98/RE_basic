.stack 100h
.model small
.data 
x1      db  0dh,0ah,'nhap vao 1 ky tu $',0ah,0dh
x2      db  0ah,0dh,'ma asc2 cua no la $',0ah,0dh
tn3     db  0ah,0dh,'so cac bit 1 la $',0ah,0dh
n       db  ?
a       db  ?
.code
main    proc 
    ;khoi tao ds
    mov ax,@data
    mov ds,ax
    mov ah,9
    lea dx,x1
    int 21h
    ;
    mov ah,1
    int 21h
    mov bl,al    ; chuyen gia tri cua al cho bl
    mov a,al     ; chuyen gia tri al cho a
    ;
    mov ah,9     ; hien dong thong bao 2
    lea dx,x2    
    int 21h
    ;
    mov cx,8     ;khoi tao so lan lap
    mov n,0
lap:
    shl bl,1     ;dich trai bl 1 don vi
    inc n        ;tang bien dem 1 don vi
    jc  inso1    ;neu CF =1 thi nhay den inso1
    mov ah,2     ;neu khong thi in so 0
    mov dl,'0'
    int 21h
    jmp nhay
inso1:
    mov ah,2     ;ham in so 1
    mov dl,'1'
    int 21h
    ;
nhay:
    cmp n,4
    jb  tiep
    mov ah,2
    mov dl,' '
    int 21h
    mov n,0   ;cu cach 4 so thi cach 1 khoang
tiep:
    loop lap 
    ;
;ham dem so 1 trong day
    mov dl,a
    mov cx,8
    dem:
    shr dl,1     
    jc cong1
    loop    dem
    jmp thoat
;dem
cong1:
    inc n
    jmp dem
thoat:
    lea dx,tn3
    mov ah,9
    int 21h
    ;
    mov dl,n
    add dl,30h
    mov ah,2
    int 21h
    ;    
    mov ah,4ch
    int 21h
main    endp
end     main
;viết một chương trình thông báo cho người sử dụng vào 1 phím bất kỳ , in ra trên các dòng liên tiếp nhau mã ascII của ký tự đó dưới dạng nhị phân, số các chữ số 1 trong mã ascii đó
