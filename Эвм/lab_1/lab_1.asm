; Резервирoвание места под стек
sseg segment stack 'stack'
 dw 256 dup(?)
sseg ends
; Определение данных
data segment
;zerx db ?
;neg_x db ?
;posx db ?
;msg1 db 10, 13, 'input number', '$'
msg2 db 10, 13, 'Number is positive', '$'
msg3 db 10, 13, 'Number is negative', '$'
msg4 db 10, 13, 'Number is null', '$'
data ends

; Макроопределения
check_num macro num, _neg, _pos, _zer
    cmp  num, 0
    je _zer
    jg _pos
    jl _neg


endm

code segment
assume cs:code,ds:data,ss:sseg
start: mov ax,data ; настроить сегментный
 mov ds,ax ; регистр DS на данные
 .386
 mov ax,0
 check_num ax, m1, m2, m3
  m1:
        mov bx, ax
        lea dx, msg3
        call print_msg
        jmp myend
    m2:
        mov cx, ax
        lea dx, msg2
        call print_msg
        jmp myend
    m3:
        mov dx, 1
        lea dx, msg4
        call print_msg
        jmp myend
    myend:
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