#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *prev;
	int data;
	struct Node *next;
}*Head;


void Display()
{
	struct Node *t = Head;
	while(t != NULL){
		if( t == Head )
			printf("%d <->", t->data);
		else if( t->next == NULL)
			printf(" %d", t->data);
		else 
			printf(" %d <->", t->data);
		
		t = t->next;
	}
	printf("\n\n");
}

void createList(int A[], int size)
{

	Head = (struct Node*)malloc(sizeof(struct Node));
	Head->data = A[0];
	Head->next = NULL;
	Head->prev = NULL;

	struct Node *t, *last = Head;

	for(int i = 1; i < size; i++){
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		// doubly-link the list
		t->prev = last;
		last->next = t;

		// Reset pointers for next loop
		last = t;
		t = t->next;
	}
}
	

void Append(int n)
{
	struct Node *last = Head;

	while(last->next != NULL){
		last = last->next;
	}

	struct Node *t = (struct Node*)malloc(sizeof(struct Node));
	t->data = n;
	t->next = NULL;
	// doubly link the list
	t->prev = last;
	last->next = t;

}

int Length(){
	int length = 1;
	struct Node *t = Head;
	while( t->next != NULL ) {
		length++;
		t = t->next;
	}
	return length;
}

// delete 1-based position in list
void Delete(int pos){

	if( pos < 1 || pos > Length() )
		return;

	struct Node *last = Head;

	// Special case for first in list
	if(pos == 1){
		// TODO what about if list is only 1 node?
		Head = Head->next;
		Head->prev = NULL;
		printf("Deleting node %d with value %d from list\n", pos, Head->data);
		free(last);
	} else {
		// Move to specified position
		for(int i = 1; i < pos; i++){
			last = last->next;
		}

		// Check if last in list, special case, next is null
		if( pos == (Length()) ){
			printf("Deleting last node %d with value %d from list\n", pos, last->data);
			// Remove link to deleted node
			last->prev->next = NULL;
			free(last);
		} else {
			// Else remove then repair connections
			last->prev->next = last->next;
			last->next->prev = last->prev;
			free(last);
		}
	}
}

void Insert(int pos, int value)
{
	if(pos < 0 || pos > Length() ){
		return;
	}

	/* FIRST */
	if(pos == 0){
		// Create new node
		struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
		tmp->data = value;
		// Three connections to fix
		tmp->prev = NULL;
		tmp->next = Head;
		Head->prev = tmp;
		// Assign as new first node
		Head = tmp;
	/* LAST */
	} else if (pos == Length() ){
		struct Node *iterator = Head;
		// Move to last node in list
		while(iterator->next){
			iterator = iterator->next;
		}
		// Create new node
		struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
		tmp->data = value;
		// Three connections to fix
		tmp->next = NULL;
		tmp->prev = iterator;
		iterator->next = tmp;
	/* EVERYTHING ELSE */
	} else {
		// Move to position
		struct Node *iterator = Head;
		for(int i = 1; i < pos; i++){
			iterator = iterator->next;
		}
		// Create new node
		struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
		tmp->data = value;
		// Four connections to replace
		tmp->next = iterator->next;
		tmp->prev = iterator;
		iterator->next->prev = tmp;
		iterator->next = tmp;
	}
}


void Reverse()
{
	// ignore case of list smaller than 3 nodes
	struct Node *tmp;
	struct Node *p = Head;

	while(p){
		// Swap links from p -> second
		tmp = p->next;
		p->next = p->prev; 
		p->prev = tmp;
		
		// Move p to "prev" node
		p = p->prev;

		if(p && !p->next)
			Head = p;
	}
}

int main(){
	int input;
	int value = 0;
	int A[] = {1, 2, 3, 4, 5};
	createList(A, 5);
menu:
	system("clear");
	printf("Welcome to Doubly Linked List demo\n");
	printf("Please choose an action on the following list:\n");
	printf("1. Add node\n");
	printf("2. Delete node\n");
	printf("3. Reverse the list\n");
	printf("4. Insert in position");
	printf("\n");
	Display();
	scanf("%1d", &input);
	switch(input){
		case 1:
			printf("Please enter a value to append\n");
			scanf("%d", &input);
			Append(input);
		break;
		case 2:
			printf("Please enter a node to delete\n");
			scanf("%d", &input);
			Delete(input);
		break;
		case 3:
			printf("Reversing list...\n");
			Reverse();
		break;
		case 4:
			printf("Please enter a position (0 is before the first node) and a value\n");
			scanf("%d", &input);
			scanf("%d", &value);
			Insert(input, value);
		default:
			break;
	}
	Display();
	printf("Chose again? ( 1 = yes, 2 = exit)\n");
	scanf("%d", &input);
	if(input == 1) goto menu;

	return 0;
}
