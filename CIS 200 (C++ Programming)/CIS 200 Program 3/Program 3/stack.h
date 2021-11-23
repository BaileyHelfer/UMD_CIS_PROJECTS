#include <iostream>
#include <fstream>
#include <new>
using namespace std;

struct Node
{
	string tag;
	int count;
	Node* next;

};

class Stack
{
private:

	Node* top;


public:
	Stack() {
		top = NULL;
	}

	void add(string x) {
		Node* temp2 = top;
		while (temp2 != NULL)
		{
			if (x == temp2->tag)
			{
				temp2->count = temp2->count + 1;
				return;
			}
			else
			{
				temp2 = temp2->next;
			}
		}

		Node* temp;
		temp = new Node;
		temp->tag = x;
		temp->count = 1;
		temp->next = NULL;
		
		
		temp->next = top;
		top = temp;
		
	}
	string peek()
	{
		return top->tag;
	}

	void print(ofstream &output)
	{
		Node* temp = top;

		while (temp != NULL)
		{
			if (!(temp->tag == "BR" || temp->tag == "IMG" || temp->tag == "P"))
			{
				cout << "Match " << temp->tag << " Occurences " << top->count << endl;
				output << "Match " << temp->tag << " Occurences " << top->count << endl;

			}
			else
			{
				cout << "No Match " << temp->tag << " Occurences " << top->count << endl;
				output << "No Match " << temp->tag << " Occurences " << top->count << endl;
			}
			temp = temp->next;
		}
	}
	string minimum()
	{
		{
			Node* p = top;

			string minimum = p->tag;

			while (p->next != NULL)
			{
				p = p->next;
				if (minimum > p->tag)
				{
					minimum = p->tag;
				}
			}
			return minimum;

		}

	}

	void Pop()
	{
		top = top->next;
	}

	bool remove(string x)
	{
		Node* p = top;
		Node* n = NULL;

		if (p->tag == x) 
		{
			top = top->next;
			delete p;
			return true;
		}
		
		while (p != NULL && p->tag != x)
		{
			n = p;
			p = p->next;

			if (p == NULL)
			{
				return false;
			}
			else if (p->tag == x)
			{
				n->next = p->next;
				delete p;
				return true;
			}
		}
	}

	void sortList()
	{
		string mini;
		bool removed;


		Node* newnode1 = new Node;
		mini = minimum();
		newnode1->tag = mini;
		newnode1->next = NULL;
		removed = remove(mini);
		Node* p = newnode1;

		while (top != NULL)
		{
			Node* newnode = new Node;
			mini = minimum();
			newnode->tag = mini;

			newnode->next = NULL;
			p->next = newnode;
			removed = remove(mini);
			p = p->next;
		}
		top = newnode1;

	}

	
	
};

