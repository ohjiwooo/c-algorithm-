#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,pair<int, int>>>v;//w,(a,b)
int p[1005];

void init(int n) {

	for (int i = 1; i <= n;i++) {
		p[i] = i;
	}
}

int find(int a) {

	if (p[a] == a)return a;
	else {
		return p[a] = find(p[a]);
	}

}
void uni(int a,int b) {

	int pa = find(a);
	int pb = find(b);

	p[pa] = pb;

}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int num = 0;
	int n, m,a,b,w; //컴퓨터의 수, 간선의 수
	cin >> n >> m;

	for (int i = 0; i < m;i++) {
		cin >> a >> b >> w;
		v.push_back(make_pair(w, make_pair(a, b)));
	}
	init(n);
	sort(v.begin(), v.end());
	long long answer = 0;
	for (int i = 0; i < m;i++) { //사이클 거르면 알아서 끝남
		int w = v[i].first; int a = v[i].second.first; int b = v[i].second.second;
		if (find(a)!=find(b)) { //사이클 아님
			uni(a, b);
			answer += w;
		}
	}
	cout << answer;


	return 0;
}