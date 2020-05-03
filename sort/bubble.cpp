#include<stdio.h>
#include<iostream>

using namespace std;

int *bubble_sort(int *arr, int n) {
	int swap = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}

		}
	}
	return arr;
}

int main() {
	int input[9999999];
	int n = 0;
	int *ans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	ans = bubble_sort(input, n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}