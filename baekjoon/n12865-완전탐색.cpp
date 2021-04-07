#include<iostream>

using namespace std;


int f(int n, int k, int arr[101][2], int nowg, int noww, int now, int answer) {
	for (int i = now; i < n; i++) {
		if (nowg + arr[i][0] <= k) {
			answer = f(n, k, arr, nowg + arr[i][0], noww + arr[i][1], i + 1, answer);
		}
	}
	if (noww > answer) { answer = noww; }
	return answer;
}

int main() {

	int n = 0;
	int k = 0;

	cin >> n >> k;

	int arr[101][2] = { 0, };
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[i][0] = a;
		arr[i][1] = b;
	}

	cout << f(n, k, arr, 0, 0, 0, 0);


	return 0;
}