#include <iostream>
#include <limits>
using namespace std;
#define MAX_ROWS 3
#define MAX_COLUMNS 2


void printArray(int x, int arr[][MAX_COLUMNS]);
int howManyEven(int arrayIntValue[][MAX_COLUMNS]);

int main() {

	int even = 0;
	int arrayIntValue[MAX_ROWS][MAX_COLUMNS] = { {3,2}, {4,5},{2,2} };	
	even = howManyEven(arrayIntValue);
	printArray(even,arrayIntValue);

	char start = 'y';
	int num = 0;
	
	while (start == 'y')
	{
		for (int x = 0; x < MAX_ROWS; x++)
		{
			for (int y = 0; y < MAX_COLUMNS; y++)
			{
				cout << "Enter a Positive integer: " << endl;
				cin >> num;
				while (cin.fail() || num<=0) {							/*While loop checks for 0 and negative integer while also making sure the data type is an integer. If num passes these condistions then the number gets passed to the array.*/
					string x;
					cout << "Error, enter positive integer: " << endl;
					if (cin.fail()) {
						cin.clear();
						cin >> x;
					}
					cin >> num;
				}
				arrayIntValue[x][y] = num;
			
			}
		}
		even = howManyEven(arrayIntValue);
		printArray(even, arrayIntValue);
		
		cout << "Do you want to continue?('y'/'n'): ";
		cin.get(start);
		cin.get(start);
		while(!(start == 'y' || start == 'n')) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//only gets the last character they entered and then prompts them to enter in correct character.
			cout << "Error, enter 'y' or 'n' " << endl;
			cout << "Do you want to continue?('y'/'n'): ";
			cin.get(start);
		

		}
	}

	

	return 0;
}

void printArray(int x, int arr[][MAX_COLUMNS]) {

	cout << "  1   " << " 2" << endl;
	cout << " --------" << endl;
	int row = 1;
	
	for (int i = 0; i < MAX_ROWS; i++)
	{
		cout << row << "|";
		for (int j = 0; j < MAX_COLUMNS; j++)			//for loop prints out each value of the array.
		{
			cout << arr[i][j] << "    ";
		}
		row = row + 1;
		cout << endl;

	
	}
	cout << endl << "The number of even numbers are : " << x << endl;
}

int howManyEven(int arrayIntValue[][MAX_COLUMNS]) {
	int even = 0;
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLUMNS; j++)
		{
			if (arrayIntValue[i][j] % 2 == 0)		//Checks to see if the value in the array divided by 2 returns a 0 remainder.
				even = even + 1;
		}
	}

	return even;

}