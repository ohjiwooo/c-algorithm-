#include<iostream>
#include<queue>

using namespace std;

char map[15][15]; //12,6
int ans;
queue <pair<int, int>> qq;
queue <pair<int, int>> qq2; //모아서 삭제
bool vis[15][15];

void init_vis() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			vis[i][j] = false;
			}
		}


}
int find2() { //찾은후 터트림
	int num = 0; 

	while (qq.empty()!=true) {
		
		int i=qq.front().first;
		int j = qq.front().second;
		char a = map[i][j];
		vis[i][j] = true;
		qq2.push(make_pair(i,j));
		qq.pop(); num++;

		if (i>0 && map[i-1][j] == a && vis[i-1][j] !=true) { //위
			qq.push(make_pair(i - 1, j));
		}
		if (j < 5 && map[i][j+1] == a && vis[i][j+1] != true) { //오
			qq.push(make_pair(i, j+1));
		}
		if (i < 11 && map[i +1][j] == a && vis[i + 1][j] != true) { //아
			qq.push(make_pair(i +1, j));
		}
		if (j > 0 && map[i][j-1] == a && vis[i][j-1] != true) { //왼
			qq.push(make_pair(i, j-1));
		}
	}

	if (num >= 4) {
		while (qq2.empty() != true) {
			int i2 = qq2.front().first;
			int j2 = qq2.front().second;
			qq2.pop();
			map[i2][j2] = '.';
		}
	}
	else {
		while (qq2.empty() != true) {
			qq2.pop();
		}
	}

	return num;
}

bool find() {
	int n;
	bool a=false;

	for (int i = 0; i < 12;i++) {
		for (int j = 0; j < 6;j++) {
			if (vis[i][j] != true && map[i][j] != '.') {
				qq.push(make_pair(i,j));
				n=find2();
				if (n >= 4) {//터친거임
					a = true;
				}
				
			}
		}
	}
	return a;

}

void ground() {
	int c = 8;
	while (c > 0) {
		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 12; i++) {
				if (map[i][j] != '.' && map[i + 1][j] == '.') {
					map[i + 1][j] = map[i][j];
					map[i][j] = '.';

				}
			}
		}
		c--;
	}
	
}

int main() {

	int ans=0;
	for (int i = 0; i < 12;i++) {
		for (int j = 0; j < 6;j++) {

			cin >> map[i][j];
			vis[i][j] = false;
		}
	}
	
	while (1) {

		bool f = find(); //1판
		if (f == true) {
			ans++;

			init_vis();//초기화
			ground();//땅으로


		}
		else { break; }
	}
	
	cout << ans;
	return 0;
}