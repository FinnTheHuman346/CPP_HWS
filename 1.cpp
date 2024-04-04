#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


class Shape {
    protected:
        double x;
        double y;
    public:
    Shape(double x, double y) : x(x), y(y) {};
    virtual ~Shape() {};
    virtual double area() const = 0;
};

class Circle : public Shape {
    protected:
        double r;
    public:
    Circle(double x, double y, double r): Shape(x, y) {
        this->r = r;
    }
    virtual double area() const {
        return M_PI * r * r;
    }
};

class Rectangle : public Shape {
    protected:
        double w;
        double h;
    public:
    Rectangle(double x, double y, double w, double h): Shape(x, y) {
        this->w = w;
        this->h = h;
    }
    virtual double area() const {
        return w * h;
    }
};


int main() {
    vector<Shape*> v;
    Circle a = Circle(3,5,7);
    Rectangle b = Rectangle(3,5,7,9);
    Circle c = Circle(2,2,2);
    v.push_back(&a);
    v.push_back(&b);
    v.push_back(&c);
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i]->area() << endl;
    }
    return 0;
}