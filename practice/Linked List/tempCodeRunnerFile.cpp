#include<iostream>
using namespace std;

class Node
{
private:
    /* data */
public:
    int data;
    Node*next;

Node(int d)
{
    data=d;
    next=NULL;
}
};

void print(Node* head){
    Node* temp=head;
    while (temp->next!=head)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    return ;
}

void insertAtHead(Node* &head, int data){
    Node* n=new Node(data);  // making new node to insert
    n->next=head;   //linking n with head
    head=n;   //shifting head to n
}

int main(){
    Node* head=NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    print(head);
}