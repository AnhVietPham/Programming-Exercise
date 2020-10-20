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

       bool isTriangle(){

       };

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

       Triangle *triangle = new Triangle(pointA, pointB, pointC);
       cout << "Edge AB: " << triangle->edgeAB()<< endl;
       cout << "Edge BC: " << triangle->edgeBC() << endl;
       cout << "Edge AC: " << triangle->edgeAC() << endl;

       return 0;
}