#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool permutation_1(string s1, string s2) {
	if(s1.length() != s2.length()) {
		return false;
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for(int i = 0; i < s1.length(); i++) {
		if(s1[i] != s2[i]) {
			return false;
		}
	}
	return true;
}

bool permutation_2(const string &s1, const string &s2) {
	if(s1.length() != s2.length()) {
		return false;
	}
	vector<int> arr(128);
	for(auto ch : s1) {
		int temp = ch;
		arr[temp]++;
	}
	for(auto ch : s2) {
		int temp = ch;
		arr[temp]--;
		if(arr[temp] < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	string s1 = "testest", s2 = "estxest", s3 = "hello", s4 = "elloh";
	// Using sort
	cout<<"Using sort to find the permuations"<<endl;
	if(permutation_1(s1, s2)) {
		cout<<s1<<" and "<<s2<<" are permutations of each other"<<endl;
	}
	else {
		cout<<s1<<" and "<<s2<<" are not permutations of each other"<<endl;
	}
	if(permutation_1(s3, s4)) {
		cout<<s3<<" and "<<s4<<" are permutations of each other"<<endl;
	}
	else {
		cout<<s3<<" and "<<s4<<" are not permutations of each other\n\n"<<endl;
	}

	// Using a vector 
	cout<<"Using vector array to find the permuations"<<endl;
	if(permutation_2(s1, s2)) {
		cout<<s1<<" and "<<s2<<" are permutations of each other"<<endl;
	}
	else {
		cout<<s1<<" and "<<s2<<" are not permutations of each other"<<endl;
	}
	if(permutation_2(s3, s4)) {
		cout<<s3<<" and "<<s4<<" are permutations of each other"<<endl;
	}
	else {
		cout<<s3<<" and "<<s4<<" are not permutations of each other"<<endl;
	}
}