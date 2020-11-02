#include <iostream>
#pragma once
using namespace std;

class Employee
{
protected:
       string name;
       float salary;

public:
       Employee(){};
       Employee(string n)
       {
              name = n;
       };
       virtual void calcSalary() = 0;

       string getName()
       {
              return name;
       }

       float getSalary()
       {
              return salary;
       }
};