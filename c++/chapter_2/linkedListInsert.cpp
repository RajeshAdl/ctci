#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int data): data(data), next(NULL) {}
};

void printList(Node *head) {
	while(head) {
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void insert(Node *head, int data) {
	Node *newNode = new Node(data);
	while(head->next) {
		head = head->next;
	}
	head->next = newNode;
}

int main() {
	Node *obj = new Node(1);
	insert(obj, 2);
	insert(obj, 3);
	insert(obj, 4);
	insert(obj, 5);
	insert(obj, 6);
	insert(obj, 7);
	printList(obj);
	return 0;
}