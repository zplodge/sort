AR ?= ar
CC ?= gcc
EXECUTABLE=test
CFLAGS = -O3 -std=c99 -Wall -Wextra -Ideps

#SRCS = 
#SRCS += quick_sort.c 
#SRCS += heap_sort.c 
#SRCS += merge_sort.c 
#SRCS += test.c 
SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: test
test: quick_sort.o heap_sort.o merge_sort.o test.o sort.h
	$(CC) $(CFLAGS) $^ -o $@
	
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)

.PHONY: test  clean install uninstall

