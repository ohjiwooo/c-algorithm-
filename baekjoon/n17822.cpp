#include<iostream>
#include<queue>
using namespace std;

typedef struct s {
	int x;
	int d;
	int k;
}s;

int n, m, t;//원판의갯수,적힌 숫자의 수, 돌리는횟수
int arr[55][55];
int arr2[55][3];
bool vis[55][55];
queue < pair<int, int >> qq;
int imap[4] = { -1,0,1,0 };
int jmap[4] = { 0,1,0,-1 };
int flag = 0;
void init() {

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = false;
		}
	}
}
void turn(int x,int d,int num) {// x배수원을 d방향으로 n번

	int k = x;
	int k2 = 1;

	while (k*k2<=n) {
		k *= k2;
		if (d == 0) {//시계방향
			for (int i = 0; i < num; i++) {
				int a = arr[k][m - 1];
				for (int j = m-1; j >0; j--) {
					arr[k][j] = arr[k][j-1];
				}
				arr[k][0] = a;
			}
		}
		else {
			for (int i = 0; i < num; i++) {
				int a = arr[k][0];
				for (int j = 0; j < m - 1; j++) {
					arr[k][j] = arr[k][j + 1];
				}
				arr[k][m - 1] = a;
			}
		}
		k2++;
		k = x;

		cout << "===============================\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}cout << "\n";
		}
	}

	
}

bool ff() {
	int ans = false;
	int f = 0;
	for (int i = 1; i <= n;i++) { 
		for (int j = 0; j < m;j++) {
			if (vis[i][j]!=true && arr[i][j]!=-1) {
				qq.push(make_pair(i, j));
				vis[i][j] = true;
			}
			f = 0;
			while (qq.empty()!=true) {
				int ni = qq.front().first;
				int nj = qq.front().second;
				qq.pop();

				for (int i2 = 0; i2 < 4; i2++) { //안쪽
					if (ni + imap[i2] > 0 && ni + imap[i2] <= n && nj + jmap[i2] >= 0 && nj + jmap[i2] < m 
						&& arr[ni][nj] == arr[ni + imap[i2]][nj + jmap[i2]] && vis[ni + imap[i2]][nj + jmap[i2]] != true) {
						qq.push(make_pair(ni + imap[i2], nj + jmap[i2]));
						vis[ni + imap[i2]][nj + jmap[i2]] = true;
						ans = true;
						f = 1;
					}
					else if (nj + jmap[i2] < 0 && arr[ni][nj] == arr[ni+imap[i2]][m-1] && vis[ni + imap[i2]][m - 1]!=true) {
						qq.push(make_pair(ni+imap[i2],m-2));
						vis[ni + imap[i2]][m - 1] = true;
						ans = true;
						f = 1;
					}
					else if (nj + jmap[i2] > m-1 && arr[ni][nj] == arr[ni+imap[i2]][0] && vis[ni + imap[i2]][0] != true) {
						qq.push(make_pair(ni + imap[i2], 0));
						vis[ni + imap[i2]][0] = true;
						ans = true;
						f = 1;
					}
				}
				if (f == 1) { arr[ni][nj] = -1; }
			}
		}
	}
	return ans;
}

void ff2() {

	int sum = 0;
	int nn = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]!= -1) {
				sum += arr[i][j];
				nn++;
			}
		}
	}
	if (sum == 0) { flag = 1; return; }
	float a = sum / nn;
	if (sum%nn > 0) { a += 0.5; }

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]!= -1 && arr[i][j]<a) {
				arr[i][j] += 1;
			}else if (arr[i][j] != -1 && arr[i][j] > a) {
				arr[i][j] -= 1;
			}
		}
	}
}

int answer() {

	int sum = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			
			if (arr[i][j]!= -1) { sum += arr[i][j]; }
		}
	}

	return sum;
}
int main() {

	cin >> n >> m >> t;
	for (int i = 1; i <= n;i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			arr[i][j] = a;
		}
	}

	for (int i = 1; i <= t;i++) {
		cin >> arr2[i][0] >> arr2[i][1] >> arr2[i][2];
	}

	for (int i = 1; i <= t;i++) {

		turn(arr2[i][0],arr2[i][1],arr2[i][2]);
		init();
		if (ff() == false) {
			ff2();
			if (flag == 1) { cout << 0; return 0; }
		}
		cout << "===============================\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}cout << "\n";
		}
		

	}
	cout << answer();
	return 0;
}