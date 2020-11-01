#include <iostream>

using namespace std;

void output_two_array(int **a, int m, int n, int i = 0)
{
       if (i == m * n)
       {
              return;
       }

       if (i % n == 0)
       {
              cout << endl;
       }

       cout << a[i / m][i % m] << "\t";

       output_two_array(a, m, n, i + 1);
}

void output_array(int *a, int n, int i = 0)
{
       if (i == n)
       {
              return;
       }

       cout << a[i] << "   ";
       output_array(a, n, i + 1);
}

void merge(int *a, int left, int mid, int right)
{
       int i, j;
       int k = left;
       int n1 = mid - left + 1;
       int n2 = right - mid;

       int *L = new int[n1];
       int *R = new int[n2];

       for (i = 0; i < n1; i++)
       {
              L[i] = a[k + i];
       }

       for (j = 0; j < n2; j++)
       {
              R[j] = a[mid + j + 1];
       }

       i = j = 0;

       while ((i < n1) && (j < n2))
       {
              a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
       }

       while (i < n1)
       {
              a[k++] = L[i++];
       }

       while (j < n2)
       {
              a[k++] = R[j++];
       }
}
void merge_sort(int *a, int left, int right)
{
       if (left < right)
       {
              int mid = (left + right) / 2;
              merge_sort(a, left, mid);
              merge_sort(a, mid + 1, right);
              merge(a, left, mid, right);
       }
}

void convertToYoung(int *a, int k, int **Y, int m, int n)
{
       merge_sort(a, 0, k - 1);

       for (int i = 0; i < m * n; i++)
       {
              if (i < k)
              {
                     Y[i / m][i % m] = a[i];
              }
              else
              {
                     Y[i / m][i % m] = 0;
              }
       }
       output_two_array(Y, m, n);
}

bool isYoungTable(int **Y, int m, int n)
{
       int i = 0;
       while (i < m * n - 1)
       {
              if ((i % m == n - 1))
              {
                     if (Y[i / m][i % m] > Y[(i + 1) / m][(i + 1) % m] && Y[(i + 1) / m][(i + 1) % m] != 0)
                     {
                            return false;
                     }
              }
              else
              {
                     if (Y[i / m][i % m] > Y[i / m][(i + 1) % m] && Y[i / m][(i + 1) % m] != 0)
                     {
                            return false;
                     }
              }
              i++;
       }
       return true;
}

int main()
{
       int a[] = {4, 2, 4, 6, 19, 5, 7, 10, 20, 21};
       int n = sizeof(a) / sizeof(a[0]);

       int row = 4;
       int column = 4;

       int **Y = new int *[row];
       for (int i = 0; i < row; i++)
       {
              Y[i] = new int[column];
       }

       output_array(a, n);

       cout << endl;

       convertToYoung(a, n, Y, row, column);

       cout << endl;

       cout << "Is Young Matrix: " << isYoungTable(Y, row, column);

       return 0;
}