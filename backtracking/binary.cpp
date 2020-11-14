#include <iostream>

using namespace std;

void sprintAllBinary(int a[], int n, int i)
{
       if (i == n)
       {
              for (int k = 0; k < n; k++)
              {
                     cout << a[k];
              }
              cout << endl;
       }
       else
       {
              a[i] = 0;
              sprintAllBinary(a, n, i + 1);
              a[i] = 1;
              sprintAllBinary(a, n, i + 1);
       }
}

int main()
{
       int N = 3;
       int a[N];
       sprintAllBinary(a, N, 0);
       return 0;
}