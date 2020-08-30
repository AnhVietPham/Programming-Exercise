#include <iostream>
#include <vector> 
using namespace std;

int longestInCreasingDecreasingSubArray(int a[], int n)
{
       int max = 1;
       int lenOfSubArray = 1;

       for (int i = 1; i < n; i++)
       {
              if (a[i] > a[i - 1])
              {
                     lenOfSubArray++;
              }
              else
              {
                     if (lenOfSubArray > 1)
                     {
                            lenOfSubArray++;
                     }
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
       

       return max;
}

int main()
{
       int arr[] = {7, 6, 5, 4, 3, 2, 9, 11, 12, 10, 8, 0};
       int arrSize = sizeof(arr) / sizeof(arr[0]);
       cout << "Value of LongestHill is: " << longestInCreasingDecreasingSubArray(arr, arrSize);
       return 0;
}