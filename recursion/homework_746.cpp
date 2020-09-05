#include <iostream>
#include <math.h>

using namespace std;

// S(n) = 1 + x^2/2! + x^4/4! + ... + x^2n/2n!

float recursion_746(int n, int x)
{
       if (n == 0)
       {
              return 1;
       }

       int fac = 1;

       for (int i = 1; i <= 2 * n; i++)
       {
              fac *= i;
       }

       return pow(x, 2 * n) / fac + recursion_746(n - 1, x);
}

float tail_recursion_746(int n, int x, float sum = 0)
{
       if (n == 0)
       {
              return 1 + sum;
       }

       int fac = 1;

       for (int i = 1; i <= 2 * n; i++)
       {
              fac *= i;
       }

       return tail_recursion_746(n - 1, x, sum + pow(x, 2 * n) / fac);
}

float naive_code_746(int n, int x)
{
       float sum = 1;

       for (int i = 1; i <= n; i++)
       {
              int fac = 1;

              for (int j = 1; j <= 2 * i; j++)
              {
                     fac *= j;
              }

              sum += pow(x, 2 * i) / fac;
       }
       return sum;
}

int main()
{

       int n = 3;
       int x = 2;
       cout << "Recursion S(n) is " << recursion_746(n, x) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_746(n, x) << "\n";
       cout << "Naive code S(n) is " << naive_code_746(n, x);

       return 0;
}