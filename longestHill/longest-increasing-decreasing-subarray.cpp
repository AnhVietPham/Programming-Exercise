#include <iostream>
using namespace std;

void longestInCreasingDecreasingSubArray(int a[], int n)
{
       int max = 1;
       int lenOfSubArray = 1;
       int lenOfIncreasingSubArray = 1;
       int lenOfDecreasingSubArray = 1;
       int lenOfTheSameValues = 1;

       if (n - 1 <= 2)
       {
              cout << "Size of Array is not enough to create Hill";
              return;
       }

       for (int i = 1; i < n - 1; i++)
       {
              if (a[i - 1] < a[i])
              {
                     lenOfIncreasingSubArray++;
              }

              if (a[i] < a[i - 1])
              {
                     lenOfDecreasingSubArray++;
              }

              if (a[i] == a[i - 1])
              {
                     lenOfTheSameValues++;
              }
       }

       if (lenOfIncreasingSubArray == n - 1)
       {
              cout << "Value is increasing";
              return;
       }

       if (lenOfDecreasingSubArray == n - 1)
       {
              cout << "Value is decreasing";
              return;
       }

       if (lenOfTheSameValues == n - 1)
       {
              cout << "Array has the same values";
              return;
       }

       for (int i = 1; i < n - 1; i++)
       {
              if (a[i] >= a[i - 1])
              {
                     lenOfSubArray++;
              }
              else
              {
                     lenOfSubArray++;
                     if (a[i + 1] > a[i])
                     {
                            if (max < lenOfSubArray)
                            {
                                   max = lenOfSubArray;
                            }
                            lenOfSubArray = 1;
                     }
              }
       }
       if (max < lenOfSubArray)
       {
              max = lenOfSubArray;
       }

       cout << "Value of LongestHill is: " << max;
}

int main()
{
       // Case 1: Increasing - decreasing Array
       // int arr[] = {7, 6, 5, 4, 3, 2, 9, 11, 12, 10, 8, 6, 20, 0};
       // Case 2: Increasing Array
       // int arr[] = {2, 3, 4, 7, 9, 11, 0};
       // Case 3: Decreasing Array
       // int arr[] = {9, 8, 6, 4, 3, 2, 1, 0};
       // Case 4: Array is not enough to create a Hill.
       // int arr[] = {2, 3, 1, 0};
       // Case 5: 
       int arr[] = {7, 6, 5, 4, 3, 2, 9, 11, 11, 11, 12, 10, 8, 6, 7, 0};
       // Case 6: The same values
       // int arr[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
       // find solution remove last value == 0;
       int arrSize = sizeof(arr) / sizeof(arr[0]);
       longestInCreasingDecreasingSubArray(arr, arrSize);
       return 0;
}