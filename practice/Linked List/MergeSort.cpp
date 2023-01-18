

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

Node *removeDuplicates(Node *head)
{
 // your code goes here
//  if(!head) return head;
 Node* temp =head->next;
 struct Node* prev=head;
 while(temp ){
     if(temp->data!=prev->data){
       //cout<<prev->data<<endl;
         prev->next=temp;
         prev=temp;
         //cout<<prev->data<<endl;
     }
     //cout<<prev->data<<" "<<temp->data<<endl;
     temp=temp->next;
 }
 prev->next=NULL;
 return head;
}

Node* mid_find(Node* head){
      Node* slow=head;
      Node* fast=head->next;
      while(fast and fast->next){
          slow=slow->next;
          fast=fast->next->next;
      }
      return slow;
  }
  
  Node* merge(Node* left, Node* right){
      if(!left){
          return right;
      }
      if(!right){
          return left;
      }
      Node* temp=newNode(-1);
      Node* ans=temp;
      while(left and right){
          if(left->data > right->data){
              temp->next=right;
              temp=right;
              right=right->next;
          }
          else{
              temp->next=left;
              temp=left;
              left=left->next;
          }
      }
      while(left){
          temp->next=left;
          temp=left;
          left=left->next;
      }
      while(right){
          temp->next=right;
          temp=right;
          right=right->next;
      }
      ans=ans->next;  // for -1 skip
      return ans;
  }

    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head or !head->next){
          return head;
      }
      Node* mid=mid_find(head);
      //cout<<mid->data<<" ";
      Node* left=head;
      Node* right=mid->next;
      mid->next=NULL;
        Node* first=mergeSort(left);
        Node* second=mergeSort(right);
        Node* ans=merge(first,second);
        return ans;
        
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

    Node* start=removeDuplicates(head);
    //printList(start);
    Node* final=mergeSort(start);
   printList(final);

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
