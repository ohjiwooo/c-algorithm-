#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

char map[55][55];
int map2[55][55];
bool c[1000005];
vector<int>v;

int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int n;
bool vis[55][55];
int num = 0;
/*bool dfs(int nowi, int nowj,int minn,int maxx,int visit) {

	
	if (map2[nowi][nowj] < minn || map2[nowi][nowj] > maxx)return false;
	if (map[nowi][nowj] == 'K')visit++;
	if (visit == num)return true;
	for (int i = 0; i < 8;i++) {
		int newi = nowi + dy[i]; int newj = nowj + dx[i];
		
		if (newi >=0 && newi < n && newj >=0 && newj <n && map2[newi][newj] >= minn && map2[newi][newj] <= maxx && vis[newi][newj]==false ) { //�����ȿ�����
			vis[newi][newj] = true;
			if (dfs(newi, newj, minn, maxx, visit) == true)return true;
			vis[newi][newj] = false;
		}
	}
	return false ;

}*/

bool bfs(int nowi,int nowj,int minn,int maxx) {

	if (map2[nowi][nowj] < minn || map2[nowi][nowj] > maxx)return false;
	queue <pair<int,int>>q;
	q.push(make_pair(nowi, nowj));
	int tmp_answer = 0;

	while (q.empty()!=true) {
	
		int ni = q.front().first; int nj = q.front().second; vis[ni][nj] = true; q.pop();
		if (map[ni][nj] == 'K')tmp_answer++;
		if (tmp_answer == num)return true;
		for (int i = 0; i < 8; i++) {
			int newi = ni + dy[i]; int newj = nj + dx[i];

			if (newi >= 0 && newi < n && newj >= 0 && newj < n && map2[newi][newj] >= minn && map2[newi][newj] <= maxx && vis[newi][newj] == false) { //�����ȿ�����
				q.push(make_pair(newi, newj));
				vis[newi][newj] = true;
			}
		}
	}

	return false;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int nowi, nowj;
	string str;
	for (int i = 0; i < n;i++) {  //��ü���� 'P', ���� 'K', �������� '.'
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'P') { nowi = i; nowj = j; } //���� ��ġ ����
			if (map[i][j] == 'K')num++;
		}
	}
	
	for (int i = 0; i < n; i++) {  //��
		for (int j = 0; j < n; j++) {
			cin >> map2[i][j];
			if (c[map2[i][j]] == false) {
				c[map2[i][j]] = true;
				v.push_back(map2[i][j]); //�������صα�
			}
		}
	}
	sort(v.begin(), v.end()); //�� ��Ʈ

	int s = 0; int e = 0; int answer = 9000000; 
	while (s <v.size() && e<v.size()) {
		
		memset(vis, false, sizeof(vis));
		if (bfs(nowi,nowj,v[s],v[e])==true) {
			answer = min(answer, v[e] - v[s]);
			s++;
		}
		else {
			e++;
		}
	
	}
	cout << answer;
	return 0;
}