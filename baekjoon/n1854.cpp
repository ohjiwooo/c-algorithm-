#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int n, m, k;//����(1000) ���� k��° 
priority_queue <pair<int, int>>q;
vector<pair<int, int>>v[1005];
bool vis[1005];
vector<int> dist[1005];
int a, b, c;


void f(int start) {


	
}
int main() {

	cin >> n >> m >> k;
	while (m--) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}

	
}