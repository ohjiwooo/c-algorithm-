#include<iostream>
#include<queue>

using namespace std;

typedef struct s {

	int i1;
	int j1;
	int i2;
	int j2;
	
}s;

int n, m; //최대10
char map[15][15];
int ri, rj;
int bi, bj;
int ans = 1;
queue <s>qq;


int up(int i,int j) {

		while (i>0) {
			i--;
			if (map[i][j] == 'O') {
				return -1;
			}
			else if (map[i][j]=='#') {
				return ++i;
			}
		}
}

int right(int i,int j) {

	
		while (j < m) {
			j++;
			if (map[i][j] == 'O') {
				return -1;
			}
			else if (map[i][j] == '#') {
				return --j;
			}
		}
	


}

int down(int i,int j) {


		while (i < n) {
			i++;
			if (map[i][j] == 'O') {
				return -1;
			}
			else if (map[i][j] == '#') {
				return --i;
			}
		}
	
	

}

int left(int i,int j) {

		while (j > 0) {
			j--;
			if (map[i][j] == 'O') {
				return -1;
			}
			else if (map[i][j] == '#') {
				return ++j;
			}
		}
	
	

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> map[i][j];

			if (map[i][j]=='R') {
				ri = i; rj = j;
			}
			else if (map[i][j]=='B') {
				bi = i; bj = j;
			}
		}
	}


	qq.push({ ri,rj,bi,bj });
	
	while (1) {
		

		int size = qq.size();
		
		//함수 - 구슬이 구멍에 빠질시 -1을 리턴하고 그외에는 변경된 좌표를 리턴
		for (int i = 0; i < size;i++) {

			int now_ri = qq.front().i1;
			int now_rj = qq.front().j1;
			int now_bi = qq.front().i2;
			int now_bj = qq.front().j2;
			int newr, newb;
			qq.pop();

			if (up(now_bi, now_bj) != -1 && up(now_ri, now_rj) != -1 && (map[now_ri-1][now_rj]!='#' || map[now_bi - 1][now_bj] != '#')) {//red구슬이 위로 이동이 가능하고 이동시 두구슬이 구멍에 빠지지않음
				newr = up(now_ri, now_rj);
				newb = up(now_bi, now_bj);
				if (newr == newb && now_rj==now_bj) { //충돌
					if(now_ri<now_bi) {
						newb++;
					}
					else { newr++; }
				}
				
					qq.push({ newr,now_rj,newb,now_bj }); 
			}
			else if(up(now_ri, now_rj) == -1 && up(now_bi, now_bj) != -1) {//위로이동시 red구슬이 구멍에 빠짐
				cout << ans; return 0;
			}

			if (right(now_bi, now_bj) != -1 && right(now_ri, now_rj) != -1 &&( map[now_ri][now_rj+1] != '#' ||  map[now_bi][now_bj + 1] != '#')) {
				newr = right(now_ri, now_rj);
				newb = right(now_bi, now_bj);
				if (newr == newb && now_ri==now_bi) { //충돌
					if (now_rj < now_bj) {
						newr--;
					}
					else {
						newb--;
					}
				}
				
					qq.push({ now_ri,newr,now_bi,newb }); 
				
			}
			else if (right(now_ri, now_rj) == -1 && right(now_bi, now_bj) != -1 ) {
				cout << ans; return 0;
			}

			if (down(now_bi, now_bj) != -1 && down(now_ri, now_rj) != -1 && (map[now_ri +1][now_rj] != '#' || map[now_bi + 1][now_bj] != '#')) {
				newr = down(now_ri, now_rj);
				newb = down(now_bi, now_bj);
				if (newr == newb && now_rj==now_bj) { //충돌
					if (now_ri < now_bi) {
						newr--;
					}
					else { newb--; }
				}
				
					qq.push({ newr,now_rj,newb,now_bj }); 

			}
			else if (down(now_ri, now_rj) == -1 && down(now_bi, now_bj) != -1 ) {
				cout << ans; return 0;
			}

			if (left(now_bi, now_bj) != -1 && left(now_ri, now_rj) != -1 && (map[now_ri][now_rj - 1] != '#'|| map[now_bi][now_bj - 1] != '#')) {
			
				newr = left(now_ri, now_rj);
				newb = left(now_bi, now_bj);
				if (newr == newb && now_ri==now_bi) { //충돌
					if (now_rj < now_bj ) {
						newb++;
					}
					else {
						newr++;
					}
				}
					qq.push({ now_ri,newr,now_bi,newb }); 
			}
			else if (left(now_ri, now_rj) == -1 && left(now_bi, now_bj) != -1) {
				cout << ans; return 0;
			}

		}ans++;

		if (ans > 10) { cout << -1; return 0; }

	}
	return 0;
}