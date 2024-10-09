#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
	int data;
	struct Node *next;
}*first=NULL,*second=NULL;

void createFirst(int A[], int n)
{
	printf("Creating first list with size %d and values: \n%d ", n, A[0]);
	int i;
	struct Node *tmp, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first; 

	for(i = 1; i < n; i++)
	{
		printf("%d ", A[i]);
		tmp = (struct Node *)malloc(sizeof(struct Node));
		tmp->data = A[i];
		tmp->next = NULL;
		
		last->next = tmp;
		last = last->next;
	}
	printf("\n");
}

void createSecond(int A[], int n)
{
	printf("Creating second list with size %d and values: \n%d ", n, A[0]);
	int i;
	struct Node *tmp, *last;
	second = (struct Node *)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second; 

	for(i = 1; i < n; i++)
	{
		printf("%d ", A[i]);
		tmp = (struct Node *)malloc(sizeof(struct Node));
		tmp->data = A[i];
		tmp->next = NULL;
		
		last->next = tmp;
		last = last->next;
	}
	printf("\n");
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
	printf("The sum of all the nodes is %d\n", c);
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
	printf("The amount of nodes is %d\n", c);
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
	printf("The max of the list is %d\n", max);
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
	printf("The min of the list is %d\n", min);
	return min;
}

struct Node *search(struct Node *p, int key)
{
	printf("Searching for %d\n", key);
	struct Node *q = p;

	while(p)
	{
		if(p->data == key)
		{
			// move to front for faster searching
			q->next = p->next;
			p->next = first;
			first = p;
			printf("Found the element %d in the list\n", key); 
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
	printf("Did not find the element %d in the list\n", key); 
}

void insertFront(struct Node *p, int n)
{
	printf("Inserting new node in front with data %d\n", n);
	// createFirst new node on HEAP
	struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
	
	tmp->data = n;
	tmp->next = first;

	first = tmp; // makes the pointer pointing to the 'first' node point to the new first node

	display(first);
}

void insertIndex(struct Node* p, int index, int n)
{
	int c = 0;
	if(index == 0)
		return insertFront(p, n);
	else {
		printf("Inserting new node at index %d with data %d\n", index, n);
		c++;
		while( p && c < index)
		{
			p = p->next;
			c++;
		}

		struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
		tmp->data = n;
		tmp->next = p->next;
		p->next = tmp;
	}

	display(first);
}

void insertSort(struct Node* p, int n)
{
	struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->next = NULL;
	tmp->data = n;

	if(first == NULL)
		first = tmp;
	else if( n < p->data)
	{
		insertFront(first, n);
		return;
	}
	else
	{
		printf("Inserting new node in sorted order with data %d\n", n);
		while(p && p->next && p->next->data < n)
		{
			p = p->next;
		}
			tmp->next = p->next;
			p->next = tmp;
	}

	display(first);
}

void delete(struct Node* p, int index)
{
	printf("Deleting node %d from list\n", index);
	int c = 1;
	
	if(index == 0)
	{
		first = first->next;
		free(p);
		display(first);
		return;
	}
	else
	{
		int cl = count(first);
		if(index > cl)
		{
			printf("Index is greater than list, could not delete\n");
			return;
		}
		struct Node* q = p;
		while(p)
		{
			if(c == index)
			{
				q->next = p->next;
				free(p);
				display(first);
				return;
			}
			c++;
			q = p;
			p = p->next;
		}
	}
}

void removeDuplicates(struct Node* p)
{
	printf("Removing duplicates from list\n");
	struct Node* q = p->next;

	while(q)
	{
		if(q->data != p->data)
		{
			q = q->next;
			p = p->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
	display(first);
}

void reverseList(struct Node* p)
{
	printf("Reversing list\n");
	struct Node* q, *r;
	q = r = NULL;

	while(p)
	{
		// slide pointers down list
		r = q;
		q = p;
		p = p->next;

		// reverse the links
		q->next = r;
	}
	first = q;
	display(first);
}

void reverseRecursive(struct Node* p, struct Node* q)
{
	printf("Reversing list recursively\n");
	if(p)
	{
		reverseRecursive(p, p->next);
		p->next = q;
	} else {
		first = q;
	}
	display(first);
}


void concatenate(struct Node *f, struct Node *s)
{
	printf("Concatenating the following lists:\n");
	struct Node *r, *l; // return and l
	r = l = f;
	// move all the way to end of f
	while(l->next != NULL) l = l->next;
	// make f->next = s;
	l->next = s;
	// return r;
	display(r);
}

void merge(struct Node* f, struct Node* s)
{
	printf("Merging the following lists:\n");
	display(f); 
	display(s);

	// just pointers to EXISTING nodes that have already been malloc'd, do not need to malloc these
	struct Node *r, *l; // r = return node, l = last node;

	if (f->data < s->data) {
		r = l = f; 		   // move l and r to smallest node
		f = f->next; 	   // move first to next
		l->next = NULL;    // clear link to prepare for next smaller node
	} else {
		r = l = s;
		s = s->next; 	   // move second to next
		l->next = NULL;    // clear link to prepare for next smaller node
	}
	// loop through list and merge smaller list
	while( f != NULL && s != NULL) {
		if( f->data < s->data){
			l->next = f;   // link last node to smaller node
			l = f;		   // move l to "last" node`
			f = f->next;   // move first node to next node in list
			l->next = NULL;// clear link to prepare for merge
		} else {
			l->next = s;   // link last node to smaller node
			l = s;		   // move l to "last" node`
			s = s->next;   // move first node to next node in list
			l->next = NULL;// clear link to prepare sor merge
		}
	}
	// add rest of list from the non-null node
	// if s is null, then make next point to first list else the opposite.
	if(!s)
		l->next = f;
	else
		l->next = s;
	display(r);
}
			

int isLoop(struct Node *f)
{
	struct Node *p, *q;

	p = q = f;

	do
	{
		p = p->next;
		q = q->next;
		q = q ? q->next : q;
	} while (p && q && p != q);

	if ( p == q)
		return 1;
	else 
		return 0;
}


int main(int argc, char **argv){

	//printf("argc: %d\n", argc);
	//for(int i = 0; i < argc; i++){
	//printf("argv[%d] = %s\n", i, argv[i]);
	//}

	if(argc < 2)
	{ 
		printf("Usage: make run <case #>\n");
		exit(0);
	}

	switch( atoi(argv[1]) )
	{
		default:
		case 1:
			printf("Running Case 1: insertion and misc. items\n");
			int A[] = {3,5,7};
			createFirst(A, 3);
			display(first);
			displayRecursive(first); printf("\n");
			count(first);
			sum(first);
			min(first);
			max(first);

			search(first, 5);

			display(first);
			insertFront(first, 25);
			insertIndex(first, 0, 14);
			insertIndex(first, 4, 14);
			break;
		case 2:
			printf("Running Case 2: insertion\n");
			// Sorted list
			int B[] = {10,20,30};
			createFirst(B, 3);
			insertSort(first, 34);
			insertSort(first, 16);
			insertSort(first, 3);
			break;
		case 3:
			printf("Running Case 3: deletion\n");
			int C[] = {0, 1, 2, 3, 4 };
			createFirst(C, 5);
			delete(first, 0);
			delete(first, 3);
			delete(first, 4);
			break;
		case 4:
			printf("Running Case 4: removing duplicates\n");
			int D[] = { 1 , 2, 3 , 4, 4, 5, 6, 7, 8, 8 };
			createFirst(D, 10);
			removeDuplicates(first);
			break;
		case 5:
			printf("Running Case 5: reversal of list\n");
			int E[] = { 10, 20, 30, 40, 50, 60 };
			createFirst(E, 6);
			reverseList(first);
			reverseRecursive(NULL, first);
			break;
		case 6:
			printf("Concatenation of lists\n");
			int F[] = { 2, 8, 10, 15};
			int G[] = { 4, 7, 12, 14};
			createFirst(F, 4);
			createSecond(G, 4);
			concatenate(first, second);
			break;
		case 7:
			printf("Concatenation of lists\n");
			int H[] = { 2, 8, 10, 15};
			int I[] = { 4, 7, 12, 14};
			createFirst(H, 4);
			createSecond(I, 4);
			merge(first, second);
			break;
		case 8:
			printf("Checking for loop in list\n");
			int J[] = { 2 , 4 , 6 , 8 , 10};
			createFirst(J, 5);
			struct Node *t1, *t2;
			t1 = first->next->next;
			t2 = first->next->next->next->next;
			t2->next = t1;
			printf("The result of isLoop() is %d\n", isLoop(first));
	}


	return 0;
}
