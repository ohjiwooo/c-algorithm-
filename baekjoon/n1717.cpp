#include<iostream>

using namespace std;

int p[1000003];



int find(int a) { //부모찾기

	if (p[a]==a) {
		return a;
	}
	else {
		return p[a] = find(p[a]);
	}

}

void uni(int a, int b) { //합치기

	int a_p = find(a);
	int b_p = find(b);

	if (a_p != b_p) {
		p[a_p] = b_p;
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m,a,b,c;
	cin >> n >> m;

	for (int i = 0; i <= n;i++) {
		p[i] = i;
	}

	while (m--) {
		cin >> a >> b >> c;
		
		if (a==0) { // 합치는 연산
			uni(b, c);
		}
		else { // 하나의 집합인가?
			if (find(b)==find(c)) {
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	
	}

	return 0;
}