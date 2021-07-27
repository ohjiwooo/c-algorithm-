#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>arr[10005];

int num = 1;
int dis[10005];
bool vis[10005];
bool ans[10005];
vector <int> answer;

int dfs(int node,bool root) {

	dis[node] = num++;
	vis[node] = true;

	int low = dis[node]; //로우점 기록
	int child = 0;

	for (int i = 0; i < arr[node].size();i++) {//인접노드 방문
		int next = arr[node][i];
		if (vis[next] != true) {
			child++;
			int new_low = dfs(next, false); // 인접노드의 low

			if (root == false && dis[node] <= new_low && ans[node]!=true) { 
				answer.push_back(node);//답에추가
				ans[node] = true;
			}
			low = min(low, new_low);
		}
		else {
			low = min(dis[next],low);
		}
	}

	if (root==true && child>1) {
		answer.push_back(node);
		ans[node] = true;
	}

	return low;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); 

	int v, e,a,b;
	cin >> v >> e;

	for (int i = 0; i < e;i++) {
	
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}


	for (int i = 0; i < v;i++) {
		if (vis[i] != true)dfs(i, true);
	
	}
	cout << answer.size() << "\n";
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size();i++) {
		cout << answer[i] << " ";
	}
	return 0;
}