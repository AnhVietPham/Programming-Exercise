#include <iostream>

using namespace std;

int greatest_odd_divisor(int n)
{
       if (n % 2 != 0)
       {
              return n;
       }

       return greatest_odd_divisor(n / 2);
}

int main()
{
       int n = 101;
       cout << "Greatest odd divisor is "<< greatest_odd_divisor(n);
       return 0;
}