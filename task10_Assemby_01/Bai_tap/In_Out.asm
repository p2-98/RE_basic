.MODEL SMALL
.STACK 100h
.DATA
CR EQU 0DH
LF EQU 0AH
CHAR DB ?,'$'
.CODE
MAIN PROC
    ;khoi tao DS
    MOV AX,@DATA
    MOV DS,AX
    ;vao mot ky tu
    MOV AH,1    ;ham doc mot ky tu
    INT 21h     ;doc 1 chua vao AL 
    MOV CHAR, AL;luu tru
    ;hien thi
    MOV AH,9    ;hien thi
    INT 21h ;
    ;DOS
    MOV AH,4CH
    INT 21h
    MAIN ENDP
    END MAIN
    /* Đọc một ký tự và hiễn thị nó ở vị trí tiếp theo trên cùng 1 dòng
    Input a Output aa */
