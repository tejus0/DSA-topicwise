#include <bits/stdc++.h>
using namespace std;

string removeDup(string s){
    int n=s.length();

    if(s.length()==1){
        return s;
    }
    int i=0;
    int filled=1;
    while(i<n-1){
        if(s[i]!=s[i+1]){
            s[filled]=s[i+1];
            filled++;
        }
        i++;
    }
    string ans=s.substr(0 ,filled);
    return ans;
}

int main()
{
     int test;
     cin>>test;
    while(test--){
        string s;
        cin>>s;
        cout<<removeDup(s);
    }
    
    return 0;
}