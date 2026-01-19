#include<iostream>
#include<stdlib.h>
using namespace std;

class FIFO{
protected:
	int st[5] , top , tail;

public:
	FIFO(){
		top = -1 ;
		tail = -1 ;

	}

	void push(int var){
		
		top++;
		if(top > 4)
			top = 0;

			st[top]=var;
		cout<<"push = "<<st[top]<<endl;



	}

	int pop(){
		// if(tail==top){top=-1;tail=-1;}
		// else
		tail++;
		if(tail == 5)
			tail = 0;
		cout<<"pop = "<<st[tail]<<endl;
		return tail;
	}

};


class FIFO2:public FIFO{
public:
	void push (int var){
		
		if( top>=4 && tail==-1)
		{
			cout<<"cannot Push 3"<<var<<", Stack is Full"<<endl;
		}
		else if( ( top == tail) && (tail != -1) ) 
		{
			cout<<"cannot Push 2 "<<var<<", Stack is Full"<<endl;
		}

		else {
			FIFO::push(var);
		}

	}


	int pop(){
		
		if(tail==-1 &&top==-1){
			cout<<"Cannot Pop, Stack is Empty "<<endl;
		return -1;
		}
		
		int val =  FIFO::pop();
		if (top == tail)
			top = tail = -1;
		return val;
	}
};


int main(){
	FIFO2 ob;
	ob.push(11);
	ob.push(22);
	ob.push(33);
	ob.push(44);
	ob.push(55);
	ob.push(66);
	ob.pop();
	ob.pop();
	ob.push(77);
	ob.push(88);
	ob.push(99);
	ob.pop();
	ob.pop();
    ob.pop();
    ob.pop();
    ob.pop();
	ob.pop();

	

	system("PAUSE");
	return 0;

	
}
