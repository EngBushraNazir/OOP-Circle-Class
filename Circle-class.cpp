#include<iostream>
#include<stdlib.h>
using namespace std;

class circle {


public:
	double X,Y,R;
	circle(){
		X=0;
		Y=0;
		R=0;
	
	}

	circle(double a,double b,double c){
		X=a;
		Y=b;
		R=c;

	}

	void set(double a, double b, double c){
		X=a;
		Y=b;
		R=c;
	}

	void get(){
	
	cout<<"Enter X cordinate : ";
	cin>>X;
	cout<<"Enter Y cordinate : ";
	cin>>Y;
	cout<<"Enter radius : ";
	cin>>R ;}

	void show (){
		cout<<"Enter X cordinate = "<<X<<endl<<"Enter Y cordinate = "<<Y<<endl<<"Radius = "<<R<<endl;
	}

	double area(){
		double A;
		A= 3.14*R*R;
		return A;
	}

	
	double circumference(){
		double C;
		C= 3.14*R*2;
		return C;
	}


};


int main (){
	circle ob1,ob2(10,20,50);
	ob2.show();
	cout<<"Area of C1 = "<<ob2.area()<<endl
		<<"Circumference of C1 = "<<ob2.circumference()<<endl;

	cout<<"For C2 : "<<endl;
	ob1.get();
	ob1.show();
	
	cout<<"Area of C2 = "<<ob1.area()<<endl
		<<"Circumference of C2 = "<<ob1.circumference()<<endl;
	system("PAUSE");
	return 0;

}
