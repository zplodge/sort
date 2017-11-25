AR ?= ar
CC ?= gcc
EXECUTABLE=test
CFLAGS = -O3 -std=c99 -Wall -Wextra -Ideps

SRCS = quick_sort.c \
		test.c 

OBJS = $(SRCS:.c=.o)

all: test
test: quick_sort.o test.c
	#$(CC) $(CFLAGS) linkedlist.o main.c -o $(EXECUTABLE)
	$(CC) $(CFLAGS) $^ -o $@
	
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)

.PHONY: test  clean install uninstall

