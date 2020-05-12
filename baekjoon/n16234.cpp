#include<iostream>
#include<algorithm>
using namespace std;

int ground[50][50] = { 0, }; //인구수 넣기
int check[50][5] = { 0, };//국경선 상태 표시
int n; //땅크기
int l; //인구차 이상
int m; //인구차 이하
int v[50][50] = { 0, };

int mm = 0;//합
int nn = 0;//개수
int vn = 1;
int p(int a) {
	if (a >= 0) { return a; }
	else { return - a; }
}

void cc(int i, int j) {

	v[i][j] = vn;
	mm = mm + ground[i][j];
	nn++;
	cout << "i:"<<i<<"  j:"<<j<<"  nn:" << nn << "  mm:" << mm << "\n";
	if (j != n - 1&&(p(ground[i][j + 1] - ground[i][j]) >= l) && (p(ground[i][j + 1] - ground[i][j]) <= m)&&v[i][j+1]!=vn) {
		cc(i, j + 1);
	}//오
	if (j!=0&&(p(ground[i][j - 1] - ground[i][j]) >= l) && (p(ground[i][j - 1] - ground[i][j]) <= m) && v[i][j - 1] != vn) {
		cc(i, j - 1);
	}//왼
	if (i != 0&& (p(ground[i - 1][j] - ground[i][j]) >= l) && (p(ground[i - 1][j] - ground[i][j]) <= m) && v[i - 1][j] != vn) {
		cc(i-1,j);
	}//위
	if (i!=n-1&&(p(ground[i + 1][j] - ground[i][j]) >= l) && (p(ground[i + 1][j] - ground[i][j]) <= m) && v[i+1][j] != vn) {
		cc(i + 1, j);
	}//아래

}

void cc2(int mm,int nn) {
	int ans = mm / nn;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if  (v[i][j] == vn) {ground[i][j]=ans;}
		}
	}
	

}

int main() {


	cin >> n;
	cin >> l;
	cin >> m;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ground[i][j];
		}
	}

	
	int g;
	for (g = 0; g < 2000; g++) {
		vn = 1;
		fill(&v[0][0], &v[50][50], 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == 0) {
					nn = 0; mm = 0; cc(i, j); 
					if (nn > 1) { cc2(mm, nn); }
					vn++;
				}
			}
			
		}//cout <<"vn:"<<vn<< "  g:" << g << "\n";
		cout << "-----------------------------------\n";
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < n ; j++) {
				cout << ground[i][j] << " ";
			}
			cout << "\n";
		}

		if (vn == (n*n+1)) {break;}
		vn = 1;
	}

	
	cout << g ;
/*	for (int i = 0; i < (n*n); i++) {
		for (int j = 1; j < 5; j++) {
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}*/



/*	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= n+1; j++) {
			cout<< ground[i][j]<<" ";
		}
		cout << "\n";
	}*/

	return 0;
}