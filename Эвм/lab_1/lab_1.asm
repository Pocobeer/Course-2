; Резервирoвание места под стек
sseg segment stack 'stack'
 dw 256 dup(?)
sseg ends
; Определение данных
data segment
x dw -5
zerx db ?
neg_x db ?
posx db ?
msg1 db 10, 13, 'input number', '$'
msg2 db 10, 13, 'Number is positive', '$'
msg3 db 10, 13, 'Number is negative', '$'
msg4 db 10, 13, 'Number is null', '$'
data ends

; Макроопределения
check_num macro num
local _neg, _pos, _zer, myend
    cmp  num, 0
    je _zer
    jg _pos
    jl _neg

    _neg:
        mov bx, num
        lea dx, msg3
        call print_msg
        jmp myend
    _pos:
        mov cx, num
        lea dx, msg2
        call print_msg
        jmp myend
    _zer:
        mov dx, 1
        lea dx, msg4
        call print_msg
        jmp myend
    myend:

endm

code segment
assume cs:code,ds:data,ss:sseg
start: mov ax,data ; настроить сегментный
 mov ds,ax ; регистр DS на данные
 .386
 check_num x
 mov ah,4ch ; завершить программу
 int 21h ; и выйти в DOS

print_msg proc
 push ax 
 mov ah,09h 
 int 21h 
 pop ax 
 ret 
print_msg endp

code ends


end start