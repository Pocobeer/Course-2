code    segment byte public
        assume  cs:code,ds:nothing
        public  PadCh
 
 
;function PadCh(S: string; C: char; Len: byte): string,
;Возвращает строку,  в которой S смещена влево, а остаток строки заполнен символами С.
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
        cld                     ; очистка флага направления (инкремент)
        lodsb                   ; al:=(ds:[si]), si:=si+1 (al - длина S)
        mov     ah,     al
        cmp     al,     [Len]
        jae     StoreLen
        mov     al,     [Len]

 Pad:
        mov     ch,     0
        mov     cl,     al
        sub     cl,     ah      ; S длиннее, чем Len
        jbe     Exit            ; выход, если s - меньше чем Len
 
        ; Дополняем строку
        mov     al,     [Ch1]   ; добавляем очередной символ
        rep     stosb           ; записать очередной символ результата Res
StoreLen:
        stosb                   ; (es:[di]):=al, di:=di+1 (запись длины)
        mov     ch,     0       ; подготовка сх в качестве счетчика
        mov     cl,     ah      ; количества символов строки S
        jcxz    Pad             ;если S - пустая строка (сх=0), то заполнить её символами
 
        ;Копируем строку
        rep     movsb

 
Exit:   pop     ds              ; восстановить ds
        pop     bp              ; восстановить bp
        ret     12-4              ; выход с удалением параметров Ch1,
                                ; Ch2 и адреса S (Res удалять нельзя!)
PadCh  endp
code   ends
       end