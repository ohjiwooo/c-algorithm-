#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

typedef struct s {

	int i;
	int j;
	int d;

}s;
int f = 0;
queue <int>qq;
stack <int>ss;
int n, k;
int map[15][15];
vector <int> v[15][15];
s arr[15];
int imap[5] = { 0,0,0,-1,1 };
int jmap[5] = { 0,1,-1,0,0 };



void w(int a,int b,int c,int d,int h) {
	int k = 0;
	int flag = 0;
	int size= v[a][b].size();
	for (int i = 0; i < size; i++) {
		if (v[a][b][i]==h) {
			flag = 1;
			k = i;
		}
		if (flag==1) {
			qq.push(v[a][b][i]);
		}
	}
	for (int i = size-1; i >=k; i--) {
		v[a][b].erase(v[a][b].begin() + i);
	}
	while (qq.empty() != true) {
		int i = qq.front();
		qq.pop();
		v[c][d].push_back(i);
		arr[i].i = c;
		arr[i].j = d;
	}
	if (v[c][d].size() >= 4) {
		f = 1;
		return;
	}

}

	
void red(int a, int b, int c, int d, int h) {
	int k = 0;
	int flag = 0;
	int size = v[a][b].size();
	for (int i = 0; i < size; i++) {
		if (v[a][b][i] == h) {
			flag = 1;
			k = i;
		}
		if (flag == 1) {
			ss.push(v[a][b][i]);
		}
	}
	for (int i = size - 1; i >= k; i--) {
		v[a][b].erase(v[a][b].begin() + i);
	}
	while (ss.empty() != true) {
		int i = ss.top();
		ss.pop();
		v[c][d].push_back(i);
		arr[i].i = c;
		arr[i].j = d;
	}
	if (v[c][d].size()>=4) {
		f = 1;
		return;
	}

}
void blue(int a, int b,int h) {

	if (arr[h].d==1) {
		arr[h].d = 2;
	}
	else if (arr[h].d==2) {
		arr[h].d = 1;
	}
	else if (arr[h].d == 3) {
		arr[h].d = 4;
	}
	else if (arr[h].d == 4) {
		arr[h].d = 3;
	}

	if (a + imap[arr[h].d]<=n && a + imap[arr[h].d] > 0 && b + jmap[arr[h].d] >0 && b + jmap[arr[h].d] <=n) {
		if (map[a + imap[arr[h].d]][b + jmap[arr[h].d]] == 0) {
			w(a, b, a + imap[arr[h].d], b + jmap[arr[h].d], h);
		}
		else if (map[a + imap[arr[h].d]][b + jmap[arr[h].d]] == 1) {
			red(a, b, a + imap[arr[h].d], b + jmap[arr[h].d], h);
		}
	}

}

int main() {

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i].i = a;
		arr[i].j = b;
		arr[i].d = c;
		v[a][b].push_back(i);
	}

	int nn = 1;

	while (nn<=1000) {

		for (int i = 1; i <= k;i++) {
			int a = arr[i].i;
			int b = arr[i].j;
			int c = arr[i].d;
			if (a + imap[c]>0 && a + imap[c] <=n &&b + jmap[c]>0 && b + jmap[c] <= n) {
				if (map[a + imap[c]][b + jmap[c]] == 0) {//white
					w(a, b, a + imap[c], b + jmap[c], i);
					if (f == 1) {
						cout << nn;
						return 0;
					}
				}
				else if (map[a + imap[c]][b + jmap[c]] == 1) {//red
					red(a, b, a + imap[c], b + jmap[c], i);
					if (f == 1) {
						cout << nn;
						return 0;
					}
				}
				else if (map[a + imap[c]][b + jmap[c]] == 2) {//blue
					blue(a, b, i);
					if (f == 1) {
						cout << nn;
						return 0;
					}
				}
			}
			else {
				blue(a, b, i);
				if (f == 1) {
					cout << nn;
					return 0;
				}
			}
		}
		nn++;
	}
	cout << -1;
	return 0;
}