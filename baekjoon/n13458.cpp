#include<iostream>
using namespace std;


int n;
int a[1000005];
int t1;
int t2;
long long ans = 0;

void f1() {//각방마다 총감독관 한명씩 
	int i = 0;
	while (i<n) {
		if (a[i]-t1 >0) {
			a[i] = a[i] - t1;
			ans++;
		}
		else {
			a[i] = 0;
			ans++;
		}
		i++;
	}
	
}

void f2() {

	int i = 0;
	while (i < n) {
		if (a[i]!=0) {
			if (a[i] % t2 > 0) {
				ans += (a[i] / t2 + 1);
			}
			else {
				ans += (a[i] / t2);
			}
		}
		i++;
	}

}
int main() {

	cin >> n;

	for (int i = 0; i < n;i++) {
		cin >> a[i];
	}

	cin >> t1 >> t2;

	f1();
	f2();

	cout << ans;

	return 0;
}