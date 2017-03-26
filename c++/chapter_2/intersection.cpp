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

int listLength(Node *head) {
	int count = 0;
	while(head) {
		count++;
		head = head->next;
	}
	return count;
}

void insert(Node *head, int data) {
	Node *newNode = new Node(data);
	while(head->next) {
		head = head->next;
	}
	head->next = newNode;
}

void combinedInsert(Node *head1, Node *head2, int data) {
	Node *newNode = new Node(data);
	while(head1->next) {
		head1 = head1->next;
	}
	while(head2->next) {
		head2 = head2->next;
	}
	head1->next = head2->next = newNode;
}

Node* intersection(Node *list1, Node *list2) {
	int len1 = listLength(list1);
	int len2 = listLength(list2);

	Node *ptr1 = len1>len2? list1: list2;
	Node *ptr2 = len1>len2? list2: list1;

	for(int i=0; i<abs(len1-len2); i++) {
		ptr1 = ptr1->next;
	}

	while(ptr1 && ptr2) {
		if(ptr1->data == ptr2->data) {
			return ptr1;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return NULL;
}

int main() {
	Node *list1 = new Node(3);
	insert(list1, 1);
	insert(list1, 5);
	insert(list1, 9);
	Node *list2 = new Node(4);
	insert(list2, 6);
	combinedInsert(list1, list2, 7);
	combinedInsert(list1, list2, 2);
	combinedInsert(list1, list2, 1);
	Node *list3 = new Node(3);
	insert(list3, 1);
	insert(list3, 5);
	insert(list3, 9);
	cout<<"List 1: ";
	printList(list1);
	cout<<"List 2: ";
	printList(list2);
	cout<<"List 3: ";
	printList(list3);
	Node *intersectionPoint = intersection(list1, list2);
	cout<<"List 1 and List 2"<<endl;
	if(intersectionPoint != NULL) {
		cout<<"The two lists intersect at "<<intersectionPoint->data<<endl;
	}
	else {
		cout<<"They dont intersect"<<endl;
	}

	cout<<"List 1 and List 3"<<endl;
	Node *intersectionPoint2 = intersection(list1, list3);
	if(intersectionPoint2 != NULL) {
		cout<<"The two lists intersect at "<<intersectionPoint2->data<<endl;
	}
	else {
		cout<<"They don't intersect"<<endl;
	}
	return 0;
}