#include <iostream>
#include <vector>
using namespace std;

void print_matrix(const vector<vector<int> > &arr) {
	for(int i=0; i<arr.size(); i++) {
		for(int j=0; j<arr[0].size(); j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void nullifyRow(vector<vector<int> > &arr, int row) {
	for(int i=0; i<arr[0].size(); i++) {
		arr[row][i] = 0;
	}
}

void nullifyColumn(vector<vector<int> > &arr, int column) {
	for(int i=0; i<arr.size(); i++) {
		arr[i][column] = 0;
	}
}

void zeroMatrix(vector<vector<int> > &arr) {
	bool rowZero = false;

	for(int i=0; i<arr[0].size(); i++) {
		if(arr[0][i] == 0) { 
			rowZero = true;
			break;
		}
	}

	for(int i=1; i<arr.size(); i++) {
		bool rowHasZero = false;
		for(int j=0; j<arr[0].size(); j++) {
			if(arr[i][j] == 0) {
				rowHasZero = true;
				arr[0][j] = 0;
			}
		}
		if(rowHasZero)
				nullifyRow(arr, i);
	}

	for(int i=0; i<arr[0].size(); i++) {
		if(arr[0][i] == 0) { 
			nullifyColumn(arr, i);
		}
	}

	if(rowZero) {
		for(int i=0; i<arr[0].size(); i++) {
			arr[0][i] = 0;
		}
	}
}

int main() {
	vector<vector<int> > arr(5, vector<int> (5, 1));
	arr[0][2] = 0;
	arr[3][2] = 0;
	arr[1][4] = 0;
	cout<<"Original Matrix"<<endl;
	print_matrix(arr);
	zeroMatrix(arr);
	cout<<"Zero Matrix"<<endl;
	print_matrix(arr);
}