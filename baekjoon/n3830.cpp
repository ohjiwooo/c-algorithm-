#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
int p[100005];
ll dist[100005];
int n, m, a, b, w;
char q;


void init(int n) {

	for (int i = 1; i <= n;i++) {
		p[i] = i;
	
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = 0;

	}
}

int find(int a) {
	if (p[a]==a) {
		return a;
	}
	else {
		int tmp = find(p[a]);
		dist[a] += dist[p[a]];
		return p[a] = tmp;
	}
}


void uni(int a, int b,int w) { //b�� a���� w��ŭ ���ſ�

	int a_p = find(a);
	int b_p = find(b);

	if (a_p == b_p)return;
	dist[a_p] = ((w + dist[b])-dist[a]);//�θ��� ���� �����ϸ� �������� find�� ������
	p[a_p] = b_p;
	

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	
	while (n != 0 && m != 0) {

		init(n);

		while (m--) {
			cin >> q;
			if (q == '!') { //��, b�� a���� w�׷� ���̴�
				cin >> a >> b >> w;
				uni(a, b, w);

			}
			else { //������ b�� a���� w�׷� ���̳�
				cin >> a >> b;
				if (find(a) != find(b)) {
					cout << "UNKNOWN\n";

				}
				else {
					cout <<dist[a] - dist[b] << "\n";
				}
			}
		}
		cin >> n >> m;
	}
	return 0;
}