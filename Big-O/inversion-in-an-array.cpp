#include <iostream>

using namespace std;

int count_number_inversion_in_an_array(int a[], int n)
{
       int count = 0;
       for (int i = 0; i < n - 1; i++)
       {
              for (int j = i + 1; j < n; j++)
              {
                     if (a[i] > a[j])
                     {
                            count++;
                     }
              }
       }

       return count;
}

int main()
{
       int a[] = {4, 5, 1, 3, 2};
       int n = sizeof(a) / sizeof(a[0]);
       cout << "Number of inversion in an array: " << count_number_inversion_in_an_array(a, n);
       return 0;
}