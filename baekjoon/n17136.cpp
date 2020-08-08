#include<iostream>

using namespace std;

int paper[15][15];
int p[6] = { 0,5,5,5,5,5 };
int n = 0;
int answer = 987654321;

bool check(int ni,int nj,int k) {

	for (int i = ni; i < ni + k;i++) {
		for (int j = nj; j < nj + k;j++) {
			if (paper[i][j] == 0) { return false; }
		}
	}
	return true;
}

void f2(int ni, int nj, int k) {

	for (int i = ni; i < ni + k; i++) {
		for (int j = nj; j < nj + k; j++) {
			paper[i][j] = 0;
		}
	}
}
void f3(int ni, int nj, int k) {

	for (int i = ni; i < ni + k; i++) {
		for (int j = nj; j < nj + k; j++) {
			paper[i][j] = 1;
		}
	}
}

void f(int ans) {

	if (n==0) {
		if (answer>ans) {
			answer = ans;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (paper[i][j]==1) {

				for (int k = 1; k < 6;k++) {
					if (p[k]>0 && i+k<=10 && j+k <=10 && check(i,j,k)==true) {
						f2(i,j,k);
						p[k]--;
						n -= (k*k);
						f(ans + 1);
						p[k]++;
						f3(i,j,k);
						n += (k*k);
					}
				}
				return;
			}
		}
	}

}

int main() {

	for (int i = 0; i < 10;i++) {
		for (int j = 0; j < 10;j++) {
			cin >> paper[i][j];
			if (paper[i][j] == 1) { n++; }
		}
	}

	if (n == 0) { cout << 0; return 0; }
	f(0);
	if (answer == 987654321) { cout << -1; return 0; }
	else { cout << answer; }
	return 0;
}