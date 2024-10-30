#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*Head;

void Display(struct Node *h)
{
	do{
		if( h->next != Head)
			printf("%d -> ", h->data);
		else
			printf("%d ", h->data);
		h=h->next;
	}while(h!=Head);
	printf("\n");
}

void createCirc(int A[], int n)
{
	printf("Creating list:\n");
	int i;
	struct Node *t, *last;

	Head = (struct Node*)malloc(sizeof(struct Node));
	Head->data = A[0];
	Head->next = Head;
	last = Head;

	for(i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
	Display(Head);
}


void Append(int n)
{
	printf("Appending node %d\n", n);
	struct Node *last = Head;

	// Move last to "end" of list
	do{
		last = last->next;
	}while( last->next != Head );

	// Create new node and append to list, then recirculate the list
	struct Node *t = (struct Node*)malloc(sizeof(struct Node));
	t->data = n;
	t->next = Head;
	last->next = t;

	Display(Head);
}

void DisplayNode(struct Node *p)
{
	printf("Data,Next: %d,%d\n", p->data, p->next->data);
}

int Length(){

	int length = 0;

	struct Node *t = Head;
	while( t->next != Head ) {
		length++;
		t = t->next;
	} length++;
	return length;
}

void Insert(int pos, int n)
{
	if( pos < 0 || pos > Length() )
		return;

	printf("Inserting node %d at position %d\n", n, pos);
	struct Node *t;

	if(pos == 0){	
		struct Node *p = (struct Node *)malloc(sizeof(struct Node));
		p->data = n;

		if(Head == NULL){
			Head = p;
			p->next = Head;
		} else {
			t = Head;
			while( t->next != Head) t = t->next;
			t->next = p;
			p->next = Head;
			Head = p;
		}
	} else { 
		t = Head;

		for(int i = 0; i < pos-1; i++){ 
			t = t->next; 
		}

		struct Node *p = (struct Node *)malloc(sizeof(struct Node));
		p->data = n;
		p->next = t->next;
		t->next = p;
	}
	Display(Head);
}
	
void Delete(int pos){

	if( pos < 0 || pos > Length())
		return;

	printf("Deleting node %d from list\n", pos);
	struct Node *t = Head;
	struct Node *last = Head;

	if(pos == 0){
		while (t->next != Head){
			last = t;
			t = t->next;
		}
		Head = Head->next;
		free(t->next);
		t->next = Head;
	} else {
		int i = 0;
		do{
			last = t;
			t = t->next;
			i++;
		} while( i < pos - 1);

		last->next = t->next;
		free(t);
	}
	Display(Head);
}


int main()
{
	int A[] = {1, 2, 3};
	createCirc(A, 3);
	
	Append(4);
	Insert(4, 5);
	Insert(0, 0);
	Delete(0);
	Delete(3);


	return 0;
}

