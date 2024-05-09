code    segment byte public
        assume  cs:code,ds:nothing
        public  PadCh
 
 
;function PadCh(S: string; C: char; Len: byte): string,
;Возвращает строку,  в которой S смещена вправо, а остаток строки заполнен символами С.
;Для этого знаки С включаются справа от конца S до тех пор  пока общая длина строки не
;станет равной Len. Если S длиннее чем Len, то строка не изменяется.
;Если S пустая строка, то возвращается строка из Len символов С.
PadCh   proc    far
; адреса параметров в стеке:
S       equ     dword ptr [bp+10]       ;  адрес строки S:string
Ch1     equ     byte  ptr [bp+8]        ;  адрес параметра С :Char
Len     equ     byte  ptr [bp+6]        ;  адрес параметра Len:Byte
Res     equ     dword ptr [bp+14]       ;  адрес строки результата
        push    bp                      ; сохранение bp
        mov     bp,     sp      ; настройка bp на вершину стека
        push    ds              ; сохранение ds
        les     di,     [Res]   ; es:di:=адрес результата
        lds     si,     [S]     ; ds:si:=адрес исходной
                                ; строки
        xor ch, ch
        cld                     ; очистка флага направления (инкремент)
        lodsb                   ; al:=(ds:[si]), si:=si+1 (al - длина S)
        stosb
        mov     ah,     al
        cmp     al,     [Len]
        jae     StoreLen
        mov     al,     [Len]

 Pad:
        mov     cl,     al
        sub     cl,     ah      ; S длиннее, чем Len
 ;вычисляем длину результата
        add al, ah
        mov es: [di-1], al        ; Дополняем строку
        mov     al,     [Ch1]   ; добавляем очередной символ
        rep     stosb           ; записать очередной символ результата Res

  StoreLen:
        mov     cl,     ah      ; количества символов строки S
 
        ;Копируем строку
        rep     movsb

Exit:   pop     ds              ; восстановить ds
        pop     bp              ; восстановить bp
        ret     12              ; выход с удалением параметров Ch1,
                                ; Ch2 и адреса S 
PadCh  endp
code   ends
       end