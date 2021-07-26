#include<iostream>
#include<vector>

using namespace std;

int p[100005];
int dist[100005];

void init(int n) {

	for (int i = 1; i <= n;i++) {
		p[i] = i;
	
	}

}

int find(int a) {
	if (p[a]==a) {
		return a;
	}
	else {
		dist[a] += dist[p[a]];
		return p[a] = find(p[a]);
	}
}

int uni(int a, int b,int w) { //b�� a���� w��ŭ ���ſ�

	int a_p = find(a);
	int b_p = find(b);

	dist[b] = dist[b_p] + w;
	p[b_p] = a_p;


}
int main() {


	int n, m,a,b,w;
	char q;
	cin >> n >> m;

	
	while (n !=0 && m != 0) {
		
		init(n);


		cin >> q;
		if (q=='!') { //��, b�� a���� w�׷� ���̴�
			cin >> a >> b >> w;
			uni(a,b,w);
		
		}
		else { //������ b�� a���� w�׷� ���̳�
			cin >> a >> b;
			if (find(a)!=find(b)) {
				cout << "UNKNOWN\n";
			
			}
			else {
				cout << dist[b] - dist[a]<<"\n";

		}

	
		cin >> n >> m;
	}


	return 0;
}