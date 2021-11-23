#include <iostream>
#include <string>
#include <vector>

using namespace std;

class myString {
private:
	string stringData;
	vector<char> charString;
	void vectConverter(){
		stringData.clear();
		for (int i = 0; i < charString.size(); i++)
		{
			stringData += charString[i];
		}
	}
public:
	myString() {
		stringData = "";
	}
	/*
		DESCIPRTION
		Method takes input string from user and stores this string into myClass data type charString.
		If string is greater than 25 characters than error message is outputed and status is set to false.
		If string is less than and 25 and not equal to 0 than string at index i will be stored in vector char at index i

	*/
	void setString(string tempString, bool &methodStatus) {
		if (tempString.length() > 25)
		{
			methodStatus = false;
			cout << "Error, string size is greater than 25." << endl;
		}
		if (tempString.length() <= 25) {
			stringData = tempString;
			
			charString.resize(tempString.length());
			for (int i = 0; i < tempString.length(); i++)
			{
				charString[i] = tempString.at(i);
			}
			

			methodStatus = true;
		}
		
	}
	
	/*
		DESCIPRTION
		Method has for loop that runs to the size of the vector size where the chracters are stored.
		Loop sets stringData at index i equal to vector char at index and then returns the string "stringData"

	*/
	string getString() {
		vectConverter();
		return stringData;
	}
	
	/*
		DESCIPRTION
		Returns the size of the vector storing the characters
		
	*/
	int size()
	{
		return charString.size();
	}
	
	/*
		DESCIPRTION
		Method runs as long as the size of the initial string and size of new string are less than or equal to 25
		char insert will insert x.char insert at the begining of charString
		if these conditions are not met than method status will be set to false

	*/
	void addStart(myString x, bool &methodStatus)
	{
		
		if (x.size() + size() <= 25)
		{
			charString.insert(charString.begin(), x.charString.begin(), x.charString.end());
			methodStatus = true;
		}
		else {
			cout << "Error, string is greater than 25." << endl;
			methodStatus = false;
		}
	}
	
	/*
		DESCIPRTION
		Method runs as long as the size of the current string and the size of the new string are less than or equal to 25
		charString.insert used the first paramter to indciated at which position we want to insert and we indictaed the end
		next two indicated that we want from the start of x.charString all the way to the end to be inserted.

		If the previous condition is not met than method status gets set to false and error messgae is printed.

	*/
	void addEnd(myString x, bool &methodStatus)
	{
		if (x.size() + size() <= 25)
		{
			charString.insert(charString.end(), x.charString.begin(), x.charString.end());
			methodStatus = true;
		}
		else {
			cout << "Error, string is greater than 25." << endl;
			methodStatus = false;
		}
	}
	
	/*
		DESCIPRTION
		 If the starting position is a negative number or greater than the size of the vector than code will generate an error message.
		 if the position is the size of the vector than it will return null.
		 If those two conditions are't met than the myClass x vector will store the instance 1 vector starting at int pos and do so for int length.
		 Finally will return the myClass variable x and all its attributes.

	*/
	myString partString(int startPos, int length, bool &methodStatus)
	{
		myString x;
		if (startPos < 0 || startPos > charString.size()) {

			cout << "Error, could not complete operation." << endl;
			methodStatus = false;

		}
		else if(startPos == charString.size())
		{
			x.charString.clear();
		}
		else {
			x.charString.resize(charString.size());

			for (int i = startPos; startPos < length + i; startPos++)
			{
				x.charString.at(startPos) = charString.at(startPos);
				methodStatus = true;
			}
			x.vectConverter();
			
			return x;
		}
	}
	
	/*
		DESCIPRTION
		If the starting position is a negative number or greater than the size of the vector than code will generate an error message.
		First we erase from the position indicated by startPos and rease up until the end.
		then we go from the start and go up to  int pos and start inserting x.charString from start to end.

	*/
	void replPartString(myString x, int startPos, bool & methodStatus)
	{
		if (startPos < 0 || startPos > charString.size() || startPos == charString.size()) {

			cout << "Error, could not complete operation." << endl;
			methodStatus = false;
		}
		if (25 - startPos < x.size())
		{
			cout << "Error, could not complete operation." << endl;
			methodStatus = false;
		}
		else {
			charString.erase(charString.begin() + startPos, charString.end());
			charString.insert(charString.begin() + startPos, x.charString.begin(), x.charString.end());
			getString();
			methodStatus = true;
		}
	}
	
	/*
		DESCIPRTION
		If the size of the new string is greater than 25 then error message is prtined and methodStatus is set to false.

		Else than we erase the old string and replace it with the new string using the insert command.

	*/
	void replWholeString(myString x, bool methodStatus)
	{
		
		if (x.size() > 25)
		{
			cout << "Error, could not complete operation." << endl;
			methodStatus = false;
		}
		else
		{
			charString.erase(charString.begin(), charString.end());
			charString.insert(charString.begin(), x.charString.begin(), x.charString.end());
			methodStatus = true;
		}

	}
	
	/*
		DESCIPRTION
		if the size of the string is equal to the integer value 0 than return the value true.
		If this is not true than return false.

	*/
	bool emptyString()
	{
		if (charString.size() == 0)
			return true;
		else
			return false;
		
	}
	
	/*
		DESCIPRTION
		If the size of the string is equal to 25 characters than return value true.
		If not than return false.

	*/
	bool fullString()
	{
		if (charString.size() == 25)
			return true;
		else
			return false;
		
	}
	
	/*
		DESCIPRTION
		If the string entered is equal to the current string then return true.
		If not then return false.

	*/
	bool compareString(myString x)
	{
		if (x.charString == charString)
			return true;

		else
			return false;
	}
	
	/*
		DESCIPRTION
		If the position they entered is a negative number or the position is greater than the size of the string then print error message.
		Else, set methodStatus to true and return charString at index [pos].

	*/
	char charAt(int pos, bool &methodStatus)
	{
		if (pos < 0 || pos > charString.size())
		{
			cout << "Error, operation could not be done." << endl;
			methodStatus = false;
		}
		else {
			methodStatus = true;
			return charString[pos];
		}
	}
	
	/*
		DESCIPRTION
		clear the data in the vector as well as the string

	*/
	void initString()
	{
		stringData.clear();
		charString.clear();
	}
	
	/*
		DESCIPRTION
		print each value of the vector by itterating through the index until you reach the size of the vector.

	*/
	void printString()
	{
		for (int i = 0; i < charString.size(); i++)
		{
			cout << charString[i];
		}
		cout << endl;
	}
};
