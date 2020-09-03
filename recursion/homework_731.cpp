#include <iostream>

using namespace std;

// S(n) = 1^2 + 2^2 + 3^2 + ... + n^2

int recursion_731(int n)
{
       if (n == 0)
       {
              return 0;
       }

       return recursion_731(n - 1) + n * n;
}

int tail_recursion_731(int n, int sum = 0)
{
       if (n == 0)
       {
              return n * n + sum;
       }

       return tail_recursion_731(n - 1, n * n + sum);
}

int naive_code_731(int n)
{
       int sum = 0;

       for (int i = 1; i <= n; i++)
       {
              sum += i * i;
       }

       return sum;
}

int main()
{
       int n = 3;
       cout << "Recursion S(n) is " << recursion_731(n) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_731(n) << "\n";
       cout << "Naive code S(n) is " << naive_code_731(n) << "\n";

       return 0;
}