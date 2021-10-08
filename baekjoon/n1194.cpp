#include<iostream>
#include<string>
#include<queue>
using namespace std;


int n, m;//��, ��
char map[55][55];
bool vis[55][55][1<<6];
string str;
int imap[4] = { 0,1,0,-1 };
int jmap[4] = { 1,0,-1,0 };
int starti, startj;

bool bfs() {

	queue<pair<pair<int, int>,pair<int,int>>>q; // i,j,cost,statu

	q.push(make_pair(make_pair(starti, startj), make_pair(0, 0)));
	while (q.empty()!=true) {
		int curi = q.front().first.first; int curj = q.front().first.second; int cost = q.front().second.first; int sta = q.front().second.second; q.pop();
		if (vis[curi][curj][sta] == true)continue;
		vis[curi][curj][sta] = true;

		for (int k = 0; k < 4;k++) {
			int newi = curi + imap[k]; int newj = curj + jmap[k];
			if (newi>=0 && newi < n && newj >=0 && newj < m && vis[newi][newj][sta]!=true && map[newi][newj]!='#') {
				if (map[newi][newj] == '1') {
					cout << cost+1; return true;
				}
				//�ⱸ�ΰ��
				else if (map[newi][newj] >= 'a' && map[newi][newj] <='z') {
					int bit = map[newi][newj] - 'a';
					q.push(make_pair(make_pair(newi, newj), make_pair(cost + 1, sta | 1 << bit)));
				} //����� �ݴ°��
				else if (map[newi][newj] >= 'A' && map[newi][newj] <= 'Z') {
					int bit = map[newi][newj] - 'A';
					if (1<<bit == (sta &(1<<bit))) { //Ű����
						q.push(make_pair(make_pair(newi, newj),make_pair(cost+1, sta|1 << bit)));
					}
				}//���谡 �ʿ��ѵ� ���谡 �ִ°��
				else {
					q.push(make_pair(make_pair(newi, newj), make_pair(cost + 1, sta)));
				}//����ΰ��
		
			}
		}
	}
	return false;
}
int main() {

	cin >> n >> m;

	for (int i = 0; i < n;i++) {
		cin >> str;
		for (int j = 0; j < m;j++) {
			map[i][j]=str[j];
			if (map[i][j] == '0') {
				starti = i; startj = j;
			}
		}
	}
	if (bfs() == false)cout << -1;

}