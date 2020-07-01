#include<iostream>

using namespace std;


typedef struct s {

	int ni;
	int nj;


}s;
int k = 0;
int map[105][105];
int n;
int arr[25][4];
s aa[1000000];
int ei, ej;//타고 올라가는 끝점
int bi,bj;//제일끝
int imap[4] = { -1,0,0,1 };
int jmap[4] = { 0,-1,1,0 };
int imap2[4] = { 0,-1,1,0 };
int jmap2[4] = { 1,0,0,-1 };
int ans = 0;

void find() {

	for (int i = 0; i <= 100;i++) {
		for (int j = 0; j <= 100;j++) {
			if (map[i][j] == 1 && map[i+1][j]==1 && map[i][j+1]==1 && map[i+1][j+1]==1) {
				ans++;
			}
		}
	}

}

void init() {

	for (int i = 0; i < 1000000;i++) {
		aa[i].ni = 0;
		aa[i].nj = 0;
	}
}
void ff(int i,int j,int d) { //find end point

	if (d==0) {
		bi = i; bj = j + 1;
		ei = bi; ej = bj;
	}
	else if (d==1) {
		bi = i - 1; bj = j;
		ei = bi; ej = bj;
	}
	else if (d==2) {
		bi = i; bj = j - 1;
		ei = bi; ej = bj;
	}
	else {
		bi = i + 1; bj = j;
		ei = bi; ej = bj;
	}

}


void turn(int ni,int nj) {
	int a=0;

	for (int i = 0; i < 4;i++) {
		if (ei+imap[i]==ni && ej+jmap[i]==nj) {
			a = i;
			break;
		}
	}

	map[bi + imap2[a]][bj + jmap2[a]] = 1;
	aa[k].ni = bi;
	aa[k++].nj = bj;
	bi += imap2[a]; bj += jmap2[a];
	
}

int main() {

	cin >> n;
	
	for (int i = 0; i < n;i++) {
		cin >> arr[i][0];
		cin >> arr[i][1];
		cin >> arr[i][2];
		cin >> arr[i][3];
	}

for (int i = 0; i < n;i++) {
	
	init();
	k = 0;

	int x = arr[i][0];
	int y = arr[i][1];
	int d = arr[i][2];
	int g = arr[i][3];
		
	

	for (int j = 0; j <= g; j++) {
		ei = bi; ej = bj;
		if (j == 0) {
			ff(y, x, d);
			map[y][x] = 1;
			map[bi][bj] = 1;
			aa[k].ni = y;
			aa[k++].nj = x;
		}
		else {
			int tk = k-1;
			while (tk >=0) {
				int ni = aa[tk].ni;
				int nj = aa[tk].nj;
				turn(ni, nj);
				ei = ni; ej = nj;
				tk--;
			}
		}
	}
}
	find();
	cout << ans;
	return 0;
}