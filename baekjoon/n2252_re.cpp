#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, a, b;
vector<int>v[32005];
vector <int>answer;
int num[32005];
queue <int>q;

int main() {

	
	cin >> n >> m;
	

	for (int i = 0; i <= n; i++) {
		num[i] = 0;
	}
	while (m--) {

		cin >> a >> b; //a가 b앞에
		v[a].push_back(b);
		num[b]++;

	}
	for (int i = 1; i <= n; i++) {

		if (num[i] == 0) {
			q.push(i);
		}
	}

	while (q.empty()!=true) {

		int now = q.front(); q.pop(); //현재학생
		answer.push_back(now);

		for (int i = 0; i < v[now].size();i++) {
			num[v[now][i]]--;
			if (num[v[now][i]]==0) {
				q.push(v[now][i]);
			}
		}
	
	}

	for (int i = 0; i < n;i++) {
		cout << answer[i] << " ";
	}

}