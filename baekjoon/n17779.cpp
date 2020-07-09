#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n;
int map[25][25];
int x, y, d1, d2;
int answer = 987654321;
queue <pair<int, int>> qq;
int temp[25][25];
void init();
int ff2();
int arr[6] = { 0, };

 void ff() {

	for (int i = 1; i <=n ; i++) {
		d1 = i;
		for (int j = 1; j <=n;j++) {
			d2 = j;

			if (d1>=1 && d2>=1 && 1<=x && x<x+d1+d2 &&x+d1+d2<=n &&1<=y-d1 &&y-d1<y &&y<y+d2 && y+d2<=n) {
				init();
				int a = ff2();
				if (a < answer) { answer = a; }
				cout << x << " " << y << " " << d1 << " " << d2 << " " << answer << "\n";
			}
		}
	}


}

void ff3(int ni,int nj) {

	if (temp[ni][nj]!=5) {
		temp[ni][nj] = 5;
		ff3(ni,nj+1);
	}

}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp[i][j] = map[i][j];
		}
	}
	
	for (int j = 1; j < 6; j++) {
		arr[j] = 0;
	}
}
int ff2() {
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i>=1 && i<x+d1 &&j>=1 && j<=y ) { //1
				temp[i][j] = 1;
			}
			else if (i>=1 && i<=x+d2 && j>y && j<=n) {//2
				temp[i][j] = 2;
			}
			else if (i>=x+d1 && i<=n && j>=1 && j<y-d1+d2 ) {//3 
				temp[i][j] = 3;
			}
			else if (i>x+d2 &&i<=n && j>=y-d1+d2 && j<=n) {//4
				temp[i][j]=4;
			}
		}
	}
	
	int k = 0; 
	while (k<=d1) { //(x, y), (x + 1, y - 1), ..., (x + d1, y - d1)
		temp[x + k][y - k]=5;
		k++;
	}

	k = 0;
	while (k <= d2 ) { //(x, y), (x + 1, y + 1), ..., (x + d2, y + d2)
		temp[x + k][y + k]=5;
		k++;
	}

	k = 0; 
	while (k <= d2 ) { //(x + d1, y - d1), (x + d1 + 1, y - d1 + 1), ... (x + d1 + d2, y - d1 + d2)
		temp[x + d1+ k][y - d1 +k]=5;
		k++;
	}

	k = 0;
	while (k <= d1) { //(x + d2, y + d2), (x + d2 + 1, y + d2 - 1), ..., (x + d2 + d1, y + d2 - d1)
		temp[x + d2 + k][y + d2 - k]=5;
		k++;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (temp[i][j] == 5 && (i!=x || j!=y)&&(i != x + d2 || j != y + d2) && (i != x + d1 + d2 || j != y + d1 + d2)) {
				ff3(i, j+1);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[temp[i][j]]++;
		}
	}
	sort(arr+1,arr+6);

	return arr[5] - arr[1];
}

int main() {

	cin >> n;

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) { //x
		x = i;
		for (int j = 1; j <= n; j++) {//y
			y = j;
			ff();
		}
	}

	cout << answer;
}