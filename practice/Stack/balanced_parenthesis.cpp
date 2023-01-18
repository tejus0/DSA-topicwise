#include<iostream>
#include <stack>
using namespace std;

bool isvalid(string s){   //we can also use char* in place of string when using below suggestion 
    stack<char>s1;
        for (int i=0;s[i]!='\0';i++){
        char ch=s[i];
        if (ch=='('){
            s1.push(ch);
        }
        else if (ch==')'){
         if(s1.top()!='(' or s1.empty()){
            return false;
        }
        s1.pop();
        }
    }
    return s1.empty();
}

int main(){
    string s="(a+(c+d))";   //we can also use char s[100] in place of string
    if(isvalid(s)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}