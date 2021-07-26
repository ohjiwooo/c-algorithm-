#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<int> v[100005];
int depth[100005];

int p[20][100005];
int n, m, a, b;
int k = 0;//�ִ밪 ���ϱ�

void dep(int node, int deep) {
	depth[node] = deep;
	
	for (int i = 0; i < v[node].size();i++) {
		if (depth[v[node][i]] != 0)continue;
		p[0][v[node][i]] = node; //���� ��� �θ�� ���ݳ��
		dep(v[node][i], deep + 1);
	}

}

void pre() {

	for (int i = 1; i < k;i++) {
		for (int j = 1; j <= n;j++) {
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}

}

int lca(int a,int b) {

	if (depth[a] > depth[b]) swap(a, b);

	for (int i = k - 1; i >= 0;i--) { //depth�����ֱ�
		if ((pow(2,i)) <= depth[b] - depth[a]) b = p[i][b]; //b�� �ö�
	}
	if (a == b)return a; //ã��

	for (int i = k - 1; i >= 0;i--) {
		if (p[i][a]!=p[i][b]) {
			a = p[i][a]; b = p[i][b];
		}
	}
	return p[0][a];
}
int main() {

	//��������� �ؾ���
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	k = 0;
	for (int i = 1; i <= n; i *= 2) {
		k++;
	}

	for (int i = 1; i < n;i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dep(1, 1);
	pre();
	cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << lca(a, b)<<"\n";
	}

	return 0;
}