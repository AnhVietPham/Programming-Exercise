#include <iostream>

using namespace std;

void reverse(char s[], int n)
{
       if (n == 0)
       {
              cout << s[0];
       }
       else
       {
              cout << s[n - 1] << " ";
              reverse(s, n - 1);
       }
}

int main()
{
       char s[] = {'a', 'b', 'c', 'd', 'e', 'f'};
       int size = sizeof(s) / sizeof(s[0]);
       reverse(s, size);
       return 0;
}