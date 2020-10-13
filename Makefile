CC = g++
CFLAGS = -g -Wall -Werror

default: SearchNewBooks.cc

SearchNewBooks: SearchNewBooks.o
	$(CC) $(CFLAGS) -o SearchNewBooks SearchNewBooks.o #100 class

SearchNewBooks.o: SearchNewBooks.cc
	$(CC) $(CFLAGS) -c SearchNewBooks.cc


clean:
	$(RM) SearchNewBooks *.o

