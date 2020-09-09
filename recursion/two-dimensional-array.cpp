#include <iostream>
#include <limits.h>
using namespace std;

/*
1/ Input two dimensional array
2/ Output two dimensional array
3/ Sum of all element in two dimensional array
4/ Min and Max in two dimensional array
5/ Quantity of even number in two dimensional array
6/ Arrange incresing and decresing two dimensional array
Note: Only using recursion
*/

void input_2D_array(int **a, int row, int column, int i = 0)
{
       if (i == row * column)
       {
              return;
       }
       cout << "Input a[" << i / column << "][" << i % column << "]: ";
       cin >> a[i / column][i % column];
       input_2D_array(a, row, column, i + 1);
}

void output_2D_array(int **a, int row, int column, int i = 0)
{
       if (i == row * column)
       {
              return;
       }

       if (i % column == 0)
       {
              cout << "\n";
       }

       cout << a[i / column][i % column] << "   ";
       output_2D_array(a, row, column, i + 1);
}

int find_min(int **a, int row, int column, int i = 0, int MIN = INT_MAX)
{

       if (i == row * column)
       {
              return MIN;
       }

       return find_min(a, row, column, i + 1, a[i / column][i % column] < MIN ? a[i / column][i % column] : MIN);
}

int find_max(int **a, int row, int column, int i = 0, int MAX = 0)
{
       if (i == column * row)
       {
              return MAX;
       }
       return find_max(a, row, column, i + 1, a[i / column][i % column] > MAX ? a[i / column][i % column] : MAX);
}

int sum_2D_array(int **a, int row, int column, int i = 0, int sum = 0)
{
       if (i == column * row)
       {
              return sum;
       }
       return sum_2D_array(a, row, column, i + 1, sum + a[i / column][i % column]);
}

int quantity_of_even_number_2D_array(int **a, int row, int column, int i = 0, int count = 0)
{
       if (i == column * row)
       {
              return count;
       }
       return quantity_of_even_number_2D_array(a, row, column, i + 1, a[i / column][i % column] % 2 == 0 ? count + 1 : count);
}

int quantity_of_odd_number_2D_array(int **a, int row, int column, int i = 0, int count = 0)
{
       if (i == column * row)
       {
              return count;
       }
       return quantity_of_odd_number_2D_array(a, row, column, i + 1, a[i / column][i % column] % 2 != 0 ? count + 1 : count);
}

int sum_of_even_numer_2D_array(int **a, int row, int column, int i = 0, int sum = 0)
{
       if (i == row * column)
       {
              return sum;
       }

       return sum_of_even_numer_2D_array(a, row, column, i + 1, a[i / column][i % column] % 2 == 0 ? (sum + a[i / column][i % column]) : sum);
}

int sum_of_odd_numer_2D_array(int **a, int row, int column, int i = 0, int sum = 0)
{
       if (i == column * row)
       {
              return sum;
       }

       return sum_of_odd_numer_2D_array(a, row, column, i + 1, a[i / column][i % column] % 2 != 0 ? (sum + a[i / column][i % column]) : sum);
}

// void swap(int &a, int &b)
// {
//        int temp = a;
//        b = a;
//        a = temp;
// }

// void arrange_increasing_2D_array(int **a, int row, int column, int i = 0)
// {
// }

// void arrange_decreasing_2D_array(int **a, int row, int column, int i = 0)
// {
// }

int main()
{
       int row = 3;
       int column = 3;

       int **a = new int *[row];

       for (int i = 0; i < row; i++)
       {
              a[i] = new int[column];
       }

       input_2D_array(a, row, column);
       output_2D_array(a, row, column);

       cout << "\nMax of 2D-Array is: " << find_max(a, row, column);
       cout << "\nMin of 2D-Array is: " << find_min(a, row, column);
       cout << "\nSum of 2D-Array is: " << sum_2D_array(a, row, column);
       cout << "\nQuantity of even number of 2D-Array is: " << quantity_of_even_number_2D_array(a, row, column);
       cout << "\nQuantity of odd number of 2D-Array is: " << quantity_of_odd_number_2D_array(a, row, column);
       cout << "\nSum of even number of 2D-Array is: " << sum_of_even_numer_2D_array(a, row, column);
       cout << "\nSum of odd number of 2D-Array is: " << sum_of_odd_numer_2D_array(a, row, column);

       return 0;
}