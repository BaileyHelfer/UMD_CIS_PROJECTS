#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;
#define NUM_STORES 2
#define NUM_DEPTS 2
#define NUM_MONTHS 12

string getMonthName(int month);
void printMonthlySales(int x, float arr[NUM_STORES][NUM_MONTHS][NUM_DEPTS]);

int main() {

	float storeMonthlySales[NUM_STORES][NUM_MONTHS][NUM_DEPTS] = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2,
																	2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2,
																	3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 4.1, 4.2,
																	2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2 };
	char start = 'y';
	
	int month = 0;
	

	while (start == 'y')
	{
		cout << "1.January" << endl;
		cout << "2.February" << endl;
		cout << "3.March" << endl;
		cout << "4.April" << endl;
		cout << "5.May" << endl;
		cout << "6.June" << endl;
		cout << "7.July" << endl;
		cout << "8.Auguest" << endl;
		cout << "9.September" << endl;
		cout << "10.October" << endl;
		cout << "11.November" << endl;
		cout << "12.December" << endl;
		cout << "Select the integer associated with the month you would like sales for:  " << endl;
		cin >> month;
		
		while (!(month > 0 && month <= 12))					//Loop checks for errors entered in by user
		{
			if (!(cin.fail())) {
				cout << "Error, Enter integer associated with the month. : " << endl;
				cin >> month;
			}
			while (cin.fail())
			{
				string x;
				cout << "Error, Enter integer associated with the month. : " << endl;
				cin.clear();
				cin >> x;
				cin >> month;
			}
		}
	
			printMonthlySales(month, storeMonthlySales);
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
string getMonthName(int month) {
	string daysName[12] = { "January", "February" , "March", "April", "May" , "June", "July", "August", "September", "October", "November", "December" };
	return daysName[month-1];
}

void printMonthlySales(int month, float storeMonthlySales[NUM_STORES][NUM_MONTHS][NUM_DEPTS]) {

	cout << "Sales for the month of " << getMonthName(month) << endl;
	cout << setw(18) << right << "";
	for (int i = 1; i <= NUM_DEPTS; i++)				
	{
		cout << setw(18) << right << "Dept " << i;				

	}
	cout << setw(18) << right << "Store Total" << endl;
	for (int i = 0; i < NUM_STORES; i++) 
	{
		float total = 0;
		cout << setw(18) << right << "Store#" <<  i + 1;
		for (int j = 0; j < NUM_DEPTS; j++)
		{
			total = total + storeMonthlySales[i][j][month];
			cout << setw(18) << right << storeMonthlySales[i][j][month];
		}
		cout << setw(18) << right << total << endl;
	}
	cout << setw(19) << right << "Dept Total";
	float overallTotal = 0;
	for (int j = 0; j < NUM_DEPTS; j++) {
		float total = 0;
		for (int i = 0; i < NUM_STORES; i++) {
			total += storeMonthlySales[i][j][month];
		}
		overallTotal += total;
		cout << setw(18) << right << total;
	}
	cout << setw(18) << right << overallTotal << endl;



}