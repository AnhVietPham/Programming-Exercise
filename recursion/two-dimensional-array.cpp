#include <iostream>
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

       return 0;
}