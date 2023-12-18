#include <stdio.h>
#include <stdlib.h>

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

   


    return 0;
}

