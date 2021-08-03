#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
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
bool dfs(int nowi, int nowj,int minn,int maxx,int visit) {

	
	if (map2[nowi][nowj] < minn || map2[nowi][nowj] > maxx)return false;
	if (map[nowi][nowj] == 'K')visit++;
	if (visit == num)return true;
	for (int i = 0; i < 8;i++) {
		int newi = nowi + dy[i]; int newj = nowj + dx[i];
		
		if (newi >=0 && newi < n && newj >=0 && newj <n && map2[newi][newj] >= minn && map2[newi][newj] <= maxx && vis[newi][newj]==false ) { //범위안에있음
			vis[newi][newj] = true;
			if (dfs(newi, newj, minn, maxx, visit) == true)return true;
			vis[newi][newj] = false;
		}
	}
	return false ;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int nowi, nowj;
	string str;
	for (int i = 0; i < n;i++) {  //우체국은 'P', 집은 'K', 목초지는 '.'
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'P') { nowi = i; nowj = j; } //시작 위치 저장
			if (map[i][j] == 'K')num++;
		}
	}
	
	for (int i = 0; i < n; i++) {  //고도
		for (int j = 0; j < n; j++) {
			cin >> map2[i][j];
			if (c[map2[i][j]] == false) {
				c[map2[i][j]] = true;
				v.push_back(map2[i][j]); //고도저장해두기
			}
		}
	}
	sort(v.begin(), v.end()); //고도 소트

	int s = 0; int e = 0; int answer = 9000000; 
	while (s <v.size() && e<v.size()) {
		
		memset(vis, false, sizeof(vis));
		vis[nowi][nowj] = true;
		if (dfs(nowi,nowj,v[s],v[e],0)==true) {
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