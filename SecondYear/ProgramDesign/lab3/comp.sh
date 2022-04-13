#!/bin/bash
nasm -i src/ -f elf32 -F dwarf -g src/rem_word.asm -o bin/rem_word.o

