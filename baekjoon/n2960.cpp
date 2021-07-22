#include<iostream>

using namespace std;



int arr[1005];
bool exist[1005];

int main() {


	int n, k;
	cin >> n >> k;

	for (int i = 0; i < 1005;i++) {
		exist[i] = true;
	}

	for (int i = 2; i <= n;i++) {
		arr[i] = i;
	}
	int kk= 0;
	while (1) {
		int m;
		for (int i = 2; i <= n;i++) {
			if (exist[i]==true) {
				m = i; break;
			}
		}
		exist[m] = false; kk++;
		if (kk == k) {
			cout << m; return 0;
		}
		for (int i = m+1; i <= n; i++) {
			if (i%m==0 && exist[i]==true) { 
				exist[i] = false; kk++;
				if (kk==k) {
					cout << i; return 0;
				}
			}
		}
	}


	return 0;

}