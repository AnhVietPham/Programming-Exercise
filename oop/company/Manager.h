#include <iostream>
#pragma once
#include "Employee.h"

using namespace std;

class Manager : public Employee
{
public:
       Manager(string n) : Employee(n){};
       void calcSalary()
       {
              salary = 120 * 10;
       }
};