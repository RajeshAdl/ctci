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
	Node *list1 = new Node(1);
	insert(list1, 2);
	insert(list1, 3);
	insert(list1, 4);
	insert(list1, 5);
	insert(list1, 6);
	insert(list1, 7);
	printList(list1);
	return 0;
}