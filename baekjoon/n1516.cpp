#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>v[505];
int dist[505];
int num[505];
int n, a;
int ans[505];
queue <int>q;

int main() {

	
	cin >> n;

	for (int i = 1; i <= n;i++) {
		cin >> a; dist[i] = a;
		cin >> a;
		while (a!=-1) {
			v[a].push_back(i); //a가 먼저 지어저야함
			num[i]++;
			cin >> a;
		}
	}

	for (int i = 1; i <= n;i++) {
		if (num[i]==0) {
			q.push(i);
		}
	}
	
	while (q.empty() != true) {
	
			int now = q.front(); q.pop();
			ans[now] += dist[now];
			for (int i = 0; i < v[now].size(); i++) {
				ans[v[now][i]] = max(ans[v[now][i]],ans[now]);
				if (--num[v[now][i]] == 0) {
					q.push(v[now][i]);
				}
			}
		
	}
	for (int i = 1; i <= n;i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}