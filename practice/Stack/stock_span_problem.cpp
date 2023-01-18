#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int* price , int n, int* span){
    stack<int>  st;
    st.push(0);
    span[0]=1;
    for (int i=1;i<n;i++){
        int currentPrice=price[i];
        while(!st.empty() and price[st.top()]<=currentPrice){
            st.pop();
        }
        if (!st.empty()){
        span[i]=i-st.top();
        }
        else{
            span[i]=i+1;
        }
        st.push(i);
    }
}

int main(){
    int price[]={100,80,60,70,60,75,85};
    int n=sizeof(price)/sizeof(int);
    int span[n]={0};
    stockSpan(price,n,span);
    for (int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }

}