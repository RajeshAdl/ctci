#include <iostream>
#include <stack>
using namespace std;

class StackWithMin {
	private:
		stack<int> values;
		stack<int> minValues;
	public:
		void push(int value) {
			values.push(value);
			if(value < min()) {
				minValues.push(value);
			}
		}

		int pop() {
			int result = values.top();
			values.pop();
			if(result == min()) {
				minValues.pop();
			}
			return result;
		}

		int min() {
			if(minValues.size() == 0) {
				return INT_MAX;
			}
			return minValues.top();
		}
};

int main() {
	StackWithMin *stk = new StackWithMin();
	stk->push(3);
	stk->push(4);
	stk->push(5);
	cout<<"Minimum value from the stack is "<<stk->min()<<endl;
	stk->push(2);
	stk->push(6);
	stk->push(7);
	cout<<"Minimum value from the stack is "<<stk->min()<<endl;
	stk->push(8);
	stk->push(9);
	stk->push(1);
	cout<<"Minimum value from the stack is "<<stk->min()<<endl;
	stk->pop();
	cout<<"Minimum value from the stack is "<<stk->min()<<endl;
	return 0;
}