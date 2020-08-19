#include<iostream>
#include<queue>
using namespace std;

typedef struct s {

	int i;
	int j;
	int d;
	int ans = 0;
}s;

int m,n;
int map[150][150];
int ni, nj, nd;
int ansi, ansj, ansd;
int imap[5] = {0,0,0,1,-1};
int jmap[5] = {0,1,-1,0,0};
bool vis[150][150][5];

void bfs() {

	queue <s> t;
	queue <s> g;
	t.push({ ni,nj,nd,0 });
	g.push({ ni,nj,nd,0 });
	int ts=t.size();
	while (1) {
		while(g.empty()!=true) {
			int i = g.front().i;
			int j = g.front().j;
			int d = g.front().d;
			int a = g.front().ans;
			g.pop();
			int k = 1;
			int temp;
			vis[i][j][d] = true;
			while (i + imap[d] * k > 0 && i + imap[d] * k <= m && j + jmap[d] * k > 0 && j + jmap[d] * k <= n && map[i + imap[d] * k][j + jmap[d] * k] == 0) {
				t.push({ i + imap[d] * k,j + jmap[d] * k,d,a + 1 });
				k++;
			}
		}
		for (int k = 0; k < ts; k++) {
			int i = t.front().i;
			int j = t.front().j;
			int d = t.front().d;
			int a = t.front().ans;
			t.pop();

			for (int k = 1; k <= 4; k++) {
				if (i == ansi && j == ansj && k == ansd && k==d) { 
					cout << a; return; }
				else if (i == ansi && j == ansj && k == ansd && ((d == 1 && k == 2) || (d == 2 && k == 1) || (d == 3 && k == 4) || (d == 4 && k == 3))) {
					cout << a+2; return;
				}
				else if (i == ansi && j == ansj && k == ansd && k != d) { 
					cout << a+1; return; }

				if (i + imap[k] > 0 && i + imap[k] <= m && j + jmap[k] > 0 && j + jmap[k] <= n && map[i + imap[k]][j + jmap[k]] == 0 && vis[i][j][k] != true) {
					vis[i][j][k] = true;
					if ((d == 1 && k == 2) || (d == 2 && k == 1) || (d == 3 && k == 4) || (d == 4 && k == 3)) {
						t.push({ i, j, k, a+1 });
						vis[i][j][k] = false;
					}
					else { g.push({ i, j, k, a + 1 }); }
				}
			}
		}ts = t.size();
	}
}

int main() {

	cin >> m >> n;
	for (int i = 1; i <= m;i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> ni >> nj >> nd >> ansi >> ansj >> ansd;
	bfs();
	return 0;
}