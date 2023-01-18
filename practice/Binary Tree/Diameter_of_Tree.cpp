#include<iostream>
#include<queue>
using namespace std;

class node{
    public :
        int data;
        node* left;
        node* right;

        node(int d){
            data=d;

        }
};

node* buildTree(){
    int d;
    cin>>d;
    if (d==-1){
        return NULL;  //if current node is left side then after -1 , pointer will go to right side, out of left loop and vice-versa
    }
    node* root=new node (d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}


int height(node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}

void printKthLevel(node* root, int k){
    if (root==NULL){
        return;
    }
    if (k==1){
        cout<<root->data<<" ";
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}

void printAllLevels(node* root){
    int h=height(root);
    for (int i=1;i<=h;i++){
        printKthLevel(root,i);
        cout<<endl;
    }
}

void bfs(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f=q.front();
        if(f==NULL) {
            q.pop();
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if (f->right){
                q.push(f->right);
            }
        }
    }
    return ;
}

int count(node* root){
    if (root==NULL){
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}

int sum(node*root){
    if (root==NULL){
        return 0;
    }

    return sum(root->left)+sum(root->right)+root->data;
    }
// this will give Diameter in O(N^2) at worst complexity
int Diameter(node* root){
    if (root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    int opt1=h1+h2;
    int opt2=Diameter(root->left);
    int opt3=Diameter(root->right);
    return max(opt1, max(opt2, opt3));
}

class Pair {
    public : 
        int height;
        int diameter;
};
// this will give Diameter in O(N) time
Pair FastDiameter(node* root ){
    Pair p;
    if (root==NULL){
        p.height=p.diameter=0;
        return p;
    }
    Pair left=FastDiameter(root->left);
    Pair right =FastDiameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));

    return p;
}

int main(){
    node* root=buildTree();
  //  printKthLevel(root,2);
 // printAllLevels(root);
 //bfs(root);
   /* cout<<count(root)<<endl;
    cout<<sum(root)<<endl; */
    cout<<Diameter(root)<<endl;
    Pair p=FastDiameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;
}