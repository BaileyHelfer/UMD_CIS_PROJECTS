#include <iostream>
#include <assert.h>
using namespace std;




double squareRoot(double x);
void assertThis(double x);

int main() {

	double userInput = 0;
	char start = 'y';
	while (start == 'y')
	{
		cout << "Enter number to find the root: ";
		cin >> userInput;
		assertThis(userInput);
		cout << "The square root of " << userInput << " is: " << squareRoot(userInput) << endl;

		cout << "Do you want to continue?('y'/'n'): ";
		cin.get(start);
		cin.get(start);
		while (!(start == 'y' || start == 'n')) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//only gets the last character they entered and then prompts them to enter in correct character.
			cout << "Error, enter 'y' or 'n' " << endl;
			cout << "Do you want to continue?('y'/'n'): ";
			cin.get(start);


		}

	}

	return 0;
}


double squareRoot(double x) {
	double xSubN = (x/2);
	double xNPlusOne = (xSubN + (x / xSubN)) / 2;
	while (xSubN - xNPlusOne > .0001)
	{
		xSubN = xNPlusOne;
		xNPlusOne = (xSubN + (x / xSubN)) / 2;
	}

		return xNPlusOne;
}

void assertThis(double x) {

	assert(x > 0 && "Error, invalid data");
}