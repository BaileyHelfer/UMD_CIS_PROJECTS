#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


struct clientData {
	int accountNumber;
	char lastName[15];
	char firstName[10];
	float balance;
};

int main() {

	ofstream outCredit("credit.dat", ios::out);
	clientData blankClient = { 0, "", "", 0.0 };
	clientData client;

	for (int i = 0; i < 100; i++)
	{
		outCredit.write(reinterpret_cast<const char*>(&blankClient), sizeof(clientData));
	}
	outCredit.close();
	ofstream outCredit1("credit.dat", ios::ate);
	cout << "Enter account number in range of 1-100(Press 0 to quit) : ";
	cin >> client.accountNumber;

	while (client.accountNumber != 0)
	{
		if (client.accountNumber < 1 || client.accountNumber > 100)
		{
			cout << "Invalid account number. " << endl;
		}
		else
		{
			cout << "Enter in first name: ";
			cin >> client.firstName;
			cout << endl;
			cout << "Enter in last name: ";
			cin >> client.lastName;
			cout << endl;
			cout << "Enter in balance: ";
			cin >> client.balance;
			cout << endl;

			outCredit1.seekp((client.accountNumber - 1) * sizeof(clientData));
			outCredit1.write(reinterpret_cast<char*> (&client), sizeof(clientData));

		}
		cout << "Enter account number in range of 1-100(Press 0 to quit): ";
		cin >> client .accountNumber;
		cout << endl;
	}
	outCredit1.close();
	cout << "Enter account numbers to display: " << endl;
	ifstream incredit("credit.dat", ios::in);
	cout << "Enter account number in range 1-100(Press 0 to quit): ";
	cin >> client.accountNumber;
	cout << fixed << setprecision(2);

	while (client.accountNumber != 0)
	{
		if (client.accountNumber < 1 || client.accountNumber > 100)
		{
			cout << "Invalid account number. " << endl;
		}
		else
		{
			incredit.seekg((client.accountNumber - 1) * sizeof(clientData));
			incredit.read(reinterpret_cast<char*>(&client), sizeof(clientData));

			cout << "Account number: " << client.accountNumber << endl;
			cout << "First name: " << client.firstName<< endl;
			cout << "Last name: " << client.lastName << endl;
			cout << "Account Balance:  $" << client.balance<< endl;


		}
		cout << "Enter account number in range 1-100(Press 0 to quit): ";
		cin >> client.accountNumber;
		cout << endl;
	}
	incredit.clear();
	incredit.seekg(0);

	incredit.read(reinterpret_cast<char*> (&client), sizeof(clientData));

	cout << left << setw(15) << "Account Number" << setw(20) << "First name" << setw(20) << "Last name" << setw(10) << "Balance" << endl;

	while (incredit && !incredit.eof())
	{
		if (client.accountNumber != 0)
		{
			cout << left << setw(15) << client.accountNumber << setw(20) << client.firstName << setw(20) << client.lastName << setw(10) << client.balance << endl;
		}
		incredit.read(reinterpret_cast<char*> (&client), sizeof(clientData));
	}

	incredit.close();
	return 0;
}