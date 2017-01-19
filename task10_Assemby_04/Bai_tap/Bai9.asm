.stack  100h
.model  small
.data 
msg1    db  0ah,0dh,'nhap 1 ky tu $',0ah,0dh 
msg2    db  0ah,0dh,'ma ASC2 o dang hex cua ky tu do la$',0ah,0dh
.code
main    proc
    ;khoi tao ds
    mov ax,@data
    mov ds,ax
    ;hien thong bao
    laplai:
    mov ah,9
    lea dx,msg1
    int 21h
    ;nhan ky tu
    mov ah,1
    int 21h
    mov bl,al
    cmp al,0dh
    je  ketthuc
    ;hien thong bao2
    lea dx,msg2
    mov ah,9
    int 21h
    ;
    cmp bl,'a' ;so sanh bl va ky tu 'a'
    jae tiep    ; neu ky tu duoc nhap vao lon hon a thi nhay den tiep 
    sub bl,10h  ; doi thanh so
    jmp inra
tiep:
    sub bl,30h
inra:
    mov ah,2
    mov dl,bl
    int 21h
    mov dl,'h'
    int 21h
    ; lap lai
    jmp laplai
ketthuc:
    mov ah,4ch
    int 21h
main    endp
end main
;viết chương trình thông báo cho người sử dụng đánh vào một ký tự và in mã ascii của ký tự dưới dạng hex ở dòng tiếp theo. lập lại cho đến khi người dùng sử dụng đánh enter
