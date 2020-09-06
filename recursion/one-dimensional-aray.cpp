#include <iostream>

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

int main()
{
       int n = 5;
       int a[1000];
       input_one_dimensional_array(a, n);
       output_one_dimensional_array(a, n);
       return 0;
}