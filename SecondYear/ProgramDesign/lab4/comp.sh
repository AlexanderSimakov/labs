#!/bin/bash
nasm -f elf32 src/func.asm -F dwarf -o bin/func.o
gcc -m32 bin/func.o src/source.c -o bin/print_progression
rm bin/func.o
