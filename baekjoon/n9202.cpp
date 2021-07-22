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

			if (now->child[c - 'a'] == NULL) { //����
				node *nd = new node;
				now->child[c - 'a'] = nd; //�����
				now = now->child[c - 'a']; //�̵�
				if (j==v[i].size()-1) { //�ܾ��� ������ ����
					now->isend = true;
				}
			}
			else { //����
				now = now->child[c - 'a']; //�̵�
				if (j == v[i].size() - 1) { //�ܾ��� ������ ����
					now->isend = true;
				}
			}
		} 
	}
}

int answer = 0; //����
string ans = ""; //���� �� �ܾ�
int score = 0; //����

int dfs(int i,int j,node *now,string word) { //���� �ε��� i,j ,���� trie��ȸ ������, ����ܾ�


	if (now->isend==true && now->ishit!=true) { //ã��
		now->ishit = true;
		int len = word.size();
		answer += 1; //���� �߰�
		if (ans.size() < len) { //���� �� �ܾ� ����
			ans = word;
		}
		else if (ans.size() == len) {//���̰� ���� - ������ ����
			if(word < ans) {
				ans = word;
			}
		}
		//1����, 2���ڷ� �̷���� �ܾ�� 0��, 3����, 4���ڴ� 1��, 5���ڴ� 2��, 6���ڴ� 3��, 7���ڴ� 5��, 8���ڴ� 11
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
		if (i + dy[k] < 0 || i + dy[k] > 3 || j + dx[k] < 0 || j + dx[k] > 3) { // ������ ��� 
			continue;
		}
		char a = map[i + dy[k]][j + dx[k]]; //�� ����
		if (now->child[a]!=NULL) { //����
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
		
		answer = 0; //����
		ans = ""; //���� �� �ܾ�
		score = 0; //����
		
		for (int i = 0; i < 4;i++) {
			for (int j = 0; j < 4;j++) {
				cin >> map[i][j];
			}
		}

		
		for (int i = 0; i < 4;i++) {
			for (int j = 0; j < 4;j++) {
				if(head->child[map[i][j] - 'a'] != NULL ){ // �����Ҽ��ִ� ����
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