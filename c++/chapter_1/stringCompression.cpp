#include <iostream>
using namespace std;

string compressString(string s) {
	string result = "";

	for(int i=0; i<s.length(); i++) {
		char temp = s[i];
		int count = 1;
		while(i+1<s.length() && s[i+1]==s[i]){
			count++;
			i++;
		}
		result = result + temp + to_string(count);
	}
	return result.length()<s.length()? result: s;
}

int main() {
	string s = "aabcccccaaa";
	string result = compressString(s);
	cout<<"The compressed string is "<<result<<endl;
	return 0;
}