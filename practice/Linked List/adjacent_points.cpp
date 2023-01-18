#include<iostream>
#include<list>
using namespace std;
int main(){
    list<pair<int,int>> *l;   //dymamic array of lists
    int n;  //vertices
    cin>>n;
    l=new list<pair<int,int>>[n];   
    int e;  //edges
    cin>>e;
    for (int i=0; i<e;i++){
        int x,y,wt;
        cin>>x>>y>>wt; 
        //doubly linked list
        l[x].push_back(make_pair(y,wt));    //linknig x with y at wt distance
        l[y].push_back(make_pair(x,wt));    // linking y with x at wt distance 
    }
    //print the linked lists
    for (int i=0;i<n;i++){   
        cout<<"List "<<i<<"->";  
        //print every linked list
        for (auto xp:l[i]){
            cout<<"("<<xp.first<<","<<xp.second<<"),";
        }
        cout<<endl;
    }
}