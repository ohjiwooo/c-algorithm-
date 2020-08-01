#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//선거구 경계는 수정 x 각 선거구 산출 수정
int n;
int map[25][25];
bool vis[25][25] = {false};
int x, y, d1, d2 = 1;
int imap[4] = { -1,0,1,0};
int jmap[4] = { 0,1,0,-1};
int arr[6] = { 0, };
int temp[25][25] = { 0, };
void init() {

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			vis[i][j] = false;
		}
	}for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp[i][j] = 0;
		}
	}
	for (int i = 0; i < 6;i++) {
		arr[i] = 0;
	}
}

void f2() {

	queue<pair<int, int>> qq;
	//1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y

	qq.push(make_pair(1, 1));
	vis[1][1] = true;

	while (qq.empty()!=true) {
		int i = qq.front().first;
		int j = qq.front().second;
		temp[i][j] = 1;
		arr[1]+=map[i][j];
		qq.pop();

		for (int z = 0; z < 4;z++) {
			if (i+imap[z] >=1 && i+imap[z]<=n && j+jmap[z]>=1 && j+jmap[z]<=n) {
				if (i + imap[z] < x + d1 && j + jmap[z] <= y && vis[i + imap[z]][j + jmap[z]] != true) {
					qq.push(make_pair(i+imap[z], j+jmap[z]));
					vis[i+imap[z]][j+jmap[z]] = true;
				}
			}
		}
	}

	//2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N

	qq.push(make_pair(1,y+1));
	vis[1][y + 1] = true;
	while (qq.empty() != true) {
		int i = qq.front().first;
		int j = qq.front().second;
		temp[i][j] = 2;
		arr[2]+=map[i][j];
		qq.pop();

		for (int z = 0; z < 4; z++) {
			if (i + imap[z] >= 1 && i + imap[z] <= n && j + jmap[z] >= 1 && j + jmap[z] <= n) {
				if (i + imap[z] <= x + d2 && j + jmap[z] <= n && vis[i + imap[z]][j + jmap[z]] != true) {
					qq.push(make_pair(i + imap[z], j + jmap[z]));
					vis[i + imap[z]][j + jmap[z]] = true;
				}
			}
		}
	}

	//3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
	if (vis[x+d1][1] != true) {
		qq.push(make_pair(x+d1,1));
		vis[x + d1][1] = true;
	}
	else {
		qq.push(make_pair(x + d1+1, 1));
		vis[x + d1+1][1] = true;
	}

	while (qq.empty() != true) {
		int i = qq.front().first;
		int j = qq.front().second;
		temp[i][j] = 3;
		arr[3]+=map[i][j];
		qq.pop();

		for (int z = 0; z < 4; z++) {
			if (i + imap[z] >= 1 && i + imap[z] <= n && j + jmap[z] >= 1 && j + jmap[z] <= n) {
				if (i + imap[z] <= n && j + jmap[z] < y-d1+d2 && vis[i + imap[z]][j + jmap[z]] != true) {
					qq.push(make_pair(i + imap[z], j + jmap[z]));
					vis[i + imap[z]][j + jmap[z]] = true;
				}
			}
		}
	}
	//4번 선거구 : x + d2 < r ≤ N, y - d1 + d2 ≤ c ≤ N


	qq.push(make_pair(x + d2 + 2, y + d2));
	vis[x + d2 + 2][y + d2] = true;
	while (qq.empty() != true) {
		int i = qq.front().first;
		int j = qq.front().second;
		temp[i][j] = 4;
		arr[4]+=map[i][j];
		qq.pop();

		for (int z = 0; z < 4; z++) {
			if (i + imap[z] >= 1 && i + imap[z] <= n && j + jmap[z] >= 1 && j + jmap[z] <= n) {
				if (i + imap[z] <= n && j + jmap[z] <= n && vis[i + imap[z]][j + jmap[z]] != true) {
					qq.push(make_pair(i + imap[z], j + jmap[z]));
					vis[i + imap[z]][j + jmap[z]] = true;
				}
			}
		}
	}
}

int f() {//경계선
	init();
	int k; 

	k = 0;
	while (k<=d1 && x+k>=1 && x+k<=n && y-k>=1 && y-k<=n ) {
		if (vis[x + k][y - k] != true) {
			temp[x + k][y - k] = 5;
			vis[x + k][y - k] = true;
			arr[5] += map[x + k][y - k];
			k++;
		}
	}//(x, y), (x + 1, y - 1), ..., (x + d1, y - d1)
	k = 0;
	while (k<=d2 && x+k >=1 && x+k<=n && y+k>=1 && y-k<=n) {
		if (vis[x + k][y + k] != true) {
			temp[x + k][y + k] = 5;
			vis[x + k][y + k] = true;
			arr[5] += map[x + k][y + k];
		}
		k++;
	}//(x, y), (x + 1, y + 1), ..., (x + d2, y + d2)
	k = 0; 
	while (k<=d2 && x + d1 + k>=1 && x + d1 + k<=n && y - d1 + k>=1 && y - d1 + k<=n ) {
		if (vis[x + d1 + k][y - d1 + k] != true) {
			temp[x + d1 + k][y - d1 + k] = 5;
			vis[x + d1 + k][y - d1 + k] = true;
			arr[5] += map[x + d1 + k][y - d1 + k];
		}
		k++;
	}//(x + d1, y - d1), (x + d1 + 1, y - d1 + 1), ... (x + d1 + d2, y - d1 + d2)
	k = 0;
	while (k<=d1 && x + d2 + k>=1 && x + d2 + k<=n && y + d2 - k>=1 && y + d2 - k<=n) {
		if (vis[x + d2 + k][y + d2 - k] != true) {
			temp[x + d2 + k][y + d2 - k] = 5;
			vis[x + d2 + k][y + d2 - k] = true;
			arr[5] += map[x + d2 + k][y + d2 - k];
		}
		k++;
	}//(x + d2, y + d2), (x + d2 + 1, y + d2 - 1), ..., (x + d2 + d1, y + d2 - d1)

	f2();//다른지역구 만들고

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			if (vis[i][j]==false) {
				temp[i][j] = 5;
				arr[5]+=map[i][j];
			}
		}
	}//나머지 지역구 채움
	sort(arr, arr + 6);
	return arr[5] - arr[1];
}

int main() {
	int ans = 987665;
	int t;
	cin >> n;
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			cin >> map[i][j];
		}
	}
	
	for (x = 1; x < n;x++) {
		for (y = 1; y < n;y++) {
			for (d1 = 1; d1 < n;d1++) {
				for (d2 = 1; d2 < n;d2++) {
					if (x<x+d1+d2 && x+d1+d2 <= n && y-d1 >=1 && y-d1<y && y<y+d2 && y+d2 <=n) {
						//d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
						t = f();
						if (t < ans) {
							ans = t;
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
