#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
	int i;
	struct Node *tmp, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first; 

	for(i = 1; i < n; i++)
	{
		tmp = (struct Node *)malloc(sizeof(struct Node));
		tmp->data = A[i];
		tmp->next = NULL;
		
		last->next = tmp;
		last = last->next;
	}
}

void display(struct Node *ll)
{
	while(ll != NULL)
	{
		printf("%d ", ll->data);
		ll = ll->next;
	}
	printf("\n");
}

void displayRecursive(struct Node *ll)
{
	if(ll != NULL)
	{
		printf("%d ", ll->data);
		displayRecursive(ll->next);
	}
	
}

int main(){

	int A[] = {3,5,7,10,15};

	create(A, 5);
	display(first);
	displayRecursive(first); printf("\n");

	return 0;
}
