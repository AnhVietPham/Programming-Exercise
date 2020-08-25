#include <iostream>

using namespace std;

int binarySearch(int a[], int n, int x)
{
       int left = 0;
       int right = n - 1;
       while (left <= right)
       {
              int mid = (left + right) / 2;

              if (x == a[mid]){
                     return mid;
              }

              if (x < a[mid])
              {
                     right = mid - 1;
              }

              if (x > a[mid])
              {
                     left = mid + 1;
              }
       }
       return -1;
}

int main()
{
       int arr[] = {1, 3, 5, 7, 8, 9, 11, 12, 40};
       int arrSize = sizeof(arr) / sizeof(arr[0]);
       int value = binarySearch(arr, arrSize, 1);
       cout << "Value is " << value;
       return 0;
}
