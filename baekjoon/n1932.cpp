#include<iostream>
#include<algorithm>
using namespace std;
int arr[505][505];


int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		for (int j = 1; j <= i+1;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i < n;i++) {
		for (int j = 1; j <= i+1;j++) {
			arr[i][j] = max(arr[i - 1][j]+arr[i][j], arr[i][j]+arr[i - 1][j - 1]);
		}
	
	}
	int answer = arr[n - 1][1];
	for (int i = 2; i <= n;i++) {
		if (answer < arr[n - 1][i])answer = arr[n - 1][i];
	}
	cout << answer;
	return 0;
}