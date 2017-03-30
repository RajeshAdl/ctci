#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int data): data(data), left(NULL), right(NULL) {}
};

void preOrder(Node *head) {
	if(head == NULL) {
		return;
	}
	preOrder(head->left);
	cout<<head->data<<" ";
	preOrder(head->right);
}

Node* minimalBST(vector<int> &arr, int low, int high) {
	if(low > high) {
		return NULL;
	}
	int mid = (low + high) / 2;
	Node *head = new Node(arr[mid]);
	head->left = minimalBST(arr, low, mid-1);
	head->right = minimalBST(arr, mid+1, high);
	return head;
}

int main() {
	vector<int> a {1, 2, 3, 4, 5, 6, 7};
	Node *head = minimalBST(a, 0, a.size()-1);
	preOrder(head);
	cout<<endl;
	return 0;
}