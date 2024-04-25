_STACK  segment para stack
        db      1024 dup(?)
_STACK  ends
 
 
String  macro   VarName, VarValue
        local   after
        VarName db      after-VarName-1
                db      VarValue
        after   =       $
endm
 
data    segment
        CrLf    db      0Dh, 0Ah, '$'
        String  asTest1, <'Proverka jelaemaya < tekuwei'>
        String  asTest2, <'Proverka jelaemaya > tekuwei'>
        String  asTest3, <'Proverka pustaya stroka'>
 
        String   asSrc, <'qwert'>
        asRes   db      0, 255 dup(?)
 
        Ch1     db      'A'
        Len1    db      3
 
        Ch2     db      '1'
        Len2    db      9
 
        Ch3     db      'A'
        Len3    db      7
 
data    ends
 
code    segment byte public
        assume  cs:code, ds:data, ss:_STACK
 
        extrn   PadCh:far
 
DoTest  macro   N
        mov     [asRes],        0
 
        push    ds
        lea     ax,     [asTest&N]
        push    ax
        call    writeln
        push    ds
        mov     ax,     offset asRes
        push    ax
        push    ds
        mov     ax,     offset asSrc
        push    ax
        mov     al,     [Ch&N]
        push    ax
        mov     al,     [Len&N]
        push    ax
        call    PadCh
        add     sp,     4       ;;удаляем из стека адрес возвращаемой строки
        push    ds
        lea     ax,     [asRes]
        push    ax
        call    writeln
endm
 
writeln proc    far
        push    bp
        mov     bp,     sp
        push    ds
 
        lds     si,     [bp+6]
        mov     ah,     40h
        mov     bx,     1
        xor     cx,     cx
        mov     cl,     [si]
        lea     dx,     [si+1]
        int     21h
        mov     ah,     02
        mov     dl,     0Dh
        int     21h
        mov     dl,     0Ah
        int     21h
 
        pop     ds
        pop     bp
        ret     4
writeln endp
 
main    proc
        ;инициализация сегментного регистра данных
        mov     ax,     data
        mov     ds,     ax
 
        DoTest  1
        DoTest  2
        mov     [asSrc],        0
        DoTest  3
 
        ;завершение программы
        mov     ax,     4C00h
        int     21h
main    endp
 
code    ends
 
        end     main