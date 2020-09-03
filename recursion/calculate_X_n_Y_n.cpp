#include <iostream>
using namespace std;

int X_n(int n);
int Y_n(int n);

int X_n(int n)
{
       if (n == 0)
       {
              return 1;
       }
       return X_n(n - 1) + Y_n(n - 1);
}

int Y_n(int n)
{
       if (n == 0)
       {
              return 0;
       }
       return 3 * X_n(n - 1) + 2 * Y_n(n - 1);
}

int unique_X_n(int n)
{
       if (n < 2)
       {
              return 1;
       }
       
       return unique_X_n(n - 2) + 3 * unique_X_n(n - 1);
}

int unique_Y_n(int n)
{
       if (n == 0)
       {
              return 0;
       }

       if (n == 1)
       {
              return 3;
       }
       
       

       return 3 * unique_Y_n(n - 1) + unique_Y_n(n - 2);
}

int main()
{
       int n = 3;
       cout << "X_n is " << X_n(n) << "\n";
       cout << "Y_n is " << Y_n(n) << "\n";
       cout << "unique_X_n is " << unique_X_n(n) << "\n";
       cout << "unique_Y_n is " << unique_Y_n(n) << "\n";
       return 0;
}