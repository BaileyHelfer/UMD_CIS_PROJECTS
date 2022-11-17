#include<iostream>
#include <fstream>
using namespace std;

template <class ItemType>
struct NodeType
{
	ItemType info;
	NodeType* next;
};

template<class ItemType>
class Queue
{
private:
	NodeType<ItemType>* front;
	NodeType<ItemType>* rear;
	

public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	Queue(const Queue<ItemType>& x)
	{
		NodeType<ItemType>* temp;
		NodeType<ItemType>* t = x.front;
		while (t != NULL)
		{
			temp = new NodeType<ItemType>();
			temp->info = t->info;
			temp->next = t->next;
			if (front == NULL)
			{
				front = temp;
				rear = temp;
			}
			else
			{
				rear->next = temp;
				rear = temp;
			}
			t = t->next;
		}
	}
	void makeEmpty()
	{
		front = NULL;
		rear = NULL;
	}
	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (length() == 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int length()
	{
		NodeType<ItemType>* t = front;
		int len = 0;
		while (t != NULL)
		{
			len++;
			t = t->next;
		}
		
		return len;
	}
	void print(ofstream& output)
	{
		for (NodeType<ItemType>* t = front; t != NULL; t = t->next)
		{
			cout << t->info << ", ";
			output << t->info << ", ";
		}
		cout << endl;
		output << endl;
	}
	bool Enqueue(ItemType x)
	{
		NodeType<ItemType>* temp;
		temp = new NodeType<ItemType>();
		temp->info = x;
		temp->next = NULL;
	
		if (front == NULL)
		{
			front = temp;
			rear = temp;
			return true;

		}
		else if (length() < 5)
		{
			rear->next = temp;
			rear = temp;
			return true;

		}
		else
			return false;
	}
	bool Dequeue(ItemType& x)
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{

			x = front->info;
			front = front->next;
			return true;

		}

	}
	ItemType FrontPeek(bool& status)
	{
		if (isEmpty())
		{
			status = false;

		}
		else
		{
			status = true;
			return front->info;
		}
	}
	~Queue()
	{
		delete front, rear;
		front = NULL;
		rear = NULL;
	}
};
template <class ItemType>
class Stack
{
private:
	ItemType arrayStack[5];
	int topOfStack;
public:
	Stack() {
		topOfStack = -1;

	}

	Stack(const Stack<ItemType>& x) {
		for (int i = 0; i <= x.topOfStack; i++)
		{
			arrayStack[i] = x.arrayStack[i];
		}
		topOfStack = x.topOfStack;
	}

	void MakeEmpty() {
		topOfStack = -1;
	}
	bool isEmpty() {
		if (topOfStack == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull() {
		if (length() == 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int length() {
		int len = topOfStack + 1;
		return len;
	}
	void print(ofstream& file) {
		for (int i = 0; i < length(); i++)
		{
			cout << arrayStack[i] << ", ";
			file << arrayStack[i] << ", ";
		}
		cout << endl;
		file << endl;
	}

	bool push(ItemType x)
	{
		if (isFull())
		{
			return false;
		}
		else
		{
			arrayStack[topOfStack + 1] = x;
			topOfStack++;
			return true;
		}
	}

	bool pop(ItemType& x) {
		if (isEmpty())
		{
			return false;
		}
		else
		{
			x = arrayStack[topOfStack];
			topOfStack--;
			return true;
		}
	}


	ItemType peek(bool& status)
	{
		if (isEmpty())
		{
			status = false;

		}
		else
		{
			status = true;
			return arrayStack[topOfStack];
		}

	}

	~Stack()
	{

	}
};

int main()
{
	Stack<int> stackInt;
	Stack<float> stackFloat;
	Stack<char> stackChar;

	Queue<int> queueInt;
	Queue<float> queueFloat;
	Queue<char> queueChar;


	ifstream input;
	ofstream output;
	output.open("output.txt");
	output.clear();
	string file;

	cout << "Please enter a file you would like to open: " << endl;
	cin >> file;
	input.open(file); //Only accept correct file names

	char read;
	int inputInt;
	float inputFloat;
	char inputChar;
	bool callStatus;

	input.get(read);

	if (read == 'I')
	{
		cout << "Integer ";
		output << "Integer ";

		input.get(read);
		input.get(read);
		if (read == 'S')
		{
			cout << "Stack" << endl;
			output << "Stack" << endl;

			while (!input.eof())
			{
				if (read == 'R')
				{
					if (stackInt.pop(inputInt))
					{
						cout << "An element was removed from stack and it was " << inputInt << endl;
						output << "An element was removed from stack and it was " << inputInt << endl;
					}
					else
					{
						cout << "Nothing was popped." << endl;
						output << "Nothing was popped." << endl;
					}
				}
				if (read == 'P')
				{
					stackInt.print(output);
					
				}
				if (read == 'L')
				{
					cout << "Length of stack is: " << stackInt.length() << endl;
					output << "Length of stack is: " << stackInt.length() << endl;

				}
				if (read == 'T')
				{
					stackInt.peek(callStatus);
					if (callStatus == true)
					{
						cout << "Top element of stack is: " << stackInt.peek(callStatus) << endl;
						output << "Top element of stack is: " << stackInt.peek(callStatus) << endl;
					}
					else
					{
						cout << "Stack is empty. No value returned" << endl;
						output << "Stack is empty. No value returned" << endl;
					}
				}
				if (read == 'A')
				{
					input >> inputInt;
					if (stackInt.push(inputInt))
					{
						cout << inputInt << " is pushed into the stack" << endl;
						output << inputInt << " is pushed into the stack" << endl;
					}
					else
					{
						cout << "Stack is full and can not push into" << endl;
						output << "Stack is full and can not push into" << endl;
					}
				}
				input.get(read);
			}

		}
		else if (read == 'Q')
		{
			cout << "Queue" << endl;
			output << "Queue" << endl;

			while (!input.eof())
			{
				if (read == 'R')
				{
					if (queueInt.Dequeue(inputInt))
					{
						cout << inputInt << " was removed from queue" << endl;
						output <<inputInt << " was removed from queue" << endl;
					}
					else
					{
						cout << "Queue is empty and nothing can be removed" << endl;
						output << "Queue is empty and nothing can be removed" << endl;
					}
				}
				if (read == 'P')
				{
					queueInt.print(output);
				}
				if (read == 'L')
				{
					cout << "Length of queue is: " << queueInt.length() << endl;
					output << "Length of queue is: " << queueInt.length() << endl;
				}
				if (read == 'T')
				{
					queueInt.FrontPeek(callStatus);
					if (callStatus)
					{
						cout << queueInt.FrontPeek(callStatus) << " is in front of queue" << endl;
						output << queueInt.FrontPeek(callStatus) << " is in front of queue" << endl;
					}
					else
					{
						cout << "Queue is empty!" << endl;
						output << "Queue is empty!" << endl;
					}
				}
				if (read == 'A')
				{
					input >> inputInt;
					if (queueInt.Enqueue(inputInt))
					{
						cout << inputInt << " added to queue" << endl;
						output << inputInt << " added to queue" << endl;
					}
					else
					{
						cout << "Queue is full and can not add " << inputInt << endl;
						output << "Queue is full and can not add " << inputInt << endl;
						
					}
				}
				input.get(read);
			}
		}
	}
	if (read == 'R')
	{
		cout << "Real Number ";
		output << "Real Number ";

		input.get(read);
		input.get(read);
		if (read == 'S')
		{
			cout << "Stack" << endl;
			output << "Stack" << endl;

			while (!input.eof())
			{
				if (read == 'R')
				{
					if (stackFloat.pop(inputFloat))
					{
						cout << "An element was removed from stack and it was " << inputFloat << endl;
						output << "An element was removed from stack and it was " << inputFloat << endl;
					}
					else
					{
						cout << "Nothing was popped." << endl;
						output << "Nothing was popped." << endl;
					}
				}
				if (read == 'P')
				{
					stackFloat.print(output);

				}
				if (read == 'L')
				{
					cout << "Length of stack is: " << stackFloat.length() << endl;
					output << "Length of stack is: " << stackFloat.length() << endl;

				}
				if (read == 'T')
				{
					stackFloat.peek(callStatus);
					if (callStatus == true)
					{
						cout << "Top element of stack is: " << stackFloat.peek(callStatus) << endl;
						output << "Top element of stack is: " << stackFloat.peek(callStatus) << endl;
					}
					else
					{
						cout << "Stack is empty. No value returned" << endl;
						output << "Stack is empty. No value returned" << endl;
					}
				}
				if (read == 'A')
				{
					input >> inputFloat;
					if (stackFloat.push(inputFloat))
					{
						cout << inputFloat << " is pushed into the stack" << endl;
						output << inputFloat << " is pushed into the stack" << endl;
					}
					else
					{
						cout << "Stack is full and can not push " << inputFloat << " into stack" << endl;
						output << "Stack is full and can not push " << inputFloat << " into stack" << endl;
					}
				}


				input.get(read);
			}
		}
		else if (read == 'Q')
		{
			cout << "Queue" << endl;
			output << "Queue" << endl;

			while (!input.eof())
			{
				if (read == 'R')
				{
					if (queueFloat.Dequeue(inputFloat))
					{
						cout << inputFloat << " was removed from queue" << endl;
						output << inputFloat << " was removed from queue" << endl;
					}
					else
					{
						cout << "Queue is empty and nothing can be removed" << endl;
						output << "Queue is empty and nothing can be removed" << endl;
					}
				}
				if (read == 'P')
				{
					queueFloat.print(output);
				}
				if (read == 'L')
				{
					cout << "Length of queue is: " << queueFloat.length() << endl;
					output << "Length of queue is: " << queueFloat.length() << endl;
				}
				if (read == 'T')
				{
					queueFloat.FrontPeek(callStatus);
					if (callStatus)
					{
						cout << queueFloat.FrontPeek(callStatus) << " is in front of queue" << endl;
						output << queueFloat.FrontPeek(callStatus) << " is in front of queue" << endl;
					}
					else
					{
						cout << "Queue is empty!" << endl;
						output << "Queue is empty!" << endl;
					}
				}
				if (read == 'A')
				{
					input >> inputFloat;
					if (queueFloat.Enqueue(inputFloat))
					{
						cout << inputFloat << " added to queue" << endl;
						output << inputFloat << " added to queue" << endl;
					}
					else
					{
						cout << "Queue is full and can not add " << inputFloat << endl;
						output << "Queue is full and can not add "<< inputFloat << endl;
					}
				}
				input.get(read);
			}
		}
	}
		if (read == 'C')
		{
			cout << "Character";
			output << "Character ";

			input.get(read);
			input.get(read);
			if (read == 'S')
			{
				cout << "Stack" << endl;
				output << "Stack" << endl;

				while (!input.eof())
				{
					if (read == 'R')
					{
						if (stackChar.pop(inputChar))
						{
							cout << "One was removed from stack and it was " << inputChar << endl;
							output << "One was removed from stack and it was " << inputChar << endl;
						}
						else
						{
							cout << "Nothing was popped." << endl;
							output << "Nothing was popped." << endl;
						}
					}
					if (read == 'P')
					{
						stackChar.print(output);

					}
					if (read == 'L')
					{
						cout << "Length of stack is: " << stackChar.length() << endl;
						output << "Length of stack is: " << stackChar.length() << endl;

					}
					if (read == 'T')
					{
						stackChar.peek(callStatus);
						if (callStatus == true)
						{
							cout << "Top element of stack is: " << stackChar.peek(callStatus) << endl;
							output << "Top element of stack is: " << stackChar.peek(callStatus) << endl;
						}
						else
						{
							cout << "Stack is empty. No value returned" << endl;
							output << "Stack is empty. No value returned" << endl;
						}
					}
					if (read == 'A')
					{
						input >> inputChar;
						
						if (stackChar.push(inputChar))
						{
							cout << inputChar << " is pushed into the stack" << endl;
							output << inputChar << " is pushed into the stack" << endl;
						}
						else
						{
							cout << "Stack is full and can not push " << inputChar << " into stack" << endl;
							output << "Stack is full and can not push " << inputChar << " into stack" << endl;
						}
					}


					input.get(read);
				}
			}
			else if (read == 'Q')
			{
				cout << "Queue" << endl;
				output << "Queue" << endl;

				while (!input.eof())
				{
					if (read == 'R')
					{
						if (queueChar.Dequeue(inputChar))
						{
							cout << inputChar << " was removed from queue" << endl;
							output << inputChar << " was removed from queue" << endl;
						}
						else
						{
							cout << "Queue is empty and nothing can be removed" << endl;
							output << "Queue is empty and nothing can be removed" << endl;
						}
					}
					if (read == 'P')
					{
						queueChar.print(output);
					}
					if (read == 'L')
					{
						cout << "Length of queue is: " << queueChar.length() << endl;
						output << "Length of queue is: " << queueChar.length() << endl;
					}
					if (read == 'T')
					{
						queueChar.FrontPeek(callStatus);
						if (callStatus)
						{
							cout << queueChar.FrontPeek(callStatus) << " is in front of queue" << endl;
							output << queueChar.FrontPeek(callStatus) << " is in front of queue" << endl;
						}
						else
						{
							cout << "Queue is empty!" << endl;
							output << "Queue is empty!" << endl;
						}
					}
					if (read == 'A')
					{
						input >> inputChar;
						
						if (queueChar.Enqueue(inputChar))
						{
							cout << inputChar << " added to queue" << endl;
							output << inputChar << " added to queue" << endl;
						}
						else
						{
							cout << "Queue is full and can not add "<< inputChar << endl;
							output << "Queue is full and can not add " << inputChar << endl;
						}
					}
					input.get(read);
				}
			}

		}








		output.close();
		return 0;
	}