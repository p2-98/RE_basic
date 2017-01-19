.stack  100h
.model  small
.data   
msg1    db  10,13,'nhap chuoi so tu 0 den 9 ket thuc bang enter $',10,13
msg2    db  10,13,'tong cua chuoi la$',10,13
msg3    db  10,13,'nhap sai hay nhap lai$',10,13
a   dw  ?
.code
main    proc
    mov ax,@data
    mov ds,ax
    ;in thong bao
    lea dx,msg1
    mov ah,9
    int 21h
    mov cl,4
    jmp nhap1so
sai:
    lea dx,msg3
    mov ah,9
    int 21h
nhap1so:
    xor bx,bx
    mov a,4    
nhapso:
    mov ah,1
    int 21h
    ;kiem tra
    cmp al,13
    je  innhac
    cmp al,39h  ;lon hon 9 hay khong
    ja  sai     ;nhay den sai
    sub al,30h  ;chuyen ve ma nhi phan
    add bx,ax   ; cong ax, vao bx
    jo  ketthuc ;neu tran se nhay
    jmp nhapso
innhac:
    lea dx,msg2
    mov ah,9
    int 21h
inra:    
    cmp a,0
    JE  ketthuc
    MOV DL,BH   ;CHUYEN BH CHO DL
    SHR DL,CL   ;DICH PHAI DL 4 LAN 
;CHIA TRUONG HOP
    CMP DL,9  ;NEU DL LON HON 9
    JA  CHU     ;THI CHUYEN DEN CHU
    ADD DL,48  ; CHUYEN VE KY TU SO
    ROL BX,CL   ;QUAY BX 4 LAN BEN TRAI
    JMP xuatkytu
CHU:    
    ADD Dl,37H  ;CHUYEN VE KY TU CHU
    ROL BX,CL
xuatkytu:
    mov ah,2
    int 21h 
    dec a
    jmp inra

ketthuc:
    mov ah,4ch
    int 21h
main    endp
end main
;viết một chương trình thông báo cho người sử dụng vào một chuỗi số các chữ số thập phân và kết thúc bằng enter, in ra màn hình ở dòng tiếp theo tổng của chúng ở dạng hex
