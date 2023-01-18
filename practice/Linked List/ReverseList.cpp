#include<iostream>
#include<map>
#include <list>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

void print();


struct Node
    {
        int data;
        Node* next; 
    };

Node* newNode(Node** head,int data){
        Node* temp= new Node;
        temp->data=data;
        temp->next=NULL;
        if(!*head)
            *head=temp;
        return temp;
    }

void insert_at_end(Node** head,int data){
  //  cout<<"here1"<<endl;
    Node* temp= new Node;
    temp=*head;
    if(!temp){
        Node* fresh=newNode(&*head,data);
        *head=fresh;
    }
    else{
    while( temp->next!=NULL){
       // cout<<"here"<<endl;
        temp=temp->next;
    }
    Node* fresh=newNode(&*head,data);
    temp->next=fresh;
   // cout<<"here"<<endl;
    }
}

Node* reverse(Node* head){
    Node* curr;
    Node* prev;
    Node*next;
    curr=head;
    prev=NULL;
    next=NULL;
    while(curr){
        cout<<"here";
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;

}

void print(Node* head){
   // cout<<"print";
    while(head){
        cout<<head->data<< " ";
        head=head->next;
    }
    
}

int main()
{
    int node;
    Node* head=NULL;
    insert_at_end(&head,4);
    insert_at_end(&head,5);
    insert_at_end(&head,6);
    insert_at_end(&head,2);
    reverse(head);
   print(head);
    return 0;
}