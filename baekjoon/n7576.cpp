#include<iostream>

using namespace std;

int box[1002][1002];
int c[1002][1002] = {0,};
int n;
int m;
int ans=0;
int a;//안익은거 수
int k=0;
int cc = 2;
int qq = 1;
int qq2=0;
void change(int i, int j) {
	if (j != m - 1 && box[i][j + 1] != 0 && box[i][j + 1] != cc && box[i][j + 1] != -1) { box[i][j] = cc; a--; qq++; }//오른쪽
	else if (j != 0 && box[i][j - 1] != 0 && box[i][j - 1] != cc && box[i][j - 1] != -1) { box[i][j] = cc; a--; qq++; }//왼쪽
	else if (i != 0 && box[i - 1][j] != 0 && box[i - 1][j] != cc && box[i - 1][j] != -1) { box[i][j] = cc; a--; qq++; }//위
	else if (i != n - 1 && box[i + 1][j] != 0 && box[i + 1][j] != cc && box[i + 1][j] != -1) { box[i][j] = cc; a--; qq++; }//아래
}


int main() {

	cin >> m; //가로칸
	cin >> n;//세로칸

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0) { a++; }
		}
	} //입력받음

	if (a == 0) { cout << "0"; return 0; }


	while (a!=0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j] == 0) {
					change(i, j);
				}
			}
		}cc++; if (qq2 == qq) { break; }
		else { qq2 = qq; }
		k++;
		
	}

	
	if (a != 0) { cout << "-1"; return 0; }


	cout << k;
	return 0;
}