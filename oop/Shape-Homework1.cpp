#include <iostream>
using namespace std;

class DrawingShape;

class Shape
{
protected:
       DrawingShape *drawer;

public:
       Shape(DrawingShape *ds)
       {
              drawer = ds;
       };
       virtual void draw() = 0;
};

class DrawingShape
{
public:
       virtual void draw(Shape *s) = 0;
};

class Rectangle : public Shape
{
private:
       int x, y, width, height;

public:
       Rectangle(int x, int y, int with, int height, DrawingShape *ds) : Shape(ds){};

       void draw()
       {
              drawer->draw(this);
       }
};

class Circle : public Shape
{
private:
       int x, y, radius;

public:
       Circle(int x, int y, int r, DrawingShape *ds) : Shape(ds){};
       void draw()
       {
              drawer->draw(this);
       }
};

class DrawingRectangle : public DrawingShape
{
public:
       void draw(Shape *s)
       {
              cout << "Rectangle" << endl;
       }
};

class DrawingCircle : public DrawingShape
{
public:
       void draw(Shape *s)
       {
              cout << "Circle" << endl;
       }
};

int main()
{
       Shape *s[3];
       DrawingShape *dr = new DrawingRectangle();
       DrawingShape *dc = new DrawingCircle();
       s[0] = new Rectangle(10, 10, 10, 10, dr);
       s[1] = new Rectangle(20, 20, 20, 20, dr);
       s[2] = new Circle(5, 5, 5, dc);
       for (int i = 0; i < 3; i++)
              s[i]->draw();

       cout << dr << "\n";
       cout << dc << "\n";
       delete dr;
       delete dc;
       cout << dr << "\n";
       cout << dc << "\n";
       for (int i = 0; i < 3; i++)
              delete s[i];
}