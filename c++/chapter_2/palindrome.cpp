#include <iostream>
#include <vector>
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

int length(Node *head) {
	int length = 0;
	while(head) {
		length++;
		head = head->next;
	}
	return length;
}

bool isPalindrome(Node *head) {
	int len = length(head);
	int middle = len/2;
	vector<int> buffer;
	for(int i=0; i<middle; i++) {
		buffer.push_back(head->data);
		head = head->next;
	}

	if(len%2 == 1) {
		head = head->next;
		middle++;
	}

	for(int i=middle; i<len; i++) {
		if(buffer.back() != head->data) {
			return false;
		}
		head = head->next;
		buffer.pop_back();
	}
	return true;
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
	isPalindrome(obj)? cout<<"Palindrome": cout<<"Not a palindrome";
	cout<<endl;
	Node *obj2 = new Node(1);
	insert(obj2, 2);
	insert(obj2, 3);
	//insert(obj2, 4);
	insert(obj2, 3);
	insert(obj2, 2);
	insert(obj2, 1);
	printList(obj2);
	isPalindrome(obj2)? cout<<"Palindrome": cout<<"Not a palindrome";
	cout<<endl;

	return 0;
}