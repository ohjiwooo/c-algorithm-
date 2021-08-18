#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int v, e;//노드 50000  간선 200000
//vector <pair<int, int>>v[50005];
vector<pair<int, pair<int, int>>>arr;
priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, int>>map[50002];
int a, b, c;
int p[50005];

void init() {
	
	for (int i = 1; i <= v;i++) {
		p[i] = i;
	}
	

}

int find(int a) {

	if (p[a] = a)return a;

	return p[a] = find(p[a]);
}
void uni(int a, int b) {

	int p_a = find(a);
	int p_b = find(b);

	p[p_b] = p_a;

}

int main() {

	cin >> v >> e;
	long long answer = 0;
	
	for (int i = 0; i < e;i++) {
	
		cin >> a >> b >> c;
		pq.push(make_pair(-c, make_pair(a, b)));
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	
	}
	int root;
	while (pq.empty()!=true) { //mst 생성

		int w = -pq.top().first; int a = pq.top().second.first; int b = pq.top().second.second;
		pq.pop();
		
		if (find(a) != find(b)) {
			uni(a, b); answer += w; root = p[a];
		}
	
	}

	while (1) {
	
		for (int i = 1; i <= v;i++) {
			
			for (int j = 0; j < map[i].size();j++) {
				
				if (i == j || p[j] == root)continue; //선택되지 않은 자식만 대상


			}
		
		}
	
	}


	return 0;
}