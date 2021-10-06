#include<iostream>
#include<queue>
using namespace std;

int n, m, k;//정점, 간선, 턴의수
int a, b, c;
int p[1002];
priority_queue < pair<int, pair<int, int>>> pq;

void init() {

	for (int i = 1; i <= n;i++) {
		p[i] = i;
	}
}
int find(int a) {

	if (p[a] == a)return a;
	return p[a] = find(p[a]);

}

void uni(int a, int b) {

	int parent_a = find(a);
	int parent_b = find(b);

	p[parent_b] = parent_a;
}
int main() {

	cin >> n >> m >> k;

	for (int i = 0; i < m;i++) {
		cin >> a >> b >> c;
		pq.push(make_pair(c, make_pair(a, b)));

	}

	while (1) {
		int count = 1;
		for (int i = 0; i < m; i++) {

		}
	}
	return 0;

}