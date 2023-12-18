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


int recursiveSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (recursiveSum(n - 1)) + n;
}

int iterativeSum(int n)
{
    int s = 0;
    for (int i = 0; i <= n; i++)
    {
        s += i;
    }
    return s;
}

int fact(int n)
{
    if (n == 0) return 1;
    return fact(n - 1) * n;
}

int pow(int m, int n)
{

    if (n == 0)
        return 1;
    return pow(m, n - 1) * m;

    /*int r = 1;
    for (int i = 0; i < n; i++)
    {
        r *= m;
    }
    return r;*/
}

double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

int fib(int n)
{
    if (n <= 1) return n;
    return fib(n - 2) + fib(n - 1);
}

int fibIter(int n)
{
    int t0 = 0, t1 = 1, s, i;

    if (n <= 1) return n;

    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int F[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int fibMemo(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = fibMemo(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = fibMemo(n - 1);
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}

int nCr(int n, int r)
{
    if (r == n || r == 0) return 1;
    else
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("move %d to %d\n", A, C);
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    /*
    //recursiveAscending(3);
    //recursiveDescending(3);
    
    //int r = 0;
    //r = recursiveStaticVar (5);
    //r = recursiveGlobalVar(5);
    //printf("%d\n", r);

    //treeRecursion(3);

    //indirectRecursionA(20);
    
    
    int r = 95;
    r = nestedRecursion(r);
    printf("%d", r);
    */
  
    // printf("%d\n", recursiveSum(5));
    // printf("%d\n", iterativeSum(5));

    //printf("%d\n", fact(5));
    //printf("%d\n", pow(3, 3));

    //printf("The Taylor Series for e is: %lf\n", e(4,100));

    //int n = 10;
    //printf("The fibonacci sequence for %d numbers will reach %d", n, fib(n));
    //printf("The iterative fibonacci seq. for %d numbers is %d", n, fibIter(n));
    //printf("The memoized fib. seq. for %d nums is %d", n, fibMemo(n));

    int n = 4, r = 2;
    //printf("# of cmbns of size %d for set of %d: %d\n", r, n, nCr(n,r));
    
    TOH(20, 1,2,3);
    
     return 0;
}