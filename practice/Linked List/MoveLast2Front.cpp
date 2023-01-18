// C++ program to return first node of loop.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

Node* lastToFront(Node** head){
    Node* temp=*head;
    temp=temp->next;
    Node* prev=*head;
    while(temp->next->next){
        temp=temp->next;
        prev=prev->next;
    }
    temp=temp->next;
    prev=prev->next;
    prev->next=NULL;
    temp->next=*head;
    *head=temp;
    return *head;
}

/* Driver program to test above function*/
int main()
{
	Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = newNode(10);
    head->next->next->next->next->next->next = newNode(40);
    head->next->next->next->next->next->next->next = newNode(40);
    lastToFront(&head);

   printList(head);

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
