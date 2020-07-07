#include<iostream>
using namespace std;

typedef struct s{
	int s; //속력
	int d; //방향
	int z; //크키
}s;
int ans = 0;
int r, c, m;
s map[105][105];
s temp[105][105];
int imap[5] = {0,-1,1,0,0};
int jmap[5] = {0,0,0,1,-1};

void init_map() {

	for (int i = 1; i <= r;i++) {
		for (int j = 1; j <= c;j++) {
			map[i][j] = temp[i][j];
		}
	}

}

void init_temp() {

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			temp[i][j].d = 0;
			temp[i][j].s = 0;
			temp[i][j].z = 0;
		}
	}

}

void fisher(int i) { //fisher's catching fish

	for (int j = 1; j <= r;j++) {
		
		if (map[j][i].z != 0) {
			ans += map[j][i].z;
			map[j][i].s = 0;
			map[j][i].d = 0;
			map[j][i].z = 0;
			return;
		}
	}
	
}

void fish_move(int ni,int nj,int temp_s) {

	int fr = ni;
	int fc = nj;
	int s = temp_s;;
	int d = map[ni][nj].d;
	int z = map[ni][nj].z;

	if (d==1 || d==2) {

		for (int i = 0; i < temp_s; i++) {

			if (ni + imap[d] < 1) {//change d				
				d = 2;
				ni += imap[d];
			}
			else if (ni + imap[d] > r) {//change d
				d = 1;
				ni += imap[d];
			}
			else {
				ni += imap[d];
			}
		}
	}
	else {
		for (int i = 0; i < temp_s; i++) {

			if (nj + jmap[d] < 1) {//change d				
				d = 3;
				nj += jmap[d];
			}
			else if (nj + jmap[d] > c) {//change d
				d = 4;
				nj += jmap[d];
			}
			else {
				nj += jmap[d];
			}
		}
	}

	if (z>temp[ni][nj].z || temp[ni][nj].z==0) {
		temp[ni][nj].d = d;
		temp[ni][nj].s = temp_s;
		temp[ni][nj].z = z;	
	}
	map[fr][fc].d = 0;
	map[fr][fc].s = 0;
	map[fr][fc].z = 0;

}

void fish() {//movement of fish

	for (int i = 1; i <= r;i++) {
		for (int j = 1; j <= c;j++) {
			if (map[i][j].z!=0) { //fish exist
				int temp_s;
				if (map[i][j].d==1 || map[i][j].d==2) {
					temp_s = (map[i][j].s % ((r - 1) * 2));
				}
				else {
					temp_s = (map[i][j].s % ((c - 1) * 2));
				}//new z
				fish_move(i,j,temp_s);
			}
		}
	}
/*	cout << "================================\n";
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << temp[i][j].z << " ";
		}cout << "\n";
	}*/
	init_map();
	init_temp();
}

int main() {

	cin >> r >> c >> m;

	for (int i = 0; i < m;i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;

		map[a][b].s = c;
		map[a][b].d = d;
		map[a][b].z = e;

	}

	for (int i = 1; i <= c;i++) { //moving fisher
		
		fisher(i);
		fish();

	}

	cout << ans;
	return 0;
}