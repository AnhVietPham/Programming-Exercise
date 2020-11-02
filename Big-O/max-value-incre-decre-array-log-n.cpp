#include <iostream>
using namespace std;

int find_max_incre_decre_array_log_n(int a[], int n)
{
       int left = 0;
       int right = n - 1;
       int mid = 0;
       while (left <= right)
       {
              mid = (left + right) / 2;

              if (a[mid - 1] < a[mid] && a[mid] > a[mid + 1])
              {
                     return a[mid];
              }

              if (a[mid - 1] < a[mid])
              {
                     left = mid + 1;
              }
              else
              {
                     right = mid - 1;
              }
       }
       return 0;
}

int main()
{

       int a[] = {6, 99, 78, 44, 33, 11, 8, 6, 4};
       int n = sizeof(a) / sizeof(a[0]);
       cout << "Max value in incre-decre array Big0(logn): " << find_max_incre_decre_array_log_n(a, n);
       return 0;
}