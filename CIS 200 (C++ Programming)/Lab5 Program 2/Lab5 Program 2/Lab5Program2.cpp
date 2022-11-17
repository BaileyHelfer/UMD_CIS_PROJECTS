#include <iostream>
#include <iomanip>
#include"Employee.h"

using namespace std;

const int ROW = 2;
const int COLUMN = 3;

void printEmployee(Employee x[][COLUMN], int ROW, int COLUMN) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << setw(7) << x[i][j].getAge() << setw(16);
			cout << x[i][j].getId() << setw(19);
			cout << x[i][j].getSalary() << endl;
		}
	}
}

int main() {
	Employee x[ROW][COLUMN];
	int age = 30;
	int ageSum = 0;
	int id = 111;
	float salary = 30000;
	float salarySum = 0;

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			x[i][j].setAge(age);
			x[i][j].setId(id);
			x[i][j].setSalary(salary);
			
			ageSum = ageSum + age;
			salarySum = salarySum + salary;
			age = age + 1;
			id = id + 1;
			salary = salary + 1000;	
		}
	}
	float avgAge = ageSum / 6.0;
	float avgSalary = salarySum / 6.0;

	cout << "Employee Age" << setw(15) << right << "Employee ID" << setw(20) << right << "Employee Salary" << endl;
	printEmployee(x, ROW, COLUMN);
	cout << "The Average Age of Employees are: " << avgAge << endl << "The Average Salary of Employees are: " << avgSalary;
	
	return 0;

}








