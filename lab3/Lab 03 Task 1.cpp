#include<iostream>
#include<stdlib.h>
using namespace std;

class tree{

public:
	unsigned int H; //high
	tree(){
	H=0;
	cout<<"a tree has been created"<<endl;}

	tree(int a){
	H =a;
	cout<<"a tree of "<<a<<"high has been created "<<endl;
	}

	~tree(){
		cout<<"the tree has been destroyed"<<endl;
	}
	void grow(int m){
		H=H+m;
	}

	void printsize(){
		cout <<"tree high is "<<H<<" meter "<<endl;
	}

	void create_tree();






};

void create_tree(){
		tree t;
		t.grow(20);
		t.printsize();
	}


int main (){

	create_tree();
	create_tree();

}
