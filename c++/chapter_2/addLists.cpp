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

Node* addLists(Node *p1, Node *p2, int carry) {
	if(p1 == NULL && p2 == NULL && carry == 0) {
		return NULL;
	}
	int sum = carry;
	if(p1) {
		sum = sum + p1->data;
	}
	if(p2) {
		sum = sum + p2->data;
	}

	Node *result = new Node(sum%10);
	result->next = addLists(p1? p1->next: NULL, p2? p2->next: NULL, sum>9? 1: 0);
	return result;
}

Node* addLists2(Node *list1, Node *list2) {
	if(list1 == NULL) {
		return list2;
	}
	if(list2 == NULL) {
		return list2;
	}
	Node *list3 = NULL;
	Node *tail = NULL;

	int sum = 0, carry = 0;
	while(list1 || list2) {
		sum = carry;

		if(list1) {
			sum += list1->data;
		}
		if(list2) {
			sum += list2->data;
		}

		if(sum > 9) {
			carry = 1;
			sum = sum%10;
		}
		else {
			carry = 0;
		}
		
		Node *node = new Node(sum);

		if(tail == NULL) {
			list3 = node;
			tail = node;
		}
		else {
			tail->next = node;
		}
		tail = node;

		if(list1) {
			list1 = list1->next;
		}
		if(list2) {
			list2 = list2->next;
		}
	}
	if(carry) {
		tail->next = new Node(carry);
	}
	return list3;
}

int main() {
	Node *obj1 = new Node(7);
	insert(obj1, 1);
	insert(obj1, 6);
	Node *obj2 = new Node(5);
	insert(obj2, 9);
	insert(obj2, 2);
	printList(obj1);
	printList(obj2);
	Node *result = addLists2(obj1, obj2);
	printList(result);
	return 0;
}