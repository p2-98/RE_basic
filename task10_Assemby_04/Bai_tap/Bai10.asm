.stack  100h
.model  small
.data   
msg1   db   0dh,0ah,'nhap mot so he hex A-F,0-9 va ket thuc bang enter $',0ah,0dh
msg2    db  0ah,0dh,'so nhi phan tuong ung la $',0ah,0dh
msg3    db  0ah,0dh,'nhap sai hay nhap lai $',0ah,0dh
n   db  ?
.code
main proc
    mov ax,@data
    mov ds,ax
    xor bx,bx ;xoa du lieu bx
    mov cl,4  ; so lan dich
;in ra dong nhac
    lea dx,msg1
    mov ah,9
    int 21h
;nhan gia tri ma hex
nhaplai:
    lea dx,msg3
    mov ah,9
    int 21h

    mov ah,1
    int 21h
while_:
    cmp al,46h
    ja  nhaplai
    cmp al,0dh    ;co phai ky tu xuong dong khong
    je  ketthuc   ; co ! ket thuc
;doi ky tu ra gia tri nhi phan
    cmp al,39h   ;kiem tra xem co la so khong
    jg  chu      ; khong phai so ! nhay den chu
; nhap 1 so
    sub al,48h   ;doi ra so nhi phan tuong ung
    jmp chen      ;dem chen vao bx
chu:
    sub al,37h
chen:
    shl bx,cl   ;danh cho gia tri moi
;dua gia tri vao bx
    or  bl,al   ;chen vao bx o 4 bit thap
    int 21h
    jmp while_
ketthuc:  
; xuat ky tu ra dang nhi phan
    mov cx,16
    mov n,0 
;in dong nhac 2
    lea dx,msg2
    mov ah,9
    int 21h
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
;tro ve dos
    mov ah,4ch
    int 21h
    main    endp
end main
;viết chương trình thông báo cho người sử dụng đánh vào 1 số hex nhỏ hơn hay bằng 4 chữ số . đưa ra số dưới dạng nhị phân ở dòng kế tiếp, khi người dùng đưa vào 1 ký tự không hợp lệ, thông báo để họ vào lại. chương trình chỉ nhận chữ hoa.
