#include <iostream>

using namespace std;

// S(n) =  1/2 + 3/4 + 5/6 + ... + (2n + 1) / (2n + 2)

float recursion_737(int n)
{
       if (n == 0)
       {
              return 1.0 / 2.0;
       }

       return (2.0 * n + 1) / (2.0 * n + 2) + recursion_737(n - 1);
}

float tail_recursion_737(int n, float sum = 0)
{
       if (n == 0)
       {
              return sum + (2.0 * n + 1) / (2.0 * n + 2);
       }

       return tail_recursion_737(n - 1, sum + (2.0 * n + 1) / (2.0 * n + 2));
}

float naive_code_737(int n)
{
       float sum = 0;

       for (int i = 0; i <= n; i++)
       {
              sum += (2.0 * i + 1) / (2.0 * i + 2);
       }

       return sum;
}

int main()
{
       int n = 3;
       cout << "Recursion S(n) is " << recursion_737(n) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_737(n) << "\n";
       cout << "Naive code S(n) is " << naive_code_737(n);
       return 0;
}