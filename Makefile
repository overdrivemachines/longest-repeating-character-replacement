
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

longest-repeating-character-replacement: longest-repeating-character-replacement.o
	$(CC) $(CFLAGS) -o longest-repeating-character-replacement longest-repeating-character-replacement.o

longest-repeating-character-replacement.o: longest-repeating-character-replacement.cpp
	$(CC) $(CFLAGS) -c longest-repeating-character-replacement.cpp

clean:
	rm -rf longest-repeating-character-replacement longest-repeating-character-replacement.o
