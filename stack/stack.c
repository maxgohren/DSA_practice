#include <stdio.h>
#include <stdlib.h>

//#include "stack.h"

struct stack {
	int *s;
	int size;
	int top;

	void (*pop)();
	void (*push)(int);
};

typedef struct stack stack_t;

void push(int x)
{
}

void pop()
{
	printf("Popping an element\n");
}

int isEmpty()
{
	return 0;
}

int isFull()
{
	return 0;
}


int main()
{
	stack_t s = { NULL, 0, 0, pop, push};

	printf("Enter size of stack\n");
	scanf("%d", &s.size);
	s.top = 0;
	s.s = (int *)malloc( sizeof(int) * s.size);


	s.pop();
	s.push(5);



	return 0;
}
