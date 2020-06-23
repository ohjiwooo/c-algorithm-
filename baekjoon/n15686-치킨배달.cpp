#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n;
int m;
int map[55][55];
vector<int> a(13);

typedef struct s {
	int i;
	int j;
}s;

int distance(int i,int j,int i2,int j2) {
	int n = 0;
	int n2 = 0;

	n = i - i2;
	if (n < 0) { n = -n; }

	n2 = j - j2;
	if (n2 < 0) { n2 = -n2; }

	return n + n2;

}

int main() {
	
	queue <s> qq;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) { qq.push({ i, j }); }
		}
	}//ют╥б

	for (int i = 0; i < n; i++) {
		
	}



	return 0;
}