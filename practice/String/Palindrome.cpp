#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int i=0, j= s.length()-1;
    while (i<j)
    {
        if(s[i]!=s[j]){
            return false;
        }
        i++, j--;
    }
    return true;
}

int main()
{
     int test;
     cin>>test;
    while(test--){
        string s;
        cin>>s;
        if(isPalindrome(s)){
            cout<<s<<" is Palindrome";
        }
        else{
            cout<<s<<" is not a palindrome";
        }
    }
    return 0;
}