CC=gcc
CFLAGS=-I.

# Object files
OBJ = color.o colormath.o rank.o unrank.o successor.o generate.o

# Target executable name
TARGET = color

# $@ is the target name, $^ are the prerequisite files
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
