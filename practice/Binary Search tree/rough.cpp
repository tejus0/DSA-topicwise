#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int isnthdigit(int a,int b, int d, int s, int e){
    int mid=(s+e)/2;
    static int cnt=0;

    int digits=floor(log(a)/log(b)+(mid*log(mid))/log(b))+1;
    if(d==digits and s<=e){
        cnt++;
        isnthdigit(a,b,d,mid+1,e);
        isnthdigit(a,b,d,s,mid-1);

    }
    else if (d==digits and s>e){
        return cnt;
    }
    else if (d<digits){
        isnthdigit(a,b,d,s,mid-1);
    }
    else{
        isnthdigit(a,b,d,mid+1,e);
    }
}

int main(){
    int a,n,b;
    cin>>a>>n>>b;
    int largest=10;
    cout<<isnthdigit(a,b,n,1,largest);
    return 0;
}