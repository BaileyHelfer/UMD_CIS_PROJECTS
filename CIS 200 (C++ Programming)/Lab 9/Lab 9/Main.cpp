#include <iostream>
using namespace std;



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
		return topOfStack + 1;
	}
	void print() {
		for (int i = 0; i < length(); i++)
		{
			cout << arrayStack[i] << " " << endl;
		}
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


int main() {
	Stack <int> IntStack;
	int x;
	bool callStatus;
	if (IntStack.pop(x))
	{
		cout << "Deletes top element in stack which is " << x << endl;
	}
	else
	{
		cout << "Stack is empty so no element can be popped/removed." << endl;
	}
	IntStack.peek(callStatus);
	if (callStatus)
	{
		cout << "Peeks into stack and grabs the top element which is " << IntStack.peek(callStatus) << endl;
	}
	else
	{
		cout << "Since call status is false then that means our stack is empty." << endl;
	}
	if (IntStack.push(11))
	{
		cout << "11 is pushed into stack and is now on top" << endl;
	}
	else
	{
		cout << "Stack is full, cannot push onto stack" << endl;
	}
	if (IntStack.push(22))
	{
		cout << "22 is pushed into stack and is now on top" << endl;
	}
	else
	{
		cout << "Stack is full, cannot push onto stack" << endl;
	}

	cout << "int length 1 = " << IntStack.length() << endl;

	if (IntStack.isEmpty())
	{
		cout << "You stack is empty" << endl;
	}
	else
	{
		cout << "Your stack is not empty" << endl;
	}
	cout << "top element = " << IntStack.peek(callStatus) << endl;

	if (IntStack.pop(x))
	{
		cout << "Deletes top element in stack which is " << x << endl;
	}
	else
	{
		cout << "Stack is empty so no element can be popped/removed." << endl;
	}
	if (IntStack.push(33))
	{
		cout << "33 is pushed into stack and is now on top" << endl;
	}
	else
	{
		cout << "Stack is full, cannot push onto stack" << endl;
	}
	cout << "int length 2 = " << IntStack.length() << endl;
	cout << "The int stack contains : " << endl;
	IntStack.print();
	if (IntStack.push(44))
	{
		cout << "44 is pushed into stack and is now on top" << endl;
	}
	else
	{
		cout << "Stack is full, cannot push onto stack" << endl;
	}
	if (IntStack.push(55))
	{
		cout << "55 is pushed into stack and is now on top" << endl;
	}
	else
	{
		cout << "Stack is full, cannot push onto stack" << endl;
	}
	if (IntStack.push(66))
	{
		cout << "66 is pushed into stack and is now on top" << endl;
	}
	else
	{
		cout << "Stack is full, cannot push onto stack" << endl;
	}
	if (IntStack.isFull() == false)
		cout << "The int stack is not full !" << endl;
	else
		cout << "The int stack is full !" << endl;
	Stack <int> IntStack2(IntStack);
	cout << "The int stack2 contains : " << endl;
	IntStack2.print();
	IntStack2.MakeEmpty();
	cout << "The int stack2 contains : " << endl;
	IntStack2.print();
	//add my own test cases
	if (IntStack.isFull())
	{
		cout << "Your stack is full." << endl;

	}
	else
	{
		cout << "Your stack is not full." << endl;
	}

	Stack <float> FloatStack;
	float y;
	if (FloatStack.pop(y))
	{

	}
	else
	{

	}
	FloatStack.peek(callStatus);
	if (callStatus)
	{

	}
	else
	{

	}
	if (FloatStack.push(7.1))
	{

	}
	else
	{

	}
	cout << "float length 1 = " << FloatStack.length() << endl;
	if (FloatStack.push(2.3))
	{

	}

	else
	{

	}
	if (FloatStack.isEmpty())
	{

	}
	else
	{
		cout << "top element = " << FloatStack.peek(callStatus) << endl;
	}
	if (FloatStack.push(3.1))
	{

	}
	else
	{

	}

	cout << "float length 2 = " << FloatStack.length() << endl;
	FloatStack.pop(y);
	cout << "The float stack contains : " << endl;
	FloatStack.print(); 
	Stack <float> FloatStack2 = FloatStack;
	cout << "The float stack 2 contains:  " << endl;
	FloatStack2.print();
	FloatStack.MakeEmpty(); 
	cout << "The float stack 3 contains:  " << endl;
	FloatStack2.print();
	// add my own test cases

	return 0;
}
