//finding minimum and maximum of stack at every traversal using vector 
#include<iostream>
#include<vector>
using namespace std;

class MinMaxStack{
    vector<int> stack;
    vector<int> min_stack;
    vector<int> max_stack;

    public :
        int top(){
            return stack[stack.size()-1];
        }
        void push(int data){
            int curr_min=data;
            int curr_max=data;

            if (max_stack.size()){
                curr_max=max(max_stack[max_stack.size()-1],data);
                curr_min=min(min_stack[min_stack.size()-1],curr_min);

            }
            stack.push_back(data);
            min_stack.push_back(curr_min);
            max_stack.push_back(curr_max);
        }

        int getmin(){
            return min_stack[min_stack.size()-1];
        }
        int getmax(){
             return max_stack[max_stack.size()-1];
        }
        void pop(){
            min_stack.pop_back();
            max_stack.pop_back();
            stack.pop_back();
        }

};
int main(){
    MinMaxStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.getmax()<<endl;
    st.pop();
    cout<<st.getmin()<<endl;
    cout<<st.getmax()<<endl;
    st.pop();
    st.pop();
    cout<<st.getmax()<<endl;
    cout<<st.getmin()<<endl;

}