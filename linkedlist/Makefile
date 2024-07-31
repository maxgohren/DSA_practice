CC = gcc
CFLAGS = -Wall -g

TARGET = LL
SRCS = ll.c

run:
	@clear
	@ctags *
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)
	./$(TARGET) $(filter-out $@,$(MAKECMDGOALS))

%:
	@:

.PHONY: all clean run



