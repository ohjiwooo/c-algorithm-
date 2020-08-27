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


void build(int i,int j,int a) {

	if (a == 0) {//기둥설치
		if (i==0 || map[i][j].a_e==true || map[i][j].b_s==true || map[i][j].b_e==true) { //바닥이거나 기둥위거나 보 위일때
			map[i + 1][j].a_e = true;
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
void remove(int i,int j,int a) {

	if (a==0) {//기둥삭제
		if (map[i + 1][j].a_s == false && map[i + 1][j].b_s == false && map[i + 1][j].b_e == false) {//혼자있는기둥
			map[i + 1][j].a_e = false;
			map[i][j].a_s = false;
		}
		else if ((map[i + 1][j].b_s == true && map[i+1][j].b_e==true &&(map[i+1][j+1].b_s==true || map[i+1][j+1].a_e==true))&&(map[i+1][j-1].b_e==true || map[i+1][j-1].a_e==true)) { //기둥위에 보-양옆보가 있어 기둥삭제 가능
			map[i][j].a_s = false;
			map[i + 1][j].a_e = false;
		}
		else if (map[i+1][j].b_s==true && map[i+1][j+1].a_e==true && map[i+1][j].b_e==false) {//기둥위에 왼쪽보-다른기둥이있음
			map[i][j].a_s = false;
			map[i + 1][j].a_e = false;
		}
		else if (map[i+1][j].b_e==true && map[i+1][j].b_s==false && map[i+1][j-1].a_e==true) {//기둥위에 오른쪽보-다른기둥이있음
			map[i][j].a_s = false;
			map[i + 1][j].a_e = false;
		}
		else if (map[i + 1][j].b_e == true && map[i + 1][j].b_s == true && (map[i + 1][j - 1].a_e == true ||map[i+1][j-1].b_e==true) && 
			(map[i + 1][j + 1].a_e == true || map[i+1][j+1].b_s==true)) {//기둥위에 양쪽보,둘다 기둥있음이나 보가있음
			map[i][j].a_s = false;
			map[i + 1][j].a_e = false;
		}
	}
	else {//보 삭제
		if (map[i][j].a_s==false && map[i][j+1].a_s==false && map[i][j].b_e==false && map[i][j+1].b_s==false) {//혼자있는보
			map[i][j].b_s = false;
			map[i][j].b_e = false;
		}
		else if (map[i][j+1].b_s==true &&(map[i][j+1].a_e==true || map[i][j].a_e==true)&& map[i][j].b_e==false) {//오른쪽에보,기둥있음
			map[i][j].b_s = false;
			map[i][j].b_e = false;
		}
		else if (map[i][j].b_e == true && (map[i][j - 1].a_e == true || map[i][j].a_e==true) && map[i][j+1].b_s==false) {//왼쪽에보,기둥있음
			map[i][j].b_s = false;
			map[i][j].b_e = false;
		}
		else if ((map[i][j].a_e == true && map[i][j].a_s == true && map[i][j + 1].a_s == false) || (map[i][j].a_s==false && map[i][j+1].a_e==true && map[i][j+1].a_s==true)) {//위에기둥이있지만 밑에도기둥이있음
			map[i][j].b_s = false;
			map[i][j].b_e = false;
		}
		else if (map[i][j].a_s==true && map[i][j+1].a_s==true && map[i][j].a_e==true && map[i][j+1].a_e==true){
			map[i][j].b_s = false;
			map[i][j].b_e = false;
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
			build(i, j, a);
		}
		else {
			remove(i,j,a);
		}
	}
	for (int i = 0; i <= n;i++) {
		for (int j = 0; j <= n;j++) {
			if (map[i][j].a_s==true) {
				answer.push_back({ j,i,0 });
				map[i][j].a_s = false; 
			}if (map[i][j].b_s==true) {
				answer.push_back({ j,i,1 });
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