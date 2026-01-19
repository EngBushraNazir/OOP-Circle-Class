#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;
class Employee {
private:
    char name[100];
    int salary;
public:
    void add_record();
    void show_all();
    void search();
    void Delete();
};
void Employee::add_record() {
    cout << "enter name: ";
    cin.ignore(100, '\n');
    cin.getline(name, 100);
    cout << "enter salary:";
    cin >> salary;
    ofstream outfile;
    outfile.open("employees.xt", std::ios_base::app);
    outfile << name << "\\" << salary << endl;
    system("pause");
}
void Employee::show_all() {
    system("CLS");
    const int MAX = 240; 
    int S_No = 0;
    char buffer[MAX];

    ifstream readfile("employees.xt");  //  to read

    while (readfile) {
        readfile.getline(buffer, MAX);

        if (strlen(buffer) > 0) {
            const char* delim = "\\";
            char* next_token;
            char* name = strtok_s(buffer, delim, &next_token);
            char* salary = strtok_s(NULL, delim, &next_token);
            cout << "#" << ++S_No << endl;
            cout << " name = " << name << endl;
            cout << " salary = " << salary << endl;
        }
    }
}
void Employee::search() {
    int S_No = 0;
    cout << "Enter name to Search: ";
    cin.ignore(100, '\n');
    cin.getline(this->name, 100);
    system("CLS");
    const int MAX = 240;
    char buffer[MAX];
    ifstream infile("employees.xt");
    while (infile) {
        infile.getline(buffer, MAX);
        if (strlen(buffer) > 0) {
            const char* delim = "\\";
            char* next_token;
            char* name = strtok_s(buffer, delim, &next_token);
            char* salary = strtok_s(NULL, delim, &next_token);
            char* output = strstr(name, this->name);
            S_No++;
            if (output) {
                cout << "#" << S_No << endl;
                cout << "name = " << name << endl;
                cout << "salary = " << salary << endl;
                cout << "_________________________________" << endl;
            }
        }
    }
}
void Employee::Delete() {
    system("CLS");
    const int MAX = 240;
    int R_No = 0, S_No = 0;
    cout << "Please Enter Record Number: ";
    cin >> R_No;
    char buffer[MAX];
    ifstream infile("employees.xt");
    ofstream outfile("temp.txt");
    while (infile) {
        infile.getline(buffer, MAX);
        if (strlen(buffer) > 0) {
            const char* delim = "\\";
            char* next_token;
            char* name = strtok_s(buffer, delim, &next_token);
            char* salary = strtok_s(NULL, delim, &next_token);
            S_No++;
            if (S_No == R_No) {
                char choice;
                cout << "#" << S_No << endl;
                cout << " name = " << name << endl;
                cout << " salary = " << salary << endl;
                cout << "Do you want to Delete this Record [y/n]?: ";
                cin >> choice;
                if (choice == 'y')
                    continue;
                else
                    outfile << name << "\\" << salary << endl;
            }
            else
                outfile << name << "\\" << salary << endl;
        }
    }
    infile.close();
    outfile.close();
    remove("employees.xt");
    rename("temp.txt", "employees.xt");
}




int main() {
    Employee e;
    while (1) {
        char choice;
        cout << "[Operations]" << endl;
        cout << "A - Add" << endl;
        cout << "D - Delete" << endl;
        cout << "R - Read All" << endl;
        cout << "S - Search Title" << endl;
        cin >> choice;
        switch (choice) {
        case 'A':
        case 'a': e.add_record(); break;
        case 'D':
        case 'd': e.Delete(); break;
        case 'R':
        case 'r': e.show_all(); break;
        case 'S':
        case 's': e.search(); break;
        default: cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}
