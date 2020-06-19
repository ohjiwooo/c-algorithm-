#include<iostream>
#include<vector>
using namespace std;

int map[10][10];
int temp[10][10];
int n, m;
int ans = 0;
int answer = 0;
vector <pair<int, int>> a;



void init_temp() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = map[i][j];
		}
	}

}



void s(int i,int j) {

	if(i>1 &&temp[i-1][j] == 0) { //위
		temp[i - 1][j] = 2;
		s(i-1,j);
	}if (j<m && temp[i][j+1] == 0) {//오
		temp[i][j+1] = 2;
		s(i, j+1);
	}if (i<n && temp[i + 1][j] == 0) {//아래
		temp[i + 1][j] = 2;
		s(i + 1, j);
	}if (j>1 &&temp[i][j-1] == 0) {//왼
		temp[i][j-1] = 2;
		s(i, j-1);
	}

}

void count() { //답세기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (temp[i][j] == 0) {
				ans++;
			}
		}
	}

}

void spread() {
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m;j++) { //map[i][j]==2 함수호출
			if (map[i][j]==2) {
				s(i, j);
			}
		}
	}

}


int main() {

	cin >> n >> m;
	

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m;j++) {
			cin >> map[i][j];
			temp[i][j] = map[i][j];
			if (map[i][j] == 0) { a.push_back(make_pair(i, j)); }
		}
	} //입력
	


		//벽세우기
	
	for (int i = 0; i < a.size(); i++) {
		for (int j = i+1; j <a.size(); j++) {
			for (int k = j+1; k <a.size(); k++) {
				

				temp[a[i].first][a[i].second] = 1;
				temp[a[j].first][a[j].second] = 1;
				temp[a[k].first][a[k].second] = 1;

				spread(); //세균퍼지기
				count(); //답세기
				if (ans > answer) { answer = ans; } //답옮기기
				ans = 0;
				init_temp();
				
			}
		}
	}



		

	cout << answer;
	return 0;
}