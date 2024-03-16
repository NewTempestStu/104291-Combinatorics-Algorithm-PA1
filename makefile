all: subsets

subsets: subsets.c
    gcc -o subsets subsets.c -lm

clean:
    rm -f subsets
