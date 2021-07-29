#include<iostream>


using namespace std;

long long map[1030][1030];

int sum(int i1,int j1, int i2, int j2) {

	int answer = 0;
	if (i1 > i2)swap(i1, i2); //i2가 더 크게
	if (j1 > j2)swap(j1, j2);//j2가 더 크게
	answer = map[i2][j2] - map[i1-1][j2] - map[i2][j1-1] + map[i1-1][j1-1];
	return answer;
}

void input(int a,int b,int c) {

	map[a][b] = map[a][b - 1] + map[a - 1][b] - map[a - 1][b - 1]+c;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m,a,b,c,d;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;
			input(i, j, a);
		}
	}
	while (m--) {
	
		cin >> a >> b >> c >> d;
		cout << sum(a, b,c, d)<<"\n";
	
	}

}