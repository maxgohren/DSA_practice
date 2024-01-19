#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

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
        printf("%d\n", arr.A[i]);
    }
}

int main()
{
    /* types of declarations */
    /*
    //view these declarations in variable viewer when debugging
    int A[5]; //garbage values
    int B[5] = { 1,2,3,4,5 };
    int C[10] = { 2,4,6 }; //0 padded array
    int D[5] = { 0 }; //0 padded array
    int E[] = { 1,2,3,4,5,6 };

    // this works because compiler knows static array size
    int sizeA = sizeof(A) / sizeof(int);
    for (int i = 0; i < sizeA; i++) printf("%u\n", &A[i]);
    */

    /* static vs dynamic arrays */ 
    /*
    int staticArray[10] = { 0 };
    int* dynamicArray;
    dynamicArray = (int*)malloc(10 * sizeof(int));
    
    // does not work, compiler does not know size of run-time arrays
    //int size = sizeof(dynamicArray) / sizeof(int);
    for (int i = 0; i < 10; i++)
        dynamicArray[i] = i * 2;
    
    for (int i = 0; i < 10; i++)
        printf("%d %d\n", dynamicArray[i], staticArray[i]);
    */

    /* Resizing an array */
    /*
    int* p, * q;

    p = (int*)malloc(5 * sizeof(int));
    p[0] = 3; p[1] = 5; p[2] = 7; p[3] = 9; p[4] = 11;

    q = (int*)malloc(10 * sizeof(int));
    
    for (int i = 0; i < 5; i++)
        q[i] = p[i];

    
    free(p); //tells run-time that this memory can be overwritten, does not delete
    p = q;
    q = NULL;

    for (int i = 0; i < 5; i++)
        printf("%d\n", p[i]);
    */

    /* 2D Arrays */

    /* Array ADT Methods */
    struct Array arr = {{2,3,4,5,6}, 10,5};
    

    Set(&arr, 0, 15);
    Display(arr);
    cout << "Max:" << Max(arr) << endl;
    cout << "Min:" << Min(arr) << endl;
    cout << "Avg:" << Avg(arr) << endl;

    
       


    return 0;
}

