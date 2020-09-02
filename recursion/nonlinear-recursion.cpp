#include <iostream>

using namespace std;

int sumX_n(int n)
{
       int sum = 0;
       if (n == 0)
       {
              return 1;
       }

       for (int i = 1; i <= n; i++)
       {
              sum += i * i * sumX_n(n - 1);
       }

       return sum;
}

int main()
{
       int n = 2;
       cout << "Sum of X_n is " << sumX_n(2);
       return 0;
}