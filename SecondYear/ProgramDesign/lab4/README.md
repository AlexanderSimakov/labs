# Task
- Write *assembly (nasm)* function for calculate and print progression
- Call this function from **C** program

## How to compile?
``` bash
./comp.sh
```
This wiil create a `bin/print_progression` executable file using **nasm** and **gcc**.

## How to use?
``` bash
cd bin/
./print_progression

Progression: (2-1)+(4-2)+(2*n-n)
Enter a number: 4
(2-1)+(4-2)+(6-3)+(8-4) = 10
```