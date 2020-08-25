#include <iostream>
#include <climits>

using namespace std;

long maxLong = LONG_MAX;

int minAboveBadSolution(int a[], int size, int k)
{
       
}

int minAboveBetterSolution(int a[], int size, int k)
{
       long minDistance = maxLong;
       long minAbove = 0;
       for (int i = 0; i < size; i++)
       {
              if (a[i] != a[k] && (a[i] - a[k] > 0) && (a[i] - a[k] < minDistance))
              {
                     minDistance = a[i] - a[k];
                     minAbove = a[i];
              }
       }
       return minAbove;
}

int main()
{
       int arr[] = {5, 3, 6, 4, 8, 11, 9, 7};
       int arraySize = sizeof(arr) / sizeof(arr[0]);
       long minAbove = minAboveBetterSolution(arr, arraySize, 2);
       cout << "Value of min above is " << minAbove;
       return 0;
}