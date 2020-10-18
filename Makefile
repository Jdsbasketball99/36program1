CC = g++
CFLAGS = -g -Wall -Werror

default: SearchNewBooks

SearchNewBooks: SearchNewBooks.o book.o
	$(CC) $(CFLAGS) -o SearchNewBooks SearchNewBooks.o book.o #100 class

SearchNewBooks.o: SearchNewBooks.cc
	$(CC) $(CFLAGS) -c SearchNewBooks.cc

book.o: book.cc book.h
	$(CC) $(CFLAGS) -c book.cc book.h

clean:
	$(RM) SearchNewBooks *.o

