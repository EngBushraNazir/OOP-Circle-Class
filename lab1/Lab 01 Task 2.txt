#include<iostream>
#include<stdlib.h>
using namespace std;

class rectangle {


public:
	int l,w;

	void set(int a, int b){
		l=a;
		w=b;
	}

	void get(){
	
	cout<<"Enter length : ";
	cin>>l;
	cout<<"Enter width : ";
	cin>>w;}


	int area(){
		int A;
		A= l*w;
		return A;
	}

	
	int perimeter(){
		int p;
		p= 2*(l+w);
		return p;
	}

	void drow(){
		for(int i=1;i<=l;i++){

			for(int j=1;j<=w;j++){

				if(i!=1&&i!=l&&j!=1&&j!=w)
					cout<<" ";
				else
					cout<<"*";
			}
			cout<<endl;
		}
	
	
	}

};


int main (){
	rectangle ob1;
	ob1.get();
	cout<<"area =  "<< ob1.area()<<endl;
	cout<<"perimeter =  "<< ob1.perimeter()<<endl;
	ob1.drow();}
