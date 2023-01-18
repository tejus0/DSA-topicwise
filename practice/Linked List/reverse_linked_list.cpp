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
//Linked List class(object oriented programming)
/*class linkedlist{
    Node*head;
    Node*tail;
    public:
    linkedlist(){ //Constructor

    }
    void insert(int d){

    }
}
*/

//Functions (Procedural Programming)
void build(){

}
//head is passed by reference as we need to update head after insertion .
void insertAtHead(Node*&head,int d){
    if (head==NULL){
        head=new Node(d);
        return;
    }
    Node *n= new Node(d);
    n->next=head;
    head=n;
}

int length(Node*head){
    int cnt=0;
    while(head!=NULL){
        head=head->next;
        cnt++;
    }
    return cnt;
}

void insertAtTail(Node*&head, int data){
    if (head==NULL){
        head=new Node (data);
        return;
    }
    Node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=new Node(data);

}

void insertAtMiddle(Node*&head, int data, int p){
    if(head==NULL || p==0){
        insertAtHead(head, data);
    }
    else if (p>=length(head)){
        insertAtTail(head, data);
    }
    else{
        int jump=1;
        Node*temp=head;
        while(jump<=p-1){
            temp=temp->next;
            jump++;
        }
        Node*n=new Node(data);
        n->next=temp->next;
        temp->next=n;

        }

    }


//if we pass head by reference then linked list is printed only once. as after printing, the head becomes NULL .
void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

void deleteHead(Node*&head){
    if (head==NULL){ //when list is empty
        return;
    }
    Node*temp=head->next; //storing the location of next element of list
    delete head; //remove head from heap
    head=temp; //shifting head to next element
}

void deleteAtMiddle(Node*head, int pos){
    int jump=1;
    Node*prev=head;
    while(jump<=pos-1){
        prev=prev->next;
        jump++;
    }
    Node*temp=prev->next;
    prev->next=temp->next;
    delete temp;

    }

void deleteTail(Node*&head){
    int end=length(head);
    Node*tail=head;
    int jump=1;
     while(jump!=end-1){
            tail=tail->next;
            jump++;
        }
        Node*del=tail->next;
        tail->next=NULL;
        delete del;
}
//Linear Search as finding middle ele will take O(N) for binary search
bool search(Node*head, int key){
    while (head!=NULL) //when the list is finished
    {
        /* code */if (head->data==key){
            return true;
        }
        head=head->next;
    }
    return false; //when head reaches end of the list
}

//recursively
bool searchrec(Node*head, int key){
    if (head==NULL){
        return false;
    }
    else if (head->data==key){
        return true;
    }
    else{
        return searchrec(head->next,key);
    }
}

Node* takeinput(){
    int d;
    cin>>d;
    Node*head=NULL;
    while(d!=-1){  //we can also take input from a file even that is not having -1 at end , by while(cin>>d)  
        insertAtHead(head,d);
        cin>>d;  
    }
    return head;
}
//operator overloading
ostream& operator<<(ostream &os, Node* head){
    print(head);
    return os;
}

istream& operator>>(istream &is, Node* &head){
    head=takeinput();
    return is;
}
//function call 
void reverse(Node*&head){ //head is passed by refernce as it needs to be updated when we call reverse
    Node*curr=head;
    Node*prev=NULL;
    Node*later;
    while(curr!=NULL){
        later=curr->next;
        curr->next=prev;
        prev=curr;
        curr=later;
    }
    head=prev; //for pointing head to starting of linked list
}
//recursively reverse list
Node* reverseRec(Node* &head){
    if (head==NULL || head->next==NULL){ //when list is empty or last element is reached
        return head;
    }
    Node* newhead=reverseRec(head->next); //traversing through list
    head->next->next=head; //reversing list
    head->next=NULL; //for last element to be NULL for ending
    return newhead;
}

int main(){
   /* Node*head=takeinput();   without operator overloading
    Node*head1=takeinput();
    */
   Node*head;   
   cin>>head;
   cout<<head;
   Node* new_list=reverseRec(head);
   cout<<new_list;
    /*
    insertAtHead(head,5);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    print(head);
    insertAtMiddle(head, 4,3);
    insertAtTail(head,7);
    print(head);
    deleteHead(head);
    print(head);
    deleteTail(head);
    print(head);
    deleteAtMiddle(head,2);
    print(head);
    int key;cin>>key;
    if (searchrec(head,key)){
        cout<<"Found";
    }
    else
    cout<<"not found";
    */

}