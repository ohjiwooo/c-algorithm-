#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v[5002];
queue <pair<int, int>> qu;

int f(int k,int s,int n) {
	queue <int> q;
	q.push(s);
	int answer[5005] = {0,};
	bool vis[5002] = { false, };
	answer[s] = 9876543210;
	q.push(s);
	while (q.empty()!=true) {
		int video = q.front();q.pop();
		vis[video] = true;

		for (int i = 0; i < v[video].size();i++) {
			int video_2 = v[video][i].first; int usado_2 = v[video][i].second;
			if (vis[video_2]==true) {
				continue;
			}
			answer[video_2] = min(answer[video], usado_2);
			q.push(video_2);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n;i++) {
		if (answer[i] >= k && i !=s) {
			ans++;
		}
	}
	return ans;

}
int main() {

	int n = 0; int q = 0;
	int a = 0; int b = 0; int c = 0;
	cin >> n >> q;

	for (int i = 0; i < n-1;i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	for (int i = 0; i < q;i++) {
		cin >> a >> b;
		qu.push(make_pair(a, b));
	}
	while (qu.empty()!=true) {
		cout << f(qu.front().first,qu.front().second,n)<<"\n";
		qu.pop();
	}


}