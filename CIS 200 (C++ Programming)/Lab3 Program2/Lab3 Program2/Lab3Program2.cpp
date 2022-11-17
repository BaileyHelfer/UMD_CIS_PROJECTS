#include <iostream>
#include <fstream>
#include <assert.h>
#include <limits>
#include <string>
using namespace std;

const int size = 20;



void readIntFile(ifstream &x, int* intArray, int size, int &length);
void printValues(int* intArray, int length);

int main (){
	ifstream inputStream;
	const int size = ::size;
	int length = 0;
	int intArray[size];
	char start = 'y';

	while (start == 'y')
	{
		bool isEmpty = 0;
		string fileName;
		cout << "Enter the name of your file: ";
		cin >> fileName;
		inputStream.open(fileName);
		
		if (inputStream.bad() || inputStream.fail())
		{
			cout << "Error, bad file name." << endl;
			continue;
		}
		else
		{
			if (inputStream.peek() == ifstream::traits_type::eof()) {

				cout << "File is empty." << endl;
				isEmpty = 1;
			}
		}
	
		if (inputStream.good() || isEmpty == 0)
		{
			readIntFile(inputStream, intArray, size, length);

			printValues(intArray, length);
			inputStream.close();
		}
		inputStream.close();
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



void readIntFile(ifstream &x, int* intArray, int size, int& length) {

	int count = 0;
	int tempArray[::size];

	while (!(x.eof()))
	{
		if (count >= 20)
		{
			cout << "The file has more than 20 values." << endl;
			break;
		}
		else
		{
			int y;
			x >> y;
			tempArray[count++] = y;
		}
	}
		length = count;
		for (int i = 0; i < length; i++)
		{
			intArray[i] = tempArray[i];
		}
	


}
void printValues(int* intArray, int length) {

	assert(length > 0);
	cout << "Here are the first " << length << " values:" << endl;
	for (int i = 0; i < 20; i++) {
		cout << intArray[i] << ", ";
	}
	cout << endl;
}
