#include<iostream>
#include<stdlib.h>
using namespace std;

class temp {


public:
	double c;

	temp(){
		c=0;
	}

	void getC(){

		cout <<"Enter temprature in C :";
		cin>>c;
	}

	
	void getF(){
		double f;
		cout <<"Enter temprature in F :";
		cin>>f;
		c=(f-32)*5.0/9.0;
	}

	void showC (){
		cout<<"current temprature in C is : "<<c<<endl;

	}

	void showF (){
		double f=(9.0/5.0)*c+32;
		cout<<"current temprature in F is : "<<f<<endl;
	}

	

};


int main (){

	temp ob1 ;
	ob1.getF();
	ob1.showC();
	ob1.showF();
	ob1.getC();
	ob1.showC();
	ob1.showF();


	system("PAUSE");
	return 0;

}
