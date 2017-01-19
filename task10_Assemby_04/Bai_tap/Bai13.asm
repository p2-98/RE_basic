.stack  100H
.model  small
.data
msg1    db  10,13,'danh vao 1 so hex khong dau va ket thuc bang enter$',10,13
msg2    db  10,13,'nhap so thu 2 ket thuc bang enter$',10,13
msg3    db  10,13,'tong cua chung la$',10,13
msg4    db  10,13,'nhap sai, nhap lai$',10,13  
a   dw  ?
b   dw  ?
n   db  0
.code
main    proc
    ;khoi tao dss
    mov ax,@data
    mov ds,ax
    ;hien thi dong nhac
    lea dx,msg1
    mov ah,9
    int 21h
    jmp nhap1so
nhapsai:
    lea dx,msg4
    mov ah,9
    int 21h
    xor bx,bx   ;xoa bx
    mov cl,4
nhap1so:    
    mov ah,1
    int 21h
nhap1:  
    ;kiem tra
    cmp n,4
    je  gan1
    cmp al,13   ;co dung la enter khong
    je  gan1   ;dung! nhay den nhap so 2
    cmp al,46h  ;kien tra xem co phai ky tu dung khong
    ja  nhapsai ; ky tu sai nhay den nhap lai
    cmp al,39h  ;kiem tra xem al co phai chu khong
    ja  kytu     ; neu >39 thi la chu nhay den chu
    sub al,30h  ;chuyen so thanh ma nhi phan tuong ung
    int 21h
    jmp chen1
kytu:
    sub al,37h  ;chuyen chu thanh ma nhi phan tuong ung
chen1:
    shl bx,cl   ;dich bx di 4 lan ve ben trai
    or  bl,al   ;chen gia tri al vao 4 bit thap cua bx
    ;nhan tiep
    int 21h
    inc n
    jmp nhap1   ; lap lai den khi enter           
gan1:
    mov a,bx
    ;xoa bx va lam lai
    xor bx,bx
    ;in dong nhac2
    lea dx,msg2
    mov ah,9
    int 21h
    jmp nhap2so
nhapsai2:
    lea dx,msg4
    mov ah,9
    int 21h
nhap2so:     
    mov ah,1
    int 21h   
nhap2:

     ;kiem tra
    cmp n,0
    je  gan2
    cmp al,13   ;co dung la enter khong
    je  gan2   ;dung! nhay den nhap so 2
    cmp al,46h  ;kien tra xem co phai ky tu dung khong
    ja  nhapsai2 ; ky tu sai nhay den nhap lai
    cmp al,39h  ;kiem tra xem al co phai chu khong
    ja  kytu2     ; neu >39 thi la chu nhay den chu
    sub al,30h  ;chuyen so thanh ma nhi phan tuong ung
    jmp chen2
kytu2:
    sub al,37h  ;chuyen chu thanh ma nhi phan tuong ung
chen2:
    shl bx,cl   ;dich bx di 4 lan ve ben trai
    or  bl,al   ;chen gia tri al vao 4 bit thap cua bx
    ;nhan tiep
    int 21h
    dec n
    jmp nhap2   ; lap lai den khi enter   

gan2:
     mov b,bx 
;tinh toan
    add bx,a     ;con a cho b va luu o bx
    jo  thoat    ;neu tran thi thoat
    ;neo khong tran ! tiep tuc
    ;xuat ra so hex
    mov n,4
    MOV Cl,4
    mov si,4
    lea dx,msg3
    mov ah,9
    int 21h
XUAT:
    cmp n,0
    JE  THOAT
    MOV DL,BH   ;CHUYEN BH CHO DL
    SHR DL,CL   ;DICH PHAI DL 4 LAN 
;CHIA TRUONG HOP
    CMP DL,9  ;NEU DL LON HON 9
    JA  CHU     ;THI CHUYEN DEN CHU
    ADD DL,48  ; CHUYEN VE KY TU SO
    ROL BX,CL   ;QUAY BX 4 LAN BEN TRAI
    dec n
    JMP xuatkytu
CHU:    
    ADD DL,37H  ;CHUYEN VE KY TU CHU
    ROL BX,CL
    dec N 
xuatkytu:
    mov ah,2
    int 21h
    jmp xuat

thoat:
    mov ah,4ch
    int 21h 
main    endp
end main
;viết chương trình thông báo cho người sử dụng đưa vào 2 số hex không dấu , in ra màn hình ở dòng tiếp theo tổng của chúng dưới dạng hex. mỗi khi người sữ dụng đánh vào một ký tự không hợp lệ sẽ có thông báo nhập lại. chương trình của bạn khả năng kiểm soát tràn không dấu. mỗi số được nhận sau khi nhấn enter.
