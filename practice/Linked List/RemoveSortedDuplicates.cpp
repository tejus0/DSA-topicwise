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

Node *removeDuplicates(Node *head)
{
 // your code goes here
//  if(!head) return head;
 Node* temp =head->next;
 struct Node* prev=head;
 while(temp ){
     if(temp->key!=prev->key){
       //cout<<prev->key<<endl;
         prev->next=temp;
         prev=temp;
         //cout<<prev->key<<endl;
     }
     //cout<<prev->key<<" "<<temp->key<<endl;
     temp=temp->next;
 }
 prev->next=NULL;
 return head;
}

/* Node* removeDuplicates(Node* head){   
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->key==temp->next->key){
            temp->next=temp->next->next;
        }
        else temp=temp->next;
    }
    return head;
    }
 */
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

    removeDuplicates(head);
   printList(head);

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
