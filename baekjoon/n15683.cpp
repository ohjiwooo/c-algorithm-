#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int map[15][15];
int n,m;
int num = 0;
int temp[15][15];
queue <pair<int, int>> qq;
vector <pair<int, int>> v2(15);

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

int main() {

	cin >>n >> m;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> map[i][j];
			if (map[i][j]!=0 && map[i][j]<6) {
				v2[num].first = i;
				v2[num++].second = j;
			}
		}
	}
	vector <int>v(num);
	
	for (int i = 0; i < num;i++) {
		v[i] = i;
	}

	do{

		for (int i = 0; i < num;i++) {
			
		}

	}while (next_permutation(v.begin(), v.end()));



}