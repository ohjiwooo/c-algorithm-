#include<iostream>
using namespace std;

int n;
int plan[20][2];
int ans = 0;

void f(int m,int sum) {

	for (int i = m; i <n ;i++) {
		if (i+plan[i][0]<=n) {//이동가능
			f(i + plan[i][0], sum +plan[i][1]);
		}
	}
	if (ans<sum) {
		ans = sum;
	}
}

int main() {
	
	cin >> n;


	for (int i = 0; i < n;i++) {
		cin >> plan[i][0];
		cin >> plan[i][1];
	}

	for (int i = 0; i < n; i++) {
	
		if (i+plan[i][0] <= n) {
			f(i+plan[i][0],plan[i][1]);//다음이동
		}
	}

	cout << ans;
	return 0;
}