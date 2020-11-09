#include <iostream>

using namespace std;

void inversion_compare(int number)
{
       if (number < 0)
       {
              cout << "You've entered wrong data" << endl;
              return;
       }

       int newNumber = 0;
       int temp = number;

       while (temp != 0)
       {
              int remainder = temp % 10;
              newNumber *= 10;
              newNumber += remainder;
              temp = temp / 10;
       }

       cout << "New Number is : " << newNumber << endl;

       if (newNumber > number)
       {
              cout << "After Inversion newNumber " << newNumber << " greater than number " << number << endl;
       }

       if (newNumber < number)
       {
              cout << "After Inversion newnumber " << newNumber << " less than number " << number << endl;
       }

       if (newNumber == number)
       {
              cout << "After Inversion newnumber " << newNumber << " equal number " << number << endl;
       }
}

int main()
{
       int a = 12345678;
       inversion_compare(a);
       return 0;
}