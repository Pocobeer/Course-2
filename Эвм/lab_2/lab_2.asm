code segment byte public
 assume cs:code,ds:code
 public Change
; function Change(S: string; Ch1, Ch2: char):
;string, возвращает строку, в которой все вхождения
;Сh1 заменены на Ch2
Change proc far
; адреса параметров в стеке:
Ch2 equ byte ptr [bp+6] ; параметр Ch2
Ch1 equ byte ptr [bp+8] ; параметр Ch1
S equ dword ptr [bp+10]; адрес строки S
Res equ dword ptr [bp+14]; адрес строки
 ; результата
 push bp ; сохранение bp
 mov bp,sp ; настройка bp на вершину
 ; стека
 push ds ; сохранение ds
 les di,Res ; es:di:=адрес результата
 lds si,S ; ds:si:=адрес исходной
 ; строки
 cld; очистка флага направления (инкремент)
 lodsb; al:=(ds:[si]), si:=si+1 (al - длина S)
 stosb; (es:[di]):=al, di:=di+1 (запись длины)
 mov ch,0; подготовка сх в качестве счетчика
 mov cl,al; количества символов строки S
 jcxz Exit; выход, если S - пустая строка (сх=0)
Repeat: lodsb ; считать в al очередной символ S
 cmp al,Ch1; символ равен Ch1?
 jne Save; нет, сохранить без изменений
 mov al,Ch2 ; да, заменить на Ch2
Save: stosb; записать очередной символ результата Res
 loop Repeat ; повторять, пока есть
 ; символы в S (cx>0)
Exit: pop ds ; восстановить ds
 pop bp ; восстановить bp
 ret 8; выход с удалением параметров Ch1,
 ; Ch2 и адреса S (Res удалять нельзя!)
Change endp
code ends
 end
code segment
 assume cs:code,ds:code
 extrn Change:far; описание внешней
 ; far-процедуры
Example: mov ax, cs; настройка сегмента данных
 mov ds,ax ; на сегмент кода
; подготовка параметров вызова Change(S,'1','2')
 push ds; сегмент строки результата Res
 mov ax, offset Res
 push ax; смещение Res
 push ds; сегмент исходной строки S
 mov ax, offset S
 push ax; смещение S
 mov al, '1'; параметр Ch1 = '1'
 push ax
 mov al, '2'; параметр Ch2 = '2'
 push ax
 call Change ; far-вызов Change
; чтение адреса результата функции Change из стека
 pop bx ; bx:=смещение Res
 pop ds ; ds:=сегмент Res
 mov ch, 0; подготовка в сх длины
 ; строки Res
 mov cl, [bx]
 jcxz Exit; выход, если строка Res пуста
Write: inc bx; продвижение указателя символа
 mov dl, [bx]; dl:=очередной символ Res
 mov ah, 2; вывод символа из dl
 int 21h ; на экран средствами DOS
 loop Write; цикл по длине строки Res
Exit: mov ax, 4c00h; завершение программы
 int 21h ; чеpез функцию DOS
S db 7, 'Ch1;Ch2', 248 dup(?)
Res dw 128 dup(?)
code ends
 end Example
