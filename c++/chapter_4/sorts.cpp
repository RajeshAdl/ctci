#include <iostream>
#include <vector>
#include <string>
using namespace std;

void insertionSort(vector<int> &a) {
    for(int i=1; i<a.size(); i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void selectionSort(vector<int> &a) {
	for(int i=0; i<a.size(); i++) {
		int min = i;
		for(int j=i+1; j<a.size(); j++) {
			if(a[j] < a[min]) {
				min = j;
			}
		}
		if(min != i) {
			swap(a[i], a[min]);
		}
	}
}

void merge(vector<int> &a, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	vector<int> L(n1), R(n2);

	for(int i=0; i<n1; i++) {
		L[i] = a[i];
	}
	for(int i=0; i<n2; i++) {
		R[i] = a[m + i + 1];
	}
	int i = 0, j=0, k = 0;

	while(i<n1 && j<n2) {
		if(L[i]<R[j]) {
			a[k] = L[i];
			i++;
			k++;
		}
		else {
			a[k] = R[j];
			j++;
			k++;
		}
	}

	while(i<n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	while(j<n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &a, int l, int r) {
	if(l > r) {
		return;
	}
	int mid = (l + r)/2;
	mergeSort(a, l, mid);
	mergeSort(a, mid+1, r);
	merge(a, l, mid, r);
}

int main()
{
  vector<int> a {6, 7, 4, 3, 2, 5, 1};
  for(auto i : a) {
      cout<<i<<" ";
  }
	cout<<endl;
  mergeSort(a, 0, a.size());
  for(auto i : a) {
      cout<<i<<" ";
  }
	cout<<endl;
}