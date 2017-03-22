#include <iostream>
#include <string>
using namespace std;


void reverse(string &input){
	for(int i=0, j=input.size()-1; i<j; i++, j--) {
		char temp = input[i];
		input[i] = input[j];
		input[j] = temp;
	}
}

int main() {
	string input;
	cout<<"Enter a string: ";
	cin>>input;
	reverse(input);
	cout<<"Its reverse is "<<input<<endl;
}