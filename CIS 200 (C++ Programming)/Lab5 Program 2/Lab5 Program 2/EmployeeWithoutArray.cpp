
#include <iostream>
#include <iomanip>
#include"Employee.h"
using namespace std;



int main() {

	Employee x;

	x.setAge(30);
	x.setId(111);
	x.setSalary(30000);

	cout << "Employee Age: " << x.getAge() << endl;
	cout << "Employee Id: " << x.getId() << endl;
	cout << "Employee Salary is: " << x.getSalary();





	return 0;
}
