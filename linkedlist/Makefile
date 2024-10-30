.SILENT:

CC = gcc
CFLAGS = -Wall -g

TARGET = LL
SRCS = ll.c

run:
	@clear
	@ctags *
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)
	./$(TARGET) $(filter-out $@,$(MAKECMDGOALS))

class:
	@clear
	@ctags *
	g++ -o classll ll.cpp
	./classll

circ:
	@clear
	@ctags *
	gcc -o Circ circlist.c
	./Circ

dub:
	@ctags *
	gcc -o Dub dublist.c
	./Dub


%:
	@:

.PHONY: all clean run
