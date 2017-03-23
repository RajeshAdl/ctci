#include <iostream>
#include <string>
using namespace std;

bool oneAway(string s1, string s2) {
	int len1 = s1.length(), len2 = s2.length();
	if(abs(len1-len2) >= 2) {
		return false;
	}
	
	string large, small;
	if(len1 > len2) {
		large = s1;
		small = s2;
	} else {
		large = s2;
		small = s1;
	}

	bool flag = false;
	for(int i=0, j=0; i<large.length(); i++, j++) {
		if(large[i] != small[j]) {
			if(flag) {
				return false;
			} else {
				flag = true;
				if(len1 != len2) i++;
			}
		}
	}
	return true;
}

void print_result(string s1, string s2) {
	cout<<s1<<" and "<<s2<<" are ";
	(oneAway(s1, s2))? cout<<"one edit away": cout<<"are not one edit away";
	cout<<endl;
}

int main() {
	print_result("pale","ple");
	print_result("pales","pale");
	print_result("pale","pales");
	print_result("pale","bale");
	print_result("pale","bake");
	return 0;
}