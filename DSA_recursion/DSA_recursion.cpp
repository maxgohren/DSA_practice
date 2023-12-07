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

int main()
{
    int r = 0;
    //recursiveAscending(x);
    //recursiveDescending(x);
    
    /* --- the following are the same --- */
    //r = recursiveStaticVar (5);
    r = recursiveGlobalVar(5);

    printf("%d\n", r);
    return 0;
}