#include<iostream>

using namespace std;

typedef struct s {

	int nu;//양분
	int tree = 0;//나무 수

}s;

typedef struct ss {

	int i;
	int j;
	int age;

}ss;

int n, m, k;

s map[15][15];
ss tree[120];

int main() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n;j++) {
			cin >> map[i][j].nu;
		}
	}
	for (int i = 0; i < m;i++) {
		cin >> tree[i].i;
		cin >> tree[i].j;
		cin >> tree[i].age;
	}




	return 0;
}