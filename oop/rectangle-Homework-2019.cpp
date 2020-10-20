#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
       float x, y;

public:
       Point(int x_init, int y_int)
       {
              x = x_init;
              y = y_int;
       };
       void display()
       {
              cout << "X: " << x << ", Y: " << y;
       };

       float getX()
       {
              return x;
       };
       float getY()
       {
              return y;
       };
};

class Triangle
{
private:
       Point *pointA, *pointB, *pointC;

public:
       Triangle(Point *pointA_init, Point *pointB_init, Point *pointC_init)
       {
              pointA = pointA_init;
              pointB = pointB_init;
              pointC = pointC_init;
       };

       void isTheSamePeak(Triangle *triangle)
       {
              if (this->pointA->getX() == triangle->pointA->getX() && this->pointA->getY() == triangle->pointA->getY())
              {
                     cout << "The same Peak A" << endl;
              }

              if (this->pointB->getX() == triangle->pointB->getX() && this->pointB->getY() == triangle->pointB->getY())
              {
                     cout << "The same Peak B" << endl;
              }

              if (this->pointC->getX() == triangle->pointC->getX() && this->pointC->getY() == triangle->pointC->getY())
              {
                     cout << "The same Peak C" << endl;
              }
       };

       bool isTheSameEdge(Triangle *triangle)
       {
              if (this->pointA->getX() == triangle->pointA->getX() && this->pointA->getY() == triangle->pointA->getY() && this->pointB->getX() == triangle->pointB->getX() && this->pointB->getY() == triangle->pointB->getY())
              {
                     cout << "The same EDGE AB" << endl;
              }

              if (this->pointA->getX() == triangle->pointA->getX() && this->pointA->getY() == triangle->pointA->getY() && this->pointC->getX() == triangle->pointC->getX() && this->pointC->getY() == triangle->pointC->getY())
              {
                     cout << "The same EDGE AC" << endl;
              }

              if (this->pointB->getX() == triangle->pointB->getX() && this->pointB->getY() == triangle->pointB->getY() && this->pointC->getX() == triangle->pointC->getX() && this->pointC->getY() == triangle->pointC->getY())
              {
                     cout << "The same EDGE BC" << endl;
              }
              
       }

       float edgeAB()
       {
              return sqrt(pow(pointB->getX() - pointA->getX(), 2) + pow(pointB->getY() - pointA->getY(), 2));
       };

       float edgeBC()
       {
              return sqrt(pow(pointB->getX() - pointC->getX(), 2) + pow(pointB->getY() - pointC->getY(), 2));
       };

       float edgeAC()
       {
              return sqrt(pow(pointA->getX() - pointC->getX(), 2) + pow(pointA->getY() - pointC->getY(), 2));
       };
};

int main()
{
       Point *pointA = new Point(3, 5);
       Point *pointB = new Point(4, 6);
       Point *pointC = new Point(6, 7);

       Triangle *triangleOne = new Triangle(pointA, pointB, pointC);
       cout << "Edge AB: " << triangleOne->edgeAB() << endl;
       cout << "Edge BC: " << triangleOne->edgeBC() << endl;
       cout << "Edge AC: " << triangleOne->edgeAC() << endl;

       Point *pointD = new Point(3, 5);
       Point *pointE = new Point(4, 6);
       Point *pointF = new Point(6, 7);

       Triangle *triangleTwo = new Triangle(pointD, pointE, pointF);

       triangleOne->isTheSamePeak(triangleTwo);
       triangleOne->isTheSameEdge(triangleTwo);


       return 0;
}