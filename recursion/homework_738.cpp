#include <iostream>

using namespace std;

// T(n) = 1x2x3x..xn

int recursion_738(int n)
{

       if (n == 1)
       {
              return 1;
       }

       return n * recursion_738(n - 1);
}

int tail_recursion_738(int n, int x = 1)
{
       if (n == 1)
       {
              return x * n;
       }

       return tail_recursion_738(n - 1, x * n);
}

int naive_code_738(int n)
{
       int x = 1;
       for (int i = 1; i <= n; i++)
       {
              x *= i;
       }

       return x;
}

int main()
{

       int n = 5;
       cout << "Recursion T(n) is " << recursion_738(n) << "\n";
       cout << "Tail Recursion T(n) is " << tail_recursion_738(n) << "\n";
       cout << "Naive code T(n) is " << naive_code_738(n);
       return 0;
}