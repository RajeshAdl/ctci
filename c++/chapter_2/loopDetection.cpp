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

bool detectLoop(Node *head) {
	Node *slow, *fast;
	slow = fast = head;
	while(fast && slow && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			break;
		}
	}

	if(fast == NULL || fast->next == NULL) {
		return false;
	}

	fast = head;
	while(fast && slow) {
		if(fast == slow) {
			cout<<"Loop found at "<<fast->data<<endl;
			break;
		}
		fast = fast->next;
		slow = slow->next;
	}
	return true;
}

int main() {
	Node *list1 = new Node(1);
	insert(list1, 2);
	insert(list1, 3);
	insert(list1, 4);
	insert(list1, 5);
	list1->next->next->next->next->next = list1->next->next;
	detectLoop(list1)? cout<<"Loop found": cout<<"No loop found";
	cout<<endl;

	return 0;
}