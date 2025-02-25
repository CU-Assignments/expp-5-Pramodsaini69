#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Employee {
public:
    string name;
    int id;
    string designation;
    double salary;

    void input() {
        cout << "Enter Employee Name: ";
        cin >> ws; // to consume any leading whitespace
        getline(cin, name);
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Designation: ";
        cin >> ws;
        getline(cin, designation);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void display() const {
        cout << "Name: " << name << ", ID: " << id << ", Designation: " << designation << ", Salary: " << salary << endl;
    }
};

void addEmployee(vector<Employee>& employees) {
    Employee emp;
    emp.input();
    employees.push_back(emp);

    ofstream outFile("employees.dat", ios::app | ios::binary);
    if (outFile.is_open()) {
        outFile.write((char*)&emp, sizeof(emp));
        outFile.close();
    } else {
        cout << "Unable to open file for writing" << endl;
    }
}

void displayAllEmployees() {
    ifstream inFile("employees.dat", ios::in | ios::binary);
    if (inFile.is_open()) {
        Employee emp;
        while (inFile.read((char*)&emp, sizeof(emp))) {
            emp.display();
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading" << endl;
    }
}

int main() {
    vector<Employee> employees;
    int option;
    do {
        cout << "1. Add an Employee\n2. Display All\n3. Exit\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1:
                addEmployee(employees);
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    } while (option != 3);

    return 0;
}
