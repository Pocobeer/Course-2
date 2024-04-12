; Резервирoвание места под стек
sseg segment stack 'stack'
 dw 256 dup(?)
sseg ends
; Определение данных
data segment
x dw 5
zerx db ?
neg_x db ?
posx db ?
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
        jmp myend
    _pos:
        mov cx, num
        jmp myend
    _zer:
        mov dx, 1
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
code ends

end start