#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;


class node {

public: node *child[26];
		bool isend = false;
		bool ishit = false;
		string value;

		void init() {
			for (int i = 0; i < 26; i++) {
				child[i] = NULL;
			}
		}
		void clear() {
			
			ishit = false;
			for (int i = 0; i < 26;i++) {
				if (child[i] != NULL)child[i]->clear();
			}
		}
};

void make_trie(string str, node*head) {

	node *now = head;
	string v = "";
	for (int i = 0; i < str.size();i++) {
		v += str[i];
		if (now->child[str[i] - 'A'] == NULL) {//없으면 만들기
			now->child[str[i] - 'A'] = new node;
			now = now->child[str[i] - 'A'];
			now->value = v;
			now->init();
		}
		else { //이미 있으면 이동만
			now = now->child[str[i] - 'A'];
		}
		if (i == str.size() - 1) { //마지막 알파벳이면 ishit
			now->isend = true;
		}
	}
}

bool vis[4][4];
int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

int score(string str) {
	if (str.size() < 3)return 0;
	if (str.size() < 5)return 1;
	if (str.size() < 6)return 2;
	if (str.size() < 7)return 3;
	if (str.size() < 8)return 5;
	else { return 11; }
}

int num = 0;
string longest = "";
int answer = 0;
void dfs(char map[5][5],node *now,int nowi,int nowj) { //단어찾기

	
	if (now->isend == true && now->ishit==false) { //단어찾음
		now->ishit = true; //찾음
		num++;
		if (longest.size() == now->value.size()) {
			longest = min(longest, now->value);
		}
		else if (longest.size() < now->value.size())longest = now->value;
		answer+= score(now->value);
	}
	for (int i = 0; i < 8; i++) {
		int newi = nowi + dy[i]; int newj = nowj + dx[i];
		if (newi >=0 && newi <4 &&newj >=0 && newj <4 && vis[newi][newj]==false && now->child[map[newi][newj]-'A']!=NULL ) { //범위에 들어가고, 방문한적이 없으며, 있는단어인경우
			vis[newi][newj] = true;
			dfs(map, now->child[map[newi][newj]-'A'], newi, newj);
			vis[newi][newj] = false;
		}
	}
	
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int w; //사전안의 단어수
	cin >> w;
	string str;
	node *head= new node; //헤더생성
	head->init();
	for (int i = 0; i < w;i++) {
		cin >> str;
		make_trie(str,head);
	} //사전생성

	int n;
	cin >> n;
	char map[5][5];

	while (n--) { //n번 반복
		for (int i = 0; i < 4; i++) {
			cin >> str;
			for (int j = 0; j < 4; j++) {
				map[i][j] = str[j];
			}
		} //주사위 입력
		num = 0;
		longest = ""; //답 초기화
		answer = 0;
		head->clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (head->child[map[i][j]-'A']!=NULL) { //가능하면 보내기
					memset(vis, false, sizeof(vis));
					vis[i][j] = true;
					dfs(map, head->child[map[i][j] - 'A'], i, j);
				}
			}
		}
		//최대 점수, 가장 긴 단어, 찾은 단어의 수
		cout << answer << " " << longest << " " << num << "\n";
	}
	

}