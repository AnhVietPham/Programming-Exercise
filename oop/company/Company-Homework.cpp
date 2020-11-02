#include <iostream>
#pragma once
#include "Engineer.h"
#include "Manager.h"
#include "SingletonCEO.h"
using namespace std;

SingletonCEO *SingletonCEO::instance = 0;

SingletonCEO *SingletonCEO::getInstance()
{
       if (instance == 0)
       {
              instance = new SingletonCEO();
       }
       return instance;
}

int main()
{
       Employee *e[3];
       e[0] = SingletonCEO::getInstance();
       SingletonCEO::getInstance()->setNameCEO("Anh Viet Pham");
       e[0]->calcSalary();
       e[1] = new Manager("Huy Hoang Pham");
       e[1]->calcSalary();
       e[2] = new Engineer("Tran Hong Phuc");
       e[2]->calcSalary();
       cout << "CEO: " << e[0]->getName() << endl;
       cout << "CEO's salary: " << e[0]->getSalary() << endl;
       cout << "Manager: " << e[1]->getName() << endl;
       cout << "Manager's salary: " << e[1]->getSalary() << endl;
       cout << "Engineer: " << e[2]->getName() << endl;
       cout << "Engineer's salary: " << e[2]->getSalary();
       return 0;
}