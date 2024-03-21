all: order

order: order.c
	gcc -o order order.c -lm

clean:
ifeq ($(OS),Windows_NT)
	del /F /Q order.exe
else
	rm -f order
endif