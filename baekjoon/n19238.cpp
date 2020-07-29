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

void pp() {
		cout << "===========================\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << map[i][j].a << " ";
			}cout << "\n";
		}
		cout << k<<"\n";
}

bool move(int ai,int aj,int d) {

	if (k>=d+map[ai][aj].f) { //�̵�����
		k -= d + map[ai][aj].f;
		map[ai][aj].a = 0; //�մԻ����
		k += (map[ai][aj].f * 2); //��������
		ni = ai;
		nj = aj;//������ǥ ����
		m--;//�մ��پ��
	//	pp();
		return true;
	}
	else { return false; }

}

int ff(int a, int b, int c, int d) {
	int dd=0;
	queue <pair<int, int>> qq;
	qq.push(make_pair(a, b));
	while (qq.empty() != true) {
		int size = qq.size();
		dd++;
		for (int s = 0; s < size; s++) {
			int newi = qq.front().first;
			int newj = qq.front().second;
			qq.pop();
			for (int i = 0; i < 4; i++) {
				if (map[newi+imap[i]][newj+jmap[i]].a !=1&&newi + imap[i] == c && newj + jmap[i] == d ) {
					return dd;
				}
				else if(map[newi + imap[i]][newj + jmap[i]].a != 1){
				qq.push(make_pair(newi + imap[i], newj + jmap[i])); }
			}
		}
	}
}

bool dis() {//�մ�ã��
	int d=0;//�Ÿ�
	int ai = 50;
	int aj=50;//����ǥ
	queue <pair<int, int>> ans;
	queue <pair<int, int>> qq;
	qq.push(make_pair(ni, nj));
	
	while (qq.empty()!=true) {
		int size = qq.size();
		d++;
		for (int s = 0; s < size;s++) {
			int newi = qq.front().first;
			int newj = qq.front().second;
			qq.pop();
			for (int i = 0; i < 4; i++) {
				if (newi + imap[i] > 0 && newi + imap[i] <= n && newj + jmap[i] > 0 && newj + jmap[i] <= n) {//�����ȿ��ְ�
					if (map[newi + imap[i]][newj + jmap[i]].a == 2) { //����� �������
						ans.push(make_pair(newi+imap[i],newj+jmap[i])); //�߰�
					}
					else if (map[newi + imap[i]][newj + jmap[i]].a == 0) {
						qq.push(make_pair(newi + imap[i],newj + jmap[i]));
					}
				}
			}
			if (ans.size() !=0) {//�����������
				while (ans.empty()!=true) {
					if (ans.front().first<ai) {
						ai = ans.front().first;
						aj = ans.front().second;
						ans.pop();
					}
					else if (ans.front().first==ai && ans.front().second<aj) {
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
	}
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
	}
//	pp();
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
