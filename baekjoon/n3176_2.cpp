#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


int n, m;//n 100000
int a, b, c;
int k = 0;
int depth[100002];//�� ����� ���̱��ϱ�
int p[20][100004];
int minn[20][100004];
int maxx[20][100004];
vector<pair<int,int>>v[100004];
int min_answer, max_answer;

void deep(int node, int d) { //�� ����� ����

	depth[node] = d;

	for (int i = 0; i < v[node].size();i++) {
		
		if (depth[v[node][i].first]!=0) {
			continue;
		}
		p[0][v[node][i].first] = node;
		minn[0][v[node][i].first] = v[node][i].second; //�ּ� �ִ��� ���� ������� ����
		maxx[0][v[node][i].first] = v[node][i].second;
		deep(v[node][i].first, d + 1);
	}

}

void parent() {

	for (int i = 1; i < k;i++) {
		for (int j = 1; j <= n;j++) {
			p[i][j] = p[i - 1][p[i - 1][j]];
			maxx[i][j] = max( maxx[i-1][p[i-1][j]], maxx[i-1][j]);

			if (minn[i-1][p[i-1][j]]==0) {
				minn[i][j] = minn[i - 1][j];
			}
			else { 
				minn[i][j] = min(minn[i - 1][p[i - 1][j]], minn[i - 1][j]); 
			}
		}
	}

}

int lca(int a, int b) {

	
	if (depth[a] > depth[b])swap(a, b); //�׻� b�� �� �ؿ�����

	min_answer = minn[0][b];
	max_answer = maxx[0][b];

	for (int i = k - 1; i >= 0; i--) { //���̸� ������
		if (pow(2,i) <= depth[b]-depth[a]) { //�ø��� ������ �ø�

			min_answer = min(min_answer, minn[i][b]);
			max_answer = max(max_answer, maxx[i][b]);
			b = p[i][b];
		}
	}

	if (a == b) { 
		cout << min_answer << " " << max_answer << "\n";
		return 0; } // ����

	for (int i = k - 1; i >= 0;i--) {
		if (p[i][a] != p[i][b]) {

			min_answer = min(min_answer, minn[i][a]);
			min_answer = min(min_answer, minn[i][b]);
			max_answer = max(max_answer, maxx[i][a]);
			max_answer = max(max_answer, maxx[i][b]);
			a = p[i][a]; b = p[i][b];
		}
	}

	min_answer = min(min_answer, minn[0][b]);
	min_answer = min(min_answer, minn[0][a]);
	max_answer = max(max_answer, maxx[0][b]);
	max_answer = max(max_answer, maxx[0][a]);

	cout << min_answer << " " << max_answer << "\n";
	return 0;

}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n-1;i++) {
		cin >> a >> b >> c; // a�� b���̿� ���̰� c�� ����
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	
	}

	for (int i = 1; i <= n; i *= 2) {
		k++;
	}//�θ𰹼� ���ϱ�

	deep(1,1);
	parent();
	cin >> m;

	while (m--) {
	
		cin >> a >> b; //a�� b������ ���� ª�� ����, �� ���� ���
		lca(a, b);
		
	}
	return 0;
}