%include "macros.mac"

; _______________DATA_______________
section .data
    mess_line db '+-------------------------------', 0
    len_line equ $-mess_line

    mess_inp_file db '|   File name: ', 0
    len_inp_file equ $-mess_inp_file

    mess_inp_word db '|        Word: ', 0
    len_inp_word equ $-mess_inp_word

    mess_is_open db '->  Open file', 0
    len_is_open equ $-mess_is_open

    mess_ist_open db '!!! File not found !!!', 0
    len_ist_open equ $-mess_ist_open

    mess_file_closed db '->  Close file', 0
    len_file_closed equ $-mess_file_closed

    mess_wrong_stack db '!!! Wrong input !!!', 0
    len_wrong_stack equ $-mess_wrong_stack

    mess_delete_complete db '->  Deleting...', 0
    len_delete_complete equ $-mess_delete_complete

    filename times 16 dw 0
    zero db 0
    
section .bss
    fd resb 8
    
    write_index resb 4
    read_index resb 4
    buffer resb 1

    stack_word resb 16
    input_word resb 16
; __________________________________


; _______________CODE_______________
    section	.text
	global _start
    
_start:
    ; prolog
    push ebp
    mov ebp, esp

;------ check stack ------
    mov ebx, [ebp+4]
    cmp ebx, 3
    je _stack_ist_empty
        PRINTLN mess_wrong_stack, len_wrong_stack
        call _exit
    _stack_ist_empty:
;------ check stack ------


;------ read filename ------
    mov edx, [ebp+12]
    mov ecx, 0
    _read_filename_loop:
        mov eax, [edx]
        mov [filename+ecx], al

        inc edx
        inc ecx
        cmp byte [edx], 0x00
    jne _read_filename_loop
;------ read filename ------
    
;------ read word ------
    mov ecx, 0
    _read_deleting_word:
        mov eax, [edx]
        mov [stack_word+ecx], ah

        inc edx
        inc ecx
        cmp byte [edx], 0x00
    jne _read_deleting_word
;------ read word ------

;----------- print filename and word --------
    PRINTLN mess_line, len_line 
    PRINT mess_inp_file, len_inp_file
    PRINTLN filename, 16

    PRINT mess_inp_word, len_inp_word
    PRINTLN stack_word, 16
    PRINTLN mess_line, len_line 
    PRINTLN
;--------------------------------------------

;---------- main work -----------------
    call _open_read_file
    call _is_read_file_open
    PRINTLN

    mov edx, 0
    mov [write_index], edx
    mov [read_index], edx

    call _read_file_and_write 
    call _clear_file_end
    

    PRINTLN mess_delete_complete, len_delete_complete

    PRINTLN
    call _close_read_file

    leave ; epilog
call _exit
;--------------------------------------




; _______________READ_FILE_______________
_open_read_file:
    mov eax, sys_open
    mov ebx, filename
    mov ecx, 2 ; read and write
    mov edx, 00777 ; read
    sys_call
    mov [fd], eax
ret

_is_read_file_open:
    mov eax, [fd]
    cmp eax, -1
    jle _cant_open
    PRINTLN mess_is_open, len_is_open
ret

_cant_open:
    PRINTLN mess_ist_open, len_ist_open
    call _exit
ret

_close_read_file:
    mov eax, sys_close
    mov ebx, [fd]
    sys_call
    PRINTLN mess_file_closed, len_file_closed
ret
; _______________________________________



; ___________Removing and writing_________
_read_file_and_write:
    mov ecx, 0
    read_loop:
    ; exit if end of file
        call _read_byte
        call _inc_read_file_index
        cmp eax, 1
        jne end_read_loop
    ; -----------------------


    ; if end of world
        cmp byte [buffer], ' '
        je first_part
        cmp byte [buffer], '.'
        je first_part
        cmp byte [buffer], ','
        je first_part
        jmp end_first_part 
        first_part:
            ; first part
            call _is_equals
            cmp eax, 1
            je end_first_first
                call _write_input_word_in_file
                call _write_buffer_in_file
                ;SPRINT input_word, 16
                ;SPRINT buffer, 1
                jmp end_first
            end_first_first:

            cmp byte [buffer], ' '
            je end_first 
                ; dec write file index
                call _dec_write_file_index
                call _write_buffer_in_file
                ;SPRINT buffer, 1
            end_first:

            call _clear_word
            mov ecx, 0
            jmp read_loop
        end_first_part:
    ; -----------------------

    ; if symbol 
        cmp byte [buffer], 0x0a
        je end_second_part
        second_part:
            mov eax, [buffer]
            shl eax, 24
            shr eax, 24
            call _write_byte_in_inp_word
            jmp read_loop
        end_second_part:

    ; -----------------------

    ; else (\n)
        third_part:
            call _write_buffer_in_file
            ;SPRINT buffer, 1 
            call _clear_word
            mov ecx, 0 
            jmp read_loop
    ; -----------------------

    jmp read_loop
end_read_loop:
ret


_inc_read_file_index:
    push eax
    mov eax, [read_index]
    add eax, 1
    mov [read_index], eax
    pop eax
ret

_dec_write_file_index:
    push eax
    mov eax, [write_index]
    dec eax
    mov [write_index], eax
    pop eax
ret

; eax = 1 - equals, 0 - not equals
_is_equals:
    push ecx
    push edx
    mov ebx, input_word
    call _len_str
    cmp eax, 0
    je _is_equals_make_zero
   
    mov ecx, 0
    _is_equals_loop:
        mov edx, [stack_word+ecx]
        cmp [ebx+ecx], edx
        jne _is_equals_make_zero
        cmp byte [ebx+ecx], 0
    je _is_equals_make_one
        inc ecx
    jmp _is_equals_loop

    _is_equals_make_one:
        mov eax, 1
        jmp _is_equals_end
    _is_equals_make_zero:
        mov eax, 0
    _is_equals_end:
        pop edx
        pop ecx
ret

; eax - amount of read bytes
_read_byte:
    push ebx
    push edx
    push ecx

    mov eax, sys_read
    mov ebx, [fd]
    mov ecx, buffer
    mov edx, 1
    sys_call

    pop ecx
    pop edx
    pop ebx
ret

_clear_word:
    push ecx
    mov ecx, 16
    clear_loop:
        mov dword [input_word+ecx-1], 0
        loop clear_loop
    pop ecx
ret

; eax - byte
; ecx - index, will inc after writing
_write_byte_in_inp_word:
    mov [input_word+ecx], eax
    inc ecx
ret

_write_input_word_in_file:
    push eax
    push ebx
    push ecx
    push edx

    ; adjust index for writing 
    mov eax, sys_lseek
    mov ebx, [fd]
    mov ecx, [write_index]
    mov edx, file_begin
    sys_call

    ; word length in eax
    mov ebx, input_word
    call _len_str

    ; inc write index
    mov edx, [write_index]
    add edx, eax
    mov [write_index], edx

    ; write input word
    mov edx, eax
    mov eax, sys_write
    mov ebx, [fd]
    mov ecx, input_word
    sys_call

    ; return file index back
    mov eax, sys_lseek
    mov ebx, [fd]
    mov ecx, [read_index]
    mov edx, file_begin
    sys_call

    pop edx
    pop ecx
    pop ebx
    pop eax
    
ret

_write_buffer_in_file:
    push eax
    push ebx
    push ecx
    push edx

    ; adjust index for writing 
    mov eax, sys_lseek
    mov ebx, [fd]
    mov ecx, [write_index]
    mov edx, file_begin
    sys_call

    ; inc write index
    mov edx, [write_index]
    inc edx 
    mov [write_index], edx

    ; write input word
    mov edx, 1
    mov eax, sys_write
    mov ebx, [fd]
    mov ecx, buffer
    sys_call

    ; return file index back
    mov eax, sys_lseek
    mov ebx, [fd]
    mov ecx, [read_index]
    mov edx, file_begin
    sys_call

    pop edx
    pop ecx
    pop ebx
    pop eax
ret

_clear_file_end:
; adjust index for writing 
    mov eax, sys_lseek
    mov ebx, [fd]
    mov ecx, [write_index]
    mov edx, file_begin
    sys_call
;------------------------------

    _clear_file_loop:
    ; exit if end of file
        call _read_byte
        cmp eax, 1
        jne end_clear_file_loop
    ; -----------------------

        call _set_previos_file_index

    ; write input word
        mov eax, sys_write
        mov ebx, [fd]
        mov edx, 1
        mov ecx, zero
        sys_call
    ; -----------------------

    ; move write index back
        mov ecx, [write_index]
        add ecx, 2
        mov [write_index], ecx
        mov eax, sys_lseek
        mov ebx, [fd]
        mov edx, file_begin
        sys_call
    ; -----------------------

    jmp _clear_file_loop
end_clear_file_loop:
ret

_set_previos_file_index:
    mov ecx, [write_index]
    dec ecx
    mov [write_index], ecx

    mov eax, sys_lseek
    mov ebx, [fd]
    mov edx, file_begin
    sys_call
ret
; ________________________________________


; ______________Other_____________________

    ; mov to ebx pointer to string
    ; length will be in eax
_len_str: 
    push ebx
    mov ecx, 0
    dec ebx
    _count:
        inc ecx
        inc ebx
        cmp byte [ebx], 0
        jnz _count
    dec ecx
    mov eax, ecx
    pop ebx
ret


_exit:
    mov eax, sys_exit
	mov ebx, 0
	sys_call 
; ________________________________________