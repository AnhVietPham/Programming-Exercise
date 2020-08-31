#include <iostream>
using namespace std;

int Min(int arr[], int n)
{
       if (n == 1)
       {
              return arr[0];
       }

       int tempMin = Min(arr, n - 1);
       if (tempMin > arr[n - 1])
       {
              return arr[n - 1];
       }
       else
       {
              return tempMin;
       }
       return 0;
}

int Max(int a[], int n)
{
       if (n == 1)
       {
              return a[0];
       }

       int tempMax = Max(a, n - 1);
       if (tempMax < a[n - 1])
       {
              return a[n - 1];
       }
       else
       {
              return tempMax;
       }
}

int main()
{
       int arr[] = {2, 3, 20, 6, 3};
       int arrSize = sizeof(arr) / sizeof(arr[0]);
       cout << "Max is " << Max(arr, arrSize) << "\n";
       cout << "Min is " << Min(arr, arrSize);
       return 0;
}