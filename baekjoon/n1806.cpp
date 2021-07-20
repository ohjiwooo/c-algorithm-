#include<iostream>

using namespace std;


int arr[100005];

int main() {


	long long n, m;
	long long sum = 0;
	int answer = 987654321;
	cin >> n >> m;

	for (int i = 0; i < n;i++) {

		cin >> arr[i];
	}

	int s = 0;
	int e = 0;
	sum = arr[s];

	while (s<n && e<n) { 

		if (sum > m  && s != e) {
			if(answer > (e-s+1)) {
				answer = e - s + 1;
			}
			sum -= arr[s++];
		}
		else if (sum==m || (sum > m  && s == e)) {
			if (answer > (e - s + 1)) {
				answer = e - s + 1;
			}
			sum -= arr[s++];
			sum += arr[++e];
		}
		else {
			sum += arr[++e];
		}
	}
	if (answer==987654321) {
		answer = 0;
	}
	cout << answer;
	return 0;
}