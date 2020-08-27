#include <iostream>
#include <vector>

using namespace std;

bool isPairSumNaiveSolution(int numbers[], int n, int X)
{
       int count = 0;
       for (int i = 0; i < n; i++)
       {
              for (int j = 0; j < n; j++)
              {
                     count++;
                     if (numbers[i] + numbers[j] == X)
                     {
                            cout << "Count is: " << count << "\n";
                            cout << "Pair(" << numbers[i] << ", " << numbers[j] << "): True";
                            return true;
                     }
                     if (numbers[i] + numbers[j] > X)
                     {
                            break;
                     }
              }
       }
       return false;
}

bool isPairSumTwoPointerSolution(int numbers[], int n, int X)
{
       int start = 0;
       int end = n - 1;
       int count = 0;
       while (start < end)
       {
              count++;
              if (numbers[start] + numbers[end] == X)
              {
                     cout << "Count is: " << count << "\n";
                     cout << "Pair(" << numbers[start] << ", " << numbers[end] << "): True";
                     return true;
              }

              if (numbers[start] + numbers[end] < X)
              {
                     start++;
              }

              if (numbers[start] + numbers[end] > X)
              {
                     end--;
              }
       }
       return false;
}

int main()
{
       int arr[] = {1, 2, 3, 4, 5, 6, 7};
       int arrSize = sizeof(arr) / sizeof(arr[0]);
       isPairSumNaiveSolution(arr, arrSize, 10);
       cout << "\n";
       isPairSumTwoPointerSolution(arr, arrSize, 10);
       return 0;
}