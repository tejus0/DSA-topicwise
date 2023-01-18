#include <iostream>
#include<list>  //initialisation is same as vectors
using namespace std;
int main(){
    list<int> l;  //just like vectors
    //init
    list<int> l1{1,3,5,7,10};
    //different data types
    list<string> l2{"apple", "guava","banana"};
    l2.push_back("mango");

    //Sorting
    l2.sort();  //lexographically

    //reverse list
    l2.reverse();

    //remove front
    cout<<l2.front()<<endl;
    l2.pop_front();

    //add to te front
    l2.push_front("kiwi");
    //remove last element
    cout<<l2.back()<<endl;
    l2.pop_back();

    //remove a fruit
    string f;
    cin>>f;
    l2.remove(f);
    //iterate over list and print data
    /*Method 1 :-
    for(auto it:l2){    
        cout<<it<<"->";
    }
    cout<<endl;*/
    //Method 2 :-
    for (string s:l2){
        cout<<s<<"->";
    } 
    /*Method 3 :- 
    for (auto it=l2.begin();it!=l2.end();it++){
        cout<<(*it)<<"->";
    }
    cout<<endl; */
    return 0;
}