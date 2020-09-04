#include <iostream>
#include <math.h>
using namespace std;

// S(n) = x^2 + x^4 + ... + x^2n

int recursion_742(int n, int x)
{
       if (n == 1)
       {
              return pow(x, 2 * n);
       }

       return pow(x, 2 * n) + recursion_742(n - 1, x);
}

int tail_recursion_742(int n, int x, int sum = 0)
{

       if (n == 1)
       {
              return pow(x, 2 * n) + sum;
       }

       return tail_recursion_742(n - 1, x, pow(x, 2 * n) + sum);
}

int naive_code_742(int n, int x)
{
       int sum = 0;

       for (int i = 1; i <= n; i++)
       {
              sum += pow(x, 2 * i);
       }

       return sum;
}

int main()
{
       int n = 3;
       int x = 2;
       cout << "Recursion S(n) is " << recursion_742(n, x) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_742(n, x) << "\n";
       cout << "Naive code S(n) is " << naive_code_742(n, x);
       return 0;
}