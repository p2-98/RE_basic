.stack  100h
.model  small
.data
msg1    db  10,13,'nhap so nhi phan voi 8 bit dau tien va enter de ket thuc $',10,13
msg2    db  10,13,'nhap so nhi phan voi 8 bit dau tien va enter de ket thuc $',10,13
msg3    db  10,13,'nhap sai nhap lai cac so 1 hoac 0$',10,13
msg4    db  10,13,'tong cua 2 so la $',10,13
a   db  ?
b   db  ?
n   db  ? 
.code
main    proc
    ;khoi tao ds
    mov ax,@data
    mov ds,ax
    ;in dong nhac
    lea dx,msg1 
    mov ah,9
    int 21h
    jmp nhapso
;thong bao nhap sai 
nhapsai:
    lea dx,msg3
    mov ah,9
    int 21h        ;xoa bh
    xor bx,bx
    mov cx,8    ;khoi tao so lan dem
nhapso:
    mov ah,1
    int 21h
    cmp al,13
    je  tt
    cmp al,31h
    ja  nhapsai
    cmp al,30h
    jb  nhapsai
    sub al,30h    
    shl bh,1    ;dich trai bh 1 don vi nhuong cho cho bit moi
    or  bh,al   ;chen bit tu al vao bh
    loop   nhapso
    ; gan gia tri cua so thu 1
    mov a,bh
tt: 
    ;in dong nhac thu 2
    lea dx,msg2
    mov ah,9
    int 21h
    ;xoa bh va khoi tao bien dem
    xor bx,bx
    mov cx,8
nhap2:
     mov ah,1    ;nhan 1 so
    int 21h      ;neu do la phim enter
    cmp al,13    ;thi nhay den gan2
    je  gan2
    cmp al,31h
    ja  nhapsai
    cmp al,30h
    jb  nhapsai
    sub al,30h    
    shl bh,1    ;dich trai bh 1 don vi nhuong cho cho bit moi
    or  bh,al   ;chen bit tu al vao bh   
    loop   nhap2
gan2:
    mov b,bh    
;in dong nhac cuoi
    lea dx,msg4
    mov ah,9
    int 21h
    ;tinh toan
    xor bx,bx
    xor cx,cx
    mov bh,a    ; truyen gia tri a cho dx
    mov ch,b
    add bh,ch    ;cong a cho b va luu o dx
    ; sau thao tac nay dx chua tong a+b
    ; in ra
    mov cx,16
    mov n,0 
inra: 
    shl bh,1    ;dich trai bx di 1
    inc n  
    jc  inso1
    mov ah,2
    mov dl,'0'
    int 21h
    jmp nhay
inso1:
    mov ah,2
    mov dl,'1'
    int 21h 
nhay:
    cmp n,4
    jb  tiep
    mov ah,2
    mov dl,' '
    int 21h
    mov n,0
tiep:
    loop   inra
;thoat
    mov ah,4ch
    int 21h
main    endp
end main
;viết một chương trình thông báo cho người đung đưa vào 2 số nhị phân, mỗi só có 8 chữ số, in ra màn hình ở dòng tiếp theo tổng của chúng dưới dạng nhị phân. mỗi khi người sử dụng đánh vào một ký tự không hợp lệ sẽ có thông báo yêu cầu nhập lại. mỗi số được nhận sau khi người sử dụng đánh enter.
