#include <iostream>
#include <math.h>

using namespace std;

// S(n) = x + x^2/2! + x^3/3! + ... + x^n/n!

float recursion_745(int n, int x)
{
       if (n == 1)
       {
              return x;
       }

       int fac = 1;

       for (int i = 1; i <= n; i++)
       {
              fac *= i;
       }

       return pow(x, n) / fac + recursion_745(n - 1, x);
}

float tail_recursion_745(int n, int x, float sum = 0)
{
       if (n == 1)
       {
              return x + sum;
       }

       int fac = 1;

       for (int i = 1; i <= n; i++)
       {
              fac *= i;
       }

       return tail_recursion_745(n - 1, x, sum + pow(x, n) / fac);
}

float naive_code_745(int n, int x)
{
       float sum = 0;

       for (int i = 1; i <= n; i++)
       {
              int fac = 1;
              for (int j = 1; j <= i; j++)
              {
                     fac *= j;
              }

              sum += pow(x, i) / fac;
       }
       return sum;
}

int main()
{

       int n = 3;
       int x = 2;
       cout << "Recursion S(n) is " << recursion_745(n, x) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_745(n, x) << "\n";
       cout << "Naive code S(n) is " << naive_code_745(n, x);

       return 0;
}