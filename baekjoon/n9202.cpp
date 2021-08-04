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
		if (now->child[str[i] - 'A'] == NULL) {//������ �����
			now->child[str[i] - 'A'] = new node;
			now = now->child[str[i] - 'A'];
			now->value = v;
			now->init();
		}
		else { //�̹� ������ �̵���
			now = now->child[str[i] - 'A'];
		}
		if (i == str.size() - 1) { //������ ���ĺ��̸� ishit
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
void dfs(char map[5][5],node *now,int nowi,int nowj) { //�ܾ�ã��

	
	if (now->isend == true && now->ishit==false) { //�ܾ�ã��
		now->ishit = true; //ã��
		num++;
		if (longest.size() == now->value.size()) {
			longest = min(longest, now->value);
		}
		else if (longest.size() < now->value.size())longest = now->value;
		answer+= score(now->value);
	}
	for (int i = 0; i < 8; i++) {
		int newi = nowi + dy[i]; int newj = nowj + dx[i];
		if (newi >=0 && newi <4 &&newj >=0 && newj <4 && vis[newi][newj]==false && now->child[map[newi][newj]-'A']!=NULL ) { //������ ����, �湮������ ������, �ִ´ܾ��ΰ��
			vis[newi][newj] = true;
			dfs(map, now->child[map[newi][newj]-'A'], newi, newj);
			vis[newi][newj] = false;
		}
	}
	
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int w; //�������� �ܾ��
	cin >> w;
	string str;
	node *head= new node; //�������
	head->init();
	for (int i = 0; i < w;i++) {
		cin >> str;
		make_trie(str,head);
	} //��������

	int n;
	cin >> n;
	char map[5][5];

	while (n--) { //n�� �ݺ�
		for (int i = 0; i < 4; i++) {
			cin >> str;
			for (int j = 0; j < 4; j++) {
				map[i][j] = str[j];
			}
		} //�ֻ��� �Է�
		num = 0;
		longest = ""; //�� �ʱ�ȭ
		answer = 0;
		head->clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (head->child[map[i][j]-'A']!=NULL) { //�����ϸ� ������
					memset(vis, false, sizeof(vis));
					vis[i][j] = true;
					dfs(map, head->child[map[i][j] - 'A'], i, j);
				}
			}
		}
		//�ִ� ����, ���� �� �ܾ�, ã�� �ܾ��� ��
		cout << answer << " " << longest << " " << num << "\n";
	}
	

}