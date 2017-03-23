#include <iostream>
using namespace std;

string urlify(string s, int len) {
	len = len - 1;
	for(int i=s.length()-1; len >= 0; i--, len--) {
		if(s[len] == ' ') {
			s[i] = '0';
			s[i-1] = '2';
			s[i-2] = '%';
			i = i-2;
		}
		else {
			s[i] = s[len];
		}
	}
	return s;
}

int main() {
	string s1 = "Mr John Smith    ";
	cout<<s1<<" after applying URLify function becomes "<<urlify(s1, 13)<<endl;
	string s2 = "Monkey D Luffy    ";
	cout<<s2<<" after applying URLify function becomes "<<urlify(s2, 14)<<endl;
	return 0;
}