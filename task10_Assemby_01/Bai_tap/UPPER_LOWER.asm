.STACK 100h
.DATA
CR EQU 0DH
LF EQU 0AH
MSG1 DB 'ENTER A UPPER CASE LETTER : $'
MSG2 DB CR, LF,'IN LOWER CASE IT IS: '
CHAR DB ?,'$'
.CODE
MAIN PROC
    ;khoi tao DS
    MOV AX,@DATA
    MOV DS,AX
    ;In dong nhac nguoi su dung
    LEA DX,MSG1 ;lay thong bao dau tien
    MOV AH,9    ;ham hien thi chuoi
    INT 21h     ;hien thi thong bao dau tien
    ;vao mot ky tu va doi thanh chu thuong
    MOV AH,1    ;ham doc mot ky tu
    INT 21h     ;doc mot chu hoa vao AL
    ADD AL,20h  ;doi thanh chu thong
    MOV CHAR,AL ;va luu tru no
    ;hien thi tren dong tiep theo
    LEA DX,MSG2 ;lay thong bao thu 2
    Mov AH,9    ;ham hien thi chuoi
    INT 21h     ;
    ;tro ve DOS
    MOV AH,4CH
    INT 21h
    MAIN ENDP
    END MAIN 
  ;Nhap vao chu hoa in ra chu thuong
;input: Enter UPPER CASE LETTER: A
;Output; IN LOWER CASE IT IS: a
