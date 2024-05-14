#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Array
{

private:
    int *A;
    int size;
    int length;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

public:
    Array()
    {
        size = 10;
        length = 10;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = sz;
        A = new int[size];
    }
    ~Array()
    {
        delete []A;
    }

int Get(int index);
void Set(int index, int x);
int Max();
int Min();
int Sum();
float Average();
void Display();
void InsertSort(int x);
int isSorted();
void Rearrange();
Array* Merge(Array B);
Array* Union(Array B);
Array* Intersection(Array B);
Array* Difference(Array B);
int Search(int key);
int Delete(int index);

};

<<<<<<< HEAD
int Array::Get(int index)
=======
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Get(struct Array arr, int index)
>>>>>>> 101be990b0f2003f39921b2748a9eae751c7e45c
{
    if(index>=0 && index<length)
            return A[index];
    return -1;
}

void Array::Set(int index, int x)
{
    if(index>=0 && index<length)
    {
        A[index] = x;
    }    
}

int Array::Max()
{
    int max=A[0];
    int i;
    for(i=1;i<length;i++)
    {
      if(A[i]>max)
        max=A[i];
    }
    return max;
}

int Array::Min()
{
    int min=A[0];
    int i;
    for(i=1;i<length;i++)
    {
        if(A[i]<min)
            min=A[i];
    }
    return min;
}

int Array::Sum()
{
    int s=0;
    int i;
    for(i=0;i<length;i++)
        s+=A[i];
    return s;
}

float Array::Average()
{
    return (float)Sum()/length;
}

<<<<<<< HEAD
void Array::Display()
=======
void ReverseCopy(struct Array *arr)
{
    int *B;
    int i=0,j=0;
    
    B = (int *)malloc(arr->length*sizeof(int));
    
    for(i = arr->length-1, j=0; i>=0; i--,j++)
        B[j] = arr->A[i];
    for(i = 0; i<arr->length; i++)
        arr->A[i] = B[i];
}

void ReverseSwap(struct Array *arr)
{
    int i=0, j=0;
    for(i = 0, j = arr->length-1; i<j;i++,j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void Display(struct Array arr)
>>>>>>> 101be990b0f2003f39921b2748a9eae751c7e45c
{
    for(int i = 0; i < length;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

<<<<<<< HEAD
void Array::InsertSort(int x)
=======
bool isSorted(struct Array arr)
{
  for(int i = 0; i < arr.length-1; i++)
  {
    if(arr.A[i] > arr.A[i+1])
      return false;
  }
  return true;
}

int main()
>>>>>>> 101be990b0f2003f39921b2748a9eae751c7e45c
{
    int i = length-1;
    if (length == size)
        return;
    while(i >= 0 && A[i] > x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}

int Array::isSorted()
{
    int i = 0;
    for(i = 0; i < length-1; i++)
    {
        if(A[i] > A[i+1])
            return 0;
    }
    return 1;
}

void Array::Rearrange()
{
    int i, j;
    i = 0;
    j = length-1;
    
    while ( i < j)
    {
        while(A[i] < 0) i++;
        while(A[j] >= 0) j--;
        if(i < j) swap(&A[i], &A[j]);
    }
}

Array* Array::Merge(struct Array B)
{
    int i = 0;
    int j = 0;
    int k = 0;

    Array *C;

    while( i < length && j < B.length)
    {
        if( A[i] < B.A[j] )
            C->A[k++] = A[i++];
        else if(B.A[j] < A[i])
            C->A[k++] = B.A[j++];
    }

    for( ; i < length ; i++)
        C->A[k++] = A[i];
    for( ; j < B.length ; j++)
        C->A[k++] = B.A[j];
   
    C->length = length + B.length;
    C->size = 10; 

    return C;
}

struct Array* Array::Union(struct Array B)
{
    int i = 0;
    int j = 0;
    int k = 0;

<<<<<<< HEAD
    struct Array *C = (struct Array *)malloc(sizeof(struct Array));

    while( i < length && j < B.length)
    {
        if( A[i] < B.A[j] )
            C->A[k++] = A[i++];
        else if(B.A[j] < A[i])
            C->A[k++] = B.A[j++];
        else{ 
            i++;
            j++;
        }
    }

    for( ; i < length ; i++)
        C->A[k++] = A[i];
    for( ; j < B.length ; j++)
        C->A[k++] = B.A[j];
   
    C->length = k;
    C->size = 10; 

    return C;
}

Array* Array::Intersection(struct Array B)
{
    int i = 0;
    int j = 0;
    int k = 0;

    Array *C;

    while( i < length && j < B.length)
    {
        if( A[i] < B.A[j] )
            i++;
        else if(B.A[j] < A[i])
            j++;
        else{ 
            C->A[k++] = A[i++];
            j++;
        }
    }

    C->length = k;
    C->size = 10;

    return C;
}

Array* Array::Difference(Array B)
{
    int i = 0;
    int j = 0;
    int k = 0;

    Array *C;

    while( i < length && j < B.length)
    {
        if( A[i] < B.A[j] )
            C->A[k++] = A[i++];
        else if(B.A[j] < A[i])
            j++;
        else{ 
            i++;
            j++;
        }
    }

    for( ; i < length ; i++)
        C->A[k++] = A[i];

    C->length = k;
    C->size = 10;

    return C;
}

int Array::Search(int key)
{
    int l, m, h;
    l = 0;
    h = length - 1;
    while(l <= h)
    {
        m = (l + h) / 2;
        if(key == A[m])
            return m;
        if(key < A[m])
            h = m - 1;
        else if(key > A[m])
            l = m + 1;
    }
    return -1;
}
         
        
int Array::Delete(int index)
{
    int x = 0;
    int i;

    if(index >= 0 && index < length)
    {
        x = A[index];
        for(i = index; i < length-1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
        return x;
    }

    return 0;
}


int main()
{
    int ch = 0;
    int x, index, size;

    printf("Enter size of Array  ");
    scanf("%d", &size);
    Array A(size);

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
                   A.Set(index, x); 
                   A.Display();
                   break;
            case 2: printf("Enter an index to delete ");
                   scanf("%d", &index);
                   A.Delete(index); 
                   A.Display();
                   break;
            case 3: printf("Enter an element to search for");
                   scanf("%d", &x);
                   index = A.Search(x);  
                   if(index != -1)
                       cout << "Element " << x << " was found at index: " << index << endl;
                   else
                       cout << "Element " << x << " was not found" << endl;
                   break;
            case 4: printf("The sum of  ");
                   x = A.Sum(); 
                   cout << x << endl;
                   break;
            case 5: printf("Elements are: \n"); 
                   A.Display();
        } 
    }
               
=======
    /* Array ADT Methods */
    /*
    struct Array arr = {{2,3,4,5,6}, 10,5};
    
    Set(&arr, 0, 15);
    Display(arr);
    cout << "Max:" << Max(arr) << endl;
    cout << "Min:" << Min(arr) << endl;
    cout << "Avg:" << Avg(arr) << endl;
    */
    
    /* Reversal of array - copy */
    /*
    struct Array A = {{1,2,3,4,5,6,7,8,9}, 9,9};
    ReverseCopy(&A);
    Display(A);
    */
    
    /* Reversal of array - swap */
    /*
    struct Array A = {{1,2,3,4,5,6,7,8,9}, 9,9};
    ReverseSwap(&A);
    Display(A);
    */
    
    /* Shift and Rotation of array */
    /*
    struct Array A = {{1,2,3,4,5,6,7,8,9}, 9,9};
    //shift: moves data to position left/right. if out of bounds, delete data
    //rotate: moves data left/right, if out of bounds, wrap around to front/end
    */
    struct Array A = {{1,2,3,4,5,6,7,8,9}, 9,9};
    
    cout << isSorted(A) << endl;
    
>>>>>>> 101be990b0f2003f39921b2748a9eae751c7e45c
    
    return 0;
}
