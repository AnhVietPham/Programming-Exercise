#include <iostream>
#include <math.h>
using namespace std;

// S(n) = x + x^3 + x^5 + ... + x^(2n + 1)

int recursion_743(int n, int x)
{
       if (n == 0)
       {
              return pow(x, 2 * n + 1);
       }
       return pow(x, 2 * n + 1) + recursion_743(n - 1, x);
}

int tail_recursion_743(int n, int x, int sum = 0)
{

       if (n == 0)
       {
              return pow(x, 2 * n + 1) + sum;
       }

       return tail_recursion_743(n - 1, x, pow(x, 2 * n + 1) + sum);
}

int naive_code_743(int n, int x)
{
       int sum = 0;

       for (int i = 0; i <= n; i++)
       {
              sum += pow(x, 2 * i + 1);
       }
       return sum;
}

int main()
{
       int n = 3;
       int x = 2;
       cout << "Recursion S(n) is " << recursion_743(n, x) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_743(n, x) << "\n";
       cout << "Naive code S(n) is " << naive_code_743(n, x);
       return 0;
}