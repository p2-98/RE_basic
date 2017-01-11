.MODEL SMALL
.STACK 100h
.DATA
CR EQU 0AH
LF EQU 0DH
MSG DB 'ENTER CHARACTER (A - F): $'
MSG1 DB CR,LF,'RES: $'
MSG10 DB '10$'
MSG11 DB '11$'
MSG12 DB '12$'
MSG13 DB '13$'
MSG14 DB '14$'
MSG15 DB '15$'
a db ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    ;Thong bao nhap
    LEA DX, MSG
    MOV AH,9
    Int 21h
    ;Nhap
    Mov ah, 1
    int 21h;
    mov a, al
    ;thong bao xuat
    LEA Dx,msg1
    mov ah,9
    int 21h
    ;kiemtra
    mov al, a
    ;
    cmp al, 65
    je In10
    ;
    cmp al, 66
    je In11
    ;
    cmp al, 67
    je In12
    ;
    cmp al, 68
    je In13
    ;
    cmp al, 69
    je In14
    ;
    cmp al, 70
    je In15
    ;IN
    In10:
    LEA dx, msg10
    mov ah,9
    int 21h
    jmp thoat
    ;
    In11:
    LEA dx, msg11
    mov ah,9
    int 21h
    jmp thoat
    ;
    In12:
    LEA dx, msg12
    mov ah,9
    int 21h
    jmp thoat
    ;
    In13:
    LEA dx, msg13
    mov ah,9
    int 21h
    jmp thoat
    ;
    In14:
    LEA dx, msg14
    mov ah,9
    int 21h
    jmp thoat
    ;
    In15:
    LEA dx, msg15
    mov ah,9
    int 21h
    jmp thoat
    ;dos
    thoat:
    mov ah,4ch
    int 21h
main endp
end main
;nhap vao tu A -> F mã hex in ra mã thập phân
;Input: A
;Output: 10
