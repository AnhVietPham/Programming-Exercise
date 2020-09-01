#include <iostream>

using namespace std;

int fibUsingNormalApproach(int n){
       if (n == 0){
              return 0;
       }

       int f0 = 0;
       int f1 = 1;
       int fn;

       for (int i = 2; i <= n; i++){
              fn = f0 + f1;
              f0 = f1;
              f1 = fn;
       }

       return f1;
}


int fibUsingDynamicProgramming(int n)
{

       if (n == 0){
              return 0;
       }

       int fi[n + 2];

       fi[0] = 0;
       fi[1] = 1;

       for (int i = 2; i <= n; i++)
       {
              fi[i] = fi[i - 1] + fi[i - 2];
       }
       return fi[n];
}

int main()
{
       // 0 1 1 2 3 5
       cout << "Fibonacci using dynamic programming is " << fibUsingDynamicProgramming(5) << "\n";
       cout << "Fibonacci using normal approach is " << fibUsingNormalApproach(5);
       return 0;
}