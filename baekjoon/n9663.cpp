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

	for (int i = 1; i < row; i++) {
		if (q[i]==q[row] || (p(i-row)==p(q[i]-q[row]))) {//������ ���
			return false;
		}
		else { return true; }
	
	}
}

int backtracking(int row) { //����ο�,�Է¹��� n

	for (int i = 1; i <= n; i++) {
	
		q[row] = i;
		if (pos(i) == true) {
			backtracking(++row);
		}
	
	}

}

int main() {

	cin >> n;
	backtracking(1);

	return 0;
}