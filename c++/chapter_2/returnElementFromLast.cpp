#include <iostream>
using namespace std;

struct Node  {
	int data;
	Node *next = NULL;
};

void insert(Node *head, int data) {
	Node *newNode = new Node();
	newNode->data = data;
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = newNode;
}

void print_list(Node *head) {
	while(head) {
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int printKthLastElement(Node *head, int n) {
	if(head == NULL) {
		return 1;
	}
	int result = printKthLastElement(head->next, n);
	if(result == n) {
		cout<<n<<" element from the last is "<<head->data<<endl;
	}
	return result+1;
}

void printKthLastElement2(Node *head, int n) {
	Node *p1 = head, *p2 = head;
	for(int i=0; i<n; i++) {
		if(p1 == NULL) {
			cout<<"Out of bounds"<<endl;
			return;
		}
		p1 = p1->next;
	}

	while(p1) {
		p1 = p1->next;
		p2 = p2->next;
	}

	cout<<n<<" element from the last is "<<p2->data<<endl;
}

int main() {
	Node *head = new Node();
	head->data = 1;
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 4);
	insert(head, 5);
	insert(head, 3);
	insert(head, 4);
	insert(head, 5);
	cout<<"Original list: ";
	print_list(head);
	printKthLastElement(head, 1);
	printKthLastElement(head, 2);
	printKthLastElement(head, 3);
	printKthLastElement(head, 4);
	printKthLastElement(head, 9);

	printKthLastElement2(head, 1);
	printKthLastElement2(head, 2);
	printKthLastElement2(head, 3);
	printKthLastElement2(head, 4);
	printKthLastElement2(head, 11);

	return 0;
}