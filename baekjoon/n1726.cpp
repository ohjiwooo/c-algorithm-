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
int ni, nj, nd,ansi, ansj, ansd;
int imap[5] = {0,0,0,1,-1};
int jmap[5] = {0,1,-1,0,0};
bool vis[150][150][6];

void bfs() {

	queue <s> t;
	queue <s> g;
	t.push({ ni,nj,nd,0 });
	int ss = 0;
	while (1) {

		while (t.empty()!=true) {
			int i = t.front().i;
			int j = t.front().j;
			int d = t.front().d;
			int a = t.front().ans;
			t.pop();
			if (i == ansi && j == ansj && d == ansd) { cout << a; return; }
			for (int k = 1; k <= 4; k++) {
				if (vis[i][j][k] != true) {
					vis[i][j][k] = true;
					if (d==k) {
						g.push({ i, j, k, a });
					}
					else if ((d == 1 && k == 2) || (d == 2 && k == 1) || (d == 3 && k == 4) || (d == 4 && k == 3)) {
						g.push({ i, j, k, a + 2 });
					}
					else { g.push({ i, j, k, a + 1 }); }
				}
			}
		}
		int size = g.size();
		for (int nn = 0; nn < size; nn++) {
			int i = g.front().i;
			int j = g.front().j;
			int d = g.front().d;
			int a = g.front().ans;
			g.pop();
			if (a==ss &&i == ansi && j == ansj && d == ansd) { cout << a; return; }
			int k = 1;
			if (a == ss) {
				while (i + imap[d] * k > 0 && i + imap[d] * k <= m && j + jmap[d] * k > 0 && j + jmap[d] * k <= n && map[i + imap[d] * k][j + jmap[d] * k] == 0
					&& k<=3) {
					t.push({ i + imap[d] * k,j + jmap[d] * k,d,a + 1 });
					k++;
				}
			}
			else {
				g.push({ i, j, d, a }); 
			}
		}
		ss++;
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