#include<iostream>
#include<queue>
using namespace std;

class node {
public:
	int data = 0;
	node* left = NULL;
	node* right = NULL;

	node(int d) {
		data = d;
	}
};
//Inorder Traversal
void printIn(node* root) {
	if (root == NULL) {
		return;
	}

	printIn(root->left);
	cout << root->data << " ";
	printIn(root->right);
}
//Print the  BST Level by Level
void bfs(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* f = q.front();
		if (f == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {

			cout << f->data << " ";
			q.pop();

			if (f->left != NULL) q.push(f->left);
			if (f->right != NULL) q.push(f->right);
		}
	}

}
//Accepts old node , data and returns new node with data 
node* insertInBST(node* root, int d) {
	// Base Case
	if (root == NULL) {
		node* n = new node(d);
		return n;
	}
    //Rec Case - Insert in the subtree and update pointers
	if (d <= root->data) {
		root->left = insertInBST(root->left, d);
	} else {
		root->right = insertInBST(root->right, d);
	}

	return root;
}
//Read the list till -1 and also insert in the tree
node* buildTree() {

	int d; cin >> d;
	node* root = NULL;
    //terminating condition of input
	while (d != -1) {
		root = insertInBST(root, d);
		cin >> d;
	}

	return root;
}

int main() {
	node* root = buildTree();
	bfs(root); 
    cout << endl;
	printIn(root);
}