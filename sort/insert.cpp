#include <stdio.h>
#include<iostream>

using namespace std;


int *insert_sort(int *arr, int n) {
	int key = 0;
	for (int i = 0; i < n; i++) {
		key = arr[i];
		int j = i;

		while (arr[j - 1] > key && j - 1 >= 0) {
			arr[j] = arr[j - 1];
			j--;
		}arr[j] = key;
	}
	return arr;
}



int main() {
	int input[100];
	int n;
	int *output;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	output = insert_sort(input, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", output[i]);
	}

	return 0;
}