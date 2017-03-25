#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int> > &arr) {
	if(arr.size() == 0 || arr.size() != arr[0].size()) {
		return;
	}
	int len = arr.size();
	for(int i=0; i<len/2; i++) {
		for(int j=i; j<len-i-1; j++) {
			int temp = arr[i][j];
			arr[i][j] = arr[len-j-1][i];
			arr[len-j-1][i] = arr[len-i-1][len-j-1];
			arr[len-i-1][len-j-1] = arr[j][len-i-1];
			arr[j][len-i-1] = temp;
		}
	}
}

void print_matrix(const vector<vector<int> > arr) {
	for(int i=0; i<arr.size(); i++) {
		for(int j=0; j<arr[0].size(); j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	vector<vector<int>> arr(5, vector<int> (5,0));
	int number = 1;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			arr[i][j] = number++;
		}
	}
	cout<<"Before matrix rotation: "<<endl;
	print_matrix(arr);
	rotateMatrix(arr);
	cout<<"After matrix rotation: "<<endl;
	print_matrix(arr);
}