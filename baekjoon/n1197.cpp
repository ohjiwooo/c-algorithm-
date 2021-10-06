#include<iostream>
#include<queue>

using namespace std;
int v, e;
int a, b, c;
int parent[10003];
priority_queue< pair<int, pair<int, int>>>pq;

void init() {

	for (int i = 1; i <= v;i++) {
		parent[i] = i;
	}
}

int find(int a) {

	if (parent[a] == a)return a;
	return parent[a] = find(parent[a]);
}

void uni(int a, int b) {

	int p_a = find(a);
	int p_b = find(b);

	parent[p_a] = p_b;

}

int main() {

	cin >> v >> e;

	while (e--) {
	
		cin >> a >> b >> c;
		pq.push(make_pair(-c, make_pair(a, b)));
	}
	init();
	int answer = 0;
	while (pq.empty()!=true) {
		int w = -pq.top().first; int a = pq.top().second.first; int b = pq.top().second.second; pq.pop();
		if (find(a)!=find(b)) { // 싸이클없음
			answer += w;
			uni(a, b);
		}
	}
	cout << answer;
	return 0;
}