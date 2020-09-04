#include <iostream>

using namespace std;

// S(n) = 1/1*2 + 1/2*3 + 1/3*4 + ... + 1/n(n + 1)

float recursion_735(int n)
{
       if (n == 0)
       {
              return 0;
       }

       return 1.0 / (n * (n + 1)) + recursion_735(n - 1);
}

float tail_recursion_735(int n, float sum = 0)
{
       if (n == 1)
       {
              return 1.0 / (n * (n + 1)) + sum;
       }
       return tail_recursion_735(n - 1, 1.0 / (n * (n + 1)) + sum);
}

float naive_code_735(int n)
{
       float sum = 0;
       for (int i = 1; i <= n; i++)
       {
              sum += 1.0 / (i * (i + 1));
       }

       return sum;
}

int main()
{
       int n = 3;
       cout << "Recursion S(n) is " << recursion_735(n) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_735(n) << "\n";
       cout << "Naive code S(n) is " << naive_code_735(n) << "\n";
       return 0;
}