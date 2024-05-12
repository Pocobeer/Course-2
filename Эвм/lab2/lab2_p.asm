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
        stosb                   ; копируем длину строки S в Res
        mov     ah,     al      ; сохраняем длину строки S
        cmp     al,     [Len]   ; сравниваем длину S с Len
        jae     StoreLen        ; если S >= Len, то копируем S и выходим

        
 Pad:

        
        mov al, [Len]
        mov es: [di-1], al        ; Дополняем строку
        mov cl, ah
        rep     movsb           ; записать очередной символ результата Res
StoreLen:
        mov cl, [Len]
        sub     cl,     ah      ; S длиннее, чем Len
         
        mov     al,     [Ch1]   ; добавляем очередной символ
        ;Копируем строку
        rep     stosb

 
Exit:   pop     ds              ; восстановить ds
        pop     bp              ; восстановить bp
        ret     12              ; выход с удалением параметров Ch1,
                                ; Ch2 и адреса S (Res удалять нельзя!)
PadCh  endp
code   ends
       end