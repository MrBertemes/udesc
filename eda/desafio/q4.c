#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int ehPrimo(int n)
{
    int num;
    if (n == 2)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {

            return 0;
        }
    }
    return 1;
}
int fib(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}
