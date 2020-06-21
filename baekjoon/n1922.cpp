#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

typedef struct s {

	int a;
	int b;
	int w;


}s;

int ans = 0;
int n, m;// 컴퓨터수 , 연결수
s in[100005];
int p[1005];
queue <pair<int, int>> qq;
bool compare(s a,s b) {

	return a.w < b.w;
}


int find(int k) {

	if (k == p[k]) {
		return k;
	}
	else { return p[k]=find(p[k]); }

}

void uni(int n , int m) {
	int np = find(n);
	int mp = find(m);

	if (np == mp) {
	
		return;
	}
	else {
		p[np] = mp;
	}
	
}
int main() {

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
			cin >> in[i].a;
			cin >> in[i].b;
			cin >> in[i].w;
	}

	for (int i = 1; i <= n; i++) {

		p[i] = i;

	}

	
	sort(in,in+m+1,compare);
	
	for (int i = 1; i <= m; i++) {
		if (find(in[i].a) != find(in[i].b)) {
			ans += in[i].w;
			uni(in[i].a, in[i].b);
		}
	}

	cout<< ans;

	return 0;
}