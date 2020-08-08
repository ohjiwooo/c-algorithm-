#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;

int n, m,d;
int map[20][20];
int temp[20][20];
vector <pair<int, int>> v3(3);//±Ã¼öÁÂÇ¥

void init() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = map[i][j];
		}
	}
	temp[0][0] = 0;
}
int dis(int i,int j,int i2,int j2) {

	int ans = 0;
	if (i>i2) {
		ans += i - i2;
	}
	else {
		ans += i2 - i;
	}

	if (j>j2) {
		ans += j - j2;
	}
	else {
		ans += j2 - j;
	}

	return ans;
}

int f() {

	int nn = 0;
	int ans = 0;
	queue <pair<int, int>>qq;

	while (nn<3) {

		int ni = v3[nn].first;
		int nj = v3[nn].second;
		int ans_dis = 987654321;
		int ans_i=0;
		int ans_j=0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

				if (temp[i][j]==1) {
					int nd = dis(ni,nj,i,j);
					if (nd <= d) {
						if (nd < ans_dis) {
							ans_dis = nd;
							ans_i = i;
							ans_j = j;
						}
						else if (nd == ans_dis && j < ans_j) {
							ans_i = i;
							ans_j = j;
						}
					}
				}
			}
		}
		qq.push(make_pair(ans_i,ans_j));
		nn++;
	}

	while (qq.empty()!=true) {
		if (temp[qq.front().first][qq.front().second] == 1) {

			ans++;
			temp[qq.front().first][qq.front().second] = 0;

		}
		qq.pop();
	}
	return ans;
}

void move() {

	for (int i = n; i > 1; i--) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = temp[i - 1][j];
		}
	}
	for (int j = 1; j <= m; j++) {
		temp[1][j] = 0;
	}
}

bool check() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (temp[i][j] == 1) { return false; }
		}
	}

	return true;
}

void p() {

	cout << "====================================\n";
	for (int i = 1; i <=n ; i++) {
		for (int j = 1; j <= m; j++) {
			cout << temp[i][j] << " ";
		}cout << "\n";
	}

}
int main() {

	cin >> n >> m>>d;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m;j++) {
			cin >> map[i][j];
		}
	}

	

	vector<pair<int, int>> v(m);
	vector<int> v2(m);
	int answer = 0;

	for (int i = 0; i < m; i++) {
		v[i].first = n + 1;
		v[i].second = i+1;
		v2[i] = 0;
	}
	for (int i = m - 3; i < m; i++) {
		v2[i] = 1;
	}

	do {
		int k = 0;
		for (int i = 0; i < m; i++) {//±Ã¼öÀÚ¸®
			
			if (v2[i] == 1) {
				v3[k].first = v[i].first;
				v3[k++].second = v[i].second;
			}
		}
		//±¸Çö
		int temp = 0;
		init();

		while (check()==false) {
			temp+=f();
			move();

		}
		if (temp > answer) { answer = temp; }
	} while (next_permutation(v2.begin(), v2.end()));

	cout << answer;
	return 0;
}