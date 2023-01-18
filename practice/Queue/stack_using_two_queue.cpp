#include<iostream>
#include<queue>
using namespace std;

template<typename t>
class stack
{
private:
    /* data */
    queue<t> q1,q2;
public:
    void push(t x){
        q1.push(x);
    }
    void pop(){
        if (q1.empty()){
            return ;
        }
        //transfering n-1 elements of q1 to q2
        while(q1.size()>1){
            t ele=q1.front();
            q2.push(ele);
            q1.pop();
        }
        //remove the last added element from q1
        q1.pop();
        //swap the two queues
        swap(q1,q2);
    }
    t top(){
        while(q1.size()>1){
            t ele=q1.front();
            q2.push(ele);
            q1.pop();
        }
         t ele=q1.front();
         q1.pop();
         q2.push(ele);
         swap(q1,q2);
         return ele;
    }
    int size (){
        return q1.size()+q2.size();
    }
    bool empty(){
        return size()==0;
    }

};


int main(int argc, char const *argv[])
{
    /* code */
    stack<int> st;
    st.push(1);
        st.push(2);
    st.pop();
    st.push(5);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
            }

    return 0;
}
