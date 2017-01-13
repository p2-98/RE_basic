.model small
.stack 100h
.data
msg_act_1 db 'Active 1: SUCCESS $',0ah,0dh
msg_act_2 db 0ah,0dh,'Active 2: SUCCESS $'
a dw ?,'$'
sum dw ?,'$'
b dw ?,'$'
subtract dw ?,'$'
.code
main proc
    mov ax,@data
    mov ds,ax
    ;init_val
    ;a
    mov ax, 1h
    mov a, ax
    ;sum
    mov ax, 0h
    mov sum, ax
    ;mov ax, 3
    ;mov b, ax
    active_1:
    ;sum
    mov ax, sum
    add ax, a
    mov sum, ax
    ;inc_a
    mov ax, a
    add ax, 3h
    mov a, ax
    mov ax, a
    cmp ax,94h
    jl active_1
    ;init_act_2
    mov ax, 64h
    mov subtract, ax
    ;active_2
    active_2:
    mov ax, subtract
    sub ax, 5h
    mov subtract, ax
    cmp ax,0
    jg active_2
    ;print_active_1
    ;msg
    lea dx, msg_act_1
    mov ah,9
    int 21h
    ;print_active_2
    ;msg
    lea dx, msg_act_2
    mov ah,9
    int 21h
    ;dos
    mov ah,4ch
    int 21h
main endp
end main

;viết lệnh thực hiện
;ax = 1 + 4 + 7 + ... + 148
;ax = 200 + 195 + ... + 5
