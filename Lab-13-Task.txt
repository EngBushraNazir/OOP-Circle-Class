#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
class Employee {
private:
    unsigned int id;
    char name[100];
    static int total;
   
public:
    Employee() {
        ++total;
        id = total;
        name[0] = '\0';
    }
    ~Employee() {
        cout << "Destroying ID: " << id << " of Employee: " << name << endl;
        --total;
        Employee::show_total();    
        system("PAUSE");       // first time using this out of main :)
       
    }
    void get_data() {
        cout << "Enter Name: ";
        cin.getline(name, 100);
    }
    void show_data() const {
        cout << "Your ID = " << id << " and Your Name = " << name << endl;
    }
    static void show_total() {
        cout << "Total Employees are: " << total << endl;
    }
};
int Employee::total = 0;
int main() {
    Employee::show_total();
    Employee emp1;
    emp1.get_data();
    emp1.show_data();
    Employee::show_total();
    Employee* emp2= new Employee;
    emp2->get_data();
    emp2->show_data();
    delete emp2;
    return 0;
}
