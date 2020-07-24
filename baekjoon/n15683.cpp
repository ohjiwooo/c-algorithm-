#include<iostream>
#include<vector>

using namespace std;

typedef struct s {

	int number;
	int i;
	int j;
}s;

int n, m;
int num = 0;
int answer = 987654321;



struct info {

	s arr[10]; //cctv 순열
	int mm[15][15];
	int k;
	int imap[4] = {-1,0,1,0};
	int jmap[4] = {0,1,0,-1};
	int ans = 0;

	void w(int d) {
		int ni = arr[k].i;
		int nj = arr[k].j;

		while (ni + imap[d] >=0 && ni + imap[d]  < n && nj + jmap[d] >= 0 && nj + jmap[d] < m) {
			ni += imap[d];
			nj += jmap[d];
			if (mm[ni][nj]==0) {
				mm[ni][nj] = 7;//감시 구간=7
			}
			else if ( mm[ni][nj] == 6) {
				break;
			}
		}
	}

	void check() {
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mm[i][j] ==0) {
					ans++;
				}
			}
		}
		if (ans < answer) { answer = ans; }
	}
};



void dfs(info in) {
	
	info temp = in;

	if (in.arr[in.k].number == 5) {
		for (int i = 0; i < 4;i++) {
			in.w(i);
		}
		if (in.k+1<num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}
	}
	else if (in.arr[in.k].number == 4) {
		in.w(0); in.w(1); in.w(3);
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}

		in.w(0); in.w(1); in.w(2);
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}
		
		in.w(1); in.w(2); in.w(3);
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}
		
		in.w(0); in.w(2); in.w(3);
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}
	}
	else if (in.arr[in.k].number == 3) {
		in.w(0); in.w(1); 
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}

		in.w(1); in.w(2);
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}
	
		in.w(2); in.w(3);
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}
		
		in.w(0); in.w(3);
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}
	}
	else if (in.arr[in.k].number == 2) {
		in.w(3); in.w(1); 
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}
		in.w(2); in.w(0);
		if (in.k + 1 < num) {
			in.k++;
			dfs(in);
			in = temp;
		}
		else {
			in.check();
			in = temp;
		}
	}
	else if (in.arr[in.k].number == 1) {
		for (int i = 0; i < 4; i++) {
			in.w(i);
			if (in.k + 1 < num) {
				in.k++;
				dfs(in);
				in = temp;
			}
			else {
				in.check();
				in = temp;
			}
		}
	}
}


int main() {

	info in;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> in.mm[i][j];
			if (in.mm[i][j] >= 1 && in.mm[i][j] <= 5) {
				in.arr[num].i = i;
				in.arr[num].j = j;
				in.arr[num].number = in.mm[i][j];
				num++;
			}
		}
	}

	in.k = 0;
	dfs(in);

	if (answer == 987654321) { in.check(); }
	cout << answer;
	return 0;
}