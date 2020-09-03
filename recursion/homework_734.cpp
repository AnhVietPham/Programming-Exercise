#include <iostream>

using namespace std;

// S(n) = 1 + 1/3 + 1/5 + 1/7 ... + 1/(2*n + 1)

float recursion_734(int n)
{
       if (n == 0)
       {
              return 1;
       }

       return 1.0 / (2 * n + 1) + recursion_734(n - 1);
}

float tail_recursion_734(int n, float sum = 0)
{
       if (n == 0)
       {
              return 1.0 / (2 * n + 1) + sum;
       }

       return tail_recursion_734(n - 1, 1.0 / (2 * n + 1) + sum);
}

float navie_code_734(int n)
{
       float sum = 0;
       for (int i = 0; i <= n; i++)
       {
              sum += 1.0 / (2 * i + 1);
       }
       return sum;
}

int main()
{
       int n = 3;
       cout << "Recursion S(n) is " << recursion_734(n) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_734(n) << "\n";
       cout << "Naive code S(n) is " << navie_code_734(n);
       return 0;
}