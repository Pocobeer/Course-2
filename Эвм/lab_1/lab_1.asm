; Макроопределения

check_num macro num, zer, neg_, pos
    cmp num, 0
    jl neg_
    je zer
    jg pos
endm
; Резервирoвание места под стек
sseg segment stack 'stack'
 dw 256 dup(?)
sseg ends
; Определение данных
data segment
numx db 5
zerx db ?
neg_x db ?
posx db ?
data ends
code segment
assume cs:code,ds:data,ss:sseg
start: mov ax,data ; настроить сегментный
 mov ds,ax ; регистр DS на данные
 check_num	numx, zerx, neg_x, posx
 mov ah,4ch ; завершить программу
 int 21h ; и выйти в DOS
code ends
end start