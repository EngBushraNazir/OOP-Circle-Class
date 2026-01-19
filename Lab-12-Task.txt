
#include <iostream>
#include <stdlib.h>
using namespace std;
class Length {
protected:
    int f;// feet
    float i;//inches
public:
    Length() { 
        f = 0, 
        i = 0; 
    }
    Length(float a) {                // for example 8.125  >>>>  i=0.125 , f=8
        int F = a;                   // this F will store just the intger part of a 
        float I =( a - F)*12;             //   this I will store the part after the dot of a
        f = F;
        i = I;
        while (I >= 12) {
            f++;
            i = I - 12;
        }
       
    }
    Length(int a, float b) {
        f = a;
        i = b;
    }
    void Show() const {
        cout << f << "'-" << i << "\"" ;
    }
    friend Length operator* (  Length , Length );
};

Length operator* (Length a, Length b) {
    float feet1 = (a.f + (a.i / 12.0)); // 2.5
    float feet2 =( b.f + (b.i / 12.0));  //3.25
    float FEET = feet1 * feet2;          // =8.125
    return Length(FEET);
};
int main() {
    Length Length1(2, 6.0);
    Length Length2(3,3.0);
    Length Length3 = Length1 * Length2;
    //or
    Length Length4= 2.5*Length2;
    Length Length5 =  Length2*2.5 ;

    cout  << "[Length1 ] ";
    Length1.Show();
    cout <<endl<< "[Length2 ] ";
    Length2.Show();

    cout << endl<<endl << "the result of multiplying two objects : "<<endl;
    Length3.Show();
    cout << endl << "the result of multiplying a number by object : "<<endl;
    Length4.Show();
    cout << endl << "the result of multiplying an object by a nubmber : " << endl;
    Length5.Show();
    cout << endl;

    return 0;
}
