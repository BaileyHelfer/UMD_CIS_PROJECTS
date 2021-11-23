#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "myString.h"

using namespace std;

int main() {

	
	ofstream myStringLog;
	myStringLog.open("myStringLog.txt");
	myStringLog.clear();		//clears the log everytime the file is ran again

	myString instance1;
	int menuNumber = 0;
	string name;
	bool methodStatus = true;
	char sentinal = 'y';
	
	cout << "Hello, what is your name? " << endl;
	getline(cin,name);
	cout << "Welcome, " << name << ". Thank you" << endl;
	myStringLog << "program action - ask user for name." << endl << "user action - user enters " << name << endl << "program action - myString instance1 created." << endl;


	while (sentinal == 'y')
	{
		cout << "1." << "Assign value to string" << endl;							//Table output to user to select which action they like
		cout << "2." << "Add string to front of current string" << endl;			
		cout << "3." << "Add string to end of current string" << endl;
		cout << "4." << "Give part of the string" << endl;
		cout << "5." << "Replace part of the string" << endl;
		cout << "6." << "Replace whole string" << endl;
		cout << "7." << "Size of string" << endl;
		cout << "8." << "Print your string" << endl;
		cout << "9." << "Check if string is empty" << endl;
		cout << "10." << "Check if string is 25 characters" << endl;
		cout << "11." << "Input string to see if equal to current string" << endl;
		cout << "12." << "Get character at certian position" << endl;
		cout << "13." << "Set string to null" << endl;
		cout << "14." << "Get String" << endl;
		cout << "15." << "Quit Program" << endl;

		cout << "Enter integer associated with the action you would like to do: ";
		cin >> menuNumber;
		cout << endl;

		switch (menuNumber) {
		case 1:
		{
			string tempString;
			myStringLog << "program action - string 'tempString' created" << endl;
			cout << "Enter String: ";
			cin.ignore();
			getline (cin, tempString);
			instance1.setString(tempString, methodStatus);				
			if (methodStatus == false)
			{
				myStringLog << "user action - instance 1 is updated to " << tempString << endl;
				myStringLog << "program action - Error, string contains more than 25 characters" << endl;
			}
			else {
				myStringLog << "user action - instance1 value is set to " << instance1.getString() << endl;
			}
			break;
		}
		case 2:
		{
			
			myString addStart;
			myStringLog << "program action - myString addStart created" << endl;
			string temp1;
			cout << "Enter string you would like to add at front: ";
			cin.ignore();
			getline(cin,temp1);
			addStart.setString(temp1, methodStatus);
			if (methodStatus == false)
			{
				myStringLog << "user action - addStart is updated to " << temp1 << endl;
				myStringLog << "program action - Error, string contains more than 25 characters" << endl;
			}
			else {
				myStringLog << "user action - addStart updated to " << addStart.getString() << endl;
			}
			instance1.addStart(addStart, methodStatus);	
			if (methodStatus == true) {
				cout << "Your string is now: " << instance1.getString() << endl;
			}
			if (methodStatus == false)
			{
				myStringLog << "program action - Error, string is greater than 25" << endl;
			}
			else {
				myStringLog << "user action - instance1 updated to " << instance1.getString() << endl;
			}
			
			

			break;
		}
		case 3:
		{
			myString addEnd;
			myStringLog << "program action - myString addEnd created" << endl;
			string temp2;
			cout << "Enter string you would like to add at end: ";
			cin.ignore();
			getline(cin,temp2);
			addEnd.setString(temp2, methodStatus);
			if (methodStatus == false)
			{
				myStringLog << "user action - addEnd is updated to " << temp2 << endl;
				myStringLog << "program action - Error, string contains more than 25 characters" << endl;
			}
			else {
				myStringLog << "user action - addEnd updated to " << addEnd.getString() << endl;
			}
			instance1.addEnd(addEnd, methodStatus);
			if (methodStatus == true)
			cout << "Your string is now: " << instance1.getString() << endl;
			myStringLog << "user action - instance1 updated to " << instance1.getString() << endl;

			break;
		}
		case 4:
		{
			myString temp3;
			myStringLog << "programa action - myString  temp3 created" << endl;
			int startPos, length;
			cout << "Enter position you would like to start at: ";
			cin >> startPos;
			myStringLog << "user action - start position is updated to " << startPos << endl;
			cout << endl;
			cout << "How many characters do you want: ";
			cin >> length;
			myStringLog << "user action - length position is updated to " << length << endl;
			cout << endl;
			instance1.partString(startPos, length, methodStatus);
			temp3 = instance1.partString(startPos, length, methodStatus);
			cout << "The part of the string at starting position " << startPos << " and " << length << " length is: " << temp3.getString() << endl;
			if (methodStatus == false)
			{
				myStringLog << "programa action - Error, could not complete operation" << endl;
			}
			else
			{
				myStringLog << "programa action - temp3 string is  " << temp3.getString() << endl;
			}

			break;
		}
		case 5:

		{
			int startPos;
			myString temp4;
			myStringLog << "programa action - myString  temp4 created" << endl;
			string replacePtStr;
			cout << "Enter position you would like to start at: ";
			cin >> startPos;
			myStringLog << "user action - start position is updated to " << startPos << endl;
			cout << endl;
			cout << "Enter the string you would like to replace current with: ";
			cin.ignore();
			getline(cin, replacePtStr);
			temp4.setString(replacePtStr, methodStatus);
			if (methodStatus == false)
			{
				myStringLog << "user action - temp4 is updated to " << replacePtStr << endl;
				myStringLog << "program action - Error, string contains more than 25 characters" << endl;
			}
			else {
				myStringLog << "program action - temp4 string updated to " << temp4.getString() << endl;
			}
			instance1.replPartString(temp4, startPos, methodStatus);
			if (methodStatus == true)
			cout << "Your string is now: " << instance1.getString() << endl;
			myStringLog << "user action - instance1 value is set to partstring " << instance1.getString() << endl;
			break;
		}
		case 6:

		{
			myString temp5;
			myStringLog << "program action - myString temp5 created" << endl;
			string temp;
			cout << "Enter string you would like to replace current with: ";
			cin.ignore();
			getline(cin, temp);
			myStringLog << "user action- string temp is set to " << temp << endl;
			cout << endl;
			temp5.setString(temp, methodStatus);
			if (methodStatus == false)
			{
				myStringLog << "user action - temp5 is updated to " << temp << endl;
				myStringLog << "program action - Error, string contains more than 25 characters" << endl;
			}
			else {
				myStringLog << "program action - temp 5 string is set to  " << temp << endl;
			}
			instance1.replWholeString(temp5, methodStatus);
			if (methodStatus == true)
				cout << "Your string is now: " << instance1.getString() << endl;
			myStringLog << "program action - instance1 string value is updated to " << instance1.getString() << endl;
			cout << "String replaced with: " << instance1.getString() << endl;
			

			break;
		}
		case 7:
		{
			cout << "The size of the string is: " << instance1.size() << endl;
			myStringLog << "progrm action - size of the string is set to " << instance1.size() << endl;

			break;
		}
		case 8:
		{
			instance1.printString();
			myStringLog << "program action - string is printed to console" << endl;
			break;
		}
		case 9:
		{
			cout << "String is empty = " << boolalpha <<instance1.emptyString();
			myStringLog << "program action - String is empty is " << instance1.emptyString() << endl;
			break;
		}
		case 10:
		{
			cout << "String is 25 characters = " << boolalpha <<instance1.fullString() << endl;
			myStringLog << "program action - String is full is "  << boolalpha << instance1.fullString() << endl;
			break;
		}
		case 11:
		{
			myString temp6;
			myStringLog << "program action - myString temp6 is created" << endl;
			string compare;
			cout << "Enter string to compare: ";
			cin.ignore();
			getline(cin, compare);
			myStringLog << "program action - string compare is created" << endl << "user action - string compare is assigned to " << compare << endl;
			temp6.setString(compare, methodStatus);
			if (methodStatus == false)
			{
				myStringLog << "user action - temp6 is updated to " << compare << endl;
				myStringLog << "program action - Error, string contains more than 25 characters" << endl;
			}
			myStringLog << "program action - myString temp6 is updated to " << compare << endl;
			cout << "Strings are equal: " << boolalpha << instance1.compareString(temp6) << endl;
			myStringLog << "program action - strings are equal is  " << boolalpha << instance1.compareString(temp6) << endl;
			
			break;
		}
		case 12:
		{
			int pos;
			cout << "Enter position of character you'd like: ";
			cin >> pos;
			myStringLog << "user action - int position is set to " << pos << endl;
			cout << endl;
			instance1.charAt(pos, methodStatus);
			if(methodStatus == true)
			cout << "The character at position " << pos << " is: " << instance1.charAt(pos, methodStatus) << endl;
			myStringLog << "program action - the character at the assigned position is " << instance1.charAt(pos, methodStatus) << endl;

			
			break;
		}
		case 13:
		{
			instance1.initString();
			myStringLog << "program action - stirng is set to null" << endl;

			break;
		}
		case 14:
		{
			cout << "String is " << instance1.getString() << endl;
			myStringLog << "program action - string is retured to main" << endl;

			break;
		}
		case 15:
		{
			sentinal = 'n';
			myStringLog << "user action - user quits program" << endl;

			break;
		}
		default:
		{
			sentinal = 'n';
		}

		}
	}
	myStringLog.close();




	return 0;
}