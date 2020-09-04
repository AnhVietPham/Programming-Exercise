#include <iostream>

using namespace std;

// S(n) = 1 + 1.2 + 1.2.3 + ... + 1.2.3...n

int recursion_740(int n)
{
       if (n == 0)
       {
              return 0;
       }

       int x = 1;
       
       for (int i = 1; i <= n; i++)
       {
              x *= i;
       }

       return recursion_740(n - 1) + x;
}

int tail_recursion_740(int n, int sum = 0)
{
       if (n == 0)
       {
              return sum + n;
       }

       int x = 1;
       for (int i = 1; i <= n; i++)
       {
              x *= i;
       }

       return tail_recursion_740(n - 1, sum + x);
}

int naive_code_740(int n)
{
       int sum = 0;
       int x = 1;
       for (int i = 1; i <= n; i++)
       {
              x = 1;
              for (int j = 1; j <= i; j++)
              {
                     x *= j;
              }
              sum += x;
       }
       return sum;
}

int main()
{
       int n = 3;
       cout << "Recursion S(n) is " << recursion_740(n) << "\n";
       cout << "Tail recursion S(n) is " << tail_recursion_740(n) << "\n";
       cout << "Naive code S(n) is " << naive_code_740(n);
       return 0;
}