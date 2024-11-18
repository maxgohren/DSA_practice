struct stack {
	int *s;
	int size;
	int top;

	void (*pop);
	void (*push)(int);
	void (*test);
};

typedef struct stack stack_t;
