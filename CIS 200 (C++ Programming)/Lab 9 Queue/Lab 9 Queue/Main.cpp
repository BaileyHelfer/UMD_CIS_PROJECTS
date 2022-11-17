#include <iostream>

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
	void print()
	{
		for (NodeType<ItemType>* t = front; t != rear; t = t->next)
		{
			cout << t->info << " "<<endl;
		}
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
			return front.info;
		}
	}
	~Queue()
	{
		delete front, rear;
		front = NULL;
		rear = NULL;
	}
};


int main()
{
	Queue<int> IntQueue;
	int x;
	IntQueue.makeEmpty();
	if (IntQueue.Dequeue(x))
	{
		cout << "Deletes last element in queue which is " << x << endl;
	}
	else
	{
		cout << "Nothing removed, queue is empty" << endl;
	}
	if (IntQueue.Enqueue(10))
	{
		cout << "10 is added to the back of the queue" << endl;
	}
	else
	{
		cout << "queue is full, can not add to queue" << endl;
	}
	if (IntQueue.Enqueue(20))
	{
		cout << "20 is added to the back of the queue" << endl;
	}
	else
	{
		cout << "queue is full, can not add to queue" << endl;
	}
	if (IntQueue.Enqueue(30))
	{
		cout << "30 is added to the back of the queue" << endl;
	}
	else
	{
		cout << "queue is full, can not add to queue" << endl;
	}
	if (IntQueue.Enqueue(40))
	{
		cout << "40 is added to the back of the queue" << endl;
	}
	else
	{
		cout << "queue is full, can not add to queue" << endl;
	}

	cout << "int length 3 = " << IntQueue.length() << endl;
	if (IntQueue.Dequeue(x))
	{
		cout << "Deletes last element in queue which is " << x << endl;
	}
	else
	{
		cout << "Nothing removed, queue is empty" << endl;
	}
	cout << "int length 4 = " << IntQueue.length() << endl;
	cout << "The int queue contains : " << endl;
	IntQueue.print();
	if (IntQueue.isFull() == false)
	{
		cout << "The int queue is not full" << endl;
	}
	else
	{
		cout << "The int queue is full" << endl;
	}




	Queue<float> FloatQueue;
	float y;
	FloatQueue.makeEmpty();
	if (FloatQueue.Dequeue(y))
	{
		cout << "Deletes last element in queue which is " << y << endl;
	}
	else
	{
		cout << "Nothing removed, queue is empty" << endl;
	}
	if (FloatQueue.Enqueue(7.1))
	{
		cout << "7.1 is added to the back of the queue" << endl;
	}
	else
	{
		cout << "queue is full, can not add to queue" << endl;
	}
		cout << "float length 3 = " << FloatQueue.length() << endl;
	if (FloatQueue.Dequeue(y))
	{
		cout << "Deletes last element in queue which is " << y << endl;
	}
	else
	{
		cout << "Nothing removed, queue is empty" << endl;
	}
		cout << "float length 3 = " << FloatQueue.length() << endl;
	if (FloatQueue.Enqueue(2.3))
	{
		cout << "2.3 is added to the back of the queue" << endl;
	}
	else
	{
		cout << "queue is full, can not add to queue" << endl;
	}
	if (FloatQueue.Enqueue(2.3))
	{
		cout << "2.3 is added to the back of the queue" << endl;
	}
	else
	{
		cout << "queue is full, can not add to queue" << endl;
	}
		cout << "float length 4 = " << FloatQueue.length() << endl;
	if (FloatQueue.Enqueue(3.1))
	{
		cout << "3.1 is added to the back of the queue" << endl;
	}
	else
	{
		cout << "queue is full, can not add to queue" << endl;
	}
	if (FloatQueue.Dequeue(y))
	{
		cout << "Deletes last element in queue which is " << y << endl;
	}
	else
	{
		cout << "Nothing removed, queue is empty" << endl;
	}

	cout << "The float queue contains : " << endl;
	FloatQueue.print();
	Queue<float> FloatQueue2 = FloatQueue;
	cout << "The float queue 2 contains:  " << endl;
	FloatQueue2.print();
	FloatQueue.makeEmpty();
	cout << "The float queue 3 contains:  " << endl;
	FloatQueue2.print();
	

	return 0;
}
