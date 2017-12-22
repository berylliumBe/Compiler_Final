
; nasm -f macho hola.asm
; ld -o hola hola.o -lc /usr/lib/crt1.o
; ./hola



extern  _printf
extern  _scanf
extern  _puts
extern  _exit

global  _main

section .data
    ;message db "Hola, mundo", 10, 0
    scan_string     db  "%d", 0
    limit           dd  0
    output_string   db  "Value %d", 10, 0
;a:  dd   5
;fmt:  db  "a=%d, eax=%d", 10, 0


section .text
_main:
    sub esp, 12
    ;mov dword[esp], message
    ;call _printf
    ;add esp, 12
    ;mov eax, 0

    mov dword[esp], scan_string
    mov dword[esp + 4], limit
    call _scanf
    mov dword[esp], output_string
    mov eax, [limit]
    mov dword[esp + 4], eax
    call _printf
    mov dword[esp], 0
    call _exit
    ret
