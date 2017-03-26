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
	printList(obj);
	return 0;
}