#include <iostream>

using namespace std;

void helper(int given_array[], int subset[], int n, int index)
{
       if (index == n)
       {
              for (int i = 0; i < index; i++)
              {
                     if (subset[i] != 0)
                     {
                            cout << subset[i] << "   ";
                     }
              }
              cout << endl;
       }
       else
       {
              subset[index] = 0;
              helper(given_array, subset, n, index + 1);
              subset[index] = given_array[index];
              helper(given_array, subset, n, index + 1);
       }
}

void find_all_subsets(int given_array[], int n)
{
       int subset[n];
       helper(given_array, subset, n, 0);
}

int main()
{
       int a[] = {1, 2};
       int n = sizeof(a) / sizeof(a[0]);
       find_all_subsets(a, n);
       return 0;
}