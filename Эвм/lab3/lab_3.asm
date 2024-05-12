cseg    segment
        assume cs:cseg,ds:cseg
    
; аргументы функции
x  dd  1.2, 3.0001, 0.1, 2.99, 4.288, 6.789, 7.987, 10.021
; результат вычисления функции
z dd ?
beg: 
    mov     ax,cs       ;Настроить сегментные
    mov     ds,ax       ;регистры
    finit               ;инициализировать сопроцессор
    fldpi                ;загружаем максимальную погрешность
    lea si, [x]         ;загружаем массив
    ; Настраиваем счетчик
    mov ch, 0
    mov cl, 7
    ; Сохраняем результат
    mov bh, 0; текущий индекс
    mov bl, 0;индекс минимального числа
    
Repeated: 
    inc bh
    fld dword ptr [si]  ;загрузить х
    add si, 4           
    fld     st(0)       ;образовать копию x(i)                          ;st(0)-копия х,st(1)-теущий х, st(2)-res
    frndint             ;Округлить до целого x1(i)                      ;st(0)-округленная копия х,st(1)-теущий х, st(2)-res
    fsubp   st(1),st(0) ;Вычитание вещественное с выталкиванием         ;st(0)-до ближайшего целового х,st(1)-res
    fabs                ;Модуль                                         ;st(0)-модуль до ближайшего целового,st(1)-res
    fcom   st(1)        ;Сравниваем текущую масимальную погрешность     ;st(0)-до ближайшего целового,st(1)-res
    .386
    fstsw ax            ;Записываем значения кодов условия
    sahf                ;загрузить коды во флаговый регистр
    ja     Processing   ;если >= переходим на финальную обработку  
NewEps:
    fxch    st(1)                                                       ;st(0)-res,st(1)-до ближайшего целового
    
    mov bl, bh
    
Processing:
    fstp st(0)             ;Уменьшаем указатель стека  на 1
    loop Repeated
Exit:
    fstp    z           ;сохранить результат
    mov     ax,4c00h    ;вернуться в DOS
    int 21h                   
cseg ends
    end beg