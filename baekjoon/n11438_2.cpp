#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;


int n,m; //n���� ����
int k = 0;//������ �ִ� �θ��� �ִ��
int a, b;
vector <int>v[100005];
int p[20][100005];
int depth[100005];
/*
void deep() {

	queue<int>q;
	int d = 0;
	q.push(1);
	while (q.empty()!=true) {

		int size = q.size();
		d++;
		while (size--) {
			int now = q.front(); q.pop();
			depth[now] = d;
			for (int i = 0; i < v[now].size(); i++) {
				if (depth[v[now][i]] != 0)continue;
				q.push(v[now][i]);
				p[0][v[now][i]] = now;
			}
		}
	}

}
*/
void deep(int d,int node) {

	depth[node] = d;

	for (int i = 0; i < v[node].size();i++) {
		if (depth[v[node][i]] != 0)continue;
		p[0][v[node][i]] = node;
		deep(d+1,v[node][i]);
	}


}

void parent() { //p[a][b] = a�� 2^b��° �θ�

	for (int i = 1; i < k;i++) {
		for (int j = 1; j <= n; j++) {
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}

}

int lca(int a, int b) { //a���� b����� ��������

	if (depth[a] > depth[b]) swap(a, b); // b�� �� �ؿ�����
	
	for (int i = k - 1; i >= 0;i--) { // �ø�
		if (pow(2, i) <= (depth[b] - depth[a])) b = p[i][b];
		
	}

	if (a==b)return a; //ã��

	for (int i = k - 1; i >= 0;i--) {
		if (p[i][a] != p[i][b]) {
			a = p[i][a]; b = p[i][b];
		}
	}

	return p[0][a]; //�θ� ����ä�� break �����Ƿ� �θ� return

}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n-1;i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> m;

	for (int i = 1; i <= n; i *= 2) {
		k++;
	}

	
	deep(1, 1);
	parent();

	while (m--) {

		cin >> a >> b;
		cout << lca(a, b) << "\n";
		
	}

	

	

	return 0;
}