#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;//건물 종류 수 ~500
vector<int>v[505];
int arr[505];
int time[505];
int answer[505];
queue<int>q;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n;i++) {
		int a;
		cin >> a;
		time[i] = a;
		cin >> a;
		while (a != -1) {
			arr[i]++;
			v[a].push_back(i);
			cin >> a;
		}
	
	}

	for (int i = 1; i <= n;i++) {
		if (arr[i] == 0)q.push(i);
	}

	while (q.empty()!=true) {

		int now = q.front(); q.pop();

		for (int i = 0; i < v[now].size();i++) {
			answer[v[now][i]] = max(answer[v[now][i]], answer[now]+time[now]);
			if (--arr[v[now][i]] == 0)q.push(v[now][i]);

		}
	}

	for (int i = 1; i <= n;i++) {
		cout << answer[i] + time[i] << "\n";
	}
	return 0;
}