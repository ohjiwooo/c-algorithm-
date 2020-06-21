#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct s {

	int a;
	int b;
	int w;

}s;

int n, m;
s arr[1000005];
int p[100005];
vector <int> ans;
int answer = 0;

bool compare(s a,s b) {

	return a.w < b.w;
}

bool cmp(int a,int b) {

	return a > b;
}

int find( int k) {

	if (k == p[k]) { return k; }
	else { return p[k] = find(p[k]); }

}

void uni(int a,int b) {
	int ap = find(a);
	int bp = find(b);

	if (ap==bp) {
		return;
	}
	else {
		p[ap] = bp;
	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m;i++) {

		cin >> arr[i].a;
		cin >> arr[i].b;
		cin >> arr[i].w;

	}

	sort(arr, arr + m,compare);

	for (int i = 1; i <= n;i++) {
		p[i] = i;
	}

	for (int i = 0; i < m; i++) {

		if (find(arr[i].a) != find(arr[i].b)) {
			answer += arr[i].w;
			uni(arr[i].a,arr[i].b);
			ans.push_back(arr[i].w);
		}
	}

	sort(ans.begin(),ans.end(),cmp);
	answer -= ans[0];
	cout << answer;
	return 0;
}