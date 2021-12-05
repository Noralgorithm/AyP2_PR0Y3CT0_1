CC=gcc
CFLAGS= -g -lm
Calc: main.o stack.o
	$(CC) $(CFLAGS) -o Calc main.o

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -rf *.o

