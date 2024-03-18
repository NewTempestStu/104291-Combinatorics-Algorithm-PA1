CC=gcc
CFLAGS=-I.

# Object files
OBJ = color.o colormath.o

# Target executable name
TARGET = colorprog

# $@ is the target name, $^ are the prerequisite files
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
