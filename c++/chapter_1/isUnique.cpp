#include <iostream>
#include <string> 
#include <vector>
using namespace std;

bool isUnique_Char(string s) {
	// Only ASCII values
	if(s.length() > 128) {
		return false;
	}
	bool arr[128] = {false};
	for(auto ch : s) {
		int val = ch;
		if(arr[val]) {
			return false;
		}
		arr[val] = true;
	}
	return true;
}

// Works with strings containing only alphabets
bool isUnique_Bit(string s) {
	int test = 0;
	for(auto ch : s) {
		int val = tolower(ch) - 'a';
		if(test>>val & 1) {
			return false;
		}
		test |= 1<<val;
	}
	return true;
}

int main() {
	vector<string> words = {"abcde", "hello", "APPLE", "kite", "PADLE"};
	for(auto input : words) {
		cout<<"Testing "<<input<<" : "<<isUnique_Char(input)<<endl;
	}
	cout<<"Using bits"<<endl;
	for(auto input : words) {
		cout<<"Testing "<<input<<" : "<<isUnique_Bit(input)<<endl;
	}
	return 0;
}