#include<iostream>
#include<algorithm>
using namespace std;

int map[1000003] = { 0, };

int f(int n,int answer) {

	for (int i = 1; i <= n; i++) {

		if (i % 3 == 0 ) {
			if (map[i] == 0) {
				map[i] = map[i / 3] + 1;
			}
			else { 
				map[i] = min(map[i / 3] + 1, map[i]);
			}
		}
		if (i % 2 == 0) {
			if (map[i] == 0) {
				map[i] = map[i / 2] + 1;
			}
			else {
				map[i] = min(map[i / 2] + 1, map[i]); 
			}
		}
		if (i - 1 > 0) {
			if (map[i] == 0) {
				map[i] = map[i - 1] + 1;
			}
			else {
				map[i] = min(map[i - 1] + 1, map[i]);
			}
		}
	}

	return map[n];

}

int main() {

	int n = 0;
	cin >> n;
	cout<<f(n, 0);
	
	return 0;
}