#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
            return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
      if(arr.A[i]>max)
        max=arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int s=0;
    int i;
    for(i=0;i<arr.length;i++)
        s+=arr.A[i];
    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void Display(struct Array arr)
{
    for(int i = 0; i<arr.length;i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void InsertSort(struct Array *arr, int x)
{
    int i = arr->length-1;
    if (arr->length == arr->size)
        return;
    while(i >= 0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i = 0;
    for(i = 0; i < arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length-1;
    
    while ( i < j)
    {
        while(arr->A[i] < 0) i++;
        while(arr->A[j] >= 0) j--;
        if(i < j) swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array* Merge(struct Array A, struct Array B)
{
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array *C = (struct Array *)malloc(sizeof(struct Array));

    while( i < A.length && j < B.length)
    { 
        if(A.A[i] < B.A[j])
            C->A[k++] = A.A[i++];
        else
            C->A[k++] = B.A[j++];
    }
    for( ; i < A.length ; i++)
        C->A[k++] = A.A[i];
    for( ; j < B.length ; j++)
        C->A[k++] = A.A[j];
   
    C->length = A.length + B.length;
    C->size = 10; 

    return C;
}

struct Array* Union(struct Array A, struct Array B)
{
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array *C = (struct Array *)malloc(sizeof(struct Array));

    while( i < A.length && j < B.length)
    { 
        if(A.A[i] < B.A[j])
            C->A[k++] = A.A[i++];
        else if(B.A[j] < A.A[i])
            C->A[k++] = B.A[j++];
        else{ 
            C->A[k++] = A.A[i++];
            j++;
        }
    }

    for( ; i < A.length ; i++)
        C->A[k++] = A.A[i];
    for( ; j < B.length ; j++)
        C->A[k++] = A.A[j];
   
    C->length = k;
    C->size = 10; 

    return C;
}

struct Array* Intersection(struct Array A, struct Array B)
{
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array *C = (struct Array *)malloc(sizeof(struct Array));

    while( i < A.length && j < B.length)
    {
        if(A.A[i] < B.A[j])
            i++;
        else if(B.A[j] < A.A[i])
            j++;
        else{
            C->A[k++] = A.A[i++];
            j++;
        }
    }

    C->length = k;
    C->size = 10;

    return C;
}

struct Array* Difference(struct Array A, struct Array B)
{
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array *C = (struct Array *)malloc(sizeof(struct Array));

    while( i < A.length && j < B.length)
    {
        if(A.A[i] < B.A[j])
            C->A[k++] = A.A[i++];
        else if(B.A[j] < A.A[i])
            j++;
        else{ 
            i++;
            j++;
        }
    }

    for( ; i < A.length ; i++)
        C->A[k++] = A.A[i];

    C->length = k;
    C->size = 10;

    return C;
}

int Search(struct Array A, int key)
{
    int l, m, h;
    l = 0;
    h = A.length - 1;
    while(l <= h)
    {
        m = (l + h) / 2;
        if(key == A.A[m])
            return m;
        if(key < A.A[m])
            h = m - 1;
        else if(key > A.A[m])
            l = m + 1;
    }
    return -1;
}
         
        
int Delete(struct Array *A, int index)
{
    int x = 0;
    int i;

    if(index >= 0 && index < A->length)
    {
        x = A->A[index];
        for(i = index; i < A->length-1; i++)
            A->A[i] = A->A[i+1];
        A->length--;
        return x;
    }

    return 0;
}

int main()
{
    struct Array A;
    int ch = 0;
    int x, index;

    printf("Enter size of Array A: ");
    scanf("%d", &A.size);
    A.A = (int *)malloc(A.size * sizeof(int));
    A.length = A.size;

    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while(ch < 6 )
    { 
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: printf("Enter an element and index ");
                   scanf("%d%d", &x, &index);
                   Set(&A, index, x); 
                   Display(A);
                   break;
            case 2: printf("Enter an index to delete ");
                   scanf("%d", &index);
                   Delete(&A, index); 
                   Display(A);
                   break;
            case 3: printf("Enter an element to search for");
                   scanf("%d", &x);
                   index = Search(A, x);  
                   if(index != -1)
                       cout << "Element " << x << " was found at index: " << index << endl;
                   else
                       cout << "Element " << x << " was not found" << endl;
                   break;
            case 4: printf("The sum of A: ");
                   x = Sum(A); 
                   cout << x << endl;
                   break;
            case 5: printf("Elements are: \n"); 
                   Display(A);
        } 
    }
               
    
    return 0;
}

