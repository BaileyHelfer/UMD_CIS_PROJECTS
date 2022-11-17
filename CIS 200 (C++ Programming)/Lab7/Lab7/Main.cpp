#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;


struct sortdListNode {
    char letter;
    int occurences;
    struct sortdListNode* next;
};


struct sortdListNode* fromString(string str)
{
    int arr[40] = { };
    struct sortdListNode* head = NULL; 
    struct sortdListNode* temp = NULL;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
            arr[str[i] - 'a']++;
        if (str[i] >= 'A' && str[i] <= 'Z') 
            arr[str[i] - 'A']++;
        
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0) 
        {
            struct sortdListNode* node = (struct sortdListNode*)malloc(sizeof(struct sortdListNode));
            node->letter = 'A' + (i);
            node->occurences = arr[i];
            node->next = NULL;

            if (head == NULL)
            {
                head = node;

            }
            else
            {
                temp->next = node;
            }
            temp = node;
        }
    }
    return head;

}


void printList(sortdListNode* temp)
{
    if (temp == NULL)
    {
        cout << "Empty Word" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->letter << " " << temp->occurences << " ";
        temp = temp->next;
    }
    cout << endl;
}


sortdListNode* combineList(struct sortdListNode* list1, struct sortdListNode* list2)
{
    sortdListNode* list3 = NULL;
    sortdListNode*temp = NULL; 
    sortdListNode*pre = NULL;
    if (list1 == NULL) 
        return list2;
    if (list2 == NULL)
        return list1;
    list3 = list1;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->letter > list2->letter)
        {
            temp = list2->next;
            if (pre == NULL)
            {
                list2->next = list1;
                list3 = list2;
            }
            else
            {
                list2->next = list1;
                pre->next = list2;

            }
            pre = list2;
            list2 = temp;
        }
        else if (list1->letter < list2->letter)
        {
            pre = list1;
            list1 = list1->next;
        }
        else
        {
            pre = list1;
            list1->occurences = list1->occurences + list2->occurences;
            list1 = list1->next;
            list2 = list2->next;
        }

    }
    return list3;
}


int main()
{
    sortdListNode* list1 = NULL;
    sortdListNode* list2 = NULL;
    sortdListNode*list3;
    string word1;
    string word2;
    ofstream output;
    
    output.open("output.txt");
    output.clear();
    cout << "Enter first word: ";
    
    cin >> word1;
    output << "Word1: " << word1 << endl;
    cout << "Enter second word: ";
    
    cin >> word2;
    output << "Word2: " << word2 << endl;


    list1 = fromString(word1);
    cout << "word 1     ";
    printList(list1);
    output << "Word1: " << list1 << endl;
    list2 = fromString(word2);
    cout << "word 2     ";
    printList(list2);
    output << "Word2: " << list2 << endl;
    list3 = combineList(list1, list2);
    cout << "combined:     ";
    printList(list3);
    output << "Combined: " << list3 << endl;
    output.close();
    return 0;
}
