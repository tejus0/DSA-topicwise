#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int >v;
    bool minheap;
    bool compare(int a, int b){
        if (minheap){
            return a<b;
                    }
    }
    public:
    Heap(int default_size=10, bool type=true){
        v.reserve(default_size);
        v.push_back(-1);
        minheap=type;
    }
    void push(int x){
        v.push_back(x);
        int idx=v.size()-1;
        int parent=idx/2;

        while(idx>1 and compare(v[idx], v[parent])){
            swap(v[idx],v[parent]);
            parent=parent/2;
            idx=parent;
        }
    }
};

int main(){
    Heap h;
    h.push(1);
    h.push(2);
    h.push(3);
    h.push(17);
    h.push(19);
    h.push(36);
    h.push(7);
    h.push(25);
    h.push(100);
    h.push(0);

}