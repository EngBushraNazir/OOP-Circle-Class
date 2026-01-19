#include<stdlib.h>
#include<iostream>
#include<windows.h>
using namespace std;


class time {
public:
	int H,M,S;  // hours,minutes,seconds

	time(){
		H=0;
		M=0;
		S=0;
	};
	time(int a, int b,int c){
		H=a;
		M=b;
		S=c;
	};

	void get(){
		cout<<"Enter time : "<<endl<<"H = ";
		cin>>H;
		cout<<"M = ";
		cin>>M;
		cout<<"S = ";
		cin>>S;
	};

	void set(int a, int b, int c){
		H=a;
		M=b;
		S=c;

	};

	void show(){
		if(H<10){cout<<"0"<<H<<" : ";}
		else{
			cout<<H<<" : ";}
		if(M<10){cout<<"0"<<M<<" : ";}
		else{
			cout<<M<<" : ";}
		if(S<10){cout<<"0"<<S;}
		else cout<<S;
		cout<<endl;


	};
	void tick (){
		S=S+1;
		
		if(S>59){S=0; M++;};
		if(M>59){M=0; H++;};
		if(H>23){H=0;};

	};

	void operator ++(){
		time temp1;
		S++;
		if(S>59){S=0; M++;};
		if(M>59){M=0; H++;};
		if(H>23){H=0; };
		temp1.S=S; temp1.M=M; temp1.H=H;

	};
	
	void operator ++(int a){
		time temp1;
		++S;
		if(S>59){S=0; ++M;};
		if(M>59){M=0; ++H;};
		if(H>23){H=0; };
		temp1.S=S; temp1.M=M; temp1.H=H;

	};

	
	void operator --(){
		time temp3;
		S--;
		if(S<0){S=59; --M;};
		if(M<59){M=59; --H;};
		if(H<0){H=23; };
		temp3.S=S; temp3.M=M; temp3.H=H;

	};
	
	void operator-- (int a){
		time temp4;
		--S;
		if(S<0){S=59; --M;};
		if(M<59){M=59; --H;};
		if(H<0){H=23; };
		temp4.S=S; temp4.M=M; temp4.H=H;

	};
};

int main (){
	time ob1;
	ob1.get();
	for(int i =1;i>=1;i++){
		//ob1.tick();
		ob1++;
		
		Sleep(1000);
		ob1.show()  ;};


}
