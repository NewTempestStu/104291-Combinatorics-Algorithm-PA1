all: main

order: main.c
	gcc -o main main.c -lm

clean:
ifeq ($(OS),Windows_NT)
	del /F /Q main.exe
else
	rm -f main
endif