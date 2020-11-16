#include <iostream>

using namespace std;
/*
       Integer division: a = qd + r and 0 ≤ r < |d|
       Input an array size n. Input every element less than n - 1.
       Example: n = 7 => {1, 2, 3, 1, 3, 6, 6}, n = 5 => {1,3,4,2,1}
*/

void print_duplicates_in_array_BigO_n(int a[], int n)
{
       for (int i = 0; i < n; i++)
       {
              int index = a[i] % n;
              a[index] += n;
       }

       for (int i = 0; i < n; i++)
       {
              if (a[i] / n >= 2)
              {
                     cout << i << "   ";
              }
       }
}

int main()
{
       int a[] = {5, 3, 5, 1, 5, 3};
       int n = sizeof(a) / sizeof(a[0]);
       print_duplicates_in_array_BigO_n(a, n);
       return 0;
}