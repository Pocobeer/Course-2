; PadCh.asm - Динамическая библиотека с функцией PadCh

.386
.model flat, stdcall
option casemap:none

; Экспортируемая функция
public PadCh

; Функция PadCh
PadCh proc pS:DWORD, pCh:BYTE, Len:BYTE, pRes:DWORD
    ; pS - адрес строки S
    ; pCh - символ для заполнения
    ; Len - длина результирующей строки
    ; pRes - адрес результата

    push ebp
    mov ebp, esp
    push edi
    push esi

    ; Получаем длину строки S
    mov esi, [ebp + 8] ; Адрес строки S
    movzx ecx, byte ptr [esi] ; Длина строки S
    mov edi, [ebp + 16] ; Адрес результата

    ; Если длина S больше или равна Len, копируем S
    cmp ecx, [ebp + 12] ; Сравниваем с Len
    jge .copy_string

    ; Если S пустая, заполняем результат символами pCh
    test ecx, ecx
    jz .fill_with_char

.copy_string:
    ; Копируем строку S в результат
    mov eax, ecx
    mov [edi], al ; Записываем длину
    inc edi
    mov ecx, eax
    rep movsb

    ; Заполняем остаток строки символами pCh
    movzx ecx, byte ptr [ebp + 12] ; Получаем Len
    sub ecx, eax ; Остаток
    mov al, [ebp + 9] ; Получаем символ для заполнения
.fill_loop:
    stosb
    loop .fill_loop
    jmp .done

.fill_with_char:
    ; Заполняем строку символами pCh
    movzx ecx, byte ptr [ebp + 12] ; Получаем Len
    mov al, [ebp + 9] ; Получаем символ для заполнения
.fill_loop_empty:
    stosb
    loop .fill_loop_empty

.done:
    pop esi
    pop edi
    pop ebp
    ret 12 ; Удаляем параметры
PadCh endp

end