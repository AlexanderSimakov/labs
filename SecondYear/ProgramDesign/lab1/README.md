# Task
1. Search for the entered words in the file and display them on the screen 
2. Removing duplicate entered words
3. Create a 'Programm' class with getters and setters

## How to compile?
Use (Linux):
``` bash
./compile.sh
```
This will create a 'bin/out.o' executable file using g++ compiler.

## How to use?
``` bash
cd bin/
./out.o <filename> <word_1> <word_2> <word_n>
```

Example:
``` bash
cd bin/
./out.o <file.txt> <Lorem> <ipsum> <dolor>
```

Output:
``` bash
	Result:
Lorem: 1
dolor: 2
ipsum: 4
------------------------------

Amount before: 483
Amount after: 479


------ Star wars 0.11.3 ------
Game about stars and wars
Date: 12.01.21
Size: 3.2Gb
```



