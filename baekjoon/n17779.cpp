#include<iostream>

using namespace std;

int n;
int map[25][25];
int x, y, d1, d2 = 1;
//d1, d2 ¡Ã 1, 1 ¡Â x < x+d1+d2 ¡Â N, 1 ¡Â y-d1 < y < y+d2 ¡Â N

void f() {


}

int main() {

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
						f();
					}
				}
			}
		}
	}

	return 0;
}
