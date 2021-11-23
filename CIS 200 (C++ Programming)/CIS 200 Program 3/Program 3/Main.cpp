#include<iostream>
#include <fstream>
#include <string>
#include "stack.h"
using namespace std;


int main()
{

	ifstream input;
	ofstream output;
	string line;


	Stack noMatch;
	Stack allTags;
	Stack tags;
	string file;
	cout << "Enter file name: " << endl;
	cin >> file;
	input.open(file);

	while (input.bad() || input.fail()|| input.peek() == ifstream::traits_type::eof())
	{
		cout << "Bad file name or empty file, enter new file: " << endl;
		cin >> file;
		input.open(file);
	}

	output.open("output.txt");
	while (!(input.eof()))
	{
		getline(input, line);

		cout << line << endl;
		output << line << endl;
	}
	input.close();
	input.open(file);
	while (!(input.eof()))
	{
		int open,close,BR,ropen,rclose = 0;
		
		getline(input, line);
		
		
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == '<')
			{
				if (line[i+1] != '/')
				{
					string open;
					int start = line.find('<');
					int end = line.find('>');

					for (int i = start + 1; i < end; i++)
					{
						open.push_back(line[i]);
					}
					
					if (open[0] == 'I')
					{
						open = "IMG";
					}

					line[start] = ' ';
					line[end] = ' ';
					allTags.add(open);
					
					if (!(open == "BR"||open =="IMG" || open == "P"))
					{
						tags.add(open);
					}
					
				}
				else
				{
					string close;
					int start = line.rfind('<');
					int end = line.rfind('>');

					for (int i = start + 2; i < end; i++)
					{
						close.push_back(line[i]);
					}
					if (close == tags.peek())
					{
						tags.Pop();
					}
					else
					{
						cout << "Error, could not find opening tag for " << close << endl;
					}
					line[start] = ' ';
					line[end - 1] = ' ';
					
					
				}
			}
		}

		

		
		



		

		
	}
	input.close();
	cout << endl;
	cout << endl;
	cout << endl;
	output << endl;
	output << endl;
	allTags.print(output);
	
	cout << endl;
	cout << endl;
	cout << endl;
	output << endl;
	output << endl;
	allTags.sortList();
	allTags.print(output);
	output.close();
}