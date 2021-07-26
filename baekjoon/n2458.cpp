#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector <int>v[505];
int num[505];


int main() {

	queue <int>q;
	int n, m,a,b;
	cin >> n >> m;//학생 수, 비교 수

	
	int ans = 0;
	while (m--) {

		cin >> a >> b; //a가 b보다 작음 - a-> b /큰애들 먼저
		v[a].push_back(b);
		num[b]++;
	} 	
	

	for (int i = 1; i <= n;i++) {
		
		int start = i;
		int answer = 0;
		bool vis[505];
		for (int i = 1; i <= n; i++) {
			vis[i] = false;
		}
		q.push(start);
		vis[start] = true;
		
		while (q.empty()!=true) {
			int now = q.front(); q.pop();
			for (int i = 0; i < v[now].size();i++) {
				if (vis[v[now][i]]!=true) {
					q.push(v[now][i]); answer++;
					vis[v[now][i]] = true;
				}
			}
		}

		if (answer+num[start]+1==n) {
			ans++;
		}
	
	}

	
	cout << ans;

	return 0;
}