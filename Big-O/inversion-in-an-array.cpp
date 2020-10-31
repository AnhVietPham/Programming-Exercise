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

int merge_count_inversion(int *a, int left, int mid, int right)
{
       int i, j;
       int k = left;
       int count_inversion = 0;
       int n1 = mid - left;
       int n2 = right - mid + 1;
       int *L = new int[n1];
       int *R = new int[n2];

       for (i = 0; i < n1; i++)
       {
              L[i] = a[left + i];
       }

       for (j = 0; j < n2; j++)
       {
              R[j] = a[mid + j];
       }

       i = j = 0;

       while (i < n1 && j < n2)
       {
              if (L[i] < R[j])
              {
                     a[k++] = L[i++];
              }
              else
              {
                     a[k++] = R[j++];

                     count_inversion = count_inversion + (mid - i);
              }
       }

       while (i < n1)
       {
              a[k++] = L[i++];
       }

       while (j < n2)
       {
              a[k++] = R[j++];
       }

       return count_inversion;
}

int merge_sort_count_inversion(int *a, int left, int right)
{
       int count_inversion = 0;
       if (left < right)
       {
              int mid = (left + right) / 2;
              count_inversion +=merge_sort_count_inversion(a, left, mid);
              count_inversion +=merge_sort_count_inversion(a, mid + 1, right);
              count_inversion += merge_count_inversion(a, left, mid + 1, right);
       }
       return count_inversion;
}

int main()
{
       int a[] = {1, 20, 6, 4, 5};
       int a1[] = {1, 20, 6, 4, 5};
       int n = sizeof(a) / sizeof(a[0]);
       int count_inversion = merge_sort_count_inversion(a, 0, n - 1);
       cout << "Number of inversion in an array: " << count_inversion << endl;
       cout << "Number of inversion in an array 1: " << count_number_inversion_in_an_array(a1, n);

       return 0;
}