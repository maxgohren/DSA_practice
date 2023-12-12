#include <stdio.h>

void recursiveDescending(int n)
{
    if (n > 0) {
        printf("%d ", n);
        recursiveDescending(n - 1);
    }
}

void recursiveAscending(int n)
{
    if (n > 0) {
        recursiveAscending(n-1);
        printf("%d ", n);
    }
}

int recursiveStaticVar(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        //x++ until n =0, x = 5
        //calls 5 times until n = 0
        //returns 0(n)+5+5+5+5+5 = 25
        return recursiveStaticVar(n - 1) + x; 
                                              
    }
    return 0;
}

int y = 0;
int recursiveGlobalVar(int n)
{
    if (n > 0)
    {
        y++;
        return recursiveGlobalVar(n - 1) + y;
    }
    return 0;
}

void treeRecursion(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        treeRecursion(n - 1);
        treeRecursion(n - 1);
    }
}

void indirectRecursionB(int n);

void indirectRecursionA(int n) 
{
    if (n > 0)
    {
        printf("%d\n", n);
        indirectRecursionB(n-1);
    }
}

void indirectRecursionB(int n)
{
    if (n > 1)
    {
        printf("%d\n", n);
        indirectRecursionA(n / 2);
    }
}

int nestedRecursion(int n)
{
    if (n > 100)
        return n - 10;
    return nestedRecursion(nestedRecursion(n + 11));
}



int main()
{
    
    //recursiveAscending(3);
    //recursiveDescending(3);
    
    /* --- the following are the same --- */
    //int r = 0;
    //r = recursiveStaticVar (5);
    //r = recursiveGlobalVar(5);
    //printf("%d\n", r);

    //treeRecursion(3);

    //indirectRecursionA(20);

    int r = 95;
    r = nestedRecursion(r);
    printf("%d", r);

    
    return 0;
}