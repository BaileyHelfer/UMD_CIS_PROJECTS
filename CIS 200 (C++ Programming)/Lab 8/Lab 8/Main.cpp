#include <iostream>
#include <fstream>

using namespace std;


template <class T>


struct randomNode
{
	T randomNumber;
	int occurances;
	randomNode* next;
};
template <class T>

struct AcesndingOrderedNode {
	T orderedNumber;
	AcesndingOrderedNode* next;
};
template <class T>
class tenForward {
private:

	randomNode* headRandom;
	randomNode* tailRandom;

	AcesndingOrderedNode* headSorted;
	AcesndingOrderedNode* tailSorted;

	int numNodes = 0;

public:
	tenForawrd() {
		headRandom = nullptr;	
		tailRandom = nullptr;

		headSorted = nullptr;
		tailSorted = nullptr;

		numNodes = 0;
	}
	bool inList(T randomNum) //update occurances if randomNum is found in linked list. Update occurance in sorted and unsorted.
	{
		if (numNodes = 0)
		{
			return false;
		}
		else {
			randomNode* helper;
			helper = headSorted;
	
			while (helper != nullptr && helper->randomNumber != randomNum)
			{
				
			}

			return true;
		}
	}
	void addNode(T randomNum) {
		
		if (inList(randomNum)) 
		{
			
		}
		else {

			randomNode* temp = new node;
			temp->randomNumber = randomNum;
			temp->occurances = 1;
			temp->next = nullptr;
			
			if (numNodes = 0)
			{
				headRandom = temp;
				tailRandom = temp;

				headSorted = temp;
				tailSorted = temp;
				numNodes += 1;
			}
			else 
			{
				tailRandom.next = temp;
				tailRandom = temp;

				if (temp->randomNum < headSorted->randomNumber)
				{
					temp -> next = headSorted;
					headSorted = temp;
				}
				else
				{
					randomNode* current = headSorted;
					randomNode* previous = nullptr;

					while (current != nullptr && current->randomNum < temp->randomNum)
					{
						previous = current;
						current = current->next;
					}
					temp->next = current;
					previous->next = temp;

					previous = nullptr;
					current = nullptr;
					numNodes += 1;
				}
			}
			temp = nullptr;
		}
	}



};
template <class T>



int main() {

	ofstream output("output.txt");
	int num = rand() % 10 + 1;




	return 0;
}