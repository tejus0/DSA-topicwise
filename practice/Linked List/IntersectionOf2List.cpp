// C++ program to return first node of loop.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* reverse(Node* head){
    Node* curr;
    Node* prev;
    Node*next;
    curr=head;
    prev=NULL;
    next=NULL;
    while(curr){
        //cout<<"here";
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;

}

Node* intersect(Node* first, Node* second){
    Node* final=new Node;
    while(first and second){             //for first
        if(first->data!=second->data){
            if(first->data>second->data){
                second=second->next;
            }
            else{
                first=first->next;
            }
        }
        else{
            Node* temp=newNode(first->data);
            final=temp;
            first=first->next;
            second=second->next;
            break;
        }
    }
    Node* head=final;
    while(first and second){             //for first
        if(first->data!=second->data){
            if(first->data>second->data){
                second=second->next;
            }
            else{
                first=first->next;
            }
        }
        else{
            Node* temp=newNode(first->data);
            final->next=temp;
            final=temp;
            first=first->next;
            second=second->next;
        }
    }
    return head;
}

/* Driver program to test above function*/
int main()
{
	Node* head_f = newNode(3);
	head_f->next = newNode(6);
    head_f->next->next=newNode(9);
	Node* head_s=newNode(2);
    head_s->next=newNode(6);
    Node* ans=intersect(head_f,head_s);
   printList(ans);

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
