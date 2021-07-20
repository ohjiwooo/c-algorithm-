#include<iostream>


using namespace std;



int main() {


	int n, m;
	cin >> n >> m;
	int arr[10005];

	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}
	int s = 0; int e = 0;
	int answer = 0;
	int sum = arr[s];

	while (s<n && e<n) {
		
		
		if ( sum== m) {
			answer++;
			sum -= arr[s];
			s++; e++;
			sum += arr[e];
		}
		else if (sum < m) {
			e++;
			sum += arr[e];
		}
		else {//sum > m
			sum -= arr[s];
			s++;
		}
	}

	cout << answer;

}