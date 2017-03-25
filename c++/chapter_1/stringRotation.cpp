#include <iostream>
#include <string>
using namespace std;

bool checkIsRotation(string &s1, string &s2) {
	string temp = s1 + s1;
	if(s1.length() == s2.length() && s1.length()) {
		return (temp.find(s2) != string::npos)? true: false;
	}
	return false;
}

int main() {
	string s1 = "waterbottle", s2 = "erbottlewat", s3 = "test", s4 = "estr";
	cout<<"Test case 1: "<<s1<<" , "<<s2<<" : ";
	if(checkIsRotation(s1, s2)) {
		cout<<"True";
	} else {
		cout<<"False";
	}
	cout<<endl;
	cout<<"Test case 2: "<<s3<<" , "<<s4<<" : ";
	if(checkIsRotation(s3, s4)) {
		cout<<"True";
	} else {
		cout<<"False";
	}
	cout<<endl;
	return 0;
}