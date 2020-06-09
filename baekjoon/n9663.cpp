#include<iostream>

using namespace std;


int q[20] = { 0 };
int n;
int ans = 0;

int p(int a) {
	if (a < 0) { return -a; }
	else { return a; }
}

bool pos(int row) {

	for (int j = 1; j < row; j++) {
		if ( (q[j] == q[row]) || ( p(j-row) == p(q[j]-q[row]) )) {//못놓는 경우
			return false;
		}
		else { return true; }
	
	}
}

int backtracking(int row) { //현재로우,입력받은 n
	
	if (row == n+1) {
		ans++;
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
	
		q[row] = i;
		if (pos(i) == true) {
			backtracking(row+1);
		}
	
	}
	return ans;
}

int main() {

	cin >> n;
	
	cout << backtracking(1);
	
	return 0;
}