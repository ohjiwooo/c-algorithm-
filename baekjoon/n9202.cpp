#include<iostream>
#include<string>
#include<vector>
using namespace std;


typedef class node {

public:
	node *child[26];
	bool isend = false;
	bool ishit = false;

	void clear() {
		
		ishit = false;

		for (int i = 0; i < 26;i++) {
			if (child[i]!=NULL) {
				child[i]->clear();
			}
		}
	}

}node;


node *head = new node;
vector<string> v;
string s = "";
int n;
char map[5][5];
int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };


void make_trie() {

	char c = ' ';
	for (int i = 0; i < n;i++) {
		node *now = head;
		for (int j = 0; j < v[i].size();j++) {
			c = v[i][j];

			if (now->child[c - 'a'] == NULL) { //없음
				node *nd = new node;
				now->child[c - 'a'] = nd; //만들고
				now = now->child[c - 'a']; //이동
				if (j==v[i].size()-1) { //단어의 마지막 글자
					now->isend = true;
				}
			}
			else { //있음
				now = now->child[c - 'a']; //이동
				if (j == v[i].size() - 1) { //단어의 마지막 글자
					now->isend = true;
				}
			}
		} 
	}
}

int answer = 0; //개수
string ans = ""; //가장 긴 단어
int score = 0; //점수

int dfs(int i,int j,node *now,string word) { //현재 인덱스 i,j ,현재 trie순회 포인터, 현재단어


	if (now->isend==true && now->ishit!=true) { //찾음
		now->ishit = true;
		int len = word.size();
		answer += 1; //갯수 추가
		if (ans.size() < len) { //가장 긴 단어 변경
			ans = word;
		}
		else if (ans.size() == len) {//길이가 같음 - 사전순 정렬
			if(word < ans) {
				ans = word;
			}
		}
		//1글자, 2글자로 이루어진 단어는 0점, 3글자, 4글자는 1점, 5글자는 2점, 6글자는 3점, 7글자는 5점, 8글자는 11
		if (len <3) {
			score += 0;
		}
		else if (len<5) {//3,4
			score += 1;
		}
		else if (len < 6) {//5
			score += 2;
		}
		else if (len < 7) { //6
			score += 3;
		}
		else if (len <8 ) { //7
			score += 5;
		}
		else {
			score += 11;
		}
		return 0;
	}


	for (int k = 0; k < 8; k++) {
		if (i + dy[k] < 0 || i + dy[k] > 3 || j + dx[k] < 0 || j + dx[k] > 3) { // 범위를 벗어남 
			continue;
		}
		char a = map[i + dy[k]][j + dx[k]]; //새 문자
		if (now->child[a]!=NULL) { //있음
			dfs(i + dy[k], j + dx[k], now->child[a],word+a);
		}
	}
	return 0;


}
int main() {



	cin >> n;

	for (int i = 0; i < n;i++) {
		cin >> s;
		v.push_back(s);
	}

	make_trie();

	int m;
	cin >> m;
	while (m--) {
		
		answer = 0; //개수
		ans = ""; //가장 긴 단어
		score = 0; //점수
		
		for (int i = 0; i < 4;i++) {
			for (int j = 0; j < 4;j++) {
				cin >> map[i][j];
			}
		}

		
		for (int i = 0; i < 4;i++) {
			for (int j = 0; j < 4;j++) {
				if(head->child[map[i][j] - 'a'] != NULL ){ // 시작할수있는 문자
					string a = "";
					a+=map[i][j];
					dfs(i, j, head, a);
				}
			}
		}
		cout << score << " " << ans << " " << answer << "\n";
	}

	return 0;
}