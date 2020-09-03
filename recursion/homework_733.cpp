#include <iostream>

using namespace std;

// S(n) = 1/2 + 1/4 + .. + 1/2n

float recursion_733(int n)
{
       if (n == 0)
       {
              return 0;
       }

       return 1.0 / (2 * n) + recursion_733(n - 1);
}

float tail_recursion_733(int n, float sum = 0)
{
       if (n == 1)
       {
              return 1.0 / (2 * n) + sum;
       }

       return tail_recursion_733(n - 1, 1.0 / (2 * n) + sum);
}

float naive_code_733(int n)
{
       float sum = 0;

       for (int i = 1; i <= n; i++)
       {
              sum += 1.0 / (2 * i);
       }

       return sum;
}

int main()
{
       int n = 3;
       cout << "Recursion S(n) is " << recursion_733(n) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_733(n) << "\n";
       cout << "Naive code S(n) is " << naive_code_733(n);
       return 0;
}