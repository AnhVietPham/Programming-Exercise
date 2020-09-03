#include <iostream>

using namespace std;

int recursion_sum(int n)
{
       if (n == 0)
       {
              return 0;
       }

       return n + recursion_sum(n - 1);
}

int tail_recursion_sum(int n, int sum = 0)
{
       if (n == 0)
       {
              return n + sum;
       }

       return tail_recursion_sum(n - 1, n + sum);
}

int naive_code_sum(int n)
{
       int sum = 0;

       for (int i = 1; i <= n; i++)
       {
              sum += i;
       }

       return sum;
}

int main()
{
       int n = 5;
       cout << "Recursion S(n) is " << recursion_sum(n) << "\n";
       cout << "Tail Recursion S(n) is " << tail_recursion_sum(n) << "\n";
       cout << "Naive code S(n) is " << naive_code_sum(n) << "\n";
       return 0;
}