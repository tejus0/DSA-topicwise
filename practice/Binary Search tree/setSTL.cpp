#include<iostream>
#include<set>
using namespace std;
int main(){
    int arr[]={10,20,11,9,8,11,10};
    int n=sizeof(arr)/sizeof(int);
    set<int> s;
    for (int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    //print values
    for (set<int> :: iterator it=s.begin();it!=s.end();it++){
        cout<<*(it)<<",";
    } 
    cout<<endl;
    //deleting values
    s.erase(10); // Method 1
    for (set<int> :: iterator it=s.begin();it!=s.end();it++){
        cout<<*(it)<<",";
    } 
    cout<<endl;
    auto it=s.find(11); //Method 2
    s.erase(it);
    for (set<int> :: iterator it=s.begin();it!=s.end();it++){
        cout<<*(it)<<",";
    } 

    return 0;
}
