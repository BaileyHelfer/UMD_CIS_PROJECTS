#include <iostream>
#include <limits>
using namespace std;
#define LENGTH 5000;



/*DESCRIPTION
	Method populates the array with varible i at index i
*/
void arrayInt(int input[], int size) {
	for (int i = 0; i < size; i++)
	{
		input[i] = i;
	}
}
/*
	DESCRIPTION
	Method searches for the they key entered in by the user and searches for the index at which it is stored.
	Method will keep calling itself until target index is found
*/
int recursiveLinearSearch(int array[], int key, int size, bool& methodStatus, int starter)
{
	if (array[starter] == key)
	{
		methodStatus = true;
		return starter;
	}
	if (starter > size && starter != key)
	{
		methodStatus = false;
		return 0;
	}
	else
	{
		int returner = recursiveLinearSearch(array, key, size, methodStatus, starter + 1);
		return returner;
	}
}



int main() {

	const int size = LENGTH;
	int thatOneArray[size];

	arrayInt(thatOneArray, size);

	bool methodStatus = NULL;
	int key = NULL;
	int starter = 0;
	char sentinal = 'y';

	while (sentinal == 'y')
	{
		cout << "Enter the value you would like to search for: ";
		cin >> key;
		cout << endl;
		while (key< 0 )
		{
			cout << "Please enter an integer between 0 and " << size << ": ";
			cin >> key;
		}
		
		
		int index = recursiveLinearSearch(thatOneArray, key, size, methodStatus, starter);

		if (methodStatus == true)
		{
			cout << "The value was in position " << index << endl;
			cout << "The function was called " << index + 1 << " times" << endl;
		}
		else if (methodStatus == false)
		{
			cout << "The number does not exist in the array." << endl;
			cout << "The function was called " << index + 1 <<" times" << endl;
		}
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