#include <iostream>
#include <stdlib.h>
using namespace std;
class Shape {
public:
    virtual void get_data() = 0;
    virtual void show_data() const = 0;
    virtual double area() const = 0;
};
class Circle : public Shape {

public:
    double r;
    void get_data() {
        cout << "Enter Radius: ";
        cin >> r;
    }
    void show_data() const {
        cout << "[Circle   ]  Radius = " << r << " , Area = " << area() << endl;
    }
    double area() const {
        return 3.1416 * r * r;
    }
};

class Rectangle : public Shape {
public:
    double l, w;
    void get_data() {
        cout << "Enter Length: ";
        cin >> l;
        cout << "Enter Width: ";
        cin >> w;
    }
    void show_data() const {
        cout << "[Rectangle]  Length = " << l << " , Width = " << w << " , Area = " << area() << endl;
    }
    double area() const {
        return l * w;
    }
};

class Triangle : public Shape {
public:
    double b, h;
    void get_data() {
        cout << "Enter Base: ";
        cin >> b;
        cout << "Enter Height: ";
        cin >> h;
    }
    void show_data() const {
        cout << "[Triangle ]  Base = " << b << " , Height = " << h << " , Area = " << area() << endl;
    }
    double area() const {
        return 0.5 * b * h;
    }
};

int main() {
    Shape* p[100];
    int numShapes;
    cout << "How many Shapes you want to enter? ";
    cin >> numShapes;
    //sir i spent 63 min on these coming lines :(
    for (int i = 0; i < numShapes; ++i) {
        char choice;
        cout << "[options ]  c = circle, r = rectangle, t = triangle: ";
        cin >> choice;

            switch (choice) {
            case 'c':
                p[i] = new Circle;
                p[i]->get_data();
                p[i]->area();
                break;
            case 'r':
                p[i] = new Rectangle;
                p[i]->get_data();
                p[i]->area();
                break;
            case 't':
                p[i] = new Triangle;
                p[i]->get_data();
                p[i]->area();
                break;
            default:
                --i;
            }
           
            
            
        }
    for (int i = 0; i < numShapes; ++i) {
        p[i]->show_data();
    }
    return 0;
}
