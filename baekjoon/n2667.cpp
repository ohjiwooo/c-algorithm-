#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int a[27][27];
int n; //ÁöµµÅ©±â
bool visited[27][27];
int zz;

void bfs(int i,int j) {
	visited[i][j] = 1;
	zz++;
	if (a[i][j + 1] == 1 && visited[i][j + 1] !=1) { //¿À
		bfs(i, j + 1); 
	}else if (a[i][j + 1] == 0 && visited[i][j + 1] != 1) { //¿À
		visited[i][j + 1] =1;
	}
	
	if (a[i + 1][j] == 1 && visited[i+1][j] != 1) { //¹Ø
		bfs(i + 1, j); 
	}else if (a[i + 1][j] == 0 && visited[i][j] != 1) { //¹Ø
		visited[i + 1][j] = 1;
	}
	
	if (a[i][j-1] == 1 && visited[i][j -1] !=1) {//¿Þ
		bfs(i, j-1); 
	}else if (a[i][j - 1] == 0 && visited[i][j - 1] !=1) {//¿Þ
		visited[i][j - 1] = 1;
	}

	if (a[i-1][j] == 1 && visited[i - 1][j] != 1) {//À§
		bfs(i-1, j);
	}
	else if (a[i-1][j] == 0 && visited[i - 1][j] != 1) {//À§
		visited[i-1][j] = 1;
	}
}

int main() {
	
	
	cin >> n;
	int ans = 0;
	vector<int> num;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}



	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == 0 && a[i][j] == 1) {
				zz = 0;
				bfs(i, j);
				num.push_back(zz);
				ans++;
			}
		}
	}
	sort(num.begin(), num.end());

	cout << ans << "\n";

	for (int i = 0; i < ans; i++) {
		cout << num[i] << "\n";
	}
	return 0;
}