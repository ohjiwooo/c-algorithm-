#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef struct s{

	bool a_s = false;//기둥
	bool a_e = false;//기둥
	bool b_s = false;//보
	bool b_e = false;//보
}s;
s map[100][100];

int f(int a,int b) {
	if (a > b) { return a - b; }
	else { return b - a; }

}

void build(int i,int j,int a,int n) {

	i = f(i,n);
	if (a == 0) {//기둥설치
		if (i==n || map[i][j].a_e==true || map[i][j].b_s==true || map[i][j].b_e==true) { //바닥이거나 기둥위거나 보 위일때
			map[i - 1][j].a_e = true;
			map[i][j].a_s = true;
		}
	}
	else {//보 설치
		if (map[i][j].a_e==true || map[i][j+1].a_e==true || (map[i][j].b_e==true && map[i][j+1].b_s==true)) {//밑이 기둥이거나 양옆에 보가있을경우
			map[i][j].b_s = true;
			map[i][j + 1].b_e = true;
		}
	}
}

bool check(int n) {
	bool ans = true;
	for (int i=0; i <= n;i++) {
		int i2 = f(i, n);
		for (int j = 0; j <= n;j++) {
			if (map[i2][j].a_s==true) {//기둥의 시작점이면
				//기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다

				if (i2==n || map[i2][j].b_e==true ||map[i2][j].b_s==true ||map[i2][j].a_e==true) {
				}
				else {
					ans=false;
				}
			}
			if(map[i2][j].b_s==true){//보의 시작점이면
			//보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다

				if (map[i2][j].a_e==true || map[i2][j+1].a_e==true ||(map[i2][j].b_e==true && map[i2][j+1].b_s==true)) {
				}
				else {
					ans=false;
				}
			}
		}
	}

	return ans;
}


void remove(int i,int j,int a,int n) {
	i = f(i, n);
	if (a==0) {//기둥삭제
		map[i][j].a_s = false;
		map[i - 1][j].a_e = false;
		if (check(n)==false) {
			map[i][j].a_s = true;
			map[i - 1][j].a_e = true;
		}
	}
	else {
		map[i][j].b_s = false;
		map[i][j+1].b_e = false;
		if (check(n) == false) {
			map[i][j].b_s = true;
			map[i][j+1].b_e = true;
		}
	}


}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	
	vector<vector<int>> answer;

	for (int k = 0; k < build_frame.size();k++) {
	
		int j = build_frame[k][0];
		int i = build_frame[k][1];
		int a = build_frame[k][2];//0-기둥,1-보
		int b = build_frame[k][3];//0-삭제,1-설치

		if (b==1) {
			build(i, j, a,n);
		}
		else {
			remove(i,j,a,n);
		}
	}
	for (int i = 0; i <= n;i++) {
		for (int j = 0; j <= n;j++) {
			if (map[i][j].a_s==true) {
				answer.push_back({ j,f(n,i),0 });
				map[i][j].a_s = false; 
			}if (map[i][j].b_s==true) {
				answer.push_back({ j,f(n,i),1 });
			}
		}
	}

	sort(answer.begin(),answer.end());

	for (int i = 0; i < answer.size();i++) {
		cout << answer[i][0] << " " << answer[i][1] << " " << answer[i][2] << "\n";
	}
	return answer;
}

int main() {

		vector<vector<int>> build_frame;

		build_frame.push_back({0,0,0,1});
		build_frame.push_back({ 2,0,0,1 });
		build_frame.push_back({ 4,0,0,1 });
		build_frame.push_back({ 0,1,1,1 });
		build_frame.push_back({ 1,1,1,1 });
		build_frame.push_back({ 2,1,1,1 });
		build_frame.push_back({ 3,1,1,1 });
		build_frame.push_back({ 2,0,0,0 });
		build_frame.push_back({ 1,1,1,0 });
		build_frame.push_back({ 2,2,0,1 });
		solution(5, build_frame);
}