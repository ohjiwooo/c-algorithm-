#include<stdio.h>
#include<iostream>

using namespace std;

int input[10000001];
int n;

int *swap(int *arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	return arr;
}



int divide(int *arr, int left, int right) {
	int key = arr[right];
	int left_2 = left;

	for (int i = left; i < right; i++) {
		if (arr[i] < key) {
			swap(arr, left_2, i);
			left_2++;
		}
	}
	swap(arr, left_2, right);
	return left_2;
}

int *quick_sort(int *arr, int left, int right) {
	int point;

	if (left < right) {
		point = divide(arr, left, right);
		quick_sort(arr, left, point - 1);
		quick_sort(arr, point + 1, right);
	}
	return arr;
}

int main() {



	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	quick_sort(input, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", input[i]);
	}
	return 0;
}