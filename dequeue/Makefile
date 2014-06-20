OBJS = main.o
CC=clang++
DEBUG=-g
CFLAGS= -Wall -c $(DEBUG)
LFLAGS= -Wall $(DEBUG)
DFLAGS= -Wall -dynamiclib

deque: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o deque

main.o: deque.h
	$(CC) $(CFLAGS) main.cpp deque.h

clean:
	rm -f *.o *.h.gch deque
