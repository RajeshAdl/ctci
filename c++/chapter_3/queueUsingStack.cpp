#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
	private:
		stack<int> newValues;
		stack<int> reversed;
		void move(stack<int> &from, stack<int> &to) {
			while(!from.empty()) {
				to.push(from.top());
				from.pop();
			}
		}
	public:
		void push(int);
		int pop();
		int peek();
		~MyQueue();
};

void MyQueue :: push(int data) {
	newValues.push(data);
}

int MyQueue :: pop() {
	if(reversed.empty()) {
		move(newValues, reversed);
	}
	if(!reversed.empty()) {
		int result = reversed.top();
		reversed.pop();
		return result;
	}
	cout<<"Data not found"<<endl;
	return -1;
}

int MyQueue :: peek() {
	if(reversed.empty()) {
		move(newValues, reversed);
	}
	if(!reversed.empty()) {
		return reversed.top();
	}
	cout<<"Data not found"<<endl;
	return -1;
}

MyQueue :: ~MyQueue() {
	reversed.empty();
	newValues.empty();
}

int main() {
	MyQueue *q = new MyQueue();
	q->peek();
	q->push(10);
	q->push(11);
	q->push(12);
	cout<<"Peek: "<<q->peek()<<endl;
	q->push(13);
	q->push(14);
	cout<<"Peek: "<<q->peek()<<endl;
	cout<<"Pop: "<<q->pop()<<endl;
	cout<<"Peek: "<<q->peek()<<endl;
	cout<<"Pop: "<<q->pop()<<endl;
	cout<<"Peek: "<<q->peek()<<endl;
	cout<<"Pop: "<<q->pop()<<endl;
	cout<<"Peek: "<<q->peek()<<endl;
	return 0;
}

