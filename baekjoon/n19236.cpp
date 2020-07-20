#include<iostream>
#include<vector>

using namespace std;

int imap[9] = { 0,-1,-1, 0, 1,1,1,0,-1 };
int jmap[9] = { 0,0, -1,-1,-1,0,1,1, 1 };
int ans = 0;

typedef struct s {
	int a;//물고기번호
	int b;//방향
}s;

typedef struct ss {

	int a;
	int i;
	int j;
	int d;

}ss;

typedef struct shark {

	int i;
	int j;
	int d;

}shark;

int compare(ss a, ss b) {

	return a.a < b.a;

}



struct info {

	s map[6][6];
	int score;
	ss fish[17];
	shark sh;

	void fish_move() {


		for (int i = 0; i < 16; i++) {
			if (fish[i].a != -1) {
				int ni = fish[i].i;
				int nj = fish[i].j;
				int nd = fish[i].d;

				for (int f = 0; f < 7; f++) {

					if (map[ni + imap[nd]][nj + jmap[nd]].a != -1 && ni + imap[nd] >= 0 &&
						ni + imap[nd] < 4 && nj + jmap[nd] >= 0 && nj + jmap[nd] < 4) {//경계에 안 닿고 상어가없음

						int k = map[ni][nj].a;
						int k2 = nd;
						map[ni][nj].a = map[ni + imap[nd]][nj + jmap[nd]].a;
						map[ni][nj].b = map[ni + imap[nd]][nj + jmap[nd]].b;
						fish[i].i = ni + imap[nd];
						fish[i].j = nj + jmap[nd];
						fish[i].d = nd;
						map[ni + imap[nd]][nj + jmap[nd]].a = k;
						map[ni + imap[nd]][nj + jmap[nd]].b = k2;//swap
						fish[map[ni + imap[nd]][nj + jmap[nd]].a].i = ni;
						fish[map[ni + imap[nd]][nj + jmap[nd]].a].j = nj;
						
						break;
					}
					nd = (nd + 1) % 9;
				}
			}

			cout << "=============f=========\n";
			for (int i2 = 0; i2 < 4; i2++) {
				for (int j2 = 0; j2 < 4; j2++) {
					cout << map[i2][j2].a << " ";
				}cout << "\n";
			}
		}
	}

	bool shark_move(int i) {
		int t;
		if (sh.i+imap[sh.d]*i >=0 && sh.i+imap[sh.d]*i<4 && sh.j+jmap[sh.d]*i >=0 && sh.j+jmap[sh.d]*i<4 && 
			map[sh.i + imap[sh.d] * i][sh.j + jmap[sh.d] * i].a != -1) {

			int ni = sh.i + imap[sh.d] * i;
			int nj = sh.j + jmap[sh.d] * i;
			
			score += map[ni][nj].a;
			t = map[ni][nj].a;
			map[ni][nj].a = -1;
			map[sh.i][sh.j].a = 0;
			sh.i = ni;
			sh.j = nj;
			sh.d = map[ni][nj].b;

			for (int i = 0; i < 16;i++) {
				if (fish[i].a==t) {
					fish[i].a = -1;
					break;
				}
			}

			if (ans < score) { ans = score; }

			cout << "======================\n";
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					cout << map[i][j].a << " ";
				}cout << "\n";
			}

			return true;

		}
		else { return false; }

	}

};

void dfs(info in) {

	info temp;
	in.fish_move();
	temp = in;

	for (int i = 1; i < 4;i++) {
		if (in.shark_move(i)==true) {
			dfs(in);
			in = temp;
		}
	}
}


int main() {
	int a, b;
	info in;

	for (int i = 0; i < 4;i++) {
		for (int j = 0; j < 4;j++) {
			cin >> a >> b;
			in.map[i][j].a = a;
			in.map[i][j].b = b;
			in.fish[a].d = b;
			in.fish[a].i = i;
			in.fish[a].j = j;
		}
	}
	
	in.fish[0].a = -1;
	in.sh.i = 0;
	in.sh.j = 0;
	in.score = in.map[0][0].a;
	in.sh.d = in.map[0][0].b;
	in.map[0][0].a = -1;
	

	cout << "======================\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << in.map[i][j].a << " ";
		}cout << "\n";
	}

	dfs(in);

	cout << ans;

	return 0;
}