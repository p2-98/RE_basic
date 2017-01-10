.MODEL SMALL
.STACK 100h
.DATA
CR EQU 0DH
LF EQU 0AH
MSG DB CR,LF,'***********$'
msge db cr,lf,'Nhap vao 3 ky tu: $'
char1 db ?,'$'
char2 db ?,'$'
char3 db ?,'$'
.CODE
MAIN PROC
    MOV ax,@data
    mov ds, ax
    ;In dau ?
    MOV ah,2
    mov dl,'?'
    int 21h;
    ;nhap vao 3 ky tu
    lea dx,msgE
    mov ah,9
    int 21h
    ;1
    mov ah,1
    int 21h
    mov char1, al
    ;2
    mov ah,1
    int 21h
    mov char2, al
    ;3
    mov ah,1
    int 21h
    mov char3, al
    ;
    ;hien thi bang 11x11 dau sao
    mov cx,11
    print:
    lea dx,msg
    mov ah,9
    int 21h
    loop print
    ;
    mov ah,2
    mov dl,7h
    int 21h
    ;dos
    mov ah,4ch
    int 21h
main endp
end main
;Viết chương trình hiển thị
;Dấu ?
;Nhập 3 ký tự
;một bảng 11x11 điền đầy dấu *
;phát tiếng bíp
