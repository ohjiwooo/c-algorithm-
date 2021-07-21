#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> top;
vector<int> bottom;

int n, h;//길이, 높이
int t[500004];
int b[500004];
int answer[500004];

void pre() {

	for (int i = 0; i < n / 2; i++) {
		b[bottom[i]]++;
	}
	for (int i = n / 2 - 2; i >= 0 / 2; i--) {
		b[i] =+ b[i + 1];
	}
	for (int i = 0; i < n / 2; i++) {
		t[h-top[i]]++;
	}
	for (int i = 1; i < n / 2;i++) {
		t[i] =+ t[i - 1];
	}


}


int main() {

	cin >> n >> h;


	for (int i = 0; i < n;i++) {
		int a;
		cin >> a;
		if (i%2==0) {
			bottom.push_back(a);
		}
		else {
			top.push_back(a);
		}
	}


	pre();//각각의 높이별 누적합
	
	for (int i = 1; i < h; i++) {
		answer[i] = t[i] + b[i]; //각 높이로 날때 부딪히는 돌 수
	}
	sort(answer, answer + h);
	int ans = 1;
	int i = 2;
	while (answer[i]==answer[i-1]) {
		ans++;
	}
	cout << answer[1] << " " << ans;

	return 0;
}