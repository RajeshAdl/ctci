#include <iostream>
#include <vector>
using namespace std;

class FixedMultiStack {
	private:
		int numberOfStacks = 3;
		int stackCapacity;
		vector<int> values; 
		vector<int> sizes;
		int indexOfTop(int);
	public:
		FixedMultiStack(int);
		void push(int, int);
		int pop(int);
		bool isStackFull(int);
		bool isStackEmpty(int);
		int peek(int);
		void printStack();
		void printSizes();
};

FixedMultiStack :: FixedMultiStack(int capacity) {
	values.resize(capacity*numberOfStacks, 0);
	sizes.resize(3, 0);
	stackCapacity = capacity;
} 

void FixedMultiStack :: push(int stackNum, int value) {
	if(!isStackFull(stackNum)) {
		sizes[stackNum]++;
		values[indexOfTop(stackNum)] = value;
	}
	else {
		cout<<"Stack is full";
	}
}

int FixedMultiStack :: pop(int stackNum) {
	if(!isStackEmpty(stackNum)) {
		int index = indexOfTop(stackNum);
		int result = values[index];
		values[index] = 0;
		sizes[stackNum]--;
		return result;
	}
	else {
		cout<<"Stack is empty";
	}
	return -1;
}

int FixedMultiStack :: peek(int stackNum) {
	if(!isStackEmpty(stackNum)) {
		return values[indexOfTop(stackNum)];
	}
	else {
		cout<<"Stack is empty";
	}
	return -1;
}

bool FixedMultiStack :: isStackFull(int stackNum) {
	return sizes[stackNum] == stackCapacity;
}

bool FixedMultiStack :: isStackEmpty(int stackNum) {
	return sizes[stackNum] == 0;
}

int FixedMultiStack :: indexOfTop(int stackNum) {
	return stackNum * stackCapacity + sizes[stackNum] - 1;
}

void FixedMultiStack :: printStack() {
	for(int i=0; i<values.size(); i++) {
		cout<<values[i]<<" ";
	}
	cout<<endl;
}

void FixedMultiStack :: printSizes() {
	for(int i=0; i<sizes.size(); i++) {
		cout<<sizes[i]<<" ";
	}
	cout<<endl;
}

int main() {
	FixedMultiStack *stk = new FixedMultiStack(3);
	stk->printStack();
	stk->push(1, 5);
	stk->printStack();
	stk->push(0, 8);
	stk->printStack();
	stk->push(2, 9);
	stk->printStack();
	stk->push(1, 2);
	stk->printStack();
	stk->printSizes();
	stk->pop(1);
	stk->printStack();
	stk->printSizes();
	return 0;
}