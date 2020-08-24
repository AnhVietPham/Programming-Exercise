#include <iostream>
#include <climits>

using namespace std;

long maxLong = LONG_MAX;

int maxBelowBadSolution(int a[], int size, int k)
{
       
}

int maxBelowBetterSolution(int a[], int size, int k)
{
       long minDistance = maxLong;
       long maxBelow = 0;
       for (int i = 0; i < size; i++)
       {
              if (a[i] != a[k] && (a[k] - a[i] > 0) && (a[k] - a[i] < minDistance))
              {
                     minDistance = a[k] - a[i];
                     maxBelow = a[i];
              }
       }
       return maxBelow;
}

int main()
{
       int arr[] = {3, 6, 5, 4, 8, 11};
       int arraySize = sizeof(arr) / sizeof(arr[0]);
       long maxBelow = maxBelowBadSolution(arr, arraySize, 2);
       cout << "Value of max below is " << maxBelow;
       return 0;
}