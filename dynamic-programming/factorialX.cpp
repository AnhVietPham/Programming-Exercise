#include <iostream>
using namespace std;

int factorialX(int X)
{
       int dp[X];
       dp[0] = 1;
       for (int i = 1; i <= X; i++)
       {
              dp[i] = dp[i - 1] * i;
       }
       return dp[X];
}

int main()
{
       cout << "Factorial X: " << factorialX(4);
       return 0;
}