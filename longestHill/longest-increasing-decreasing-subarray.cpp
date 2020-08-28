#include <iostream>

using namespace std;

int longestHill(int a[], int n)
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

       return max;
}

int main()
{

       int arr[] = {2, 3, 5, 6, 4, 7, 8, 9, 10, 11, 15, 14, 1, 6, 4};
       int arrSize = sizeof(arr) / sizeof(arr[0]);

       cout << "Value of LongestHill is: " << longestHill(arr, arrSize);

       return 0;
}