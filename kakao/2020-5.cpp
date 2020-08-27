#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef struct s{

	bool a_s = false;//���
	bool a_e = false;//���
	bool b_s = false;//��
	bool b_e = false;//��
}s;
s map[100][100];


void build(int i,int j,int a) {

	if (a == 0) {//��ռ�ġ
		if (i==0 || map[i][j].a_e==true || map[i][j].b_s==true || map[i][j].b_e==true) { //�ٴ��̰ų� ������ų� �� ���϶�
			map[i + 1][j].a_e = true;
			map[i][j].a_s = true;
		}
	}
	else {//�� ��ġ
		if (map[i][j].a_e==true || map[i][j+1].a_e==true || (map[i][j].b_e==true && map[i][j+1].b_s==true)) {//���� ����̰ų� �翷�� �����������
			map[i][j].b_s = true;
			map[i][j + 1].b_e = true;
		}
	}
}
void remove(int i,int j,int a) {

	if (a==0) {//��ջ���
		if (map[i + 1][j].a_s == false && map[i + 1][j].b_s == false && map[i + 1][j].b_e == false) {//ȥ���ִ±��
			map[i + 1][j].a_e = false;
			map[i][j].a_s = false;
		}
		else if ((map[i + 1][j].b_s == true && map[i+1][j].b_e==true &&(map[i+1][j+1].b_s==true || map[i+1][j+1].a_e==true))&&(map[i+1][j-1].b_e==true || map[i+1][j-1].a_e==true)) { //������� ��-�翷���� �־� ��ջ��� ����
			map[i][j].a_s = false;
			map[i + 1][j].a_e = false;
		}
		else if (map[i+1][j].b_s==true && map[i+1][j+1].a_e==true && map[i+1][j].b_e==false) {//������� ���ʺ�-�ٸ����������
			map[i][j].a_s = false;
			map[i + 1][j].a_e = false;
		}
		else if (map[i+1][j].b_e==true && map[i+1][j].b_s==false && map[i+1][j-1].a_e==true) {//������� �����ʺ�-�ٸ����������
			map[i][j].a_s = false;
			map[i + 1][j].a_e = false;
		}
		else if (map[i + 1][j].b_e == true && map[i + 1][j].b_s == true && (map[i + 1][j - 1].a_e == true ||map[i+1][j-1].b_e==true) && 
			(map[i + 1][j + 1].a_e == true || map[i+1][j+1].b_s==true)) {//������� ���ʺ�,�Ѵ� ��������̳� ��������
			map[i][j].a_s = false;
			map[i + 1][j].a_e = false;
		}
	}
	else {//�� ����
		if (map[i][j].a_s==false && map[i][j+1].a_s==false && map[i][j].b_e==false && map[i][j+1].b_s==false) {//ȥ���ִº�
			map[i][j].b_s = false;
			map[i][j].b_e = false;
		}
		else if (map[i][j+1].b_s==true &&(map[i][j+1].a_e==true || map[i][j].a_e==true)&& map[i][j].b_e==false) {//�����ʿ���,�������
			map[i][j].b_s = false;
			map[i][j].b_e = false;
		}
		else if (map[i][j].b_e == true && (map[i][j - 1].a_e == true || map[i][j].a_e==true) && map[i][j+1].b_s==false) {//���ʿ���,�������
			map[i][j].b_s = false;
			map[i][j].b_e = false;
		}
		else if ((map[i][j].a_e == true && map[i][j].a_s == true && map[i][j + 1].a_s == false) || (map[i][j].a_s==false && map[i][j+1].a_e==true && map[i][j+1].a_s==true)) {//��������������� �ؿ������������
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
		int a = build_frame[k][2];//0-���,1-��
		int b = build_frame[k][3];//0-����,1-��ġ

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