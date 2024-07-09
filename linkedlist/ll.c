#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int sum(struct Node *p)
{
	int c = 0;
	while( p != NULL )
	{
		c += p->data;
		p = p->next;
	}
	return c;
}

int count(struct Node *p)
{
	int c = 0;
	while( p != NULL )
	{
		c += 1;
		p = p->next;
	}
	return c;
}

int max(struct Node *p)
{
	int max = INT_MIN;
	while(p != NULL)
	{
		if(p->data > max)
		{
			max = p->data;
		}
	p = p->next;
	}
	return max;
}

int min(struct Node *p)
{
	int min = INT_MAX;
	while(p != NULL)
	{
		if(p->data < min)
		{
			min = p->data;
		}
	p = p->next;
	}
	return min;
}
int main(){

	int A[] = {3,5,7,10,15};

	create(A, 5);
	display(first);
	displayRecursive(first); printf("\n");
	printf("The sum of all the nodes is %d\n", sum(first));
	printf("The amount of nodes is %d\n", count(first));
	printf("The max of the list is %d\n", max(first));
	printf("The min of the list is %d\n", min(first));


	return 0;
}
