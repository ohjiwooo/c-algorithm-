#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef struct s {

	int i;
	int j;
	int n;

}s;

int map[15][15];
int n,m;
int num = 0;
int temp[15][15];
int imap[4] = { 0,1,0,-1 };
int jmap[4] = {1,0,-1,0};
queue <s> qq;
vector <s> v2(15);

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

void ff1(int a,int b,int n) {

	

}




int main() {

	cin >>n >> m;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> map[i][j];
			if (map[i][j]!=0 && map[i][j]<6) {
				v2[num].i = i;
				v2[num].j = j;
				v2[num++].n = map[i][j];
			}
		}
	}
	

	



}