#include<iostream>
#include<vector>
using namespace std;

int n, m, h;
vector< vector<int> >map(35,vector<int>(15,0));

bool s(vector <vector<int>>temp) {
	
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
bool s2(int ni,int nj,int f,int k,vector <vector<int>> temp) {
	
	temp[ni][nj] = 1;
	if (f==k) {
		if (s(temp) == true) { cout << k; return true; }
		else { return false; }
	}
	else if (f<k) {
		for (int i = ni; i <= h; i++) {
			for (int j = 1; j < n; j++) {
				if (temp[i][j] == 0 && temp[i][j - 1] != 1 && temp[i][j + 1] != 1) {
					if (s2(i, j, f + 1, k, temp) == true) { return true; }
				}
			}
		}
	}
	return false;
}

bool ff(vector<vector<int>> temp, int k) {

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (temp[i][j] == 0 && temp[i][j - 1] != 1 && temp[i][j + 1] != 1) {
				if (s2(i, j, 1, k, temp)==true) { return true; }
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


	if (ff(map, 1) == true) {return 0;}
	if (ff(map, 2)==true) { return 0; }
	if (ff(map, 3) == true){return 0; }
	else { cout << -1; }
	return 0;
}