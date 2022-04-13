# Task
- Create a program which will remove input word from input file.
- **Language:** Nasm
## How to compile?
``` bash
./comp.sh
./link.sh
```
This wiil create a `bin/rem_word` executable file using **nasm** and **ld**.

## How to use?
``` bash
cd bin/
./rem_word <filename> <word>
```
### Example
*example.txt:*
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit. 
Mauris sodales nisl ipsum, cursus fringilla odio consectetur quis.
```

Run program:
``` bash
cd bin/
./rem_word example.txt ipsum

+-------------------------------
|   File name: example.txt
|        Word: ipsum
+-------------------------------

->  Open file

->  Deleting...

->  Close file

```

*example.txt:*
```
Lorem dolor sit amet, consectetur adipiscing elit. 
Mauris sodales nisl, cursus fringilla odio consectetur quis.
```