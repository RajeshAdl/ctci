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

void insert(Node *head, int data) {
	Node *newNode = new Node();
	newNode->data = data;
	while(head->next) {
		head = head->next;
	}
	head->next = newNode;
}

Node* partition1(Node *head, int x) {
	Node *beforeStart, *beforeEnd, *afterStart, *afterEnd;
	beforeStart = beforeEnd = afterStart = afterEnd = NULL;

	while(head) {
		Node *next = head->next;
		head->next = NULL;
		if(head->data < x) {
			if(beforeStart == NULL) {
				beforeStart = head;
				beforeEnd = beforeStart;
			}
			else {
				beforeEnd->next = head;
				beforeEnd = beforeEnd->next;
			}
		}
		else {
			if(afterStart == NULL) {
				afterStart = head;
				afterEnd = afterStart;
			}
			else {
				afterEnd->next = head;
				afterEnd = afterEnd->next;
			}
		}
		head = next;
	}

	if(beforeStart == NULL) {
		return afterStart;
	}

	beforeEnd->next = afterStart;
	return beforeStart;
}

Node* partition2(Node *head, int x) {
	Node *start, *end;
	start = end = head;
	while(head) {
		Node *next = head->next;
		if(head->data < x) {
			head->next = start;
			start = head;
		}
		else {
			end->next = head;
			end = head;
		}
		head = next;
	}

	end->next = NULL;
	return start;
}

int main() {
	Node *obj = new Node();
	obj->data = 3;
	insert(obj, 5);
	insert(obj, 8);
	insert(obj, 5);
	insert(obj, 10);
	insert(obj, 2);
	insert(obj, 1);
	printList(obj);
	Node *result = partition2(obj, 5);
	printList(result);

	return 0;
}