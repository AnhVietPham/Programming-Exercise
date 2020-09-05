#include <iostream>

using namespace std;

// S(n) = 1 + 1/(1 + 2) + 1/(1 + 2 + 3) + ... + 1/(1+2+3+...+n)

float recursion_744(int n)
{
       if (n == 1)
       {
              return 1;
       }

       int denominator_sum = 0;

       for (int i = 1; i <= n; i++)
       {
              denominator_sum += i;
       }

       return (1.0 / denominator_sum) + recursion_744(n - 1);
}

float tail_recursion_744(int n, float sum = 0)
{
       if (n == 1)
       {
              return sum + 1.0 / n;
       }

       int denominator_sum = 0;

       for (int i = 1; i <= n; i++)
       {
              denominator_sum += i;
       }

       return tail_recursion_744(n - 1, sum + 1.0 / denominator_sum);
}

float naive_code_744(int n)
{
       float sum = 0;

       for (int i = 1; i <= n; i++)
       {
              int denominator_sum = 0;
              for (int j = 0; j <= i; j++)
              {
                     denominator_sum += j;
              }
              sum += 1.0 / denominator_sum;
       }
       return sum;
}

int main()
{
       int n = 3;
       int x = 2;
       cout << "Recursion S(n) is " << recursion_744(n) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_744(n) << "\n";
       cout << "Naive code S(n) is " << naive_code_744(n);
       return 0;
}