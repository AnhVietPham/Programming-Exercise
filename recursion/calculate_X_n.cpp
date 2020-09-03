#include <iostream>

using namespace std;

// Non-linear Recursion.

int calculate_X_n(int n)
{
       int sum = 0;
       if (n == 0)
       {
              return 1;
       }

       for (int i = 1; i <= n; i++)
       {
              sum += i * i * calculate_X_n(n - i);
       }

       return sum;
}


int main()
{
       int n = 3;
       cout << "Sum of X_n is " << calculate_X_n(n);
       return 0;
}