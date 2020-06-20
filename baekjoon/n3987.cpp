#include<iostream>

using namespace std;


typedef struct s {

	bool u = false;
	bool d = false;
	bool r = false;
	bool l = false;

}s;

int n, m;
char map[505][505];
int pr, pc;
int ans = 0;
char answer;
int answ = 0;
int flag = 0;
s vis[505][505];


void u(int i, int j);
void d(int i, int j);
void r(int i, int j);
void l(int i, int j);

void u(int i, int j) {
	
	while (i>0) {
		i--;

		if (map[i][j] == '.') {
			ans++;
			if (vis[i][j].u == true) {
				cout << "U\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].u = true;
		}
		else if (map[i][j] == 'C') {
			return;
		}
		else if (map[i][j] == 92) {
			ans++;
			if (vis[i][j].u == true) {
				cout << "U\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].u = true;
			l(i, j);
			return;
		}
		else if (map[i][j] == '/') {
			ans++;
			if (vis[i][j].u == true) {
				cout << "U\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].u = true;
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
			if (vis[i][j].r == true) {
				cout << "R\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].r = true;
		}
		else if (map[i][j] == 'C') {
			return;
		}
		else if (map[i][j] == 92) {
			ans++;
			if (vis[i][j].r == true) {
				cout << "R\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].r = true;
			d(i, j);
			return;
		}
		else if (map[i][j] == '/') {
			ans++;
			if (vis[i][j].r == true) {
				cout << "R\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].r = true;
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
			if (vis[i][j].d == true) {
				cout << "D\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].d = true;
		}
		else if (map[i][j] == 'C') {
			return;
		}
		else if (map[i][j] == 92) {
			ans++;
			if (vis[i][j].d == true) {
				cout << "D\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].d = true;
			r(i, j);
			return;
		}
		else if (map[i][j] == '/') {
			ans++;
			if (vis[i][j].d == true) {
				cout << "D\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].d = true;
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
			if (vis[i][j].l == true) {
				cout << "L\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].l = true;
		}
		else if (map[i][j] == 'C') {
			return;
		}
		else if (map[i][j] == 92) {
			ans++;
			if (vis[i][j].l == true) {
				cout << "L\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].l = true;
			u(i, j);
			return;
		}
		else if (map[i][j] == '/') {
			ans++;
			if (vis[i][j].l == true) {
				cout << "L\n";
				cout << "Voyager";
				flag = 1;
				return;
			}
			vis[i][j].l = true;
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

	while (1) {
		u(pr, pc);
		if (flag == 1) { return 0; }

		if (ans > answ) {
			answ = ans;
			answer = 'U';
		}
		ans = 0;
		

		r(pr, pc);
		if (flag == 1) { return 0; }

		if (ans > answ) {
			answ = ans;
			answer = 'R';
		}
		ans = 0;
		
		d(pr, pc);
		if (flag == 1) { return 0; }

		if (ans > answ) {
			answ = ans;
			answer = 'D';
		}
		ans = 0;
	

		l(pr, pc);
		if (flag == 1) { return 0; }

		if (ans > answ) {
			answ = ans;
			answer = 'L';
		}
		break;
	}

	
	cout << answer << "\n";
	cout << ++answ;

	return 0;
}