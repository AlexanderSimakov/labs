section .data
    mess_sum db ' = %d', 0x0A, 0
    mess_first db '(2-1)', 0
    mess db '+(%d-%d)', 0

section .bss
    amount resb 4
    counter resb 4
    sum resb 4

section .text
    global print_progression
extern printf

print_progression:
    mov ebx, [esp+4]    ; amount
    mov [amount], ebx

    mov dword [counter], 1
    mov dword [sum], 1

    push mess_first
    call printf
    add esp, 4


    _LOOP:
    ; is end of out
        mov eax, [amount]
        mov ebx, [counter]
        cmp eax, ebx
        jng _ENDLOOP
    ;-------------

    ; encrease counter
        mov eax, [counter]
        inc eax
        mov [counter], eax
    ;-------------
        
    ; calculate sum
        mov eax, [sum]
        add eax, [counter]
        mov [sum], eax
    ;-------------

    ; print
        mov eax, [counter]
        mov ebx, eax
        add ebx, eax
        push eax
        push ebx
        push mess
        call printf
        add esp, 12
    ;-------------

        jmp _LOOP
    _ENDLOOP:

; print summ
    push dword [sum]
    push mess_sum
    call printf
    add esp, 8
;-------------

ret

