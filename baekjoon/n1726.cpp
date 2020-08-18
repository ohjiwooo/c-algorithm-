#include<iostream>

using namespace std;

int m,n;
int map[150][150];
int ni, nj, nd;
int ansi, ansj, ansd;
int imap[5] = {0,0,0,1,-1};
int jmap[5] = {0,1,-1,0,0};
int answer = 987654321;

void go(int i, int j, int d, int ans);

void turn(int i, int j, int d, int ans,int dd) {

	for (int k = 1; k <= 4; k++) {
		if (i == ansi && j == ansj && k == ansd) {//answer
			if (d == k) {
				if (ans < answer) { answer = ans; return; }
			}
			else {
				if (ans + 1 < answer) { answer = ans + 1; return; }
			}
		}

		if (i+imap[k] > 0 && i+imap[k] <= m && j+jmap[k] > 0 && j+jmap[k] <= n && map[i + imap[k]][j + jmap[k]] == 0 && k != dd) {
			
			if ((d==1 && k==2) || (d==2 && k==1) || (d==3 && k==4) || (d==4 && k==3)) {
				go(i, j, k, ans+2 );
			}
			else if (d==k) { go(i, j, k, ans); }
			else { go(i, j, k,ans+1); }

		}
	}
}

void go(int i, int j, int d, int ans) {
	int k = 1;
	int temp;
	if (d == 1) { temp = 2; }
	else if (d == 2) { temp = 1; }
	else  if (d == 3) { temp = 4; }
	else { temp = 3; }
	while (i + imap[d] * k > 0 && i + imap[d] * k <= m && j + jmap[d] * k > 0 && j + jmap[d] * k <= n && map[i + imap[d] * k][j + jmap[d] * k] == 0) {
	
		turn(i + imap[d] * k, j + jmap[d] * k, d, ans + 1, temp);//Á÷Áø
		k++;
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
	turn(ni,nj,nd,0,7);
	cout << answer;
	return 0;
}