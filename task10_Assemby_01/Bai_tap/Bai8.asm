.MODEL SMALL
.STACK 100h
.DATA
CR EQU 0DH
LF EQU 0AH
MSG DB 'NHAP VAO 3 CHU CAI DAU: $'
MSG1 DB CR,LF,'$'
char1 DB ?,'$'
char2 DB ?,'$'
char3 DB ?,'$'
.CODE
MAIN PROC
    mov ax,@data
    mov ds,ax
    ;in thong bao
    LEA dx,MSG
    mov ah,9
    int 21h
    ;nhap
    mov ah,1
    int 21h
    mov char1, al
    ;
    mov ah,1
    int 21h
    mov char2, al
    ;
    mov ah,1
    int 21h
    mov char3, al
    ;in 
    ;
    lea dx,MSG1
    mov ah,9
    int 21h
    lea dx,char1
    mov ah,9
    int 21h
    ;
    lea dx,MSG1
    mov ah,9
    int 21h
    LEA dx, char2
    mov ah,9
    int 21h
    ;
    lea dx,MSG1
    mov ah,9
    int 21h
    LEA dx, char3
    mov ah,9
    int 21h
    ;
    mov ah,4ch
    int 21h
    main endp
end main
;Nhập vào chữ cái
;In 3 chữ mỗi chữ 1 dòng
;Input: Nhap vao 3 chu cai: abc
;Output:
;a
;b
;c
    
    
