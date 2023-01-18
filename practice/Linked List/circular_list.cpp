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
    while (temp->next!=head) //taking temp to last node
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<"->"<<endl; //printing last node
    return ;
}
//making circular linked list
void insertAtHead(Node* &head, int data){
     Node* n=new Node(data);  // making new node to insert
     Node* temp=head;
     n->next=head;
    if (temp!=NULL){
        while(temp->next!=head){   //for making last node point to new added node n
            temp=temp->next;
        }
        temp->next=n; //entering new node address to last node 
    }
    else{
        n->next=n; //if only 1 node , then linking with itself
    }
    head=n; //start of list
    /*Mistake of treating as normal list, 
    as i am not changing the address of last element to point to first
    n->next=head;   //linking n with head
    head=n;   //shifting head to n*/

}
//checking if the node to delete is present or not
Node* getNodeToDel(Node* head, int data){
    Node* temp=head;
    while(temp->next!=head){  //checking the list till second last node
        if (temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    if(temp->data==data){  //checking last node
        return temp;
    }
    return NULL; //if data to delete is not present
}
//deletion in circular linked list
void deleteNode(Node* &head, int data){
    Node* del=getNodeToDel(head, data);
    if(del==NULL){  
        return;
    }
    if (del==head){ 
        head=head->next;
    }
    Node* temp=head;
    while (temp->next!=del)
    {
        temp=temp->next;
    }
    temp->next=del->next;
    delete del;
}

int main(){
    Node* head=NULL;
    insertAtHead(head,0);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    print(head);
    deleteNode(head,0);
    print(head);
    deleteNode(head,5);
    print(head);
}