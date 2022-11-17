#include <iostream>
#include <string>

using namespace std;

class invalidDay {
private:

	string message;
public:
	invalidDay()
	{
		message = "Invalid Day";
	}
	invalidDay(int day)
	{
		message = day;
	}
	string what()
	{
		return message;
	}
};

class invalidMonth {
private:

	string message;
public:
	invalidMonth()
	{
		message = "Invalid Month";
	}
	invalidMonth(int month)
	{
		message = month;
	}
	string what()
	{
		return message;
	}
};
