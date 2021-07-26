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

int uni(int a, int b,int w) { //b가 a보다 w만큼 무거움

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
		if (q=='!') { //일, b가 a보다 w그램 무겁다
			cin >> a >> b >> w;
			uni(a,b,w);
		
		}
		else { //교수님 b가 a보다 w그램 무겁냐
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