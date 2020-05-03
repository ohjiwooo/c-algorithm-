#include<stdio.h>
#include<iostream>

using namespace std;



int *heapify(int *a, int n, int root) {
	int small = 0;
	int left = root * 2;
	int right = root * 2 + 1;
	int temp;

	if (right <= n) {
		if (a[right] <= a[left]) {
			small = right;
		}
		else { small = left; }
	}
	else if (left <= n) {
		small = left;
	}
	else return a;

	if (a[root] > a[small]) {
		temp = a[root];
		a[root] = a[small];
		a[small] = temp;
		heapify(a, n, small);
	}
	return a;
}

int *make_heap(int *a, int n) {

	for (int i = n / 2; i > 0; i--) {
		heapify(a, n, i);
	}
	return a;
}

int sort(int *a, int n) {
	int out[100];
	int n2 = n;


	for (int i = 0; i < n; i++) {
		out[i] = a[1];
		a[1] = a[n2--];
		make_heap(a, n2);
		printf("%d ", out[i]);

	}
	return 0;


}
int main() {
	int input[100];
	int n;
	int *output;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	make_heap(input, n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", input[i]);
	}
	printf("\n");

	sort(input, n);



	return 0;
}