.MODEL SMALL
.STACK 100h
.DATA
CR EQU 0DH
LF EQU 0AH
MSG DB CR,LF,'**********$'
.CODE
MAIN PROC
    mov ax,@data
    mov ds,ax
    ;khoi tao lap
    mov cx,10 
    print:
    LEA dx,MSG
    mov ah,9
    int 21h
    loop print
    ;dos
    mov ah,4ch
    int 21h
MAIN ENDP
END MAIN
;Viết chương trình hiển thị 1 bảng 10x10 đầy dấu *
