#include <iostream>
#pragma once
#include "Employee.h"

using namespace std;

class SingletonCEO : public Employee
{

private:
       static SingletonCEO *instance;
       SingletonCEO(){};

public:
       static SingletonCEO *getInstance();

       void setNameCEO(string nameCEO)
       {
              name = nameCEO;
       }

       string getNameCEO()
       {
              return name;
       }

       void calcSalary()
       {
              salary = 120 * 100;
       }
};