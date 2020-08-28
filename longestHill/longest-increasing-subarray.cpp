#include <iostream>

using namespace std;

int longestIncreasingSubArray(int a[], int n)
{
       int max = 1;
       int len = 1;

       for (int i = 1; i < n; i++)
       {
              if (a[i] > a[i - 1])
              {
                     len++;
              }
              else
              {
                     if (max < len)
                     {
                            max = len;
                     }
                     len = 1;
              }
       }
       return max;
}

int main()
{
       int arr[] = {2, 3, 4, 5, 1, 9, 6};
       int arrSize = sizeof(arr) / sizeof(arr[0]);
       cout << "Value of longest increasing subarray is " << longestIncreasingSubArray(arr, arrSize);
       return 0;
}