#include<iostream>
#include<algorithm>
using namespace std;

int box[1002][1002];
int c[1002][1002] = {0,};
int n;
int m;
int ans=0;
int a;//안익은거 수
int k=0;
int day[1002] = { 0, };
int dayn = 0;
void change(int i, int j, int dayn) {
	day[dayn]++;
	c[i][j] = 1;
	a--;
	if (j != m - 1 && box[i][j + 1] == 0 && c[i][j + 1] != 1) { change(i, j + 1,dayn); }//오른쪽
	else if (j != 0 && box[i][j - 1] == 0 && c[i][j - 1] != 1 ) { change(i, j - 1,dayn); }//왼쪽
	else if (i != 0 && box[i - 1][j] == 0 &&c[i - 1][j] !=1 ) { change(i-1, j,dayn); }//위
	else if (i != n - 1 && box[i + 1][j] == 0 && c[i + 1][j] != 1 ) { change(i+1,j,dayn); }//아래
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


	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j] == 1) {
					change(i, j,dayn++);
				}
			}
		}
		if (a != 0) { cout << "-1"; return 0; }
		sort(day[0], day[dayn - 1]);
		
	


	cout << day[0];
	return 0;
}