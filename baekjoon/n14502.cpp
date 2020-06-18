#include<iostream>

using namespace std;

int map[10][10];
int temp[10][10];
bool vis[10][10];
int n, m;

void init_vis() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (temp[i][j] == 1 || temp[i][j] == 2) {
				vis[i][j] = true;
			}
		}
	}

}
void init_temp() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = map[i][j];
		}
	}

}



void spread() {
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m;j++) {
			
		}
	}


}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m;j++) {
			cin >> map[i][j];
		}
	}
	return 0;
}