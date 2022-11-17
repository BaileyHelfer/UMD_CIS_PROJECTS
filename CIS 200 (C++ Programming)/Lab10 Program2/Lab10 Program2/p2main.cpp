#include <iostream>
#include <string>
#include "Class.h"
using namespace std;



void printBday(string month, int day, int year)
{
	cout << month << " " << day << ", " << year;
}

string convertMonth(int month)
{
	if (month == 1)
	{
		return "January";
	}
	else if (month == 2)
	{
		return "February";
	}
	else if (month == 3)
	{
		return "March";
	}
	else if (month == 4)
	{
		return "April";
	}
	else if (month == 5)
	{
		return "May";
	}
	else if (month == 6)
	{
		return "June";
	}
	else if (month == 7)
	{
		return "July";
	}
	else if (month == 8)
	{
		return "August";
	}
	else if (month == 9)
	{
		return "September";
	}
	else if (month == 10)
	{
		return "October";
	}
	else if (month == 11)
	{
		return "November";
	}
	else
	{
		return "December";
	}
}

int main()
{
	string bday;
	string day, month, year;
	cout << "Enter birthday in numeric form: ";
	cin >> bday;

	int num = bday.find("-");
	month = bday.substr(0, num);
	int num1 = bday.rfind("-");
	year = bday.substr(num1 + 1, bday.size() - 1);
	day = bday.substr(num + 1, num1 - 3);

	int intDay = stoi(day);
	int intMonth = stoi(month);
	int intYear = stoi(year);
	int check = bday.find('-');




	try {

		try
		{

			if (intDay < 0 || intDay > 31)
			{
				throw invalidDay();
			}
			if (intMonth < 1 || intMonth > 12)
			{
				throw invalidMonth();
			}
			if (check != 2 && check != 1)
			{
				throw runtime_error("Incorrect formating");
			}
			if (intYear > 2020 || intYear < 1915)
			{
				throw "year has to be between 1915 and 2020";

			}
		}
		catch (runtime_error ex)
		{
			cout << "Error: " << ex.what() << endl;
			cout << "Thrown to outer block" << endl;
			throw;

		}
		catch (invalidDay x)
		{
			cout << "Error : " << x.what() << endl;
			cout << "Thrown to outer block" << endl;
			throw;
		}
		catch (invalidMonth y)
		{
			cout << "Error : " << y.what() << endl;
			cout << "Thrown to outer block" << endl;
			throw;
		}
		catch (...)
		{
			cout << "Error: Invalid year" << endl;
			cout << "Thrown to outer block" << endl;
			throw;
		}
	}
	catch (runtime_error ex)
	{
		cout << "Enter with bday with proper formating: ";
		cin >> bday;
		num = bday.find("-");
		month = bday.substr(0, num);
		num1 = bday.rfind("-");
		year = bday.substr(num1 + 1, bday.size() - 1);
		day = bday.substr(num + 1, num1 - 3);

		intDay = stoi(day);
		intMonth = stoi(month);
		intYear = stoi(year);

	}
	catch (invalidDay x)
	{
		cout << "Enter valid day: ";
		cin >> intDay;
	}
	catch (invalidMonth y)
	{
		cout << "Enter valid month: ";
		cin >> intMonth;
	}
	catch (...)
	{
		cout << "Enter valid year: ";
		cin >> intYear;
	}


	printBday(convertMonth(intMonth), intDay, intYear);




	return 0;
}