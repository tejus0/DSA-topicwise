#include<iostream>
#include<stack>  
using namespace std;

void transfer(stack<int>&s1,stack<int>&s2,int n){   
    for (int i=0;i<n;i++){
        s2.push(s1.top());
        s1.pop();
    }
}
//using 1 stack 
void reverseStack(stack<int> &s1){
    stack<int>s2;
    int n=s1.size();
    for (int i=0;i<n;i++){
        int x=s1.top();
        s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(x);
        transfer(s2,s1,n-i-1);
    }
}

    void insertAtBottom(stack<int>&s1, int x){
        if (s1.empty()){  //base case for inserting last element
            s1.push(x);
            return ;
        }
        int data=s1.top();  //saving previous element
        s1.pop();
        insertAtBottom(s1,x);  
        s1.push(data);  //inserting data after last element
    }

//recursion 
void rec_reverseStack(stack<int>&s1){
    if(s1.empty()){
        return;
    }
    int data=s1.top();
    s1.pop();
    rec_reverseStack(s1);
    insertAtBottom(s1,data);
}    



int main(){
    stack<int>s;
    int n;
    cin>>n;
    for (int i=0; i<n;i++){
        int ele;
        cin>>ele;
        s.push(ele);
    }
    rec_reverseStack(s);
        while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}