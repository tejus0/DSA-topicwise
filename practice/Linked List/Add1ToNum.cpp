#include <iostream>
using namespace std;
//n=next node ; d=data ; p= previous node; h=head node; c=current node
class Node {
   public:
      int d;
      Node* n;
};
Node *newNode(int d) {
   Node *new_node = new Node;
   new_node->d = d;
   new_node->n = NULL;
   return new_node;
}
Node *reverse(Node *h) {
   Node * p = NULL;
   Node * c = h;
   Node * n;
   while (c != NULL) {
      n = c->n;
      c->n = p;
      p = c;
      c = n;
   }
   return p;
}
Node *addOneUtil(Node *h) {
   Node* res = h;
   Node *temp, *p = NULL;
   int carry = 1, sum;
   while (h != NULL) {
      sum = carry + h->d;
      carry = (sum >= 10)? 1 : 0;
      sum = sum % 10;
      h->d = sum;
      temp = h;
      h = h->n;
   }
   if (carry > 0)
      temp->n = newNode(carry);
   return res;
}
Node* addOne(Node *h) {
   h = reverse(h);
   h = addOneUtil(h);
   return reverse(h);
}
int main() {
   Node *h = newNode(1);
   h->n = newNode(9);
   h->n->n = newNode(9);
   h->n->n->n = newNode(9);
   h = addOne(h);
   while (h != NULL) {
      cout << h->d;
      h = h->n;
   }
   cout<<endl;
   return 0;
}