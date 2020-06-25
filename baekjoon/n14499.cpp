#include<iostream>
#include<queue>

using namespace std;

int n, m,x,y,k;
queue <int>qq;
int map[25][25];
int dice[10] = { 0,};
int new_dice[10]={ 0,};
int imap[5] = {0,0,0,-1,1};
int jmap[5] = {0,1,-1,0,0};
queue<int>ans;

void init() {
	for (int i = 0; i < 6; i++) {
		dice[i] = new_dice[i];
	}

}
void north() {
	
	new_dice[0] = dice[4];
	new_dice[1] = dice[0];
	new_dice[2] = dice[2];
	new_dice[3] = dice[3];
	new_dice[4] = dice[5];
	new_dice[5] = dice[1];

}

void east() {

	new_dice[0] = dice[3];
	new_dice[1] = dice[1];
	new_dice[2] = dice[0];
	new_dice[3] = dice[5];
	new_dice[4] = dice[4];
	new_dice[5] = dice[2];

}


void south() {

	new_dice[0] = dice[1];
	new_dice[1] = dice[5];
	new_dice[2] = dice[2];
	new_dice[3] = dice[3];
	new_dice[4] = dice[0];
	new_dice[5] = dice[4];

}
void west() {

	new_dice[0] = dice[2];
	new_dice[1] = dice[1];
	new_dice[2] = dice[5];
	new_dice[3] = dice[0];
	new_dice[4] = dice[4];
	new_dice[5] = dice[3];

}
void change() {
	if (map[x][y] == 0) {
		map[x][y] =new_dice[5];
	}
	else {
		new_dice[5] = map[x][y];
		map[x][y] = 0;
	}
}
int main() {

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k;i++) {
		int a;
		cin >> a;
		qq.push(a);
	}

	while (qq.empty()!=true) {

		int d = qq.front();
		qq.pop();

		if (x+imap[d] >=0 && x+imap[d] <n && y+jmap[d] >=0 && y+jmap[d] <m) { //나가지 않는경우에만 진행
			if (d==3) {
				north();
				x -= 1;
				change();
				init();
				ans.push(dice[0]);
			}
			else if (d==1) {
				east();
				y += 1;
				change();
				init();
				ans.push(dice[0]);
			}
			else if (d==4) {
				south();
				x += 1;
				change();
				init();
				ans.push(dice[0]);
			}
			else { 
				west(); y -= 1; change(); init(); ans.push(dice[0]);
			}
		}
	}
	while (ans.empty()!=true) {
		int a;
		a = ans.front();
		ans.pop();
		cout << a << "\n";
	}

	
	return 0;
}
