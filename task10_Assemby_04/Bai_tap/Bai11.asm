.STACK  100H
.MODEL  SMALL
.DATA
MSG1   DB   0AH,0DH,'NHAP VAO CAC SO 1,0 CUA MA NHI PHAN KET THUC BANG ENTER $',0AH,0DH
MSG2   DB   0AH,0DH,'MA HEX TUONG UNG LA $',0AH,0DH
MSG3    DB  0AH,0DH,'NHAP SAI, NHAP LAI $',0AH,0DH
N   DB 4
.CODE
MAIN    PROC
    MOV AX,@DATA
    MOV DS,AX
 ;IN DONG CHU
    LEA DX,MSG1
    MOV AH,9
    INT 21H
 ;NHAN SO NHI PHAN 
    XOR BX,BX   ;XOA BX
    jmp d1
NHAPLAI:
    LEA DX,MSG3
    MOV AH,9
    INT 21H
d1:
    ;NHAP VAO 1 KY TU
    MOV AH,1
    INT 21H 
WHILE_:
    CMP AL,0DH      ;CR?
    JE  END_WHILE   ; DUNG! KET THUC
    CMP AL,31h       ; NEU SO DO LON HON 1
    JA  NHAPLAI     ; THI NHAP LAI
    SUB AL,30H      ; CHUYEN THANH MA NHI PHAN 
    SHL BX,1        ;GIANH CHO CHO BIT MOI
    OR  BL,AL       ;CHEN GIA TRI VAO
    INT 21H
    JMP WHILE_      ;LAP LAI
END_WHILE:
    ;xuat ra so hex
    MOV Cl,4
    mov si,4
    lea dx,msg2
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
    ADD DL,48H  ; CHUYEN VE KY TU SO
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
;chương trình thông báo cho người sử dụng đánh vào một số nhị phân có nhỏ hơn hay bằng 16 bit. đưa ra số dưới dạng hex ở dòng kế tiếp. khi người sử dụng đưa vào 1 ký tự không hợp lệ, thông báo để vào lại
