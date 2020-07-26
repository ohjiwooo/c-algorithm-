#include<iostream>
#include<deque>

using namespace std;

typedef struct s {

	int add_nu;
	int nu;
}s;

typedef struct ss {

	int i;
	int j;
	int age;

}ss;

int n, m, k;
int nn = 0;
s map[15][15];
deque <ss> t;
deque <ss> t2;
deque <ss> dead;
int imap[8] = {-1,-1,-1,0,1,1,1,0};
int jmap[8] = {-1,0,1,1,1,0,-1,-1};

void spring() {

	while (t.empty()!=true) {
	
		int i = t.front().i;
		int j = t.front().j;
		int age = t.front().age;
		t.pop_front();
		if (map[i][j].nu >= age) {
			map[i][j].nu -= age;
			t2.push_back({i,j,age+1});
		}
		else {
			dead.push_back({i,j,age});
		}

	}

	

}

void summer() {

	while (dead.empty() !=true) {
		int a = dead.front().i;
		int b = dead.front().j;
		int c = dead.front().age;
		dead.pop_front();
		nn--;
		map[a][b].nu += c / 2;
			
	}
}

void fall() {

	while (t2.empty()!=true) {
		int a = t2.front().i;
		int b = t2.front().j;
		int c = t2.front().age;
		t2.pop_front();

		if (c % 5 ==0 ) {
			for (int i = 0; i < 8;i++) {
				if (a+imap[i] > 0 && a+imap[i]<=n && b+jmap[i]>0 && b+jmap[i]<=n) {
					t.push_front({a+imap[i],b+jmap[i],1});
					nn++;
				}
			}t.push_back({a,b,c});
		}
		else {
			t.push_back({ a,b,c });
		}
	}
}
void winter() {

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			map[i][j].nu += map[i][j].add_nu;
		}
	}

}
int main() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n;j++) {
			cin >> map[i][j].add_nu;
			map[i][j].nu = 5;
		}
	}
	int a, b, c;
	for (int i = 0; i < m;i++) {
		cin >> a;
		cin >> b;
		cin >> c;
		t.push_front({a,b,c});
		nn++;
	}


	for (int i = 0; i < k; i++) {

		spring();
		summer();
		fall();
		winter();

	}

	cout << nn;

	return 0;
}