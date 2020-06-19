#include<iostream>

using namespace std;

int n, m;
char map[505][505];
int pr, pc;
int ans = 0;
char answer;
int answ = 0;



void u(int i, int j);
void d(int i, int j);
void r(int i, int j);
void l(int i, int j);

void u(int i, int j) {
	
	while (i>0) {
		i--;

		if (map[i][j] == '.') {
			ans++;
		}
		else if (map[i][j] == 'C') {
			return;
		}
		else if (map[i][j] == 92) {
			ans++;
			l(i, j);
			return;
		}
		else if (map[i][j] == '/') {
			ans++;
			r(i, j);
			return;
		}
	}
}

void r(int i, int j) {
	
	while (j <= m) {
		
		j++;

		if (map[i][j] == '.') {
			ans++;
		}
		else if (map[i][j] == 'C') {
			return;
		}
		else if (map[i][j] == 92) {
			ans++;
			d(i, j);
			return;
		}
		else if (map[i][j] == '/') {
			ans++;
			u(i, j);
			return;
		}


	}
}

void d(int i, int j) {
	
	while (i <= n) {

		i++;

		if (map[i][j] == '.') {
			ans++;
		}
		else if (map[i][j] == 'C') {
			return;
		}
		else if (map[i][j] == 92) {
			ans++;
			r(i, j);
			return;
		}
		else if (map[i][j] == '/') {
			ans++;
			l(i, j);
			return;
		}


	}
}

void l(int i, int j) {
	while (j > 0) {

		j--;

		if (map[i][j] == '.') {
			ans++;
		}
		else if (map[i][j] == 'C') {
			return;
		}
		else if (map[i][j] == 92) {
			ans++;
			u(i, j);
			return;
		}
		else if (map[i][j] == '/') {
			ans++;
			d(i, j);
			return;
		}


	}
}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	
	cin >> pr >> pc;

	u(pr, pc);
	
	if (ans > answ) {
		answ = ans;
		answer = 'U';
	}
	ans = 0;


	r(pr, pc);
	if (ans > answ) {
		answ = ans;
		answer = 'R';
	}
	ans = 0;

	d(pr, pc);
	if (ans > answ) {
		answ = ans;
		answer = 'D';
	}
	ans = 0;

	l(pr, pc);

	if (ans > answ) {
		answ = ans;
		answer = 'L';
	}
	

	cout << answer << "\n";
	cout << ++answ;

	return 0;
}