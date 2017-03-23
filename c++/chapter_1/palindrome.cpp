#include <iostream>
#include <vector>
using namespace std;

bool palindrome(string s) {
	bool flag = s.length()%2 == 0? true: false;
	vector<int> arr(26);

	for(auto ch : s) {
		if(isalpha(ch)) {
			int val = tolower(ch) - 'a';
			arr[val]++;
		}
	}

	for(int i=0; i<26; i++) {
		if(arr[i]%2 != 0) {
			if(flag) {
				return false;
			}
			else {
				flag = true;
			}
		}
	}
	return true;
}

int main() {
	string s1 = "racecar", s2 = "applebee";
	cout<<s1<<" is ";
	palindrome(s1) ? cout<<"a palindrome": cout<<"not a palindrome";
	cout<<endl;
	cout<<s2<<" is ";
	palindrome(s2) ? cout<<"a palindrome": cout<<"not a palindrome";
	cout<<endl;
	return 0;
}