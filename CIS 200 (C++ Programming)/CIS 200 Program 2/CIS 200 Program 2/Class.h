#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
		CLASS EMPLOYEE
		contains attributes of name, SSN and employee number
*/
class Employee
{
private:
	string firstName, lastName, SSN, empNum;
	char empLetter;

public:
	Employee()
	{
		firstName, lastName, SSN, empNum = " ";
		empLetter = ' ';
	}
	/*
		DESCRIPTION
		assigns the values of first and last name
	*/
	void setName(string first, string last)
	{
		firstName = first;
		lastName = last;
	}
	/*
		DESCRIPTION
		returns employee name
	*/
	string getName()
	{
		return firstName + " " + lastName;
	}
	/*
		DESCRIPTION
		assigns the employees SSN and checks for correct length and integers
	*/
	void setSSN(string ssn)
	{
		char check;					

		for (int i = 0; i < ssn.length(); i++)				//runs until length of string is reached
			{
				check = ssn.at(i);
				if (int(check) > 57 || int(check) < 47)			//if character is anything besdies digit 0-9 then i = length and exits for loop
				{
					i = ssn.length();
				}
			
			}
		
		while (ssn.size() != 9 || int(check) > 57|| int(check) < 48)		//Continues to check if string is length 9 and if it contains any chars that are not 0-9
		{
			int i = 0;
			for (i; i < ssn.length(); i++)
			{
				check = ssn.at(i);
				if (int(check) > 57 || int(check) < 48)		//Prompts user to enter new string if string contains anything besides 0-9
				{
					i = ssn.length();
					cout << "Incorrect SSN, must equal length 9. Enter again: ";
					cin >> ssn;
					cout << endl;
				}
				else if (ssn.length() != 9)					//Prompts user to enter new string if length of string does not equal 9
				{
					cout << "Incorrect SSN, must equal length 9. Enter again: ";
					cin >> ssn;
					cout << endl;
				}	
			}		
		}
		SSN = ssn;
	}
	/*
		DESCRIPTION
		returns the users last 4 digits of SSN while masking rest
	*/
	string getSSN()
	{
		string firstDigit, secondDigit, thirdDigit, fourthDigit;
		firstDigit = SSN.at(5);
		secondDigit = SSN.at(6);
		thirdDigit = SSN.at(7);
		fourthDigit = SSN.at(8);

		return "xxx-xx-" + firstDigit + secondDigit + thirdDigit + fourthDigit;
	}
	/*
		DESCRIPTION
		Assigns the employee's number along with the last letter in their number as well
		While the number is not 3 or contains characters it will keep asking user for input
		While the letter is not between A-M will keep asking user to enter character
	*/
	void setEmpNum(string num, char letter)
	{
		char checkNum;

		for (int i = 0; i < num.length(); i++)
		{
			checkNum = num.at(i);
			if (int(checkNum) > 57 || int(checkNum) < 48)
			{
				i = num.length();
			}
		}
		while (num.length() != 3 || int(checkNum) > 57 || int(checkNum) < 48 || letter > 77 || letter < 65)
		{
			int i = 0;
			for (i; i < num.length(); i++)
			{
				checkNum = num.at(i);
				if (int(checkNum) > 57 || int(checkNum) < 48)		//Prompts user to enter new string if string contains anything besides 0-9
				{
					i = num.length();
					cout << "Incorrect employee number, Enter in number accosiated with employee number: ";
					cin >> num;
					cout << endl;
				}
				else if (num.length() != 3)					//Prompts user to enter new string if length of string does not equal 3
				{
					cout << "Incorrect employee number, Enter in number accosiated with employee number: ";
					cin >> num;
					cout << endl;
				}
				
			}
			if (int(letter) > 77 || int(letter) < 65)
			{
				cout << "Incorrect employee letter, letter must be A-M. Enter again: ";
				cin >> letter;
				cout << endl;
			}

		}

		empNum = num;
		empLetter = letter;
	}
	/*
		DESCRIPTION
		returns the employee's number plus their letter
	*/
	string getEmpNum()
	{
		return empNum + "-" + empLetter;
	}
};

/*


		CLASS SALARYEMPLOYEE
		Contains attributes associated with Salary employee such as 
		AnnualPay, Week pay and tax code

*/

class SalaryEmployeePay : public Employee
{
private:
	float annualPay, weekPay;
	int taxCode;

public:
	SalaryEmployeePay()
	{
		annualPay, weekPay = NULL;
		taxCode = 0;
	}
	/*
		DESCRIPTION
		Assigns employees annual pay as long as number is not negative
	*/
	void setAnnualPay(float pay)
	{
		while (pay < 0)
		{
			cout << "Salary can not be negative. Enter a positive salary in: ";
			cin >> pay;
			cout << endl;
		}

		annualPay = pay;
	}

	/*
		DESCRIPTION
		Return annual salary
	*/
	float getAnnualPay()
	{
		return annualPay;
	}

	/*
		DESCRIPTION
		Assign weekly pay by dividing annualPay by 52 (weeks)
	*/
	void setWeekPay(float annualPay)
	{
		weekPay = annualPay / 52;
	}

	/*
		DESCRIPTION
		Return weekly pay
	*/
	float getWeekPay()
	{
		return weekPay;
	}

	/*
		DESCRIPTION
		Assign tax rate by taking the integer given by user and assign it accordingly
		While tax code sint 1-3 then ask user to keep inputing
	*/
	void setTaxCode(int code)
	{
		while (code < 1 || code > 3)
		{
			cout << "Not valid tax code, please enter code from 1-3: ";
			cin >> code;
			cout << endl;
		}
		if (code == 1)
		{
			taxCode = 25;
		}
		else if (code == 2)
		{
			taxCode = 20;
		}
		else if (code == 3)
		{
			taxCode = 15;
		}
	}

	/*
		DESCRIPTION
		Return tax code
	*/
	int getTaxCode()
	{
		return taxCode;
	}

	/*
		DESCRIPTION
		Prints out all of Salary Employee details
	*/
	void printSalaryEmployee(ofstream& outFile)
	{
		cout << "Salary Employees name is " << getName() << endl;
		outFile << "Salary Employees name is " << getName() << endl;

		cout << "SSN: " << getSSN() << "       " << "Employee Number: " << getEmpNum() << endl;
		outFile << "SSN: " << getSSN() << "       " << "Employee Number: " << getEmpNum() << endl;

		cout << "Annual Pay: $" << getAnnualPay() << "     " << "Weekly Pay: $" << getWeekPay() << endl;
		outFile << "Annual Pay: $" << getAnnualPay() << "     " << "Weekly Pay: $" << getWeekPay() << endl;

		cout << "Tax Percentage: " << getTaxCode() << "%" << endl;
		outFile << "Tax Percentage: " << getTaxCode() << "%" << endl;


		

	}

};

class HourlyEmployee : public Employee
{
private:
	float hourPay, hoursWorked;


public:
	HourlyEmployee()
	{
		hourPay = NULL;
		hoursWorked = NULL;
	}

	void setHourPay(float pay)
	{
		while (pay > 75 || pay < 10)
		{
			cout << "Invalid input, enter rate between $10.00 and $75.00: ";
			cin >> pay;
			cout << endl;
		}
		hourPay = pay;
	}

	float getHourPay()
	{
		return hourPay;
	}

	void setHoursWorked(float hours)
	{
		while (hours > 60)
		{
			cout << "Hours can not be greater than 60, enter hours worked again: ";
			cin >> hours;
			cout << endl;
		}
		hoursWorked = hours;
	}

	float getHoursWorked()
	{
		return hoursWorked;
	}
};

class HourlyEmployeePay : public HourlyEmployee 
{
private:
	float otPay;
	int taxCode;
	char workStatus;

public:
	HourlyEmployeePay()
	{
		otPay = NULL;
		taxCode = NULL;
		workStatus = ' ';
	}

	void setOtPay(float hourRate)
	{
	
		otPay = 1.5 * getHourPay();
		
		
	}

	float getOtPay()
	{
		return otPay;
	}

	void setTaxCode(int code)
	{
		while (code < 1 || code > 3)
		{
			cout << "Not valid tax code, please enter code from 1-3: ";
			cin >> code;
			cout << endl;
		}
		if (code == 1)
		{
			taxCode = 25;
		}
		else if (code == 2)
		{
			taxCode = 20;
		}
		else if (code == 3)
		{
			taxCode = 15;
		}
	}

	int getTaxCode()
	{
		return taxCode;
	}

	void setWorkStatus(char status)
	{
		if (status == 'F' || status == 'P')
		{
			
			workStatus = status;
		}
		else
		{
			while (status != 'F' && status != 'P')
			{
				cout << "Incorrect status, Enter F for full time or P for part time: ";
				cin >> status;
				cout << endl;
			}
		}
		

	}

	char getWorkStatus()
	{
		return workStatus;
	}

	void printHourlyEmployee(ofstream &outFile)
	{
		cout << "Hourly Employees name is " << getName() << endl;
		outFile << "Hourly Employees name is " << getName() << endl;

		cout << "SSN: " << getSSN() << "    " << "Employee Number: " << getEmpNum() << endl;
		outFile << "SSN: " << getSSN() << "    " << "Employee Number: " << getEmpNum() << endl;

		cout << "Pay Rate: $" << getHourPay() << "       " << "Hours worked: "<< getHoursWorked() << endl;
		outFile << "Pay Rate: $" << getHourPay() << "       " << "Hours worked: " << getHoursWorked() << endl;

		cout << "OT Pay Rate: $" << getOtPay() << "   " << "Tax Percentage: " << getTaxCode() << "%" << endl;
		outFile << "OT Pay Rate: $" << getOtPay() << "   " << "Tax Percentage: " << getTaxCode() << "%" << endl;
			
		
		if (getWorkStatus() == 'F')
		{
			cout << "Work Status: "<< "Full Time" << endl;
			outFile << "Work Status: " << "Full Time" << endl;
		}
		else
		{
			cout << "Work Status: " << "Part Time" << endl;
			outFile << "Work Status: " << "Part Time" << endl;
		}

	}
};


class AgencyEmployeePay : public HourlyEmployee
{
private:
	string companyToPay;

public:
	AgencyEmployeePay()
	{
		companyToPay = " ";
	}

	void setCompanyToPay(string company)
	{
		companyToPay = company;
	}
	string getCompanyToPay()
	{
		return companyToPay;
	}

	void printAgencyEmployee(ofstream& outFile)
	{
		cout << "Agency Employees name is " << getName() << endl;
		outFile << "Agency Employees name is " << getName() << endl;

		cout << "SSN: " << getSSN() << "    " << "Employee Number: " << getEmpNum() << endl;
		outFile << "SSN: " << getSSN() << "    " << "Employee Number: " << getEmpNum() << endl;

		cout << "Pay Rate: $" << getHourPay() << "       " << "Hours worked: " << getHoursWorked() << endl;
		outFile << "Pay Rate: $" << getHourPay() << "       " << "Hours worked: " << getHoursWorked() << endl;

	
		cout << "Company to pay: " << getCompanyToPay();
		outFile << "Company to pay: " << getCompanyToPay();

		

	}
};

