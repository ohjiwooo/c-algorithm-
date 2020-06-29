#include<iostream>
#include<queue>
using namespace std;

int w1[8];
int w2[8];
int w3[8];
int w4[8];
int n;
bool vis[5];
queue<pair<int, int>> qq;
int aa;
void turn1(int d);
void turn2(int d);
void turn3(int d);
void turn4(int d);

void ff1() {
	int i = 7;
	while (i>=0) {
		w1[i] = aa % 10;
		aa /= 10;
		i--;
	}
}
void ff2() {
	int i = 7;
	while (i >= 0) {
		w2[i] = aa % 10;
		aa /= 10;
		i--;
	}
}
void ff3() {
	int i = 7;
	while (i >= 0) {
		w3[i] = aa % 10;
		aa /= 10;
		i--;
	}
}
void ff4() {
	int i = 7;
	while (i >= 0) {
		w4[i] = aa % 10;
		aa /= 10;
		i--;
	}
}
int score() {
	int ans = 0;

	if (w1[0]==1) {
		ans += 1;
	}
	if (w2[0] == 1) {
		ans += 2;
	}
	if (w3[0] == 1) {
		ans += 4;
	}
	if (w4[0] == 1) {
		ans += 8;
	}
	return ans;
}
void init() {
	for (int i = 0; i < 5;i++) {
		vis[i] = false;
	}
}
void turn1(int d) { //번호,방향
	vis[1] = true;

	if (w1[2] != w2[6] && vis[2]!=true) {
		turn2(-d);
	}

	if (d==1) { //시계방향
		int a = w1[7];
		for (int i = 7; i > 0;i--) {
			w1[i] = w1[i - 1];
		}
		w1[0] = a;
	}
	else {
		int a = w1[0];
		for (int i = 0; i < 7; i++) {
			w1[i] = w1[i + 1];
		}
		w1[7] = a;
	}
}

void turn2(int d) { //번호,방향
	vis[2] = true;
	if (w1[2] != w2[6] && vis[1]!=true) {
		turn1(-d);
	}
	if (w2[2]!=w3[6] && vis[3] !=true) {
		turn3(-d);
	}


	if (d == 1) { //시계방향
		int a = w2[7];
		for (int i = 7; i > 0; i--) {
			w2[i] = w2[i - 1];
		}
		w2[0] = a;
	}
	else {
		int a = w2[0];
		for (int i = 0; i < 7; i++) {
			w2[i] = w2[i + 1];
		}
		w2[7] = a;
	}
}

void turn3(int d) { //번호,방향
	vis[3] = true;

	if (w3[2] != w4[6] && vis[4] != true) {
		turn4(-d);
	}
	if (w3[6] != w2[2] && vis[2] != true) {
		turn2(-d);
	}

	if (d == 1) { //시계방향
		int a = w3[7];
		for (int i = 7; i > 0; i--) {
			w3[i] = w3[i - 1];
		}
		w3[0] = a;
	}
	else {
		int a = w3[0];
		for (int i = 0; i < 7; i++) {
			w3[i] = w3[i + 1];
		}
		w3[7] = a;
	}
}
void turn4(int d) { //번호,방향
	vis[4] = true;

	if (w3[2] != w4[6] && vis[3] != true) {
		turn3(-d);
	}
	

	if (d == 1) { //시계방향
		int a = w4[7];
		for (int i = 7; i > 0; i--) {
			w4[i] = w4[i - 1];
		}
		w4[0] = a;
	}
	else {
		int a = w4[0];
		for (int i = 0; i < 7; i++) {
			w4[i] = w4[i + 1];
		}
		w4[7] = a;
	}
}
int main() {

	cin >> aa;
	ff1();
	cin >> aa;
	ff2();
	cin >> aa;
	ff3();
	cin >> aa;
	ff4();
	cin >> n;

	for (int i = 0; i < n;i++) {
		int a, b;
		cin >> a >> b;
		qq.push(make_pair(a, b));
	}

	while (qq.empty()!=true) {

		int a = qq.front().first;//회전번호
		int b = qq.front().second;//방향
		qq.pop();
		init();

		if (a==1) {
			turn1(b);
		}
		else if (a==2) {
			turn2(b);
		}
		else if (a==3) {
			turn3(b);
		}
		else {
			turn4(b);
		}
	}
	cout << score();

	return 0;
}