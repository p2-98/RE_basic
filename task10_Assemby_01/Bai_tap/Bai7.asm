.MODEL SMALL
.STACK 100h
.DATA
CR EQU 0DH
LF EQU 0AH
MSG DB  "Tong cua 2 so vua nhap la:$"
A DW ?
B DW ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS, AX
    ;In dau ?
    MOV AH, 2   ;ham hien thi chuoi 
    MOV DL,'?'  ;ky tu dau ?
    INT 21h;
    ;Nhap 1 so
    MOV AH, 1   ;nhap vao 1 so
    INT 21h     ;doc 1 so vao AL
    SUB AL,30h  ;chuyen ky tu sang dang so
    mov a, ax ;
    MOV AH, 1   ;nhap vao 1 so
    INT 21h     ;doc 1 so vao AL
    SUB al,30h  ;chuyen ky tu sang dang so 
    mov b, ax ;
    ;thong bao in tong
    LEA DX,MSG; 
    MOV AH, 9
    INT 21h;
    ;cong
    MOV AX,A    ;chuyen A vao AX
    ADD AX,B    ;cong vao B 
    ;mov dx, 0   ; xoa bit cao trong dx
    ;push dx;
    MOV A,AX    ;AX vao A
    ;pop dx;     ;lay du trong ngan xep ra khoi dx
    ;in kq
    mov dx, ax;
    ADD DL,30h  ;chuyen so sang ky tu
    MOV AH,2    ;ham hien thi chuoi
    INT 21h                        
    ;tro ve DOS
    MOV AH,4CH
    INT 21h
    MAIN ENDP
END MAIN
;In ra dau cham hoi
;Doc 2 so thap phan nho hon 10
;In ra tong 3 so
;Input: ?27
;Output: Tong 2 so la: 9
