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

void insert(int data,Node** head){
    Node* temp=*head;
    while(temp->next){
        temp=temp->next;
    }
    Node* fresh=newNode(data);
    temp->next=fresh;
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


Node* removeDuplicates(Node* head){   
    map<int,bool> m;
    Node* temp=head;
    while(temp){
        m[temp->key]=false;
        temp=temp->next;
    }
    temp=head->next;
    Node* prev=head;
    m[prev->key]=true;
    while(temp){
        if(m[temp->key]){
           // cout<<temp->key<<" ";
            prev->next=temp->next;
            
        }
        else{
           // cout<<"false";
            m[temp->key]=true;
            prev=temp;
        }
        temp=temp->next;
    }


    return head;
    }

/* Driver program to test above function*/
int main()
{
	Node* head = newNode(50);
    head->next = newNode(50);
    head->next->next = newNode(50);
    head->next->next->next = newNode(50);
    head->next->next->next->next = newNode(50);
    head->next->next->next->next->next = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = newNode(10);
    head->next->next->next->next->next->next = newNode(40);
    head->next->next->next->next->next->next->next = newNode(40);
    head->next->next->next->next->next->next->next->next = newNode(70);

    removeDuplicates(head);
   printList(head);

	return 0;
}

