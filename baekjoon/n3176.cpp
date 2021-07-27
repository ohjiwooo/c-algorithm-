#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
vector <pair<int,int>>v[100005];
int depth[100005];
int p[20][100005];
int minn[20][100005];
int maxx[20][100005];
priority_queue <pair<int, int>> pq;
int n, a, b, c;
int k;

int answer_min;
int answer_max;


void dep(int node,int deep) { 

	depth[node] = deep;

	
	for (int i = 0; i < v[node].size();i++) {

		if (depth[v[node][i].first] != 0) continue; //이미 depth만듬 
		p[0][v[node][i].first] = node; //부모 체크
		minn[0][v[node][i].first] = v[node][i].second;
		maxx[0][v[node][i].first] = v[node][i].second;//min max 초기화
		dep(v[node][i].first, deep + 1);
	}
}

void make_arr() {

	for (int i = 1; i < k;i++) {
		for (int j = 1; j <= n;j++) {
			p[i][j] = p[i - 1][p[i - 1][j]];
			maxx[i][j] = max(maxx[i-1][j], maxx[i - 1][p[i - 1][j]]);
			if (minn[i - 1][p[i - 1][j]]==0) {
				minn[i][j] = minn[i - 1][j];
			}
			else { minn[i][j] = min(minn[i - 1][j], minn[i - 1][p[i - 1][j]]); }
			
		}
	}
}

int lca(int a,int b) {

	

	if (depth[a] > depth[b])swap(a, b);
	answer_max = maxx[0][b];
	answer_min = minn[0][b];
	for (int i = k - 1; i >= 0;i--) { //깊이를 맞춰줌
		if (pow(2,i) <= depth[b]-depth[a]) { 
			answer_min = min(answer_min, minn[i][b]);
			answer_max = max(answer_max, maxx[i][b]);
			b = p[i][b]; //b가 올라감
			
		}
	}
	if (a == b) return a;

	for (int i = k - 1; i >= 0; i--) { 
		if (p[i][a]!=p[i][b]) {
			answer_min = min(answer_min, minn[i][b]);
			answer_min = min(answer_min, minn[i][a]);
			answer_max = max(answer_max, maxx[i][b]);
			answer_max = max(answer_max, maxx[i][a]);
			a = p[i][a]; b = p[i][b]; //부모가 같을때까지 올라감
		}
	}
	answer_min = min(answer_min, minn[0][b]);
	answer_min = min(answer_min, minn[0][a]);
	answer_max = max(answer_max, maxx[0][b]);
	answer_max = max(answer_max, maxx[0][a]);
	return p[0][a];
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n-1;i++) {

		cin >> a >> b >> c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));

	}
	k = 0;
	for (int i = 1; i <= n; i *= 2) {
		k++;
	}

	cin >> a;
	dep(1,1);
	make_arr();

	while (a--) {
		cin >> b >> c;
		lca(b, c);
		cout << answer_min << " " << answer_max << "\n";
		//b,c사이의 최단,최소 거리
	}

	return 0;
}