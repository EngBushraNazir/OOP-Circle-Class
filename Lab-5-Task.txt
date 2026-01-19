
#define VECTOR_H
#include <iostream>
#include <cmath>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Vector {
private:
    double i;
    double j;
    double k;
public:
    Vector() {
            i = 0;
            j = 0;
            k = 0;
    }
    Vector(double iVal, double jVal, double kVal) {
            i = iVal;
            j = jVal;
            k = kVal;
    }
    void Get() {
        cout << "Enter Coefficient of <i>: ";
        cin >> i;
        cout << "Enter Coefficient of <j>: ";
        cin >> j;
        cout << "Enter Coefficient of <k>: ";
        cin >> k;
    }
    void Show() {
        cout << "< " << i << ", " << j << ", " << k << " >";
    }
    double Mod() const;
    double Dot(const Vector& B) const;
    Vector Cross(const Vector& B) const;
    Vector Sub(const Vector& B) const;
    Vector Add(const Vector& B) const;
};
double Vector::Mod() const {
    return sqrt(i * i + j * j + k * k);
}
double Vector::Dot(const Vector& B) const {
    return i * B.i + j * B.j + k * B.k;
}
Vector Vector::Cross(const Vector& B) const {
    double crossI = j * B.k - k * B.j;
    double crossJ = k * B.i - i * B.k;
    double crossK = i * B.j - j * B.i;
    return Vector(crossI, crossJ, crossK);
}
Vector Vector::Sub(const Vector& B) const {
    double subI = i - B.i;
    double subJ = j - B.j;
    double subK = k - B.k;
    return Vector(subI, subJ, subK);
}
Vector Vector::Add(const Vector& B) const {
    double addI = i + B.i;
    double addJ = j + B.j;
    double addK = k + B.k;

    return Vector(addI, addJ, addK);
}
int main() {
    Vector A, B;
    char operation;
    cout << "Enter Vector A:\n";
    A.Get();
    cout << "Enter Vector B:\n";
    B.Get();
    cout << "Enter Vector Operation:\n"
        << "[1] - Magnitude of A Vector.\n"
        << "[2] - Dot Product.\n"
        << "[3] - Cross Product.\n"
        << "[4] - A - B\n"
        << "[5] - A + B\n"
        << "[q] - Quit this Program\n";
    cin >> operation;

    switch (operation) {
    case '1':
        cout << "|A| = " << A.Mod() << '\n';
        break;
    case '2':
        cout << "A ∙ B = " << A.Dot(B) << '\n';
        break;
    case '3':
        A.Show();
        cout << " Cross ";
        B.Show();
        cout << " = ";
        A.Cross(B).Show();
        cout << '\n';
        break;
    case '4':
        A.Show();
        cout << " - ";
        B.Show();
        cout << " = ";
        A.Sub(B).Show();
        cout << '\n';
        break;
    case '5':
        A.Show();
        cout << " + ";
        B.Show();
        cout << " = ";
        A.Add(B).Show();
        cout << '\n';
        break;
    default:
        cout << "Invalid operation.\n";
        break;
    }
    return 0;
}
