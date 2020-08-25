#include <iostream>
#include <climits>

using namespace std;

long maxInt = INT_MAX;

int maxBelowBetterSolution(int a[], int size, int k)
{
       int minDistance = maxInt;
       int maxBelow = 0;
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

int maxBelowBetter2Solution(int a[], int size, int k)
{

       int maxBelow = 0;

       for (int i = 0; i < size; i++)
       {
              if (a[i] < a[k])
              {
                     maxBelow = maxBelow > a[i] ? maxBelow : a[i];
              }
       }

       return maxBelow;
}

int main()
{
       int arr[] = {5, 3, 6, 4, 8, 11};
       int arraySize = sizeof(arr) / sizeof(arr[0]);
       int maxBelow = maxBelowBetterSolution(arr, arraySize, 0);
       int maxBelowTwo = maxBelowBetter2Solution(arr, arraySize, 0);
       cout << "Value of max below is " << maxBelow;
       cout << "Value of max below 2 is " << maxBelowTwo;
       return 0;
}