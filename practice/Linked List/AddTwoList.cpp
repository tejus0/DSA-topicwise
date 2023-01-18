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


Node* join(Node* first, Node* second){
    Node* r1=reverse(first);
    Node* r2=reverse(second);
    Node* final=new Node;
    int sum=0;
    int carry=0;
    int one=r1->key;
    int two=r2->key;
    r1=r1->next;
    r2=r2->next;
    sum=one+two;
    carry=(sum>=10)?1:0;
    sum=sum%10;
    final=newNode(sum);
    Node* head=final;
    Node* temp=new Node;
    while(r1 and r2){
        //cout<<r1->key<<" "<<r2->key;
        cout<<endl;
        one=r1->key;
        two=r2->key;
        sum=one+two;
        carry=(sum>=10)?1:0;
        sum=sum%10;
        temp=newNode(sum);
        final->next=temp; 
        final=temp;
        r1=r1->next;   
        r2=r2->next;    
    }
    if(r1){
        while(r1){
        one=r1->key;
        sum=one+carry;
        carry=(sum>=10)?1:0;
        sum=sum%10;
        temp=newNode(sum);
        final->next=temp;
        final=temp;
        r1=r1->next;
        }
        if(carry){
            temp=newNode(carry);
            final->next=temp;
        }
    }
    else{
        while(r2){
        one=r2->key;
        sum=one+carry;
        carry=(sum>=10)?1:0;
        sum=sum%10;
        temp=newNode(sum);
        final->next=temp;
        final=temp;
        r2=r2->next;
        }
        if(carry){
            temp=newNode(carry);
            final->next=temp;
        }
    }
    //printList(head);
    return reverse(head);
}

/* Driver program to test above function*/
int main()
{
	Node* head_f = newNode(5);
	head_f->next = newNode(2);
    head_f->next->next=newNode(1);
	Node* head_s=newNode(2);
    head_s->next=newNode(1);
    Node* ans=join(head_f,head_s);
   printList(ans);

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
