#include<stdio.h>
#include<iostream>

using namespace std;
int temp[100];

void merge(int *arr, int start, int mid, int end) {


	int lpoint = start;
	int rpoint = mid + 1;
	int n = start;

	while ((lpoint <= mid) && (rpoint <= end)) {
		if (arr[lpoint] < arr[rpoint]) {
			temp[n++] = arr[lpoint++];
		}
		else {
			temp[n++] = arr[rpoint++];
		}
	}

	while (lpoint <= mid) {
		temp[n++] = arr[lpoint++];
	}
	while (rpoint <= end) {
		temp[n++] = arr[rpoint];
	}
	for (int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}


}



void devide(int *arr, int start, int end) {
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		devide(arr, start, mid);
		devide(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}


}


int main() {

	int n;
	int arr[100];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	devide(arr, 0, n - 1);


	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}