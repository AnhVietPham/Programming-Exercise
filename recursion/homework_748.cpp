#include <iostream>
#include <math.h>

using namespace std;

// Exercise 748

float n_sign_square_root_of_2_recursion_748(int n)
{
       if (n == 1)
       {
              return sqrt(2);
       }

       return sqrt(2 + n_sign_square_root_of_2_recursion_748(n - 1));
}

float tail_n_sign_square_root_of_2_recursion_748(int n, float result = sqrt(2))
{
       if (n == 1)
       {
              return result;
       }

       return tail_n_sign_square_root_of_2_recursion_748(n - 1, sqrt(2 + result));
}

float naive_code_n_sign_square_root_of_2_recursion_748(int n)
{
       float square_root_of_2 = sqrt(2);

       for (int i = 2; i <= n; i++)
       {
              square_root_of_2 = sqrt(2 + square_root_of_2);
       }

       return square_root_of_2;
}

int main()
{
       int n = 1;
       cout << "N sign square of 2 Recursion is " << n_sign_square_root_of_2_recursion_748(n) << "\n";
       cout << "N sign square of 2 Tail Recursion is " << tail_n_sign_square_root_of_2_recursion_748(n) << "\n";
       cout << "N sign square of 2 Naive code is " << naive_code_n_sign_square_root_of_2_recursion_748(n);
       return 0;
}