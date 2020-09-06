#include <iostream>
#include <limits.h>

using namespace std;

/*
1/ Input one dimensional array
2/ Output one dimensional array
3/ Sum of all element in one dimensional array
4/ Min and Max in one dimensional array
5/ Quantity of even number in one dimensional array
6/ Arrange incresing and decresing one dimensional array
 Note: Only using recursion
*/

void input_one_dimensional_array(int a[], int n, int i = 0)
{
       if (i == n)
       {
              return;
       }

       cout << "\nInput a[" << i << "]: ";
       cin >> a[i];
       input_one_dimensional_array(a, n, i + 1);
}

void output_one_dimensional_array(int a[], int n, int i = 0)
{
       if (i == n)
       {
              return;
       }
       cout << a[i] << "   ";
       output_one_dimensional_array(a, n, i + 1);
}

int find_min(int a[], int n, int i = 0, int Min = INT_MAX)
{
       if (i == n)
       {
              return Min;
       }

       return find_min(a, n, i + 1, a[i] < Min ? a[i] : Min);
}

int find_max(int a[], int n, int i = 0, int Max = 0)
{
       if (i == n)
       {
              return Max;
       }

       return find_max(a, n, i + 1, a[i] > Max ? a[i] : Max);
}

int sum_1d_array(int a[], int n, int i = 0, int sum = 0)
{
       if (i == n)
       {
              return sum;
       }
       return sum_1d_array(a, n, i + 1, sum + a[i]);
}

int main()
{
       int n = 5;
       int a[1000];
       input_one_dimensional_array(a, n);
       output_one_dimensional_array(a, n);
       cout << "\n Min in 1D-Array is: " << find_min(a, n);
       cout << "\n Max in 1D-Array is: " << find_max(a, n);
       cout << "\n Sum of all element in 1D-Array is: " << sum_1d_array(a, n);
       return 0;
}