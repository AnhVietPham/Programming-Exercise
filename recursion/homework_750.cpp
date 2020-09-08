#include <iostream>
#include <math.h>

using namespace std;

// Exercise 750

float recursion_750(int n, int x = 1)
{
       if (n == 1)
       {
              return sqrt(x);
       }

       return sqrt(x + recursion_750(n - 1, x + 1));
}

float tail_recursion_750(int n,float result = 0){
       if (n == 1)
       {
              return sqrt(n + result);
       }
       
       return tail_recursion_750(n - 1, sqrt(n + result));
}

float naive_code_750(int n)
{
       float result = sqrt(n);

       for (int i = 1; i < n; i++)
       {
              result = sqrt(n - i + result);
       }
       return result;
}

int main()
{

       int n = 2;
       cout << "Recursion 750 is " << recursion_750(n) << "\n";
       cout << "Tail Recursion 750 is " << tail_recursion_750(n) << "\n";
       cout << "Naive code 750 is " << naive_code_750(n);
       return 0;
}