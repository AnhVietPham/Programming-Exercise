#include <iostream>
#include <climits>

using namespace std;

int maxInt = INT_MAX;

int minAboveBetterSolution(int a[], int size, int k)
{
       int minDistance = maxInt;
       int minAbove = 0;
       for (int i = 0; i < size; i++)
       {
              if (a[i] - a[k] > 0 && (a[i] - a[k] < minDistance))
              {
                     minDistance = a[i] - a[k];
                     minAbove = a[i];
              }
       }
       return minAbove;
}

int minAbove2BetterSolution(int a[], int size, int k)
{
       int minAbove = maxInt;
       for (int i = 0; i < size; i++)
       {
              if (a[i] > a[k])
              {
                     minAbove = minAbove > a[i] ? a[i] : minAbove;
              }
       }
       return minAbove;
}

int main()
{
       int arr[] = {5, 3, 6, 4, 8, 6, 11, 9, 7};
       int arraySize = sizeof(arr) / sizeof(arr[0]);
       int minAbove = minAboveBetterSolution(arr, arraySize, 8);
       int min2Above = minAbove2BetterSolution(arr, arraySize, 8);
       cout << "Value of min above is " << minAbove;
       cout << "Value of min above is 2 " << min2Above;
       return 0;
}