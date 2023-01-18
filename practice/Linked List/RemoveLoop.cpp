#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void removeLoop(struct Node*, struct Node*);

int detectAndRemoveLoop(struct Node* list)
{
	struct Node *slow_p = list, *fast_p = list;

	// Iterate and find if loop exists or not
	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		/* If slow_p and fast_p meet at some point then there
		is a loop */
		if (slow_p == fast_p) {
			removeLoop(slow_p, list);

			/* Return 1 to indicate that loop is found */
			return 1;
		}
	}

	/* Return 0 to indicate that there is no loop*/
	return 0;
}

/* Function to remove loop.
loop_node --> Pointer to one of the loop nodes
head --> Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head)
{
	struct Node* ptr1 = head;
	struct Node* ptr2 = loop_node;

	// Get pointer to the last node
	while (ptr2->next != ptr1->next){
		ptr2 = ptr2->next;
        ptr1=ptr1->next;
    }

	/* Set the next node of the loop ending node
	to fix the loop */
	ptr2->next = NULL;
}

/* Function to print linked list */
void printList(struct Node* node)
{
	// Print the list after loop removal
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

 Node* newNode(int key)
{
	struct Node* temp = new Node();
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// Driver Code
int main()
{
	struct Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;
	detectAndRemoveLoop(head);

	cout << "Linked List after removing loop \n";
	printList(head);
	return 0;
}

// This code has been contributed by Striver
