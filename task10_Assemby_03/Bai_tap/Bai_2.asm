.model small
.stack 100h
.data
msg db 'nhap ky tu: $'
.code
main proc
    ;khoi tao ds
    mov ax,@data
    mov ds,ax
    ;msg
    lea dx,msg
    mov ah,9
    int 21h
    ;enter
    case_:
    mov ah,1
    int 21h
    ;case
    cmp al,'A'
    je active1_
    cmp al,'B'
    je active2_
    jmp dos_
    ;active1
    active1_:
    mov dl,0ah
    mov ah,2
    int 21h
    jmp case_
    ;active2
    active2_:
    mov dl,0dh
    mov ah,2
    int 21h
    jmp case_
    ;dos
    dos_:
    mov ah,4ch
    int 21h
main endp
end main
    
;Dùng cấu trúc case mã hoá công việc sau đây
;nhập A đưa con trỏ về đầu dòng
;Nhập B đưa con trỏ xuống dòng
;ký tự khác về dos
    
