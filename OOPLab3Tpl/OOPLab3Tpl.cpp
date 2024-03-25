// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
    double side1, side2, side3;
    unsigned int color;

public:
    Triangle() : side1(1.0), side2(1.0), side3(1.0), color(0) {}

    Triangle(double s1, double s2, double s3) : color(0) {
        if (isValidTriangle(s1, s2, s3)) {
            side1 = s1;
            side2 = s2;
            side3 = s3;
        }
        else {
            cout << "Invalid triangle sides. Defaulting to equilateral triangle." << endl;
            side1 = side2 = side3 = 1.0;
        }
    }

    Triangle(double s1, double s2, double s3, int c) {
        if (isValidTriangle(s1, s2, s3)) {
            side1 = s1;
            side2 = s2;
            side3 = s3;
        }
        else {
            cout << "Invalid triangle sides. Defaulting to equilateral triangle." << endl;
            side1 = side2 = side3 = 1.0;
        }
        if (c >= 0 && c <= 10000)
            color = c;
        else {
            cout << "Invalid color value. Defaulting to 0." << endl;
            color = 0;
        }
    }

    double getSide1() const { return side1; }
    double getSide2() const { return side2; }
    double getSide3() const { return side3; }
    int getColor() const { return color; }

    void setSides(double s1, double s2, double s3) {
        if (isValidTriangle(s1, s2, s3)) {
            side1 = s1;
            side2 = s2;
            side3 = s3;
        }
        else {
            cout << "Invalid triangle sides." << endl;
        }
    }

    void setColor(int c) {
        if (c >= 0 && c <= 10000)
            color = c;
        else
            cout << "Invalid color value." << endl;
    }

    double calculateArea() {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() {
        return side1 + side2 + side3;
    }

    void printInfo() {
        cout << "Triangle sides: " << side1 << ", " << side2 << ", " << side3 << endl;
        cout << "Triangle color: " << color << endl;
        cout << "Triangle area: " << calculateArea() << endl;
        cout << "Triangle perimeter: " << calculatePerimeter() << endl;
    }

private:
    bool isValidTriangle(double s1, double s2, double s3) {
        return (s1 > 0 && s2 > 0 && s3 > 0 && s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1);
    }
};

int main() {
    Triangle triangle1;
    triangle1.printInfo();

    double side1, side2, side3;
    int color;

    cout << "Enter sides of the triangle: ";
    cin >> side1 >> side2 >> side3;

    cout << "Enter color of the triangle: ";
    cin >> color;

    Triangle triangle2(side1, side2, side3);
    Triangle triangle3(side1, side2, side3, color);

    triangle2.printInfo();
    triangle3.printInfo();

    return 0;
}

