#include <math.h>
#include <iostream>

using namespace std;

// S(n) = x + x^2 + x^3 + ... + x^n

int recursion_741(int n, int x)
{
       if (n == 1)
       {
              return pow(x, n);
       }
       return pow(x, n) + recursion_741(n - 1, x);
}

int tail_recursion_741(int n, int x, int sum = 0)
{
       if (n == 1)
       {
              return sum + pow(x, n);
       }
       return tail_recursion_741(n - 1, x, sum + pow(x, n));
}

int navie_code_741(int n, int x)
{
       int sum = 0;

       for (int i = 1; i <= n; i++)
       {
              sum += pow(x, i);
       }

       return sum;
}

int main()
{
       int n = 3;
       int x = 2;
       cout << "Recursion S(n) is " << recursion_741(n, x) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_741(n, x) << "\n";
       cout << "Navie code S(n) is " << navie_code_741(n, x);
       return 0;
}