#include <iostream>

using namespace std;

// T(n) = x^n

int recursion_739(int n, int x)
{
       if (n == 1)
       {
              return x;
       }

       return x * recursion_739(n - 1, x);
}

int tail_recursion_739(int n, int x, int T = 1)
{
       if (n == 1)
       {
              return T * x;
       }

       return tail_recursion_739(n - 1, x, T * x);
}

int naive_code_739(int n, int x)
{
       int T = 1;
       for (int i = 1; i <= n; i++)
       {
              T *= x;
       }
       return T;
}

int main()
{
       int n = 3;
       int x = 2;
       cout<< "Recursion T(n,x) is "<< recursion_739(n,2)<<"\n";
       cout<< "Tail Recursion T(n,x) is "<< tail_recursion_739(n,2)<<"\n";
       cout<< "Naive code T(n,x) is "<< naive_code_739(n,2)<<"\n";
       return 0;
}