#include <iostream>
#include <math.h>

using namespace std;

// Homework 749

float recursion_749(int n){
       if (n == 1)
       {
              return 1;
       }
       
       return sqrt(n + recursion_749(n - 1));
}

float tail_recursion_749(int n,int x = 2, float result = 1){
       if (n == 1)
       {
              return result;
       }
       

       if (n == x)
       {
              return sqrt(x + result);
       }
       
       return tail_recursion_749(n, x + 1, sqrt(x + result));
}

float naive_code_749(int n){
   
       float result = 1;

       for (int i = 2; i <= n; i++)
       {
              result = sqrt(i + result); 
       }

       return result;
}


int main(){
       int n = 3;
       cout << "Recursion is " << recursion_749(n) << "\n";
       cout << "Tail Recursion is " << tail_recursion_749(n) << "\n";
       cout << "Naive code is " << naive_code_749(n);
       return 0;
}