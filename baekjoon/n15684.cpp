#include<iostream>
using namespace std;

int n, m, h;
int map[35][15] = {0,};


bool s(int temp[35][15]) {
	
	int ni,nj;
	for (int i = 1; i <= n; i++) {
		ni = 1; nj = i;
		while (ni<=h) {
			if ( temp[ni][nj - 1] == 1) {
				ni++; nj--;
			}
			else if (temp[ni][nj] == 0) {
				ni++;
			}
			else if(temp[ni][nj]==1){
				ni++; nj++;
			}
			
		}if (nj!=i) {
			return false;
		}
	}
	return true;
}

bool ff(int temp[35][15],int ni,int nj,int k,int f) {

	if (f == k) {
		if (s(temp) == true) {
			cout << k; return true;
		}
		else {
			return false;
		}
	}
	for (int i = ni; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (temp[i][j] == 0 && temp[i][j - 1] != 1 && temp[i][j + 1] != 1) {
				temp[i][j] = 1;
				if (ff(temp, i, j, k, f + 1) == true) { return true; }
				temp[i][j] = 0;
			}
		}
	}
	return false;
}

int main(){
	int f = 0;
	cin >> n >> m >> h;


	for (int i = 0; i < m;i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	if (s(map)==true) {
		cout << 0; return 0;
	}
	
	if (ff(map, 1,1,1,0) == true) {return 0;}
	if (ff(map, 1,1,2,0)==true) { return 0; }
	if (ff(map, 1,1,3,0) == true){return 0; }
	else { cout << -1; }
	return 0;
}