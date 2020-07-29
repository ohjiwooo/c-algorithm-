#include<iostream>
#include<queue>
using namespace std;

typedef struct s {

	int a=0;//������� 0-��ĭ 1-�� 2-���
	int di=0;
	int dj = 0;//a�� 1�ϰ�� ������
	int f = 0;//������ ���� �ʿ��� ���ᷮ
}s;

int ni, nj;
int n, m, k;
s map[25][25];
int imap[4] = {-1,0,1,0};
int jmap[4] = {0,1,0,-1};

bool move(int ai,int aj,int d) {

	if (k>=d+map[ai][aj].f) { //�̵�����
		k -= d + map[ai][aj].f;
		map[ai][aj].a = 0; //�մԻ����
		k += (map[ai][aj].f * 2); //��������
		ni = map[ai][aj].di;
		nj = map[ai][aj].dj;//������ǥ ����
		m--;//�մ��پ��
		return true;
	}
	else { return false; }

}

int ff(int a, int b, int c, int d) {
	int dd=0;
	queue <pair<int, int>> qq;
	bool vis[25][25]={false};

	qq.push(make_pair(a, b));
	vis[a][b] = true;
	while (qq.empty() != true) {
		int size = qq.size();
		dd++;
		for (int s = 0; s < size; s++) {
			int newi = qq.front().first;
			int newj = qq.front().second;
			qq.pop();
			for (int i = 0; i < 4; i++) {
				if (newi + imap[i] > 0 && newi + imap[i] <= n && newj + jmap[i] > 0 && newj + jmap[i] <= n && vis[newi+imap[i]][newj+jmap[i]]==false) {
					if (map[newi + imap[i]][newj + jmap[i]].a != 1 && newi + imap[i] == c && newj + jmap[i] == d) {
						return dd;
					}
					else if (map[newi + imap[i]][newj + jmap[i]].a != 1) {
						qq.push(make_pair(newi + imap[i], newj + jmap[i]));
						vis[newi + imap[i]][newj + jmap[i]] = true;
					}
				}
			}
		}
	}return -1;
}

bool dis() {//�մ�ã��
	int d=0;//�Ÿ�
	int ai = 50;
	int aj=50;//����ǥ
	int vis[25][25] = {false};
	queue <pair<int, int>> ans;
	queue <pair<int, int>> qq;
	qq.push(make_pair(ni, nj));
	
	if (map[ni][nj].a==2) {
		return move(ni,nj,0);
	}
	while (qq.empty()!=true) {
		int size = qq.size();
		d++;
		for (int s = 0; s < size;s++) {
			int newi = qq.front().first;
			int newj = qq.front().second;
			qq.pop();
			for (int i = 0; i < 4; i++) {
				if (newi + imap[i] > 0 && newi + imap[i] <= n && newj + jmap[i] > 0 && newj + jmap[i] <= n && vis[newi + imap[i]][newj + jmap[i]] == false) {//�����ȿ��ְ�
					if (map[newi + imap[i]][newj + jmap[i]].a == 2) { //����� �������
						ans.push(make_pair(newi+imap[i],newj+jmap[i])); //�߰�
						vis[newi + imap[i]][newj + jmap[i]] = true;
					}
					else if (map[newi + imap[i]][newj + jmap[i]].a == 0) {
						qq.push(make_pair(newi + imap[i],newj + jmap[i]));
						vis[newi + imap[i]][newj + jmap[i]] = true;
					}
				}
			}
		}
		if (ans.size() != 0) {//�����������
			while (ans.empty() != true) {

				if (ans.front().first < ai) {
					ai = ans.front().first;
					aj = ans.front().second;
					ans.pop();
				}
				else if (ans.front().first == ai && ans.front().second < aj) {
					ai = ans.front().first;
					aj = ans.front().second;
					ans.pop();
				}
				else {
					ans.pop();
				}
			}
			return move(ai, aj, d);
		}
	}
	return false;
}

int main() {

	
	cin >> n >> m >> k;
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			cin >> map[i][j].a;
		}
	}
	cin >> ni >> nj;
	for (int i = 0; i < m;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		map[a][b].a = 2;
		map[a][b].di = c;
		map[a][b].dj = d;
		map[a][b].f=ff(a, b, c, d);
		if (map[a][b].f == -1) { cout << -1; return 0; }
	}
	bool ans = dis();
	while (ans == true && m>0) {
		ans = dis();
	}

	if (m ==0) {
		cout << k;
		return 0;
	}
	else {
		cout << -1;
		return 0;
	}
	return 0;
}
