#include<iostream>
#include<vector>
using namespace std;

int map[15][15];
int num = 0;
vector <pair<int, int>>v(100);


void p() {
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}cout << "\n";
	}
}

 bool f(int now) {
	
	if (now == num) { p(); return true; }
	bool arr[10] = { false };//false가 아직 안쓴 숫자
	int ni = v[now].first;
	int nj = v[now].second;

	for (int i = 0; i < 9;i++) {//행
		arr[map[ni][i]] = true;
	}
	for (int i = 0; i < 9; i++) {//행
		arr[map[i][nj]] = true;
	}

	int k, k2;
	if (ni < 3) { k = 0; }
	else if (ni < 6) { k = 3; }
	else { k = 6; }

	if (nj < 3) { k2 = 0; }
	else if (nj < 6) { k2 = 3; }
	else { k2 = 6; }

	for (int a = k; a < k + 3; a++) {//사각검사 
		for (int b = k2; b < k2 + 3; b++) {
			arr[map[a][b]] = true;
		}
	}

	for (int i = 1; i < 10;i++) {
		if (arr[i] != true ) {
			map[ni][nj] = i;
			if (f(now + 1) == true) { return true; };
		}
	}
	map[ni][nj] = 0;
	return false;
}

 void q() {
	 for (int i = 0; i < 9; i++) {
		 for (int j = 0; j < 9; j++) {
			 cin >> map[i][j];
			 if (map[i][j] == 0) { v[num].first = i; v[num++].second = j; }
		 }
	 }
 }

int main() {
	
	q();
	f(0);
	return 0;
}