#include<iostream>
#include<vector>
using namespace std;


int parents[50002];
int depth[50002];
vector <int> v[50003];

int search(int now, int d,int p) { //현재노드, 현재 depth,현재 노드의 부모노드

	parents[now] = p;
	depth[now] = d;

	for (int i = 0; i < v[now].size();i++) {
		if (v[now][i]==p) {
			continue;
		}
		search(v[now][i],d+1,now);
	}

	return 0;
}

int lca(int a,int b) {

	int depth_a = depth[a];
	int depth_b = depth[b];

	while (depth_a > depth_b) {
		
		a = parents[a];
		depth_a--;
	
	}
	while (depth_b > depth_a) {
		b = parents[b];
		depth_b--;
	}
	while (a!=b) {
		a = parents[a];
		b = parents[b];
	
	}

	return a;
}

int main() {


	int n = 0; int m = 0; int a = 0; int b = 0;
	cin >> n;

	int i = n-1;
	while (i--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	search(1, 1, 0);
	cin >> m;

	while (m--) {
	
		cin >> a >> b;
		cout << lca(a, b) << "\n";

	}



	return 0;
}