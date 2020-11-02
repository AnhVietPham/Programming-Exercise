#include <iostream>
#pragma once
#include "Employee.h"

using namespace std;

class Engineer : public Employee
{
public:
       Engineer(string n) : Employee(n){};
       void calcSalary()
       {
              salary = 120;
       }
};