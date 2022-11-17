#include <iostream>
#include <limits>
using namespace std;

/*
	DESCRIPTION
	Method status is set to false if a negative number is given
	if it is equal to 0 then 1 is given
	if these two arent true then the number the user entered will be multiplied by the number minus that number calculating the factorial 
*/
int factorial(int value, bool& methodStatus)
{
	if (value < 0)
	{
		methodStatus = false;
		return -1;
	}
	if (value == 0)
	{
		methodStatus = true;
		return 1;
	}
	int x = value * factorial(value - 1, methodStatus);
	return x;
}

int main() {
	int value = NULL;
	bool methodStatus = NULL;
	char sentinal = 'y';

	while (sentinal == 'y')
	{
		cout << "Enter the integer you would like to evaluate: ";
		cin >> value;
		int output = factorial(value, methodStatus);
		if (methodStatus == true)
			cout << "The factorial of " << value << " is " << output << endl;
		if (methodStatus == false)
			cout << "try again with a value that is greater than 0." << endl;
		
		cout << "Do you want to continue?('y'/'n'): ";
		cin.get(sentinal);
		cin.get(sentinal);
		while (!(sentinal == 'y' || sentinal == 'n')) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//only gets the last character they entered and then prompts them to enter in correct character.
			cout << "Error, enter 'y' or 'n' " << endl;
			cout << "Do you want to continue?('y'/'n'): ";
			cin.get(sentinal);
		}

	}


	return 0;
}

