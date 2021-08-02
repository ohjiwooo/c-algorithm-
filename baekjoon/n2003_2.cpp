#include<iostream>

using namespace std;

typedef long long ll;


ll arr[10005];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; ll m;
	cin >> n >> m;

	for (int i = 0; i < n;i++) {
		cin >> arr[i];

	}


	int l = 0; int r = 0; ll sum = arr[l]; ll  answer = 0;

	while (r < n && l<n) {
		if (sum > m) { 
			sum -= arr[l++];
		}
		else if(sum < m){
			sum += arr[++r];
		}
		else {
			answer++; sum -= arr[l++]; sum += arr[++r];
		}
		
	}

	cout << answer;

}