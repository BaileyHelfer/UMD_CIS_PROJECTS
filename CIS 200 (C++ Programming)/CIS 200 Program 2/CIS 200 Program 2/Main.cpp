#include <iostream>
#include <fstream>
#include "Class.h"
using namespace std;


int main()
{
	HourlyEmployeePay instance1;
	ofstream outFile;
	outFile.open("pay.txt");
	outFile.clear();
	string first, last, ssn, num, company;
	char letter, workStatus;
	float hourRate, hoursWorked, otPay, annualPay;
	int taxCode;
	cout << "Hourly Employee" << endl;
	outFile << "Hourly Emplyee" << endl;
	cout << "Enter first name: ";
	cin >> first;
	cout << endl;
	cout << "Enter last: ";
	cin >> last;
	cout << endl;
	instance1.setName(first, last);

	cout << "Enter SSN: ";
	cin >> ssn;
	cout << endl;
	instance1.setSSN(ssn);

	cout << "Enter num to emp: ";
	cin >> num;
	

	cout << "Enter letter to emp: ";
	cin >> letter;
	cout << endl;
	instance1.setEmpNum(num, letter);

	cout << "Enter in hour rate: ";
	cin >> hourRate;

	instance1.setHourPay(hourRate);

	cout << "Hours worked: ";
	cin >> hoursWorked;
	cout << endl;
	instance1.setHoursWorked(hoursWorked);
	instance1.setOtPay(instance1.getHourPay());
	
	cout << "Tax Code: ";
	cin >> taxCode;
	cout << endl;
	instance1.setTaxCode(taxCode);

	cout << "Work status: ";
	cin >> workStatus;
	cout << endl;
	instance1.setWorkStatus(workStatus);
	
	instance1.printHourlyEmployee(outFile);
	

	SalaryEmployeePay instance2;
	cout << endl;
	outFile << endl;

	cout << "Salary Employee" << endl;
	outFile << "Salary Employee" << endl;
	cout << "Enter first name: ";
	cin >> first;
	cout << endl;
	cout << "Enter last: ";
	cin >> last;
	cout << endl;
	instance2.setName(first, last);

	cout << "Enter SSN: ";
	cin >> ssn;
	cout << endl;
	instance2.setSSN(ssn);

	cout << "Enter num to emp: ";
	cin >> num;


	cout << "Enter letter to emp: ";
	cin >> letter;
	cout << endl;
	instance2.setEmpNum(num, letter);

	cout << "Enter in Annual Pay: ";
	cin >> annualPay;
	cout << endl;
	instance2.setAnnualPay(annualPay);
	instance2.setWeekPay(annualPay);

	cout << "Tax Code: ";
	cin >> taxCode;
	cout << endl;
	instance2.setTaxCode(taxCode);

	instance2.printSalaryEmployee(outFile);
	
	AgencyEmployeePay instance3;
	cout << endl;
	outFile << endl;
	cout << "Agency Employee" << endl;
	outFile << "Agency Emplyee" << endl;
	cout << "Enter first name: ";
	cin >> first;
	cout << endl;
	cout << "Enter last: ";
	cin >> last;
	cout << endl;
	instance3.setName(first, last);

	cout << "Enter SSN: ";
	cin >> ssn;
	cout << endl;
	instance3.setSSN(ssn);

	cout << "Enter num to emp: ";
	cin >> num;


	cout << "Enter letter to emp: ";
	cin >> letter;
	cout << endl;
	instance3.setEmpNum(num, letter);

	cout << "Enter in hour rate: ";
	cin >> hourRate;

	instance3.setHourPay(hourRate);

	cout << "Hours worked: ";
	cin >> hoursWorked;
	cout << endl;
	instance3.setHoursWorked(hoursWorked);
	
	cout << "Company to pay: ";
	cin >> company;
	cout << endl;
	instance3.setCompanyToPay(company);
	
	instance3.printAgencyEmployee(outFile);

}