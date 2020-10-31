#include <iostream>

using namespace std;

void input_one_dimensional_array(int *a, int n, int i = 0)
{
       if (i == n)
       {
              return;
       }

       cout << "\nInput a[" << i << "]: ";
       cin >> a[i];
       input_one_dimensional_array(a, n, i + 1);
}

void output_one_dimensional_array(int *a, int n, int i = 0)
{
       if (i == n)
       {
              return;
       }
       cout << a[i] << "   ";
       output_one_dimensional_array(a, n, i + 1);
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
              L[i] = a[left + i];
       }

       for (j = 0; j < n2; j++)
       {
              R[j] = a[mid + j + 1];
       }

       i = j = 0;

       while (i < n1 && j < n2)
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

int main()
{
       int a[] = {38, 27, 43, 3, 9, 82, 10};
       int n = sizeof(a) / sizeof(a[0]);
       // input_one_dimensional_array(a, n);
       output_one_dimensional_array(a, n);
       cout << "\n";
       merge_sort(a, 0, n - 1);
       output_one_dimensional_array(a, n);
       return 0;
}