#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* insert(int key,Node** head)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = *head;
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

Node* kReverse(Node** head, int k) {

  
}


int main()
{


    int n, x, k;
  cin >> n >> k;
  Node * head = NULL;

  for (int i = 0; i < n; i++) {
    cin >> x;
    insert( x, &head);
  }

    kReverse(&head,3);
   printList(head);

	return 0;
}