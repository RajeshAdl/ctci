#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next = NULL;
};

void printList(Node *head) {
	while(head) {
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void deleteNodeMain(Node *head) {
	if(head->next == NULL) {
		cout<<"Sorry, can't delete this node";
		return;
	}
	Node *temp = head->next;
	head->data = head->next->data;
	head->next = head->next->next;
	delete(temp);
}

void deleteNode(Node *head, int n) {
	int i = 0;
	while(head != NULL && i < n) {
		head = head->next;
		i++;
	}
	if(head == NULL) {
		cout<<"Out of bounds"<<endl;
		return;
	}
	deleteNodeMain(head);
}

void insert(Node *head, int data) {
	Node *newNode = new Node();
	newNode->data = data;
	while(head->next) {
		head = head->next;
	}
	head->next = newNode;
}

int main() {
	Node *obj = new Node();
	obj->data = 1;
	insert(obj, 2);
	insert(obj, 3);
	insert(obj, 4);
	insert(obj, 5);
	insert(obj, 6);
	insert(obj, 7);
	cout<<"List elements: ";
	printList(obj);
	deleteNode(obj, 2);
	cout<<"List after deleting the 3rd element: ";
	printList(obj);
	deleteNode(obj, 3);
	cout<<"List after deleting the 4th element: ";
	printList(obj);
	deleteNode(obj, 0);
	cout<<"List after deleting the 1st element: ";
	printList(obj);
	return 0;
}