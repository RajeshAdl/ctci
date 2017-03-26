#include <iostream>
#include <set>
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

void removeDupsWithoutBuffer(Node *head) {
	Node *back = head;
	Node *front = head->next;
	Node *temp;
	while(head) {
		back = head;
		front = head->next;
		while(front) {
			if(front->data == head->data) {
				back->next = front->next;
				temp = front;
				front = back->next;
				delete(temp);
			} 
			else { 
				back = back->next;
				front = front->next;
			}
		}
		head = head->next;
	}
}

void removeDupsWithBuffer(Node *head) {
	Node *temp, *runner = head;
	set<int> numbers;
	numbers.insert(head->data);
	while(head && head->next) {
		runner = head->next;
		if(numbers.find(runner->data) != numbers.end()) {
			temp = runner;
			head->next = runner->next;
			delete(temp);
		} 
		else {
			numbers.insert(runner->data); 
			head = head->next;
		}
	}
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
	removeDupsWithoutBuffer(head);
	removeDupsWithBuffer(head);
	cout<<"List after removing the duplicate items: ";
	print_list(head);

	return 0;
}