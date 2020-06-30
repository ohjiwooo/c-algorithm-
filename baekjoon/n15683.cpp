#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int map[10][10];
int temp[10][10];
int imap[4] = {0,1,0,-1};
int jmap[4] = {1,0,-1,0};
queue <int> qq;
queue<int> q;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

void w(int ni,int nj) {
	int i2 = ni;
	int j2 = nj;

	while (qq.empty()!=true) {
		int a = qq.front();
		qq.pop();
		int i = a;
		i2 = ni;
		j2 = nj;
		while (i2 + imap[i] >= 0 && i2 + imap[i] < n && j2 + jmap[i] >= 0 && j2 + jmap[i] < m) {
			if (map[i2 + imap[i]][j2 + jmap[i]] == 0) { //빈공간일때
				i2 += imap[i];
				j2 += jmap[i];
				map[i2][j2] = 7;
			}
			else if (map[i2 + imap[i]][j2 + jmap[i]] != 6 && map[i2 + imap[i]][j2 + jmap[i]] != 0) {//cctv일때
				i2 += imap[i];
				j2 += jmap[i];
			}
			else { //벽일때
				break;
			}
		}
	}


}

int f(int a,int ni,int nj) { //종류,죄표

	
	int i2 = ni;
	int j2 = nj;
	int temp[4];
	int ans = 0;
	int temp_ans = 0;

	for (int i = 0; i < 4;i++) {	
		i2 = ni;
		j2 = nj;
		
		while (i2 + imap[i] >= 0 && i2 + imap[i] < n && j2 + jmap[i] >= 0 && j2 + jmap[i] < m) {
			if (map[i2 + imap[i]][j2+jmap[i]]==0) { //빈공간일때
				i2 += imap[i];
				j2 += jmap[i];
				temp_ans++;	
			}
			else if (map[i2 + imap[i]][j2 + jmap[i]] != 6 && map[i2 + imap[i]][j2 + jmap[i]] != 0) {//cctv일때이나 이미 본곳일때-넘어감
				i2 += imap[i];
				j2 += jmap[i];
			}
			else { //벽일때
				break;
			}
		}
		temp[i] = temp_ans;
		temp_ans = 0;
	}

	if (a==1) {
		ans = temp[0];
		qq.push(0);
		if (temp[1]>ans) {
			ans = temp[1];
			qq.pop();
			qq.push(1);
		}if (temp[2] > ans) {
			ans = temp[2];
			qq.pop();
			qq.push(2);
		}if (temp[3] > ans) {
			ans = temp[3];
			qq.pop();
			qq.push(3);
		}
	}
	else if (a==2) {
		ans = temp[1] + temp[3];
		qq.push(1);
		qq.push(3);
		if (temp[0]+temp[2]>ans) {
			ans = temp[0] + temp[2];
			qq.pop();
			qq.pop();
			qq.push(0);
			qq.push(2);
		}
	}
	else if (a==3) {
		ans = temp[3] + temp[0];
		qq.push(3);
		qq.push(0);
		if (temp[1]+temp[0]>ans) {
			ans = temp[1] + temp[0];
			qq.pop();
			qq.pop();
			qq.push(0);
			qq.push(1);
		}
		if (temp[1] + temp[2] > ans) {
			ans = temp[1] + temp[2];
			qq.pop();
			qq.pop();
			qq.push(2);
			qq.push(1);
		}
		if (temp[3] + temp[2] > ans) {
			ans = temp[3] + temp[2];
			qq.pop();
			qq.pop();
			qq.push(2);
			qq.push(3);
		}
	}
	else if (a==4) {
		ans = temp[3] + temp[0]+temp[2];
		qq.push(3);
		qq.push(2);
		qq.push(0);
		if (temp[1] + temp[0]+temp[3] > ans) {
			ans = temp[1] + temp[0]+temp[3];
			qq.pop();
			qq.pop();
			qq.pop();
			qq.push(1);
			qq.push(3);
			qq.push(0);
		}
		if (temp[1] + temp[2]+temp[0] > ans) {
			ans = temp[1] + temp[2]+temp[0];
			qq.pop();
			qq.pop();
			qq.pop();
			qq.push(1);
			qq.push(2);
			qq.push(0);
		}
		if (temp[3] + temp[2] +temp[1]> ans) {
			ans = temp[3] + temp[2]+temp[1];
			qq.pop();
			qq.pop();
			qq.pop();
			qq.push(1);
			qq.push(3);
			qq.push(2);
		}
	}
	else {
		ans = temp[0] + temp[1] + temp[2] + temp[3];
	
		qq.push(1);
		qq.push(3);
		qq.push(0);
		qq.push(2);

	}
	w(ni,nj);
	return ans;
}



int main() {

	cin >> n >> m;
	int ans = 0;
	int num = 0;
	int cnum = 0;
	int aa[8];

	
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> map[i][j];
			temp[i][j] = map[i][j];
			if (map[i][j]==0) {
				num++;
			}
			if (map[i][j]!=6 && map[i][j]!=0) {
				q.push(map[i][j]);
				aa[cnum] = map[i][j];
				cnum++;
			}
		}
	}
	vector <int> v(cnum);
	for (int i = 0; i < cnum;i++) {
		v[i] = aa[i];
	}

	do {
	
		for (int i = 0; i < cnum;i++) {
			
		}
	
	} while (next_permutation(v.begin(),v.end()));


	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]!=6 && map[i][j]!=0 && map[i][j]!=7) {
				int a = map[i][j];
				ans+=f(a, i, j);
			}
		}
	}
	cout <<num - ans;*/

	return 0;
}