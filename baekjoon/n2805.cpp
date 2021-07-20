#include<iostream>


using namespace std;

long long arr[1000005];

int main() {

	int n, m;

	cin >> n >> m;
	int max = 0;
	int e = 0;
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
		if (arr[i]>max) {
			max= arr[i];
		}
	}

	e = max;
	long long s = 0;
	long long sum = 0;
	long long answer = 0;
	long long mid = 0;
	while (s <= e ) {

		mid = (s + e) / 2;
		if (mid == 0)break;
		sum = 0;

		for (int i = 0; i < n;i++) {
			if (arr[i]>mid) {
				sum += arr[i] - mid;
			}
		}

		if (sum >= m) {
			s = mid+1;
			if (answer < mid) {
				answer = mid;
			}
		}
		else {
			e = mid - 1;
		}

	}

	cout<<answer;

}