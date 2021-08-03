#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
vector<int>a;
vector<int>b;
int arr_a[1005];
int arr_b[1005];
int n_a, n_b;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	
	cin >> n_a;
	for (int i = 0; i < n_a;i++) {
		cin >> arr_a[i];
	}
	cin >> n_b;
	for (int i = 0; i < n_b; i++) {
		cin >> arr_b[i];
	}

	//부분합 구하기
	int sum = 0;
	for (int i = 0; i < n_a;i++) {
		sum = arr_a[i];
		a.push_back(sum);
		for (int j = i+1; j < n_a;j++) {
			sum += arr_a[j];
			a.push_back(sum);
		}
	}

	for (int i = 0; i < n_b; i++) {
		sum = arr_b[i];
		b.push_back(sum);
		for (int j = i + 1; j < n_b; j++) {
			sum += arr_b[j];
			b.push_back(sum);
		}
	}

	sort(b.begin(), b.end()); // b 정렬
	ll answer = 0;
	for (int i = 0; i < a.size();i++) {
		
		int diff = t - a[i];
		int lower = lower_bound(b.begin(), b.end(), diff)-b.begin();
		int upper = upper_bound(b.begin(), b.end(), diff)-b.begin();
		
		answer += (upper - lower);
	}
	
	cout << answer;

	return 0;
}