#include<iostream>
#include<vector>
using namespace std;


int depth[50003];
int parent[50003][50003];
vector<int> v[50003];

int d(int now,int dep,int p) { //현재노드, 현재깊이,현재부모

	depth[now] = dep;
	parent[now][0] = p;

	for (int i = 0; i < v[now].size();i++) {
		
		if (p == v[now][i]) {
			continue;
		}
		d(v[now][i],dep+1,now);
	}
	return 0;
}

int lca(int a,int b) {




}

int main() {

	int n,m = 0;
	cin >> n;
	int a ,b = 0;
	for (int i = 0; i < n;i++) {
	
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}
	d(1, 1, 1);
	int deep = log2(50000);
	for (int k = 1; k < deep;k++) {
		for (int j = 1; j <= n;j++) {
			if (parent[j][k-1]!=0) {
				parent[j][k] = parent[parent[j][k - 1]][k - 1];
			}

		}
	}

	cin >> m;
	while (m--) {
		cin >> a >> b;
	}

}