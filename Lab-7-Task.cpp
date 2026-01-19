#include <iostream>
#include <stdlib.h>
using namespace std;
class Rational {
private:
    int P, Q;
public:
    Rational() : P(1), Q(1) {}
    Rational(int p, int q) : P(p), Q(q) {}
    void Set(int p, int q) {
        P = p; 
        Q = q; 
    }
    void Get() {
        cout << "Enter P : "; 
        cin >> P; 
        cout << "Enter Q : "; 
        cin >> Q; 
    }
    void Show() { 
        cout << P << "/" << Q; 
    }
    int GCD();
    void Reduce();
    double Return_Double() {
        return static_cast<double>(P) / static_cast<double>(Q); 
    }
    Rational operator+(Rational B);
    Rational operator-(Rational B);
    Rational operator*(Rational B);
    Rational operator/(Rational B);
};
int Rational::GCD()
{
    int a = P, b = Q, temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void Rational::Reduce()
{
    int gcd = GCD();
    P /= gcd;
    Q /= gcd;
}
Rational Rational::operator+(Rational B)
{
    Rational C;
    C.P = P * B.Q + B.P * Q;
    C.Q = Q * B.Q;
    C.Reduce();
    return C;
}
Rational Rational::operator-(Rational B)
{
    Rational C;
    C.P = P * B.Q - B.P * Q;
    C.Q = Q * B.Q;
    C.Reduce();
    return C;
}
Rational Rational::operator*(Rational B)
{
    Rational C;
    C.P = P * B.P;
    C.Q = Q * B.Q;
    C.Reduce();
    return C;
}
Rational Rational::operator/(Rational B)
{
    Rational C;
    C.P = P * B.Q;
    C.Q = Q * B.P;
    C.Reduce();
    return C;
}
int main()
{
    Rational A, B, C;
    cout << "Enter 1st Rational Number:\n";
    A.Get();
    cout << "Enter 2nd Rational Number:\n";
    B.Get();
    C = A + B;
    cout << "\n";
    A.Show(); cout << " + "; B.Show(); cout << " = "; C.Show(); cout << "\n";
    C = A - B;
    cout << "\n";
    A.Show(); cout << " - "; B.Show(); cout << " = "; C.Show(); cout << "\n";
    C = A * B;
    cout << "\n";
    A.Show(); cout << " * "; B.Show(); cout << " = "; C.Show(); cout << "\n";
    C = A / B;
    cout << "\n";
    A.Show(); cout << " / "; B.Show(); cout << " = "; C.Show(); cout << "\n";
    return 0;
}
